#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz[5][12];
    int promedio[5];
    int maximo=0, minimo=50000, anioMayor, mesMayor, anioMenor, mesMenor;
    srand(time(NULL));
    
    for (int i = 0; i < 5; i++)
    {
        promedio[i] = 0; 
        printf("|");
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = 10000 + rand() % (50001-10000);
            printf("%d|", matriz[i][j]);
            promedio[i] += matriz[i][j];
            if (maximo < matriz[i][j])
            {
                maximo = matriz[i][j];
                anioMayor = i;
                mesMayor = j;
            }
            if (minimo > matriz[i][j])
            {
                minimo = matriz[i][j];
                anioMenor = i;
                mesMenor = j;
            }
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Promedio de Ganancias por Anio 202%d: %d\n",i+4,(promedio[i]/12));
    }

    printf("\nMaximo: %d, Obtenido en el Anio: 202%d y Mes: %d\n",maximo,anioMayor+4,mesMayor+1);
    printf("Minimo: %d, Obtenido en el Anio: 202%d y Mes: %d\n",minimo,anioMenor+4,mesMenor+1);
    
    return 0;
}