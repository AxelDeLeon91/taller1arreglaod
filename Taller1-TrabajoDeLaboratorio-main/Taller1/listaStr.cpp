#include "listaStr.h"

void mostrar(listaStr lStr) {
    printf("Entro a la funcion mostrar");
    while(lStr != NULL) {
        printf("\nPalabra: ");
        print(lStr->str1);
        lStr = lStr->sig;
    }
}

void InsBackIter(listaStr &L, string str) {
    listaStr nuevo = new nodoLS;
    strcrear(nuevo->str1);
    strcop(nuevo->str1, str);
    nuevo->sig = NULL;
    if (L == NULL)
        L = nuevo;
    else {
        listaStr aux = L;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    }
}

void crear(listaStr &ls) {
    ls = NULL;
}
void borrarLista(listaStr &ls) {
    if(ls != NULL) {
        borrarLista(ls->sig);
        delete []ls;
    }
}

int contarNodos(listaStr ls) {
    int i = 0;
        do {
            i++;
            ls = ls->sig;
        } while (ls->sig != NULL);
    return i;
}

void insertarPalabra(string str, listaStr &ls) {
    ls = new nodoLS;
    strcop(ls->str1, str);
    ls->sig = NULL;
}

void separarString(string str, listaStr &ls) {
    listaStr listaAux = ls;
    string strAux;
    int i = 0, j = 0;
    while(str[i] != '\0') {
        strcrear(strAux);
        if(str[i] == ' ') {
            i++;
        } else {
            while(str[i] != ' ' && str[i] != '\0') {
                strAux[j] = str[i];
                i++; j++;
            }
            strAux[j] = '\0';
            j = 0;
            InsBackIter(ls, strAux);
            strdestruir(strAux);
        }
    }
}
