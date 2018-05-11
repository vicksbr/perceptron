#include <stdio.h>
#include <stdlib.h>

int main() { 

	printf("hello world\n");
	
	FILE *arquivo;
	arquivo = fopen("data.dat","r");

	int vetor[12];
	
	int i=0;
	int j=0;
	
	int linhas=3;
	int colunas=4;
	
	for(i=0; i < linhas*colunas; i++)
			fscanf(arquivo,"%d",&vetor[i]);	

	fclose(arquivo);
	
	for(i=0; i < linhas; i++) { 
		printf("\n");	
		for(j=0; j < colunas; j++) { 
			printf("%d ",vetor[i*colunas + j]);	
		}
	}
	printf("\n");

	return 0;
}

