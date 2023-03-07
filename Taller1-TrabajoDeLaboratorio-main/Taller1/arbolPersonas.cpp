#include "arbolPersonas.h"

void crear(arbol &abb) {
    abb = NULL;
}
void cargar(arbol &a, persona e) {
    if(a == NULL) {
        a = new nodoA;
        a->p = e;
        a->izq = NULL;
        a->der = NULL;
    }
    else {
        if(strmen(e.nombre, a->p.nombre))
            cargar(a->izq, e);
        else
            cargar(a->der, e);
    }
}
void mostrarArbol(arbol a) {
    printf("\nMostrarArbol");
    if(a!= NULL) {
        mostrarArbol(a->izq);
        mostrarPersona(a->p);
        mostrarArbol(a->der);
    }
}

boolean buscarPersona(arbol a, string s){
    if(a!=NULL){
        if(streq(s, a->p.nombre))
            return TRUE;
        else {
            buscarPersona(a->izq, s);
            buscarPersona(a->der, s);
        }
    }
    else
            return FALSE;
}

// Archivos
void bajarAux(arbol abb, FILE *a) {
    if(abb != NULL) {
    	bajar(abb->p, a);
    	bajarAux(abb->izq, a);
    	bajarAux(abb->der, a);
    }
}

void bajar(arbol abb) {
	FILE *a = fopen("arbolBinario.dat", "wb");
	bajarAux(abb, a);
	fclose(a);
}

void levantar(arbol &abb) {
	FILE *a = fopen("arbolBinario.dat", "rb");
	persona p;
	crear(abb);
		if(a!=NULL) {
    		levantar(p, a);
    			while(!feof(a)) {
    				cargar(abb, p);
    				levantar(p, a);
    			}
		}
	fclose(a);
}
