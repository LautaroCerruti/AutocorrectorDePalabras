En el archivo DS.h se encuentran las declaraciones y en DS.clas funciones correspondientes para cada estructura de datos utilizadas en el programa
las cuales son lista enlazada, array dinamico y tabla hash.

En los archivos Strings.h y Strings.c se encuentran las funciones relacionadas a la creacion de las palabras a buscar en el hash.

Comandos para compilar y ejecutar:

Compilar:	
		gcc -c Strings.c
		gcc -c DS.c
		gcc -o main main.c Strings.o DS.o

Ejecutar:
		main ArchivoDeDiccionario.txt ArchivoDeEntrada.txt ArchivoDeSalida.txt