#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD* VETORD_create(int n, COMP* compara) {
	VETORORD* vetor = malloc(sizeof(VETORORD));
	vetor->elems = malloc(n * sizeof(void*));
	vetor->N = n;
	vetor->P = 0;
	vetor->comparador = compara;

	return vetor;
}

void VETORD_add(VETORORD* vetor, void* newelem) {
	if (vetor->P < vetor->N) {
		int i, pos = vetor->P;

		for (i = 0; i < vetor->P; i++) {
			if (vetor->comparador(vetor->elems[i], newelem) < 0) {
				pos = i;
				break;
			}
		}

		for (i = vetor->P; i > pos; i--) {
			vetor->elems[i] = vetor->elems[i - 1];
		}

		vetor->elems[pos] = newelem;
		vetor->P++;
	}	
}

void* VETORD_remove(VETORORD* vetor) {
	if (vetor->P > 0) {
		void* min = vetor->elems[0];

		for (int i = 0; i < vetor->P - 1; i++) {
			vetor->elems[i] = vetor->elems[i + 1];
		}
	
		vetor->P--;
		return min;
	}
}

//Função de comparação
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx < pty){
		return -1;
	}else{
		if(ptx > pty) return 1;
		else return 0;
	}
}

//Print para a estrutura
void print(void** vet, int P){
	int i;
	printf("VETOR DE %d TAMANHO:\n", P);
	for(i = 0; i < 10; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vet = VETORD_create(10, myCOMP);
   	
   	int* x;
   	int i;
   	
   	printf("INCLUINDO... \n");
	for(i = 0; i < 10; i++){
		x = malloc(sizeof(int));
		*x = i*10;
		VETORD_add(vet, x);
	}
	
	print(vet->elems, vet->P);
  
  	printf("REMOVENDO!");
  	VETORD_remove(vet);
  	
	print(vet->elems, vet->P);
   
	return 0;  
}