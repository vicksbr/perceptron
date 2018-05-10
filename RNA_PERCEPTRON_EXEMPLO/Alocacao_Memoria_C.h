/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alocacao_Dados_C.h
 * Author: Daniel
 *
 * Created on 30 de Maio de 2016, 03:03
 */

#ifndef ALOCACAO_DADOS_C_H
#define ALOCACAO_DADOS_C_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "Constantes.h"
#include "Estruturas.h"

Base_Dados alocarBaseDadosInput_MALLOC_CPU() {
    Base_Dados baseDados;

    baseDados.entradas_Base = (float*) malloc((NUM_AMOSTRAS_TREINO * NUM_DADOS_ENTRADA) * sizeof (float));
    baseDados.saida_Base = (float*) malloc((NUM_DADOS_SAIDA) * sizeof (float));
    
    return baseDados;
}

void liberarMemoriaBaseDadosInput_MALLOC_CPU(Base_Dados baseDados) {
    free(baseDados.entradas_Base);
    free(baseDados.saida_Base);
}

Neuronio_Perceptron alocarNeuronioPerceptronInput_MALLOC_CPU() {
    Neuronio_Perceptron neuronioPerceptron;

    neuronioPerceptron.pesos_Neuronio = (float*) malloc((NUM_DADOS_PESOS) * sizeof (float));
    neuronioPerceptron.saida_Neuronio = (float*) malloc((NUM_DADOS_SAIDA) * sizeof (float));
    //neuronioPerceptron.saida_Neuronio = (float*) malloc((NUM_AMOSTRAS_TREINO*NUM_VARIAVEIS_SAIDA) * sizeof(float));
    neuronioPerceptron.saidaEstimada_Neuronio = (float*) malloc((1) * sizeof (float));
    neuronioPerceptron.isErro = (short*) malloc((1) * sizeof (short));

    return neuronioPerceptron;
}

void liberarMemoriaNeuronioPerceptronInput_MALLOC_CPU(Neuronio_Perceptron neuronioPerceptron) {
    free(neuronioPerceptron.pesos_Neuronio);
    free(neuronioPerceptron.saida_Neuronio);
    free(neuronioPerceptron.saidaEstimada_Neuronio); 
    free(neuronioPerceptron.isErro);
}

#endif /* ALOCACAO_DADOS_C_H */

