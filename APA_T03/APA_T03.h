#ifndef APA_T03_H_INCLUDED
#define APA_T03_H_INCLUDED

#define MAX_ELEMENTOS 10000

typedef struct {
        int   nElementos; /* Nu´mero de elementos */
        int   elementos[MAX_ELEMENTOS]; /* Os elementos */
} tLista;

extern void IniciaLista(tLista *lista);
extern int Comprimento(const tLista *lista);
extern void ExibeLista(const tLista *lista);
extern int AcrescentaElemento(tLista *lista, int elemento);
extern void heapSort(tLista *lista, int n);
extern void swap(int *i, int *j);
extern void countingSort(tLista *lista, int tam);

#endif // APA_T03_H_INCLUDED
