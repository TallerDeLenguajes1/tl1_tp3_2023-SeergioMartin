#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 5
#define COLUMNAS 10

int main(){
    char *V[5];

    printf("Ingrese 5 Nombres:\n");
    for (int i = 0; i < FILAS; i++)
    {
        V[i] = (char *)malloc(sizeof(char) * COLUMNAS);
        gets(V[i]);
    }

    printf("-------Nombres:-------\n");
    for (int i = 0; i < FILAS; i++)
    {
        printf("%s\n",V[i]);
    }
    
    for (int i = 0; i < FILAS; i++)
    {
        free(V[i]);
    }
    return 0;
}