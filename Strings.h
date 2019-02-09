#ifndef __STRINGS_H__
#define __STRINGS_H__
#include <stddef.h>

/**
*   Funcion que intercambia dos letras de lugar
*/
void intercambiar(mhash tabla,char palabra[],FILE *fp);

/**
*   Funcion que inserta letras entre medio de otras
*/
void insert(mhash tabla,char palabra[],FILE *fp);

/**
*   Funcion que separa una palabra en 2
*/
void separa(mhash tabla,char palabra[],FILE *fp);

/**
*   Funcion que reemplaza las letras por otras
*/
void reemplaza(mhash tabla,char palabra[],FILE *fp);

/**
*   Funcion que elimina letras
*/
void elimina(mhash tabla,char palabra[],FILE *fp);

/**
*   Funcion que analiza las posibles palabras de una erronea utilizando las demas funciones
*/
void analyzer(mhash tabla,char palabra[],FILE *fp);

/**
*   Un to lower que tambien funciona con letras con tildes o dieresis
*/
char ToLower(char c);
#endif
