/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estruturas.h
 * Author: Daniel
 *
 * Created on 29 de Maio de 2016, 21:31
 */

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float* entradas_Base;           //[i * NUM_DADOS_ENTRADA + j] -> ((NUM_AMOSTRAS_TREINO * NUM_DADOS_ENTRADA) * sizeof(float))
    float* saida_Base;              //[i] -> ((NUM_DADOS_SAIDA) * sizeof(float))
} Base_Dados;

typedef struct {
    float* pesos_Neuronio;          //[i] -> ((NUM_DADOS_PESOS) * sizeof(float))
    float* saida_Neuronio;          //[i] -> ((NUM_DADOS_SAIDA) * sizeof(float))
    float* saidaEstimada_Neuronio;  //[0] -> ((1) * sizeof(float))
    short* isErro;                  //[0] -> ((1) * sizeof(short))
} Neuronio_Perceptron;

#endif /* ESTRUTURAS_H */

