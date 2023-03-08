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
            printf("\n-------------------------------------\n");
            printf("\nIngrese el Comando: ");
            scan(com);
            printf("\nComando escaneado");
            separarString(com,lStr);
            printf("\nsepare string");
            c = reconocerCom(lStr->str1);
            switch(c){
                    case Iniciar:
                        if(verificarComando(lStr,c,abb,lSuc)==TRUE){
                            iniciar(abb, lSuc, lStr);
                        }else{
                            printf("\nEntre a else");
                            mostrarError(lStr,c,abb,lSuc);
                            }

                        break;
                    case Nacimiento:
                        printf("\nEntre CASENacimiento\n");
                        print(lStr->sig->sig->str1);
                        mostrar(verificarComando(lStr,c,abb,lSuc));
                        if(verificarComando(lStr,c,abb,lSuc)==TRUE){
                            printf("\nEntre al if Nacimiento");
                            nacimiento(abb,lSuc,lStr);
                            printf("\nSali Nacimiento");
                        }else{
                            printf("\nEntre a else");
                            mostrarError(lStr,c,abb,lSuc);
                            }
                        break;
                    case Fallecimiento:
                        printf("\npalme");
                        if(verificarComando(lStr,c,abb,lSuc)==TRUE){
                            fallecimiento(lSuc, lStr);
                        }else{
                            printf("\nEntre a else");
                            mostrarError(lStr,c,abb,lSuc);
                            }
                        break;
                    case Abdicacion:
                        printf("\nEntre a CaseAbdicar");
                        if(verificarComando(lStr,c,abb,lSuc)==TRUE){
                            printf("\nEntre al if");
                            abdicacion(lSuc, lStr);
                        }else{
                            printf("\nEntre a else");
                            mostrarError(lStr,c,abb,lSuc);
                            }

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
                        bajar(lSuc);
                        bajar(abb);
                        break;
                    case Recuperar:
                        printf("\nrec");
                        levantar(lSuc);
                        levantar(abb);
                        break;
                    case Desconocido:
                        printf("\nDesco");
                        break;
                    case Salir:
                        printf("\nSalir");
                        break;
                    default:
                        printf("Mensaje invalido");
                        break;
                }
            borrarLista(lStr);
            strdestruir(com);
            printf("\nLimpie lista string y string");

        }while(c!= Salir);
}


/*

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
*/
