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

void swap(fabricante *a, fabricante*b){
	fabricante tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int left(int r){
	return 2 * r + 1;
}

int right(int r){
	return 2 * r + 2;
}

void heapify(fabricante *vet, int n, int indice){
	int esquerda = left(indice);
	int direita = right(indice);
	int max;
	if(esquerda>n-1)
		return;
	else if(direita>n-1)
		max = esquerda;
	else{
		if(strcmp(vet[esquerda].nome, vet[direita].nome) > 0 ||
		   (strcmp(vet[esquerda].nome, vet[direita].nome) == 0 &&
            strcmp(vet[esquerda].nacionalidade, vet[direita].nacionalidade) > 0) ||
           (strcmp(vet[esquerda].nacionalidade, vet[direita].nacionalidade) == 0 &&
            vet[esquerda].ano > vet[direita].ano)){
            max = esquerda;
			}
		else
			max = direita;
	}
	if((strcmp(vet[max].nome, vet[indice].nome) > 0) ||
       (strcmp(vet[max].nome, vet[indice].nome) == 0 &&
        strcmp(vet[max].nacionalidade, vet[indice].nacionalidade) > 0) ||
       (strcmp(vet[max].nacionalidade, vet[indice].nacionalidade) == 0 &&
        vet[max].ano > vet[indice].ano)){
			swap(&vet[max], &vet[indice]);
			heapify(vet, n, max);
		}
}

void construirHeap(fabricante *vet, int n){
	int i;
	for(i=n/2 - 1; i>=0; i--){
		heapify(vet, n, i);
	}
}	 

void heapSort(fabricante *vet, int n){
	construirHeap(vet, n);
	int i;
	for(i=n-1; i>0; i--){
		swap(&vet[i], &vet[0]);
		heapify(vet, i, 0);
	}
}

int main (){
	fabricante fabricantes[8];
	preencher(fabricantes);
	heapSort(fabricantes, 8);
	printar(fabricantes, 8);
	return 0;
}