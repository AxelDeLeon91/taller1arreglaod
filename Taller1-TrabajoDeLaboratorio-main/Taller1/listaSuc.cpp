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
    int i = 0;
    while(lsuc != NULL) {
        if(aspirante(darDatos(lsuc)))
            hay = TRUE;
        i++;
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
    printf("\nEntre a mostrarAspirante");
    printf("\n");
    print(d.miembro.nombre);
    printf(" hijo/a de ");
    print(d.miembro.progenitor);
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
