#include "APA_T01.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void IniciaLista(tLista *lista){
    lista->nElementos = 0;
}

static int EstaCheia(const tLista *lista){
    return lista->nElementos >= MAX_ELEMENTOS;
}

int Comprimento(const tLista *lista){
    return lista->nElementos; /* Não há o que calcular */
}

void ExibeLista(const tLista *lista){
    int i;
    for(i = 0; i < Comprimento(lista); i++){
        printf("#%d: %d \n", i, lista->elementos[i]);
    }
}

int AcrescentaElemento(tLista *lista, int elemento){
    /* Verifica se é possível acrescentar */
    /* mais um elemento na lista          */
    if (EstaCheia(lista)) {
        return 1; /* A lista está cheia */
    }

    /* Acrescenta um novo elemento ao final da lista */
    lista->elementos[lista->nElementos] = elemento;
    ++lista->nElementos; /* O tamanho da lista aumentou */

    return 0;
}

void selection_sort(tLista *lista, int tam) {
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)//Percorre todo o array
  {
     min = i; //Assumo que o primeiro elemento é o menor e já está na posição correta
     for (j = (i+1); j < tam; j++) {
       if(lista->elementos[j] < lista->elementos[min]) //Se o proximo elemento é menor, então é o novo min
         min = j; //Guarda o índice do novo min
     }
     if (lista->elementos[i] != lista->elementos[min]) { //Swap
       aux = lista->elementos[i];
       lista->elementos[i] = lista->elementos[min];
       lista->elementos[min] = aux;
     }
  }
}

void insertion_sort(tLista *lista, int tam) {

int escolhido, j;

    for (int i = 1; i < tam; i++) {//Percorre toda a lista
		escolhido = lista->elementos[i];//O elemento escolhido como pivô é o segundo da lista
		j = i - 1;//Posição imediatamente anterior ao elemento atual

		while ((j >= 0) && (lista->elementos[j] > escolhido)) { //Verifica se o anterior é maior que o escolhido
			lista->elementos[j + 1]= lista->elementos[j];//Atual recebe anterior se anterior for maior
			j--;//Volta ao elemento anterior
		}

		lista->elementos[j + 1]= escolhido;
	}
}
