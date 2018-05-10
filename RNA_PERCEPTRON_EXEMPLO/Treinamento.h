/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Treinamento.h
 * Author: Daniel
 *
 * Created on 30 de Maio de 2016, 14:42
 */

#ifndef TREINAMENTO_H
#define TREINAMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "Constantes.h"
#include "Inicializacao_Dados.h"
#include "Estruturas.h"
#include "Funcoes_Ativacao.h"

void correcaoRegraHebb(Neuronio_Perceptron neuronioPerceptron, Base_Dados baseDados, int i) {
    int j = 0;

    for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
        //        neuronioPerceptron.pesos_Neuronio[j] =
        //                (float) (neuronioPerceptron.pesos_Neuronio[j] + (TAXA_APRENDIZADO * (neuronioPerceptron.saida_Neuronio[i]
        //                - neuronioPerceptron.saidaEstimada_Neuronio[0]) * neuronioPerceptron.entradas_Neuronio[i * NUM_DADOS_ENTRADA + j]));
        neuronioPerceptron.pesos_Neuronio[j] =
                (float) (neuronioPerceptron.pesos_Neuronio[j] + (TAXA_APRENDIZADO * (neuronioPerceptron.saida_Neuronio[i]
                - neuronioPerceptron.saidaEstimada_Neuronio[0]) * baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + j]));
    }
    
    neuronioPerceptron.pesos_Neuronio[(NUM_DADOS_PESOS - 1)] =
            (float) (neuronioPerceptron.pesos_Neuronio[(NUM_DADOS_PESOS - 1)] + (TAXA_APRENDIZADO * (neuronioPerceptron.saida_Neuronio[i]
            - neuronioPerceptron.saidaEstimada_Neuronio[0]) * (float) CONSTANTE_BIAS));
}

void processamentoPerceptron(Base_Dados baseDados, Neuronio_Perceptron neuronioPerceptron) {
    int i = 0;
    int j = 0;

    float somatorioPerceptron = 0.0f;

    neuronioPerceptron.isErro[0] = 0;
    for (i = 0; i < NUM_AMOSTRAS_TREINO; i++) {
        somatorioPerceptron = 0.0f;
        for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
            //            somatorioPerceptron +=
            //                    (float) (neuronioPerceptron.entradas_Neuronio[i * NUM_DADOS_ENTRADA + j] * neuronioPerceptron.pesos_Neuronio[j]);
            somatorioPerceptron +=
                    (float) (baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + j] * neuronioPerceptron.pesos_Neuronio[j]);
            //printf("Valor de J = %d\n",j);
        }
        
        //printf("Valor de J final = %d\n",j);
        
        somatorioPerceptron +=
                (float) ((float) CONSTANTE_BIAS * neuronioPerceptron.pesos_Neuronio[(NUM_DADOS_PESOS - 1)]);

        neuronioPerceptron.saidaEstimada_Neuronio[0] = funcaoDegrauBipolar_Classica_Negativa(somatorioPerceptron);

        //neuronioPerceptron.saidaEstimada_Neuronio[0] = funcaoDegrauBipolar_Simetrica(somatorioPerceptron, 3, 2, 1);
        
        printf("Saída estimada[%d] = %f | Saída Real[%d] = %f\n", i, neuronioPerceptron.saidaEstimada_Neuronio[0], i, neuronioPerceptron.saida_Neuronio[i]);

        if (neuronioPerceptron.saidaEstimada_Neuronio[0] != neuronioPerceptron.saida_Neuronio[i]) {
            printf("ERRO NA AMOSTRA %d: Saída estimada = %f | Saída Real = %f\n", i, neuronioPerceptron.saidaEstimada_Neuronio[0], neuronioPerceptron.saida_Neuronio[i]);

            correcaoRegraHebb(neuronioPerceptron, baseDados, i);
            neuronioPerceptron.isErro[0] = 1;
        }
    }
}
#endif /* TREINAMENTO_H */

