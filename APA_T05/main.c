#include <stdio.h>
#include <stdlib.h>
#include "APA_T05.h"

int main(){
    tItens mItens;
    IniciaItens(&mItens);

    int p,v;/* Peso e valores de cada um dos elementos */
    int n, M;/* Número de elementos disponíveis, Capacidade da mochila */

    FILE *mFile;
    mFile = fopen("mochila01.txt.txt", "r");

    if(mFile == NULL){
        printf("Nao foi possivel ler o arquivo\n");
        system("pause");
        exit(0);
    }

    fscanf(mFile, "%d %d",&n,&M);

    while (!feof(mFile)){ //Checa o fim do arquivo
		fscanf(mFile, "%d %d", &p, &v);
		Acrescenta(&mItens, p, v);
    }
    fclose(mFile);

    printf("Lucro Max: %d\n", knapSack(&mItens, M, n));

    return 0;
}
