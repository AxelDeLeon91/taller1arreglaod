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
    printf("\nEntre a CargarNacimiento");
    listaSuc aux1=ls, aux2, aux3;
    printf("\nPRIMER PERSONA LISTA: ");
    print(aux1->dat.miembro.nombre);
    while(streq(aux1->dat.miembro.progenitor,padre)==FALSE && aux1->sig!=NULL){
        printf("\nEntre a while...");
        aux1=aux1->sig;
    }
    printf("\nPRIMER PERSONA LISTA: ");
    print(aux1->dat.miembro.nombre);
    printf("\nSalgo del while");
    //AUX ESTA EN EL PADRE
    aux2=aux1;
    aux3=aux1->sig;
    boolean posi=FALSE;
    if(aux1->sig==NULL && aux1->dat.miembro.primerMonarca==TRUE){
        printf("\nEntre a PRIMER IF");
        aux1->sig= new nodoL;
        aux1=aux1->sig;
        aux1->dat= aux;
        aux1->sig=NULL;
        printf("\nPRIMER PERSONA LISTA: ");
        print(ls->dat.miembro.nombre);
    }else{
        do{
            printf("\nEntre a doWhile");
            if(streq(aux3->dat.miembro.progenitor,aux1->dat.miembro.progenitor)==FALSE){
                    printf("\nEntre a if=FALSE");
                    aux3=aux3->sig;
                    aux2=aux2->sig;
            }else{
                if(streq(aux3->dat.miembro.progenitor,aux1->dat.miembro.progenitor)==TRUE){
                    printf("\nEntre a if=TRUE");
                    posi=TRUE;
                }
            }
        }while(aux3!=NULL && posi!=TRUE);
        printf("\nSALI DEL DOWHILE");
            aux2=aux3;
            aux3->sig= new nodoL;
            aux3=aux3->sig;
            aux3->dat= aux;
            aux2->sig=aux3;
        }
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
