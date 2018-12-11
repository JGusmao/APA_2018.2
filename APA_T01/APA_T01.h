#ifndef APA_T01_H_INCLUDED
#define APA_T01_H_INCLUDED

#define MAX_ELEMENTOS 10000

typedef struct {
        int   nElementos; /* Número de elementos */
        int   elementos[MAX_ELEMENTOS]; /* Os elementos */
} tLista;

extern void IniciaLista(tLista *lista);
extern int Comprimento(const tLista *lista);
extern void ExibeLista(const tLista *lista);
extern int AcrescentaElemento(tLista *lista, int elemento);
extern void selection_sort(tLista *lista, int tam);
extern void insertion_sort(tLista *lista, int tam);

#endif // APA_T01_H_INCLUDED
