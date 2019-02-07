#ifndef APA_T02_H_INCLUDED
#define APA_T02_H_INCLUDED

#define MAX_ELEMENTOS 10000

typedef struct {
        int   nElementos; /* Nu´mero de elementos */
        int   elementos[MAX_ELEMENTOS]; /* Os elementos */
} tLista;

extern void IniciaLista(tLista *lista);
extern int Comprimento(const tLista *lista);
extern void ExibeLista(const tLista *lista);
extern int AcrescentaElemento(tLista *lista, int elemento);
extern void mergeSort(tLista *lista, int comeco, int fim);
extern void merge(tLista *lista, int comeco, int meio, int fim);
extern void quickSort(tLista *lista, int inicio, int fim);

#endif // APA_T02_H_INCLUDED
