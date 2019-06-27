//quando o numero de elementos de um vetor for maior que 20 chamar o quick sort menor que 20 chamar o insertion ou bublle sort
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

int particao (fabricante* v, int inicio, int fim){
	struct fabricante pivo = v[inicio]; 
	int i = inicio+1, f=fim;
	while(i<=f){
		if((strcmp(v[i].nome, pivo.nome) < 0) || (strcmp(v[i].nome,pivo.nome) == 0 && strcmp(v[i].nacionalidade,pivo.nacionalidade)<0)
              || (strcmp(v[i].nacionalidade,pivo.nacionalidade) == 0 && v[i].ano <pivo.ano)){
			i++;
		}else if((strcmp(pivo.nome, v[f].nome) < 0) || (strcmp(pivo.nome,v[f].nome) == 0 && strcmp(pivo.nacionalidade,v[f].nacionalidade)<0)
              || (strcmp(pivo.nacionalidade,v[f].nacionalidade) == 0 && pivo.ano < v[f].ano)){
			f--;
		}else{
			swap(&v[i], &v[f]);
			i++;
			f--;
		}
	}
	v[inicio] = v[f];
	v[f] = pivo;
	return f;
}

void quickSort(fabricante *v, int ini, int fim){
	int meio;
	if(ini<fim){
		meio = particao(v,ini,fim);
		quickSort(v,ini,meio);
		quickSort(v,meio+1,fim);
	}
}

int main (){
	fabricante fabricantes[8];
	preencher(fabricantes);
	quickSort(fabricantes,0,7);
	printar(fabricantes, 8);
	return 0;
}