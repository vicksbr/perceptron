/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inicializacao_Dados.h
 * Author: Daniel
 *
 * Created on 30 de Maio de 2016, 00:31
 */

#ifndef INICIALIZACAO_DADOS_H
#define INICIALIZACAO_DADOS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_rng.h>

#include "Constantes.h"
#include "Estruturas.h"

void iniciarBaseDados(Base_Dados baseDados, char* diretorio_base) {
    int i = 0;
    int j = 0;

    FILE *arquivoBase;
    arquivoBase = fopen(diretorio_base, "r");

    if (arquivoBase == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("- INICIALIZAÇÃO DA BASE DE DADOS\n\n");

    for (i = 0; i < NUM_AMOSTRAS_TREINO; i++) {
        for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
            if (!fscanf(arquivoBase, "%f", &baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + j])) {
                exit(EXIT_FAILURE);
            }

            printf("%f\t", baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + j]);
        }

        if (!fscanf(arquivoBase, "%f", &baseDados.saida_Base[i])) {
            exit(EXIT_FAILURE);
        }

        printf("%f\t", baseDados.saida_Base[i]);
        printf("%f", (float) CONSTANTE_BIAS);
        printf("\n");
    }

    printf("\n\n\n");

    //    for (i = 0; i < NUM_AMOSTRAS_TREINO; i++) {
    //        //baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + (NUM_VARIAVEIS_ENTRADAS)] = CONSTANTE_BIAS;
    //        for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
    //            printf("%f\t", baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + j]);
    //        }
    //        printf("%f\t", baseDados.saida_Base[i]);
    //        printf("%f", (float)CONSTANTE_BIAS);
    //        printf("\n");
    //    }

    fflush(stdin);
    fclose(arquivoBase);
}

void incializacaoBaseValidacao(Base_Dados baseDados_Validacao, gsl_rng* r) {
    int i = 0;
    int j = 0;

    for (i = 0; i < NUM_AMOSTRAS_TREINO; i++) {
        for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
            baseDados_Validacao.entradas_Base[i * NUM_DADOS_ENTRADA + j] = gsl_rng_uniform(r);
        }
    }
}

void incializacaoNeuronioPerceptron(Neuronio_Perceptron neuronioPerceptron, Base_Dados baseDados, gsl_rng* r) {
    int i = 0;
    int j = 0;

    neuronioPerceptron.isErro[0] = 0.0f;

    printf("\n- INICIALIZAÇÃO DO NEURÔNIO (PERCEPTRON ÚNICO)\n\n");

    for (i = 0; i < NUM_AMOSTRAS_TREINO; i++) {
        neuronioPerceptron.saida_Neuronio[i] = baseDados.saida_Base[i];
        for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
            printf("%f\t", baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + j]);

            if (i == (NUM_AMOSTRAS_TREINO - 1)) {
                neuronioPerceptron.pesos_Neuronio[j] = gsl_rng_uniform(r) * (W_MAX - W_MIN) + W_MIN;
            }
        }
        
        neuronioPerceptron.pesos_Neuronio[(NUM_DADOS_PESOS - 1)] = gsl_rng_uniform(r) * (W_MAX - W_MIN) + W_MIN;

        //printf("%f\n", baseDados.saida_Base[i]);
        printf("%f\t", neuronioPerceptron.saida_Neuronio[i]);
        printf("%f", (float) CONSTANTE_BIAS);
        printf("\n");
    }

    printf("\n- VALOR DOS PESOS (PERCEPTRON ÚNICO)\n\n");

    for (i = 0; i < NUM_DADOS_PESOS; i++) {
        printf("W[%d] = %f\t", i, neuronioPerceptron.pesos_Neuronio[i]);
    }

    printf("\n\n");
}

#endif /* INICIALIZACAO_DADOS_H */

