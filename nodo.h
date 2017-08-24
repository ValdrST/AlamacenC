#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
typedef struct producto{
    char nombre[50];
    float precio;
    int existencias;
    struct producto *sig;
    struct producto *ant;
}TNODO;

TNODO* crearNodo2();
void imprimirNodo(TNODO *q);
TNODO* crearNodoFile(FILE **arch, char *archivoTxt);
void guardarNodo(FILE **arch, TNODO *q);
#endif // NODO_H_INCLUDED
