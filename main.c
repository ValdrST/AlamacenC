#include <stdio.h>
#include <stdlib.h>
#include "opcion.h"
#include "nodo.h"
#include "listaDoble.h"
#include "ventas.h"
int main()
{
    char opt;
    LISTADOBLE *listaAlmacen, *listaRestock;
    TNODO *p;
    listaAlmacen=crearLista2();
    listaRestock=crearLista2();
    agregarFILE(listaAlmacen,"Almacen.txt");
    agregarFILE(listaRestock,"Restock.txt");
    do
    {
        printf("(a) Listar Almacen (b) Agregar Producto (c) vender Producto (d) mostrar lista de restock (e) Resurtir almacen (f)salir\n ");
        opt=opcion();
        fflush(stdin);
        switch(opt)
        {
        case 'a':
            mostrarlistaAscendente(listaAlmacen);
            break;
        case 'b':
            p=crearNodo2();
            agregar(listaAlmacen, p);
            fflush(stdin);
            break;
        case 'c':
            venderProducto(listaAlmacen,listaRestock);
            fflush(stdin);
            break;
        case 'd':
            mostrarlistaAscendente(listaRestock);
            break;
        case 'e':
            ResurtirProducto(listaRestock,listaAlmacen);
            break;
        case 'f':
            guardarLista(listaAlmacen,"Almacen.txt");
            guardarLista(listaRestock,"Restock.txt");
            printf("\nbye bye\n");
            break;
        }
    }
    while(opt!='f');
    return 0;
}
