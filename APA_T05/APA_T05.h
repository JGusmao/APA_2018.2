#ifndef APA_T05_H_INCLUDED
#define APA_T05_H_INCLUDED
#define MAX_ELEMENTOS 50001

typedef struct {
        int   nElementos;
        int   pesos[MAX_ELEMENTOS]; /* Peso dos elementos */
        int   valores[MAX_ELEMENTOS]; /* Valores dos elementos */
} tItens;


extern void IniciaItens(tItens *itens);
extern void Acrescenta(tItens *itens, int peso, int valor);
extern int maximo(int a, int b);
extern int knapSack(tItens *itens, int W, int n);


#endif
