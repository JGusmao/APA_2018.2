#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "APA_T03.h"

void swap (int *i, int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

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

// heapify uma sub-árvore cuja raiz é o nó i como
// index na lista[]. n é o tam da heap
void heapify(tLista *lista, int n, int i){
    int maior = i; // inicializa o maior como raíz
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // se o filho da esquerda é maior que a raíz
    if (l < n && lista->elementos[l] > lista->elementos[maior])
        maior = l;

    // se o filho da direito é maior que o maior até agora
    if (r < n && lista->elementos[r] > lista->elementos[maior])
        maior = r;

    // se o maior não é a raíz
    if (maior != i)
    {
        swap(&lista->elementos[i], &lista->elementos[maior]);
        // Chamar recursivamente na sub-árvore
        heapify(lista, n, maior);
    }
}

void heapSort(tLista *lista, int n){
    // faz a heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(lista, n, i);

    // Vai retirando os elementos um por um da heap, desassociando os filhos
    for (int i=n-1; i>=0; i--)
    {
        // move a raíz atual para o fim
         swap(&lista->elementos[0], &lista->elementos[i]);

        // chama max heapify na heap reduzida
        heapify(lista, i, 0);
    }
}

int maximum(tLista *lista, int tam){

  int atual = 0;
  int max = 0;

  for(atual = 0; atual < tam; atual++){
    if(lista->elementos[atual] > max){ max = lista->elementos[atual]; }
  }

  return max;
}

void countingSort(tLista *lista, int tam){

  int atual = 0;
  int max = maximum(lista, tam);
  int * counting = calloc(max, sizeof(int)); // Zeros out the array

  for(atual = 0; atual < tam; atual ++){
    counting[lista->elementos[atual]]++;
  }

  int num = 0;
  atual = 0;

  while(atual <= tam){
    while(counting[num] > 0){
      lista->elementos[atual] = num;
      counting[num]--;
      atual++;
      if(atual > tam){ break; }
    }
    num++;
  }
}
