#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 0;
#define V 1;

typedef struct fabricante{
	char nome[50];
	char nacionalidade[20];
	int ano;
}fabricante;

int max (int a, int*b){
	if(a>b){
		return a;
	}else{
		return b;
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

void combsort(fabricante *v, int n){
	int h = n, troca,i;
	fabricante aux;
	do{
		h = max((int) (h/1.3), 1);
		if((h==0) || (h==10)){
			h==11;
		}
		troca = F;
		for(i = 0; i<n-h; i++){
			if ((strcmp(v[i].nome, v[i+h].nome) > 0) || (strcmp(v[i].nome,v[i+h].nome) == 0 && strcmp(v[i].nacionalidade,v[i+h].nacionalidade)>0)
              || (strcmp(v[i].nacionalidade,v[i+h].nacionalidade) == 0 && v[i].ano >v[i+h].ano)){
				aux = v[i];
				v[i] = v[i+h];
				v[i+h] = aux;
				troca = V;
			  }
		}
	}while (troca || (h!=1));
}

int main(){
	fabricante fabricantes[8];
	preencher(fabricantes);
	combsort(fabricantes, 8);
	printar(fabricantes, 8);
	return 0;
}