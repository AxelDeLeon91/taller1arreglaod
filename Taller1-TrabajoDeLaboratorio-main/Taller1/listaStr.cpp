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
        while (ls != NULL){
            i++;
            ls = ls->sig;
        } ;
    return i;
}

void insertarPalabra(string str, listaStr &ls) {
    ls = new nodoLS;
    strcop(ls->str1, str);
    ls->sig = NULL;
}

void separarString(string str, listaStr &ls) {
    printf("\nentre separar string");
    string strAux;
    int i = 0, j = 0;
    if(str[i]=='\n'){
            ls=NULL;
        printf("\nentre if");

    }else{
        printf("\nentre else");
        while(str[i] != '\0') {
            strcrear(strAux);
            if(str[i] == ' ') {
                printf("\nentre segundo if");
                i++;
            } else {
                printf("\nentre segundo else");
                while(str[i] != ' ' && str[i] != '\0') {
                    strAux[j] = str[i];
                    i++; j++;
                }
                strAux[j] = '\0';
                j = 0;
                InsBackIter(ls, strAux);
            }
            strdestruir(strAux);
        }
    }
}
