#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
typedef struct listaDoble{
    struct producto *ph;
    struct producto *pt;
}LISTADOBLE;

LISTADOBLE *crearLista2();
void recorre2(LISTADOBLE *L);
void recorreInverso(LISTADOBLE *L);
void agregar(LISTADOBLE *L, TNODO *p);
struct producto *buscar(LISTADOBLE *L, char *nombre);
void mostrarlistaAscendente(LISTADOBLE *L);
void mostrarlistaDescendente(LISTADOBLE *L);
TNODO *borrar(LISTADOBLE *L, char *nombre);
void agregarFILE(LISTADOBLE *L, char* archivoTxt);
void guardarLista(LISTADOBLE *L, char* archivoTxt);
#endif // LISTADOBLE_H_INCLUDED
