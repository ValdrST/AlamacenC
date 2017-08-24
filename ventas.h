#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
void venderProducto(LISTADOBLE *listaAlmacen, LISTADOBLE *listaRestock);
void restockProducto(LISTADOBLE *listaAlmacen, LISTADOBLE *listaRestock, TNODO *producto);
void ResurtirProducto(LISTADOBLE *listaRestock, LISTADOBLE *listaAlmacen);
#endif // VENTAS_H_INCLUDED
