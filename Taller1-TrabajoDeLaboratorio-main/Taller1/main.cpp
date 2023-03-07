#include <stdio.h>
#include "parsing.h"



int main() {
    arbol abb;
    crear(abb);
    listaStr lStr;
    listaSuc lSuc;
    crear(lSuc);
    string com;
    comando c;
    do{
            crear(lStr);
            strcrear(com);
            printf("\nIngrese el Comando: ");
            scan(com);
            printf("\nComando escaneado");
            separarString(com,lStr);
            printf("\nsepare string");
            c = reconocerCom(lStr->str1);
            switch(c){
                    case Iniciar:
                        printf("\nInicie");
                        iniciar(abb, lSuc, lStr);
                        break;
                    case Nacimiento:
                        printf("\nnaci");
                        nacimiento(abb, lSuc, lStr);
                        break;
                    case Fallecimiento:
                        printf("\npalme");
                        fallecimiento(lSuc, lStr);
                        break;
                    case Abdicacion:
                        printf("\nabdi");
                        abdicacion(lSuc, lStr);
                        break;
                    case Miembros:
                        printf("\nmiem");
                        miembros(abb);
                        break;
                    case Monarcas:
                        printf("\nmon");
                        monarcas(lSuc);
                        break;
                    case Aspirantes:
                        printf("\naspi");
                        aspirantes(lSuc);
                        break;
                    case Historial:
                        printf("\nhist");
                        historial(lSuc);
                        break;
                    case Respaldar:
                        printf("\nresp");
                        break;
                    case Recuperar:
                        printf("\nrec");
                        break;
                    case Desconocido:
                        printf("\nDesco");
                        break;
                    case Salir:
                        printf("\nSalir");
                    default:
                        break;
                }
            strdestruir(com);
            borrarLista(lStr);
            printf("\nLimpie lista string y string");
        }while(c!= Salir);
    return 0;
}

