/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Avaliacao.h
 * Author: Daniel
 *
 * Created on 30 de Maio de 2016, 22:14
 */

#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "Constantes.h"
#include "Inicializacao_Dados.h"
#include "Estruturas.h"
#include "Funcoes_Ativacao.h"

void classificarNovasAmostras(Neuronio_Perceptron neuronioPerceptron, Base_Dados baseDados_Validacao) {
    int i = 0;
    int j = 0;
    float somatorioPerceptron = 0.0;

    printf("\n\n");

    for (i = 0; i < NUM_AMOSTRAS_TREINO; i++) {
        somatorioPerceptron = 0.0f;
        for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
            somatorioPerceptron +=
                    (float) (baseDados_Validacao.entradas_Base[i * NUM_DADOS_ENTRADA + j] * neuronioPerceptron.pesos_Neuronio[j]);
        }
        somatorioPerceptron +=
                (float) ((float) CONSTANTE_BIAS * neuronioPerceptron.pesos_Neuronio[(NUM_DADOS_PESOS - 1)]);

//        if (funcaoDegrauBipolar_Simetrica(somatorioPerceptron, 3, 2, 1) == 3) {
//            printf("A amostra %d com saída %d pertence a Classe A (Somatório = %f)\n", i, 3, somatorioPerceptron);
//        }
//        if (funcaoDegrauBipolar_Simetrica(somatorioPerceptron, 3, 2, 1) == 2) {
//            printf("A amostra %d com saída %d pertence a Classe B (Somatório = %f)\n", i, 2, somatorioPerceptron);
//        }
//        if (funcaoDegrauBipolar_Simetrica(somatorioPerceptron, 3, 2, 1) == 1) {
//            printf("A amostra %d com saída %d pertence a Classe C (Somatório = %f)\n", i, 1, somatorioPerceptron);
//        }

        if (funcaoDegrauBipolar_Classica_Negativa(somatorioPerceptron) == -1) {
            printf("A amostra %d com saída %d pertence a Classe A (Somatório = %f)\n", i, -1, somatorioPerceptron);
        }
        if (funcaoDegrauBipolar_Classica_Negativa(somatorioPerceptron) == 1) {
            printf("A amostra %d com saída %d pertence a Classe B (Somatório = %f)\n", i, 1, somatorioPerceptron);
        }
    }
}

void classificarAmostrasBase(Neuronio_Perceptron neuronioPerceptron, Base_Dados baseDados) {
    int i = 0;
    int j = 0;
    float somatorioPerceptron = 0.0;

    printf("\n\n");

    for (i = 0; i < NUM_AMOSTRAS_TREINO; i++) {
        somatorioPerceptron = 0.0f;
        for (j = 0; j < NUM_DADOS_ENTRADA; j++) {
            somatorioPerceptron +=
                    (float) (baseDados.entradas_Base[i * NUM_DADOS_ENTRADA + j] * neuronioPerceptron.pesos_Neuronio[j]);
        }
        somatorioPerceptron +=
                (float) ((float) CONSTANTE_BIAS * neuronioPerceptron.pesos_Neuronio[(NUM_DADOS_PESOS - 1)]);

//        if (funcaoDegrauBipolar_Simetrica(somatorioPerceptron, 3, 2, 1) == 3) {
//            printf("BASE: A amostra %d com saída %d pertence a Classe A (Somatório = %f)\n", i, 3, somatorioPerceptron);
//        }
//        if (funcaoDegrauBipolar_Simetrica(somatorioPerceptron, 3, 2, 1) == 2) {
//            printf("BASE: A amostra %d com saída %d pertence a Classe B (Somatório = %f)\n", i, 2, somatorioPerceptron);
//        }
//        if (funcaoDegrauBipolar_Simetrica(somatorioPerceptron, 3, 2, 1) == 1) {
//            printf("BASE: A amostra %d com saída %d pertence a Classe C (Somatório = %f)\n", i, 1, somatorioPerceptron);
//        }

                if (funcaoDegrauBipolar_Classica_Negativa(somatorioPerceptron) == -1) {
                    printf("BASE: A amostra %d com saída %d pertence a Classe A (Somatório = %f)\n",i,-1, somatorioPerceptron);
                }
                if (funcaoDegrauBipolar_Classica_Negativa(somatorioPerceptron) == 1) {
                    printf("BASE: A amostra %d com saída %d pertence a Classe B (Somatório = %f)\n",i,1, somatorioPerceptron);
                }
    }
}

#endif /* AVALIACAO_H */

