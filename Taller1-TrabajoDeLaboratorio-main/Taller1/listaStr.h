#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_LISTASTR_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_LISTASTR_H

#include "string.h"

typedef struct nodoLS {
    string str1;
    nodoLS *sig;
} nodoLS;

typedef nodoLS *listaStr;

void mostrar(listaStr lStr);
// Funcionalidades
void InsBackIter(listaStr &L, string str);
void crear(listaStr &ls);
void borrarLista(listaStr &ls);
int contarNodos(listaStr ls);
void insertarPalabra(string str, listaStr &ls);
// void avanzar(listaStr &ls);

void separarString(string str, listaStr &ls);


#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_LISTASTR_H
