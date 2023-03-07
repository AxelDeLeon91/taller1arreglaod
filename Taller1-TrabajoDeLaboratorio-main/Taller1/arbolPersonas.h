#ifndef ARBOLPERSONAS_H_INCLUDED
#define ARBOLPERSONAS_H_INCLUDED

#include "persona.h"

typedef struct nodoA{
    persona p;
    nodoA *izq;
    nodoA *der;
}nodoA;

typedef nodoA *arbol;

void crear(arbol &abb);
void mostrarArbol(arbol a);
void cargar(arbol &a, persona e);
boolean buscarPersona(arbol a, string s);

// Archivos
void bajarAux(arbol abb, FILE *a);
void bajar(arbol abb);
void levantar(arbol &abb);

#endif // ARBOLPERSONAS_H_INCLUDED
