#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMNAS 15

int main(){
    int cant;
    char arreglo[COLUMNAS];

    printf("Ingrese la cantidad de nombres a cargar: ");
    fflush(stdin);
    scanf("%d",&cant);

    char **V = (char **)malloc(sizeof(char *) * cant);

    printf("Ingrese los Nombres:\n");
    for (int i = 0; i < cant; i++)
    {
        fflush(stdin);
        gets(arreglo);
        V[i] = (char *)malloc(sizeof(char) * (strlen(arreglo)+1));
        strcpy(V[i],arreglo);
    }

    printf("-------Nombres:-------\n");
    for (int i = 0; i < cant; i++)
    {
        printf("%s\n",V[i]);
    }
    
    for (int i = 0; i < cant; i++)
    {
        free(V[i]);
    }
    free(V);
    return 0;
}