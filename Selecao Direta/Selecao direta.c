#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fabricante{
	char nome[50];
	char nacionalidade[20];
	int ano;
}fabricante;

void printar(fabricante *vet, int n){
	int i;
	for(i=0; i<n; i++){
		printf("fabricante[%d]: \n",i);
		printf(" Nome: %s \n", vet[i].nome);
		printf(" Nacionalidade: %s \n", vet[i].nacionalidade);
		printf(" Fundada em: %d \n\n", vet[i].ano);
	}
}

void preencher(fabricante *fabricantes){
	strcpy(fabricantes[0].nome,"coc");
	strcpy(fabricantes[0].nacionalidade,"chileno");
	fabricantes[0].ano = 2000;
	strcpy(fabricantes[1].nome,"ful");
	strcpy(fabricantes[1].nacionalidade,"argentino");
	fabricantes[1].ano = 2010;
	strcpy(fabricantes[2].nome,"boz");
	strcpy(fabricantes[2].nacionalidade,"americano");
	fabricantes[2].ano = 1950;
	strcpy(fabricantes[3].nome,"zap");
	strcpy(fabricantes[3].nacionalidade,"mexicano");
	fabricantes[3].ano = 1999;
	strcpy(fabricantes[4].nome,"mas");
	strcpy(fabricantes[4].nacionalidade,"chines");
	fabricantes[4].ano = 1940;
	strcpy(fabricantes[5].nome,"alol");
	strcpy(fabricantes[5].nacionalidade,"britanico");
	fabricantes[5].ano = 2018;
	strcpy(fabricantes[6].nome,"cool");
	strcpy(fabricantes[6].nacionalidade,"africano");
	fabricantes[6].ano = 1961;
	strcpy(fabricantes[7].nome,"ziz");
	strcpy(fabricantes[7].nacionalidade,"polones");
	fabricantes[7].ano = 2019;
}

int ind_valor_min(fabricante *vet, int inicio, int fim){
	int min = inicio, i;
	for(i=inicio+1; i<fim; i++){
		if((strcmp(vet[min].nome, vet[i].nome) > 0) ||
		   (strcmp(vet[min].nome, vet[i].nome) == 0 &&
           strcmp(vet[min].nacionalidade, vet[i].nacionalidade) > 0) ||
           (strcmp(vet[min].nacionalidade, vet[i].nacionalidade) == 0 &&
           vet[min].ano > vet[i].ano))
           {
           min = i;
		   }
	}
	return min;
}

void swap(fabricante *a, fabricante*b){
	fabricante tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void selecaodireta(fabricante *vet, int n){
	int min, i;
	for(i=0; i<n-1; i++){
		min = ind_valor_min(vet, i, n);
		swap(&vet[i], &vet[min]);
	}
}

int main (){
	fabricante fabricantes[8];
	preencher(fabricantes);
	selecaodireta(fabricantes, 8);
	printar(fabricantes, 8);
	return 0;
}