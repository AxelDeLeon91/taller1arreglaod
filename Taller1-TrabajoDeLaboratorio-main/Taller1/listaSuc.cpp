#include "listaSuc.h"

void crear(listaSuc &lsuc) {
    lsuc = NULL;
}
void cargar(listaSuc &ls, datos dat) {
  listaSuc aux = new nodoL;
  aux->dat = dat;
  aux->sig = ls;
  ls = aux;
}
boolean hayAspirantes(listaSuc lsuc) {
    boolean hay = FALSE;
    while(lsuc != NULL) {
        if(lsuc->dat.aspTrono==TRUE){
            hay = TRUE;
        }else
            lsuc=lsuc->sig;
    }
    return hay;
}
datos darDatos(listaSuc ls) {
    return ls->dat;
}

void agregarDatos(datos d, listaSuc &ls) {
    listaSuc aux = ls;
    while(aux != NULL)
        aux = aux->sig;
    aux->dat = d;
}

boolean esUltimaFecha(fecha f, listaSuc lsuc){
    boolean ultima=TRUE;
    while(lsuc!=NULL && ultima==TRUE){
        if(menor(f,lsuc->dat.miembro.nacimiento)==TRUE){
            ultima=FALSE;
        }else
            if(menor(f,lsuc->dat.fechAbd)==TRUE){
                ultima=FALSE;
            }else
                if(menor(f,lsuc->dat.fechAsc)==TRUE){
                    ultima=FALSE;
                }else
                    if(menor(f,lsuc->dat.fechFall)==TRUE){
                        ultima=FALSE;
                    }

    lsuc=lsuc->sig;
    }//while
    return ultima;
}

void mostrarAspirante(datos d){
    print(d.miembro.nombre);
    printf(" hijo/a de ");
    print(d.miembro.progenitor);
}

void cargarNacimiento(listaSuc &ls,string padre,datos aux){
    printf("\nEntre cargar nacimiento:  ");
    print(padre);
    boolean encontre=FALSE, pad=FALSE;
    int cantHijos=0;
    listaSuc aux2=ls, aux3;

    while(pad==FALSE&& aux2!=NULL){
        printf("\nWhile");
        if(streq(padre,aux2->dat.miembro.nombre)==TRUE){
            pad=TRUE;
            printf("\nEncontre padre");
        }else
            aux2=aux2->sig;
    }
    printf("\nSali while");


            do{
                print(aux2->dat.miembro.progenitor);
                if(streq(padre,aux2->dat.miembro.progenitor)==TRUE){
                    printf("\n%c",cantHijos);
                    cantHijos++;
                    }
                aux2=aux2->sig;
            }while(aux2!=NULL);
            printf("\nSali while");

            while(cantHijos!=0){
                if(streq(padre,aux2->dat.miembro.progenitor)){
                    printf("\n%c",cantHijos);
                    cantHijos--;
                    aux3=aux2;
                }
                aux2=aux2->sig;
            }
            printf("\nSali while");
            aux3->sig=new nodoL;
            aux3=aux3->sig;
            aux3->sig=aux2;
            aux3->dat=aux;
    }


// Archivos
void bajar(listaSuc ls) {
    FILE *a = fopen("listaSucesion.dat", "wb");
    while(ls != NULL) {
        bajar(darDatos(ls), a);
        ls = ls->sig;
    }
    fclose(a);
}
void levantar(listaSuc &ls) {
    FILE *a = fopen("listaSucesion.dat", "rb");
    datos dat;
    crear(ls);
        if(a!=NULL) {
            levantar(dat, a);
            while(!feof(a)) {
                cargar(ls, dat);
                levantar(dat, a);
            }
        }
    fclose(a);
}
