#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "DS.h"
SList slist_crear() {
  return NULL;
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_inicio(SList lista, char dato[]) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato=malloc(sizeof(char)*(strlen(dato)+2));
  strcpy(nuevoNodo->dato,dato);
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

int slist_contiene(SList lista, char elem[]){
    for(;lista!=NULL;lista=lista->sig){
        if(strcmp(lista->dato,elem)==0){return 1;}
    }
    return 0;
}

mhash creatab(){
    int i=0,k=0;
    mhash aux;
    aux.primo=503;
    aux.primo2=17;
    for(;i<aux.primo;++i){
            for(k=0;k<aux.primo2;++k){
                aux.palabras[i][k]=NULL;
            }
    }
    return aux;
}

mhash agregarATablaHash(mhash tabla, char *dato){
    int i=0,modulo1=0,modulo2=0;
    int k=tabla.primo;
    unsigned long long int n=0;
    for(i=0;dato[i];++i){
        n+=dato[i]*pow(2,i);
    }
    modulo1=n%k;
    modulo2=n%tabla.primo2;
    tabla.palabras[modulo1][modulo2] = slist_agregar_inicio(tabla.palabras[modulo1][modulo2],dato);
    return tabla;
}

int BuscarEnHash(mhash tabla,char *palab){
    int i=0;
    int k=tabla.primo;
    unsigned long long int n=0;
    for(i=0;palab[i];++i){
        n+=palab[i]*pow(2,i);
    }
    return (slist_contiene(tabla.palabras[n%k][n%tabla.primo2],palab));
}

Darray crear() {
    Darray marray;
    marray.arr=malloc(sizeof(char*));
    marray.cantel=0;
    return marray;
}

Darray agregar(Darray marray,char palabra[]) {
    marray.cantel++;
    marray.arr=realloc(marray.arr,sizeof(char*)*(marray.cantel));
    (marray.arr[marray.cantel-1])=malloc(sizeof(char)*(strlen(palabra)+2));
    strcpy(marray.arr[marray.cantel-1],palabra);
    return marray;
}
