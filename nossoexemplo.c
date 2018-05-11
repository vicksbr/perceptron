#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTRADA 2
#define VLR_BIAS 1
#define TX_APR 1
#define QTD_DADOS_TREINAMENTOS 4
#define EPOCAS 100

const int dadosTreinamento[4][3] = {{0,0,0}, {0,1,0}, {1,0,0}, {1,1,1} };

int *dado_estrategia1;

float soma(int e1, int e2, float* sinapses);
int degrau(float s);
float regraDelta(int erro, int entrada, float sinapse);
void treinarRede(float *sinapses);


void print_matriz(unsigned char *Matriz, int linhas, int colunas) {  

		int i,j;
		
		for (i = 0; i < linhas; i++) { 
			for (j=0; j < colunas; j++) {
				printf("%d ",Matriz[i*colunas+j]);
			}
		printf("\n");
		}
}

unsigned char *lerBase() {
	
	char grupo = 7; 
	char *linhaLida = (char*)malloc(1024*sizeof(char));
	
	unsigned char *A = (char*)malloc(48*49*1);

	FILE *fp = fopen("dBtestGr7St1.dat","r");    
	int i=0;	
	int aux=0;
	
    if( fp == NULL ) {                       
        printf("Problemas ao abrir o arquivo");        
    }
	
	char *token = NULL;
    while (!feof (fp)) {
        if (fgets(linhaLida, 1024, fp)) {
			
			i = 0;
            token = strtok(linhaLida, ",");
			
            while(token != NULL) {
				
				if(i > 47) {					
					A[i + 49*aux] = 1;
					//printf("%d(%d) ",A[i + 49*aux],i + 49*aux);				    					
					break;
				}
                else {
                	int i2 = atoi(token);
					A[i + 49*aux] = i2;
					//printf("%d(%d)",A[i + 49*aux],i + 49*aux);				    
				}
                token=strtok(NULL,",");
                i++;
            }         
		printf("\n");		
		aux++;		
		}
    }
    printf("\n");
    fclose(fp);
	printf("\n");
    
	return A;
}


int main()
{

	int linhas_str1 = 48;
	int colunas_str1 = 49;

	//alocando o vetor de pesos sinapticos 
	//a primeira posição será o peso do bias
	
	float *sinapses;
	
	sinapses = (float*)malloc((ENTRADA+1)*sizeof(float));
	
	if (!sinapses)
		printf("ERRO: memoria insuficiente\n");
	
	//a estratégia utilizada começa com todos os pesos = 0	
	for (int aux=0; aux < ENTRADA+1; aux++)
		sinapses[aux] = 0;

		
	unsigned char *matriz_treinamento1;
	
	matriz_treinamento1 = (char*)malloc(linhas_str1 * colunas_str1 * 1);
			
	matriz_treinamento1 = lerBase();

	print_matriz(matriz_treinamento1,48,49);
	
	// int e1, e2;

	// treinarRede(sinapses);
	
	// while(1){
	// 	printf("Entrada 1 .................: ");
	// 	scanf("%d", &e1);
	// 	printf("Entrada 2 .................: ");
	// 	scanf("%d", &e2);
	// 	printf("Resultado............: %d \n", degrau(soma(e1, e2, sinapses)));
	// }

	return 0;
}



float prod_vetorial(double v[], double u[], int n) {
	
	float result = 0;
	
	for (int i = 0; i < n; i++)
		result += v[i]*u[i];
	return result;

}

float soma(int e1, int e2, float *sinapses)
{
	float resultado = 0;
	resultado = resultado + sinapses[0] * VLR_BIAS;
	resultado = resultado + sinapses[1] * e1;
	resultado = resultado + sinapses[2] * e2;
	return resultado;
}

int degrau(float s)
{
	if(s > 0) return 1;
	return 0;
}

float regraDelta(int erro, int entrada, float sinapse)
{
	printf("erro: %d | Entrada: %d | SAIDA: %f\n", erro, entrada, (sinapse + (TX_APR * erro * entrada)));
	return (sinapse + (TX_APR * erro * entrada));
	
}

void treinarRede(float * sinapses)
{
	int i, j, erro;
	
	float resposta;

	// NUMERO DE EPOCAS
	for(i = 0; i < EPOCAS; i++){
		// CONJUNTO DE TREINAMENTOS
		for(j = 0; j < QTD_DADOS_TREINAMENTOS; j++){
			resposta = degrau(soma(dadosTreinamento[j][0], dadosTreinamento[j][1], sinapses));			
			erro = dadosTreinamento[j][2] - resposta;
			printf("epoca=%d j=%d resposta=%f erro=%d pesos[%f,%f,%f]\n",i,j,resposta,erro,sinapses[0],sinapses[1],sinapses[2]);
			if(erro){
				sinapses[0] = regraDelta(erro, VLR_BIAS, sinapses[0]);
				sinapses[1] = regraDelta(erro, dadosTreinamento[j][0], sinapses[1]);
				sinapses[2] = regraDelta(erro, dadosTreinamento[j][1], sinapses[2]);
			}
		}
	}
	
	printf("RESULTADO TREINAMENTO");
	printf("w[bias] = %f\n", sinapses[0]);
	printf("w[e1] = %f\n", sinapses[1]);
	printf("w[e2] = %f\n", sinapses[2]);	

}


