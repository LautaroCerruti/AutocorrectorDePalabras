#ifndef __DS_H__
#define __DS_H__
#include <stddef.h>

/**
* Estructura Array Dinamico
*/
typedef struct charray {
    char **arr;
    int cantel;
} Darray;

/**
* Estructura Lista Enlazada
*/
typedef struct _SNodo {
  char *dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
* Estructura hash
*/
typedef struct mhash{
    SList palabras[503][17];
    int primo,primo2;
}mhash;

/**
* Devuelve una lista Vacia
*/
SList slist_crear();

/**
* Devuelve 1  o si la lista esta vacia o no
*/
int slist_vacia(SList lista);

/**
* Agrega un elemento al comienzo de una lista
*/
SList slist_agregar_inicio(SList lista, char dato[]);

/**
* Busca un elemento en una lista y devueve 1 en caso de encontrarlo
*/
int slist_contiene(SList lista, char elem[]);

/**
* Devuelve una tabla hash vacia
*/
mhash creatab();

/**
* Agrega un elemento a la tabla Hash
*/
mhash agregarATablaHash(mhash tabla, char *dato);

/**
* Busca un elemento en la tabla Hash
*/
int BuscarEnHash(mhash tabla,char *palab);

/**
* Crea un array dinamico vacio
*/
Darray crear();

/**
* Agrega un elemento a un array dinamico
*/
Darray agregar(Darray marray,char palabra[]);

#endif
