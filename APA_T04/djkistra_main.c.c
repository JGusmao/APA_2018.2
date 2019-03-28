#include <stdio.h>
#include <limits.h>
#include<stdbool.h>
#define V 9

int distanciaMin(int dist[], bool filaMin[]){
   int min = INT_MAX, indiceMin;

   for (int v = 0; v < V; v++){
     if (filaMin[v] == false && dist[v] <= min)
         min = dist[v], indiceMin = v;
   }
   return indiceMin;
}

void exibe(int dist[], int n){
   printf("Vertice   Distancia ate o inicio\n");
   for (int i = 0; i < V; i++){
      printf("%d ............... %d\n", i, dist[i]);
   }

}

void dijkstra(int grafo[V][V], int src){
     int dist[V];
     bool filaMin[V];
     for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, filaMin[i] = false;
     }

     dist[src] = 0;

     for (int count = 0; count < V-1; count++){

       int u = distanciaMin(dist, filaMin);
       filaMin[u] = true;

       for (int v = 0; v < V; v++){
         if (!filaMin[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u]+grafo[u][v] < dist[v]){
            dist[v] = dist[u] + grafo[u][v];
            }
       }
     }

     exibe(dist, V);
}

int main(){
   int grafo[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(grafo, 0);

    return 0;
}
