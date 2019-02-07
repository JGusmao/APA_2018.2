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
    return lista->nElementos; /* Na~o ha� o que calcular */
}

void ExibeLista(const tLista *lista){
    int i;
    for(i = 0; i < Comprimento(lista); i++){
        printf("#%d: %d \n", i, lista->elementos[i]);
    }
}

int AcrescentaElemento(tLista *lista, int elemento){
    /* Verifica se e� possi�vel acrescentar */
    /* mais um elemento na lista          */
    if (EstaCheia(lista)) {
        return 1; /* A lista esta� cheia */
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
	pivo = lista->elementos[(inicio + fim) / 2]; //Escolho usar o piv� como o elemento central
	while(i <= j)
	{
		while(lista->elementos[i] < pivo && i < fim)
		{
			i++;
		}
		while(lista->elementos[j] > pivo && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
			aux = lista->elementos[i];
			lista->elementos[i] = lista->elementos[j];
			lista->elementos[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quickSort(lista, inicio, j+1);
	if(i < fim)
		quickSort(lista, i, fim);
}

void merge(tLista *lista, int comeco, int meio, int fim) { //essa fun��o vai fundir as metades anteriormente divididas
    int com1 = comeco, com2 = meio+1, comAux = 0; //Cria��o da lista auxiliar para fundir as parti��es
    tLista *listaAux;
    listaAux = malloc(sizeof(tLista));

    while(com1 <= meio && com2 <= fim){ //Ordena��o dos elementos no vetor auxiliar por compara��o
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

void mergeSort(tLista *lista, int comeco, int fim){ //Essa fun��o � respons�vel por dividir recursivamente o conjunto de dados at� que cada subconjunto possua 1 elemento
    if (comeco < fim) {
        int meio = (fim+comeco)/2; //Defini��o dos novos inicio e fim

        mergeSort(lista, comeco, meio); //Parti��o da esquerda
        mergeSort(lista, meio+1, fim); //Parti��o da direita
        merge(lista, comeco, meio, fim); //Funde ordenando
    }
}
