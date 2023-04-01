#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int productoID;                 //Numerado en ciclo iterativo
    int cantidad;                   // entre 1 y 10
    char *tipoProducto;             // Algún valor del arreglo TiposProductos
    float precioUnitario;           // entre 10 - 100
} typedef Producto;
struct Cliente {
    int clienteID;                  // Numerado en el ciclo iterativo
    char *nombreCliente;            // Ingresado por usuario
    int cantidadProductosAPedir;    // (aleatorio entre 1 y 5)
    Producto *productos;            //El tamaño de este arreglo depende de la variable
} typedef Cliente;                  // ""CantidadProductosAPedir"

void Cargar(Cliente *p, int cant);
void Mostrar(Cliente *p, int cant);
float Costo(Producto producto);

int main(){
    int cant=0;

    printf("Ingrese cantidad de Clientes: ");
    scanf("%d", &cant);

    Cliente *pclientes = (Cliente *)malloc(sizeof(Cliente) * cant);

    srand(time(NULL));

    Cargar(pclientes, cant);
    Mostrar(pclientes, cant);

    free(pclientes);
    return 0;
}

void Cargar(Cliente *p, int x){
    printf("\n\n------------CARGAR CLIENTES:------------\n");
    for (int i = 0; i < x; i++)
    {   
        p[i].clienteID = (i + 1);
        char *nombre = (char *)malloc(sizeof(char) * 12);
        printf("Ingrese Nombre: \n");
        scanf("%s", nombre);
        p[i].nombreCliente = nombre;
        p[i].cantidadProductosAPedir = 1 + rand() % (6-1);
        Producto *productos = (Producto *)malloc(sizeof(Producto) * (p[i].cantidadProductosAPedir));
        for (int j = 0; j < p[i].cantidadProductosAPedir; j++)
        {
            productos[j].productoID = (j + 1);
            productos[j].cantidad = 1 + rand() % (11-1);
            productos[j].tipoProducto = TiposProductos[rand() % 5];
            productos[j].precioUnitario = 10 + rand() % (101-10) / 1.0;
        }
        p[i].productos = productos;
        free(nombre);
    }
    printf("\n----------------------------------------\n");
}

void Mostrar(Cliente *p, int x){
    float costo=0, total=0;
    printf("\n***********LISTADO CLIENTES:***********\n");
    for (int i = 0; i < x; i++)
    {
        printf("---Id[%d]---\n", p[i].clienteID);
        printf("Nombre: %s\n", p[i].nombreCliente);
        printf("Cantidad de Productos: %d\n", p[i].cantidadProductosAPedir);
        printf("[Productos:]\n");
        for (int j = 0; j < p[i].cantidadProductosAPedir; j++)
        {
            printf("** Producto[%d]\n", p[i].productos[j].productoID);
            printf("***** Cantidad: %d\n", p[i].productos[j].cantidad);
            printf("***** Tipo Producto: %s\n", p[i].productos[j].tipoProducto);
            printf("***** Precio Unitario: $%.2f\n", p[i].productos[j].precioUnitario);
            costo = Costo(p[i].productos[j]);
            printf("******* Costo Producto: $%.2f\n", costo);
            total += costo;
        }
        printf("******* Costo Total a Pagar: $%.2f\n", total);
        printf("\n***************************************\n");
    }
    printf("\n***************************************\n");
    free(p->productos);
}

float Costo(Producto producto){
    float aux;
    aux = producto.precioUnitario * producto.cantidad;
    return aux;
}
