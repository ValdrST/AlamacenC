#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "listaDoble.h"
#include <string.h>
TNODO* crearNodo2()
{
    TNODO *q;
    q=(TNODO*)calloc(1,sizeof(TNODO));
    q->ant=NULL;
    q->sig=NULL;
    printf("\nNombre: ");
    gets(q->nombre);
    strcat(q->nombre,"\n");
    fflush(stdin);
    printf("\nprecio: ");
    scanf("%f",&q->precio);
    printf("\nExistencias: ");
    scanf("%d",&q->existencias);
    return q;
}

void imprimirNodo(TNODO *q)
{
    printf("\nnombre: %s",q->nombre);
    printf("Precio: %.2f\n",q->precio);
    printf("existencias: %2d\n",q->existencias);
}

TNODO* crearNodoFile(FILE **arch, char *archivoTxt)
{
    TNODO *q;
    q=(TNODO*)calloc(1,sizeof(TNODO));
    if(fgets(q->nombre,50,*arch))
    {
        fflush(stdin);
        fscanf(*arch,"%f",&q->precio);
        fscanf(*arch,"%d\n",&q->existencias);
        q->ant=NULL;
        q->sig=NULL;
    }
    else
    {
        return NULL;
    }
    return q;
}

void guardarNodo(FILE **arch, TNODO *q)
{
    fputs(q->nombre,*arch);
    fprintf(*arch,"%f\n",q->precio);
    fprintf(*arch,"%d\n",q->existencias);
}
