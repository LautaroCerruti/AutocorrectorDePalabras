#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "DS.h"
#include "Strings.h"

void intercambiar(mhash tabla,char palabra[],FILE *fp){
    char aux[strlen(palabra)];
    strcpy(aux,palabra);
    int iterador=0;
    for(; iterador<(strlen(palabra)-1); ++iterador) {
        strcpy(aux,palabra);
        aux[iterador]=palabra[iterador+1];
        aux[iterador+1]=palabra[iterador];
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
    }
}

void insert(mhash tabla,char palabra[],FILE *fp) {
    int lugp=0,creaux=0,largo=strlen(palabra),paliter=0,iteradorprueba=0;
    char aux[largo+2];
    for(;lugp<(largo+1);++lugp){
        for(creaux=0,paliter=0;creaux<(largo+2);++creaux){
            if(creaux==lugp){
                aux[creaux]=' ';
            }
            else{
                aux[creaux]=palabra[paliter];
                ++paliter;
            }
        }
        for(iteradorprueba=0;iteradorprueba<26;++iteradorprueba){
            aux[lugp]='a'+iteradorprueba;
            if(BuscarEnHash(tabla,aux)){
                fprintf(fp,"%s\n",aux);
            }
        }
        aux[lugp]='á';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugp]='é';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugp]='í';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugp]='ó';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugp]='ú';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugp]='ü';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugp]='ñ';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
    }
    }
}

void separa(mhash tabla,char palabra[],FILE *fp){
    int lugp=1,creaux=0,largo=strlen(palabra),paliter=0,ban=0,segunda=0;
    char aux[largo+2],aux2[largo+5],aux3[largo+5];
    for(;lugp<(largo);++lugp){
        for(creaux=0,paliter=0,segunda=0,ban=0;creaux<(largo+2);++creaux){
            if(creaux==lugp){
                ban=1;
                aux2[paliter]='\0';
                aux[creaux]=' ';
            }
            else{
                if(ban==0){
                aux2[paliter]=palabra[paliter];
                }
                else{
                    aux3[segunda]=palabra[paliter];
                    ++segunda;
                }
                aux[creaux]=palabra[paliter];
                ++paliter;
            }
        }
        aux3[segunda]='\0';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        if(BuscarEnHash(tabla,aux2) && BuscarEnHash(tabla,aux3)){
            fprintf(fp,"%s %s\n",aux2,aux3);
        }
    }
}

void remplaza(mhash tabla,char palabra[],FILE *fp){
    char aux[strlen(palabra)];
    int lugares=0,i=0;
    strcpy(aux,palabra);
    for(;lugares<strlen(palabra);++lugares){
        strcpy(aux,palabra);
        for(i=0;i<26;++i){
            aux[lugares]='a'+i;
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        }
        aux[lugares]='á';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugares]='é';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugares]='í';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugares]='ó';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugares]='ú';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugares]='ü';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
        aux[lugares]='ñ';
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
    }
}
}
void elimina(mhash tabla,char palabra[],FILE *fp){
    int lug=0,largo=strlen(palabra),i,intaux=0;
    char aux[largo];
    for(;lug<largo;++lug){
        for(i=0,intaux=0;i<=largo;++i){
            if(i!=lug){
                aux[intaux]=palabra[i];
                ++intaux;
            }
        }
        if(lug!=0 && palabra[lug]==palabra[lug-1]){continue;}
        if(BuscarEnHash(tabla,aux)){
            fprintf(fp,"%s\n",aux);
        }
    }
}

char ToLower(char c){
    if(c>='A' && c<='Z'){
        return tolower(c);
    }else{
        switch(c){
            case 'Á':
                return 'á';
                break;
            case 'É':
                return 'é';
                break;
            case 'Í':
                return 'í';
                break;
            case 'Ó':
                return 'ó';
                break;
            case 'Ú':
                return 'ú';
                break;
            case 'Ü':
                return 'ü';
                break;
            case 'Ñ':
                return 'ñ';
                break;
            default:
                break;
        }
    }
    return c;
}

void analyzer(mhash tabla,char palabra[],FILE *fp) {
    intercambiar(tabla,palabra,fp);
    insert(tabla,palabra,fp);
    separa(tabla,palabra,fp);
    remplaza(tabla,palabra,fp);
    elimina(tabla,palabra,fp);
}
