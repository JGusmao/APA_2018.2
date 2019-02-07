#include "APA_T02.h"
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
    return lista->nElementos; /* Na~o ha´ o que calcular */
}

void ExibeLista(const tLista *lista){
    int i;
    for(i = 0; i < Comprimento(lista); i++){
        printf("#%d: %d \n", i, lista->elementos[i]);
    }
}

int AcrescentaElemento(tLista *lista, int elemento){
    /* Verifica se e´ possi´vel acrescentar */
    /* mais um elemento na lista          */
    if (EstaCheia(lista)) {
        return 1; /* A lista esta´ cheia */
    }

    /* Acrescenta um novo elemento ao final da lista */
    lista->elementos[lista->nElementos] = elemento;
    ++lista->nElementos; /* O tamanho da lista aumentou */

    return 0;
}

void quickSort(tLista *lista, int inicio, int fim){
	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = lista->elementos[(inicio + fim) / 2]; //Escolho usar o pivô como o elemento central
	while(i <= j)
	{
		while(lista->elementos[i] < pivo && i < fim) //percorre a lista atá achar um elemento menor que o pivô
		{
			i++;
		}
		while(lista->elementos[j] > pivo && j > inicio) // procura os elementos maiores que o pivô
		{
			j--;
		}
		if(i <= j) //troca os elementos achados
		{
			aux = lista->elementos[i];
			lista->elementos[i] = lista->elementos[j];
			lista->elementos[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio) //quebra a lista para realizar o quicksort recursivamente
		quickSort(lista, inicio, j+1);
	if(i < fim)
		quickSort(lista, i, fim);
}

void merge(tLista *lista, int comeco, int meio, int fim) { //essa função vai fundir as metades anteriormente divididas
    int com1 = comeco, com2 = meio+1, comAux = 0; //Criação da lista auxiliar para fundir as partições
    tLista *listaAux;
    listaAux = malloc(sizeof(tLista));

    while(com1 <= meio && com2 <= fim){ //Ordenação dos elementos no vetor auxiliar por comparação
        if(lista->elementos[com1] < lista->elementos[com2]) {
            listaAux->elementos[comAux] = lista->elementos[com1];
            com1++;
        } else {
            listaAux->elementos[comAux] = lista->elementos[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        listaAux->elementos[comAux] = lista->elementos[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        listaAux->elementos[comAux] = lista->elementos[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        lista->elementos[comAux] = listaAux->elementos[comAux-comeco];
    }

    free(listaAux);
}

void mergeSort(tLista *lista, int comeco, int fim){ //Essa função é responsável por dividir recursivamente o conjunto de dados até que cada subconjunto possua 1 elemento
    if (comeco < fim) {
        int meio = (fim+comeco)/2; //Definição dos novos inicio e fim

        mergeSort(lista, comeco, meio); //Partição da esquerda
        mergeSort(lista, meio+1, fim); //Partição da direita
        merge(lista, comeco, meio, fim); //Funde ordenando
    }
}
