#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "DS.h"
#include "Strings.h"

// Autocorrector by Bachur, Cerruti y Garavano

int main(int cant,char *arch[]) {
    FILE *fp=NULL;
    int iteradorletras=0,iterpalab=0,iteradorarch=0,largodepalabra=0;
    Darray parr=crear();
    mhash tabla=creatab();
    char pal[255],c,buff[255];
    fp = fopen(arch[cant-2],"r");
    while((c=getc(fp))!=EOF) {
        if(c!=',' && c!='.' && c!='?' && c!='!' && c!='¿' && c!='¡'){
        if(c==' ') {
            pal[iteradorletras]='\0';
            parr=agregar(parr,pal);
            iteradorletras=0;
        } else {
            pal[iteradorletras]=ToLower(c);
            iteradorletras++;
        }
    }
    }
    pal[iteradorletras]='\0';
    parr=agregar(parr,pal);

    fclose(fp);
    fp = fopen(arch[cant-3],"r");

    while((fgets(buff,255,(FILE*)fp))){
            largodepalabra=strlen(buff);
            if(buff[largodepalabra-1]=='\n'){
                buff[largodepalabra-1]='\0';
            }
            buff[0]=ToLower(buff[0]);
            tabla=agregarATablaHash(tabla,buff);
    }
    fclose(fp);
    fp=fopen(arch[cant-1],"w");
    for(; iterpalab<parr.cantel; ++iterpalab){
            if(BuscarEnHash(tabla,parr.arr[iterpalab])==0){
                 fprintf(fp,"\nTal vez en lugar de %s quiso poner:\n",parr.arr[iterpalab]);
                analyzer(tabla,parr.arr[iterpalab],fp);
            }
    }
    fclose(fp);

    return 0;
}
