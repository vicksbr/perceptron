/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.c
 * Author: Daniel
 *
 * Created on 29 de Maio de 2016, 21:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_rng.h>

#include "Constantes.h"
#include "Inicializacao_Dados.h"
#include "Estruturas.h"
#include "Alocacao_Memoria_C.h"
#include "Treinamento.h"
#include "Avaliacao.h"

/*
 * 
 */
int main(int argc, char** argv) {
    //char* diretorio_base = (char*) malloc(sizeof (char));
    char* diretorio_base = "Base_Exemplo.dat";

    int numEpocas = 0;
    int j = 0;

    const gsl_rng_type * T;
    gsl_rng* r;

    T = gsl_rng_rand48;
    r = gsl_rng_alloc(T);

    gsl_rng_set(r, time(NULL));
    gsl_rng_env_setup();

    Base_Dados baseDados = alocarBaseDadosInput_MALLOC_CPU();
    Base_Dados baseDados_Validacao = alocarBaseDadosInput_MALLOC_CPU();
    Neuronio_Perceptron neuronioPerceptron = alocarNeuronioPerceptronInput_MALLOC_CPU();

    printf("Teste de Redes Neurais Artificiais (RNA PERCEPTRON - UM NEURÔNIO COM CORREÇÃO VIA REGRA DE HEBB)\n\n");

    iniciarBaseDados(baseDados, diretorio_base);
    incializacaoNeuronioPerceptron(neuronioPerceptron, baseDados, r);
    incializacaoBaseValidacao(baseDados_Validacao, r);

    printf("\n");

    for (j = 0; j < NUM_AMOSTRAS_TREINO; j++) {
        printf("Saída Real Base[%d] = %f\n", j, baseDados.saida_Base[j]);
        printf("Saída Real Neuronio[%d] = %f\n", j, neuronioPerceptron.saida_Neuronio[j]);
    }
    
    printf("\n");

    neuronioPerceptron.isErro[0] = 0;

    for (numEpocas = 0; numEpocas < NUM_EPOCAS; numEpocas++) {
        if (numEpocas >= 1 && neuronioPerceptron.isErro[0] == 0) {
            printf("\n\nPerceptron Treinado: Erro = %d\n\n", neuronioPerceptron.isErro[0]);
            break;
        }

        printf("Número de épocas: %d\n", numEpocas);

        processamentoPerceptron(baseDados, neuronioPerceptron);
        printf("\n");
    }

    incializacaoBaseValidacao(baseDados_Validacao, r);

    classificarNovasAmostras(neuronioPerceptron, baseDados_Validacao);
    classificarNovasAmostras(neuronioPerceptron, baseDados);

    gsl_rng_free(r);

    liberarMemoriaBaseDadosInput_MALLOC_CPU(baseDados);
    liberarMemoriaNeuronioPerceptronInput_MALLOC_CPU(neuronioPerceptron);

    return (EXIT_SUCCESS);
}

