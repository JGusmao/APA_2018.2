#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "APA_T05.h"

void Acrescenta(tItens *itens, int peso, int valor){
    itens->pesos[itens->nElementos] = peso;
    itens->valores[itens->nElementos] = valor;
    ++itens->nElementos;
}

int maximo(int a, int b){
    return (a > b)? a : b;
}

void IniciaItens(tItens *itens){
    itens->nElementos = 0;
}

int knapSack(tItens *itens, int W, int n){
   int i, w;
   int K[n+1][W+1];

   // Constrói a tabela K[][] de baixo para cima
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (itens->pesos[i-1] <= w)
                 K[i][w] = maximo(itens->valores[i-1] + K[i-1][w-itens->pesos[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}
