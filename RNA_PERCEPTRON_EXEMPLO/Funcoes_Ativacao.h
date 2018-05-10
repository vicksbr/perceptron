/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funcoes_Ativacao.h
 * Author: Daniel
 *
 * Created on 27 de Maio de 2016, 19:28
 */

#ifndef FUNCOES_ATIVACAO_H
#define FUNCOES_ATIVACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "Constantes.h"
#include "Inicializacao_Dados.h"
#include "Estruturas.h"

//Parcialmente diferenciavéis

short funcaoDegrauBipolar_Classica_Booleana(float somatorioPerceptron) {
    if (somatorioPerceptron >= 0) {
        return 1;
    } else {
        return 0;
    }
}

short funcaoDegrauBipolar_Classica_Negativa(float somatorioPerceptron) {
    if (somatorioPerceptron >= 0) {
        return 1;
    } else {
        return -1;
    }
}

short funcaoDegrauBipolar_Simetrica(float somatorioAdaline, int valorA, int valorB, int valorC) {
    //    if (somatorioAdaline > 0) {
    //        return 1;
    //    } else {
    //        if (somatorioAdaline == 0) {
    //            return 0;
    //        } else {
    //            return -1;
    //        }
    //    }
    if (somatorioAdaline > 0) {
        return valorA;
    } else {
        if (somatorioAdaline == 0) {
            return valorB;
        } else {
            return valorC;
        }
    }
}

float funcaoDegrauBipolar_RampaSimetrica(float somatorioPerceptron) {
    if (somatorioPerceptron > LIMITE_MIN_RAMPA_SIMETRICA) {
        return LIMITE_MAX_RAMPA_SIMETRICA;
    } else {
        if ((somatorioPerceptron >= LIMITE_MIN_RAMPA_SIMETRICA) &&
                (somatorioPerceptron <= LIMITE_MAX_RAMPA_SIMETRICA)) {
            return somatorioPerceptron;
        } else {
            return LIMITE_MIN_RAMPA_SIMETRICA;
        }
    }
}

//Totalmente diferenciavéis

float funcaoLinear(float somatorioPerceptron) {
    return (float) somatorioPerceptron;
}

float funcaoLogistica(float somatorioPerceptron) {
    return (float) (1.0f / (1.0f + powf(M_E, ((-BETA) * somatorioPerceptron))));
}

float funcaoTangenteHiperbolica(float somatorioPerceptron) {
    return (float) ((1.0f - powf(M_E, ((-BETA) * somatorioPerceptron))) / (1.0f + powf(M_E, ((-BETA) * somatorioPerceptron))));
}

float funcaoGaussiana(float somatorioPerceptron) {
    return (float) (powf(M_E, -((powf((somatorioPerceptron - PONTO_CENTRAL_GAUSSIANO), 2.0f)) / (2 * powf(DESVIO_PADRAO_GAUSSIANO, 2.0f)))));
}

#endif /* FUNCOES_ATIVACAO_H */

