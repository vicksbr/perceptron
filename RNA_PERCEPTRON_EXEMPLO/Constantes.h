/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constantes.h
 * Author: Daniel
 *
 * Created on 18 de Fevereiro de 2016, 02:39
 */

#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef ABS
#define ABS(x)   ( (x) > (0) ? (x): (-(x)) )
#endif
#ifndef MAX
#define MAX(x,y) ( (x) > (y) ? (x) : (y) )
#endif
#ifndef MIN
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )
#endif

#define NUM_EPOCAS                      (int)400

#define LIMITE_MIN_RAMPA_SIMETRICA      (float)-1.2f
#define LIMITE_MAX_RAMPA_SIMETRICA      (float)1.2f

#define BETA                            (float)0.2f
#define PONTO_CENTRAL_GAUSSIANO         (float)0.6f
#define DESVIO_PADRAO_GAUSSIANO         (float)1.0f
#define CONSTANTE_BIAS                  (float)-1.0f

#define TAXA_APRENDIZADO                (float)0.4f

#define NUM_VARIAVEIS_ENTRADAS          (int)3
#define NUM_DADOS_ENTRADA               (int)NUM_VARIAVEIS_ENTRADAS //+1

#define NUM_VARIAVEIS_PESOS             (int)NUM_VARIAVEIS_ENTRADAS
#define NUM_DADOS_PESOS                 (int)NUM_VARIAVEIS_PESOS+1

#define NUM_AMOSTRAS_TREINO             (int)4
#define NUM_DADOS_SAIDA                 (int)4

#define W_MIN                           (float)0.0f//-0.5f
#define W_MAX                           (float)1.0f//0.5f

//#define LIMITE_RAND_X1                      ((ESPACO_MAX_X1) - fabsf((float)ESPACO_MIN_X1))
//#define LIMITE_RAND_X2                      ((ESPACO_MAX_X2) - fabsf((float)ESPACO_MIN_X2))
//#define LIMITE_RAND_X3                      ((ESPACO_MAX_X3) - fabsf((float)ESPACO_MIN_X3))

#endif /* CONSTANTES_H */

