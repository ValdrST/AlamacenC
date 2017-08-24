#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"
#include "listaDoble.h"

LISTADOBLE *crearLista2()
{
    LISTADOBLE *p;
    p=(LISTADOBLE*)malloc(sizeof(LISTADOBLE));
    p->ph=NULL;
    p->pt=NULL;
    return p;
}

void recorre2(LISTADOBLE *L)
{
    TNODO *q;
    q=L->ph;
    while(q!=NULL)
    {
        imprimirNodo(q);
        q=q->sig;
    }
}

void recorreInverso(LISTADOBLE *L)
{
    TNODO *q;
    q=L->pt;
    while(q!=NULL)
    {
        imprimirNodo(q);
        q=q->ant;
    }
}

void agregar(LISTADOBLE *L, TNODO *p)
{
    TNODO *q;
    if(L->ph==NULL&&L->pt==NULL)
    {
        L->pt=p;
        L->ph=p;
        return;
    }
    if(strcmp(L->ph->nombre,p->nombre)>0)
    {
        p->sig=L->ph;
        L->ph->ant=p;
        L->ph=p;
        return;
    }
    if(strcmp(L->pt->nombre,p->nombre)<0)
    {
        p->ant=L->pt;
        L->pt->sig=p;
        L->pt=p;
        return;
    }
    if(strcmp(L->pt->nombre,p->nombre)==0){
        if(L->pt->precio>p->precio)
        {
            p->sig=L->ph;
            L->ph->ant=p;
            L->ph=p;
            return;
        }
        else
        {
            p->ant=L->pt;
            L->pt->sig=p;
            L->pt=p;
            return;
        }
    }
    q=L->ph;
    while(strcmp(q->nombre,p->nombre)<0)
        q=q->sig;
    p->sig=q;
    p->ant=q->ant;
    p->ant->sig=p;
    q->ant=p;
}

struct producto* buscar(LISTADOBLE *L, char *nombre)
{
    TNODO *p;
    strcat(nombre,"\n");
    p=L->ph;
    if(L->ph==NULL)
    {
        printf("Lista Vacia\n");
        return NULL;
    }
    while(p!=NULL)
    {
        if(strcmp(p->nombre,nombre)==0)
        {
            imprimirNodo(p);
            return p;
        }
        p=p->sig;
    }
    printf("producto no encontrado\n");
    return NULL;
}

void mostrarlistaAscendente(LISTADOBLE *L)
{
    TNODO *q;
    q=L->ph;
    if(q!=NULL)
    {
        while(q!=NULL)
        {
            imprimirNodo(q);
            q=q->sig;
        }
    }
    else
        printf("lista Vacia\n");
}

void mostrarlistaDescendente(LISTADOBLE *L)
{
    TNODO *q;
    q=L->pt;
    if(q!=NULL)
    {
        while(q!=NULL)
        {
            imprimirNodo(q);
            q=q->ant;
        }
    }
    else
        printf("lista Vacia\n");
}

TNODO *borrar(LISTADOBLE *L, char *nombre)
{
    TNODO *p, *auxSig, *auxAnt;
    p=L->ph;
    while(p!=NULL)
    {
        if(strcmp(p->nombre,nombre)==0)
        {
            if(p->sig!=NULL && p->ant!=NULL)
            {
                auxSig=p->sig;
                auxAnt=p->ant;
                auxSig->ant=auxAnt;
                auxAnt->sig=auxSig;
            }
            else if(p->sig==NULL && p->ant!=NULL)
            {
                auxAnt=p->ant;
                auxAnt->sig=NULL;
                L->pt=auxAnt;
                p->ant=NULL;
            }
            else if(p->ant==NULL && p->sig!=NULL)
            {
                auxSig=p->sig;
                auxSig->ant=NULL;
                L->ph=auxSig;
                p->sig=NULL;
            }
            else if(p->ant==NULL && p->sig==NULL)
            {
                L->ph=NULL;
                L->pt=NULL;
                return p;
            }
            p->sig=NULL;
            p->ant=NULL;
            return p;
        }
        p=p->sig;
    }
    return NULL;
}

void agregarFILE(LISTADOBLE *L, char* archivoTxt)
{
    FILE *arch;
    arch=fopen(archivoTxt,"r");
    while(!feof(arch))
        agregar(L,crearNodoFile(&arch,archivoTxt));
    fclose(arch);
}

void guardarLista(LISTADOBLE *L, char* archivoTxt){
    FILE *arch;
    TNODO *q;
    q=L->ph;
    arch=fopen(archivoTxt,"w");
    while(q!=NULL){
        guardarNodo(&arch,q);
        q=q->sig;
    }
    fclose(arch);
}
