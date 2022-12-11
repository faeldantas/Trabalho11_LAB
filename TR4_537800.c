#include "ordvetor.h"
//Cria e aloca memória para uma variável de tipo "VETORORD"
VETORORD* VETORD_create(int n, COMP* compara) {
	VETORORD* vetor = malloc(sizeof(VETORORD));
	vetor->elems = malloc(n * sizeof(void*));
	vetor->N = n;
	vetor->P = 0;
	vetor->comparador = compara;

	return vetor;
}
//param @n determina o tamanho do vetor
//param @compara determina a função de comparação a ser utilizada
//e a função VETORD_create retorna um ponteiro para a struct criada.

//Adiciona um elemento ao vetor
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
//param @vetor determina a struct onde está o vetor a ser manipulado
// e o param @newelem determina o elemento a ser adicionado no vetor

//Remomove o primeiro item do vetor ordenado realocando seus elementos 
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
