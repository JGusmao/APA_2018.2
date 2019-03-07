/* Este programa vai ler um conjunto desorganizado de n�meros inteiros de um arquivo, que ser�o ordenados
 * pelas fun��es COUNTING e HEAP, e posteriormente exibi-los na ordem correta na tela.
 */

#include "APA_T03.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    tLista mLista;
    int c;

    FILE *mFile;
    mFile = fopen("Inst_100.txt", "r");

    if(mFile == NULL){
        printf("Nao foi possivel ler o arquivo\n");
        system("pause");
        exit(0);
    }

    while (!feof(mFile)){ //Checa o fim do arquivo
		fscanf(mFile, "%d", &c);
		AcrescentaElemento(&mLista, c);
    }

    //heapSort(&mLista, Comprimento(&mLista));
    countingSort(&mLista, Comprimento(&mLista));


    ExibeLista(&mLista);

    fclose(mFile);
    printf("\n");

    //system("pause");
    return 0;
}

