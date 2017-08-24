#include <stdio.h>
#include "nodo.h"
#include "listaDoble.h"
void restockProducto(LISTADOBLE *listaAlmacen, LISTADOBLE *listaRestock, TNODO *producto)
{
    producto=borrar(listaAlmacen,producto->nombre);
    printf("Cuantos productos desea agregar? \n");
    scanf("%d",&producto->existencias);
    agregar(listaRestock,producto);
}

void venderProducto(LISTADOBLE *listaAlmacen, LISTADOBLE *listaRestock)
{
    TNODO *q;
    char nombre[50];
    int cantidadProductos;
    printf("\n nombre de producto a vender: ");
    gets(nombre);
    fflush(stdin);
    q=buscar(listaAlmacen, nombre);
    if(q!=NULL)
    {
        printf("\nCantidad de productos a comprar: ");
        scanf("%d",&cantidadProductos);
        if(cantidadProductos>=q->existencias)
        {
            cantidadProductos=q->existencias;
            q->existencias=(q->existencias-cantidadProductos);
        }
        else
            q->existencias=q->existencias-cantidadProductos;
        if(q->existencias==0)
        {
            restockProducto(listaAlmacen,listaRestock,q);
        }
    }
    else
        return;
}
void ResurtirProducto(LISTADOBLE *listaRestock, LISTADOBLE *listaAlmacen)
{
    TNODO *q;
    char nombre[50];
    printf("\n nombre del producto a resurtir: ");
    gets(nombre);
    fflush(stdin);
    q=buscar(listaRestock,nombre);
    if(q!=NULL)
    {
        q=borrar(listaRestock,q->nombre);
        agregar(listaAlmacen,q);
    }
    else
        return;
}
