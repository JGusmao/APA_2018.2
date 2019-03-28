// Algoritmo de  Prim para MST
#include <stdio.h>
#include <limits.h>
#include<stdbool.h>
// Vertices no grafo
#define V 5

int chaveMin(int key[], bool iniciaMst[]){

    int min = INT_MAX, indiceMin;

    for (int v = 0; v < V; v++){
        if (iniciaMst[v] == false && key[v] < min)
            min = key[v], indiceMin = v;
    }

    return indiceMin;
}

int exibeMst(int pai[], int n, int grafo[V][V]){
    printf("Aresta \tPeso\n");
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", pai[i], i, grafo[i][pai[i]]);
    }

    return 0;
}

void primMST(int grafo[V][V]){
    int pai[V];

    int key[V];

    bool Mst[V];

    // inicializa todas como infinito
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, Mst[i] = false;

    key[0] = 0;
    pai[0] = -1;

    for (int count = 0; count < V-1; count++){
        int u = chaveMin(key, Mst);

        Mst[u] = true;

        for (int v = 0; v < V; v++){
            if (grafo[u][v] && Mst[v] == false && grafo[u][v] < key[v]){
                pai[v] = u, key[v] = grafo[u][v];
            }
        }
    }

    exibeMst(pai, V, grafo);
}

int main(){
    int grafo[V][V] = {{0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0}};


        primMST(grafo);

        return 0;
}
