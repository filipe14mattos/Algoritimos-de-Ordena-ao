//quando o numero de elementos de um vetor for maior que 20 chamar o quick sort menor que 20 chamar o insertion ou bublle sort
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int particao (int* vetor, int inicio, int fim){
	int pivo = vetor[inicio], i = inicio+1, f=fim;
	while(i<=f){
		if(vetor[i]<pivo){
			i++;
		}else if(pivo<vetor[f]){
			f--;
		}else{
			swap(&vetor[i], &vetor[f]);
			i++;
			f--;
		}
	}
	vetor[inicio] = vetor[f];
	vetor[f] = pivo;
	return f;
}

void quickSort(int *v, int ini, int fim){
	int meio;
	if((fim-ini)+1 <= 20){
		//chamar o insertion sort aqui
	}
	if(ini<fim){
		meio = particao(v,ini,fim);
		quickSort(v,ini,meio);
		quickSort(v,meio+1,fim);
	}
}

void escreveVetor(int *vet, int n){
	int i;
	for(i=0; i<n; i++){
		printf("vet[%d] vale %d \n", i, vet[i]);
	}
	printf("\n\n");
}

int main (){
	int vet[100] = { 7 , 8 , 3 , 4 , 5 , 6,
                     1 , 2 , 9 , 10 , 11 , 12,
                     19 , 14 , 15 , 16 , 17 , 18,
                     13 , 26 , 21 , 22 , 23 , 24,
                     31 , 20 , 27 , 28 , 29 , 30,
                     25 , 38 , 33 , 34 , 35 , 36,
                     43 , 32 , 39 , 40 , 41 , 42,
                     37 , 50 , 45 , 46 , 47 , 48,
                     55 , 44 , 51 , 52 , 53 , 54,
                     49 , 62 , 57 , 58 , 59 , 60,
                     61 , 56 , 63 , 64 , 65 , 66,
                     67 , 74 , 69 , 70 , 71 , 72,
                     73 , 68 , 75 , 76 , 77 , 78,
                     79 , 86 , 81 , 82 , 83 , 84,
                     85 , 80 , 87 , 88 , 89 , 90,
                     91 , 98 , 93 , 94 , 95 , 96,
                     97 , 92 , 99 , 100 };
	quickSort(vet,0,99);
	escreveVetor(vet,100);
}