#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct fabricante{
	char nome[50];
	char nacionalidade[20];
	int ano;
}fabricante;

void insertionsort(fabricante *vet, int n, int h, int f){
	fabricante aux;
	int i, j;
	for(i=f+h; i<n; i = i+h){
		aux = vet[i];
		j = i-h;
		while( (j>=f) && (strcmp(vet[j].nome, aux.nome) > 0)
        || (strcmp(vet[j].nome, aux.nome) == 0 && strcmp(vet[j].nacionalidade, 
        aux.nacionalidade) > 0)|| (strcmp(vet[j].nacionalidade,
		aux.nacionalidade) == 0 && vet[j].ano > aux.ano)){
        	vet[j+h] = vet[j];
        	j = j-h;
		}
		vet[j+h] = aux;
	}
}

void shellSort(fabricante *vet, int n, int np){
	int j, p, h;
	for(p = np; p>0; p--){
		h = (int) pow(2, (int) p-1);
		for(j=0; j<h; j++)
			insertionsort(vet, n, h, j);
}
}

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

int main(){
	fabricante fabricantes[8];
	preencher(fabricantes);
	shellSort(fabricantes, 8, 2);
	printar(fabricantes, 8);
	return 0;
}