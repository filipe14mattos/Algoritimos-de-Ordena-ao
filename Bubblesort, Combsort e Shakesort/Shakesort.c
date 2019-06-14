//Rever porque nao esta ordenando

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

void shakesort(fabricante *v, int n){
	int bottom, top, swapped, i;
	fabricante aux;
	bottom = 0;
	top = n-1;
	swapped = 0;
	while(swapped ==0 && bottom <top){
		swapped = 1;
		for(i = bottom; i<top; i =i+1){
			if((strcmp(v[i].nome, v[i+1].nome) > 0) || (strcmp(v[i].nome,v[i+1].nome) == 0 && strcmp(v[i].nacionalidade,v[i+1].nacionalidade)>0)
              || (strcmp(v[i].nacionalidade,v[i+1].nacionalidade) == 0 && v[i].ano >v[i+1].ano)){
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				swapped = 0;
			}
		}
		top = top -1;
		for(i=top; i>bottom; i = i-1){
			if((strcmp(v[i-1].nome, v[i].nome) > 0) || (strcmp(v[i-1].nome,v[i].nome) == 0 && strcmp(v[i-1].nacionalidade,v[i].nacionalidade)>0)
              || (strcmp(v[i-1].nacionalidade,v[i].nacionalidade) == 0 && v[i-1].ano >v[i].ano)){
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
				swapped = 0;
			}
		}
		bottom = bottom +1;
	}
}

int main(){
	fabricante fabricantes[8];
	preencher(fabricantes);
	shakesort(fabricantes, 8);
	printar(fabricantes, 8);
	return 0;
}