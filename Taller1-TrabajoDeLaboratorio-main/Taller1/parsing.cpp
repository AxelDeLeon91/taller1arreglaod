#include "parsing.h"

boolean verificarCom(listaStr str, comando com, arbol abb,listaSuc lsuc) {
    boolean comValido = FALSE;
    switch(com) {
        case Nacimiento: // Nacimiento Fecha NombreProgenitor -> nombreNuevo // Ej.: nacimiento 21/04/1926 Jorge -> Isabel
                if(contarNodos(str) != 5) {
                    mostrarError(error1);
                } else {
                    str = str->sig;
                    if(valida(stringFecha(str->str1))==FALSE) {
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==FALSE)
                            mostrarError(error3);
                        else
                            mostrarError(error2);
                    } else {
                        str = str->sig;
                        if(alfabetico(str->str1)==FALSE) {
                            mostrarError(error4);
                        } else {
                            if(buscarPersona(abb,str->str1)==FALSE) {
                                mostrarError(error5);
                            } else {
                                str = str->sig;
                                if(streq(str->str1,"->")==FALSE) {
                                    mostrarError(error6);
                                } else {
                                    str = str->sig;
                                    if(alfabetico(str->str1)==FALSE) {
                                        mostrarError(error4);
                                    } else {
                                            if(buscarPersona(abb,str->str1)==TRUE) {
                                                mostrarError(error7);
                                            } else comValido=TRUE;
                                    }
                                }
                            }
                        }
                    }
                }
            break;
        case Iniciar: // Iniciar Fecha Nombre // Ej.: iniciar 14/12/1895 Jorge
                if(contarNodos(str) != 3) {
                  mostrarError(error1);
                } else {
                    str=str->sig;
                    if(valida(stringFecha(str->str1))==FALSE) {
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==FALSE)
                            mostrarError(error3);
                        else
                            mostrarError(error2);
                    } else {
                        str=str->sig;
                        if(alfabetico(str->str1)==FALSE) {
                            mostrarError(error4);
                        } else comValido=TRUE;
                    }
                }
            break;
        case Fallecimiento: // Fallecimiento Fecha Nombre // Ej.: fallecimiento 06/02/1952 Jorge
        case Abdicacion: // Abdicacion Fecha Nombre // Ej.: abdicacion 01/04/2020 Enrique
                if(contarNodos(str) != 3) {
                    mostrarError(error1);
                } else {
                    str=str->sig;
                    if(valida(stringFecha(str->str1))==FALSE) {
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==FALSE)
                            mostrarError(error3);
                        else
                            mostrarError(error2);
                    } else {
                        str=str->sig;
                        if(alfabetico(str->str1)==FALSE) {
                            mostrarError(error4);
                        } else {
                            if(buscarPersona(abb,str->str1)==FALSE) {
                                mostrarError(error5);
                            } else comValido=TRUE;
                        }
                    }
                }
                break;
        case Miembros:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(abb==NULL) {
                        mostrarError(error8);
                    } else comValido=TRUE;
                }
            break;
        case Monarcas:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(lsuc==NULL) {
                       mostrarError(error9);
                    } else comValido=TRUE;
                }
            break;
        case Aspirantes:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(hayAspirantes(lsuc)==FALSE) {
                        mostrarError(error10);
                    } else comValido=TRUE;
                }
            break;
        case Historial:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(lsuc==NULL) {
                        mostrarError(error9);
                    } else comValido=TRUE;
                }

            break;
        case Respaldar:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(abb==NULL) {
                        mostrarError(error9);
                    } else {
                        if(lsuc==NULL) {
                            mostrarError(error9);
                        } else
                            comValido=TRUE;
                    }
                }
            break;
        case Recuperar:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(abb!=NULL) {
                        mostrarError(error11);
                    } else {
                        if(lsuc!=NULL) {
                            mostrarError(error12);
                        } else comValido=TRUE;
                    }
                }
            break;
        case Salir:
                if(contarNodos(str) == 1){
                    comValido = TRUE;
                }else
                    mostrarError(error1);
            break;
        default:
            break;
    }
    return comValido;
}

comando reconocerCom(string str) {
    comando c;
    mayus(str);

    if(streq(str,"INICIAR")){
        c = Iniciar;
    }else if(streq(str, "NACIMIENTO"))
        c = Nacimiento;
    else if(streq(str, "FALLECIMIENTO"))
        c = Fallecimiento;
    else if(streq(str, "ABDICACION"))
        c = Abdicacion;
    else if(streq(str, "MIEMBROS"))
        c = Miembros;
    else if(streq(str, "MONARCAS"))
        c = Monarcas;
    else if(streq(str, "ASPIRANTES"))
        c = Aspirantes;
    else if(streq(str, "HISTORIAL"))
        c = Historial;
    else if(streq(str, "RESPALDAR"))
        c = Respaldar;
    else if(streq(str, "RECUPERAR"))
        c = Recuperar;
    else if(streq(str, "SALIR"))
        c = Salir;
    else
        c= Desconocido;
    return c;
}

void iniciar(arbol &a, listaSuc &ls, listaStr &lstr) {
    //Cargar datos en una persona AUX
    persona aux;
    lstr=lstr->sig;
    fecha auxi = stringFecha(lstr->str1);
    lstr = lstr->sig;
    strcop(aux.nombre,lstr->str1);
    mayus(aux.nombre);
    aux.nacimiento = auxi;
    aux.primerMonarca = TRUE;
    strcop(aux.progenitor, " ");

     //Cargar datos al ABB
     cargar(a,aux);

     //Cargar datos a la lista
     datos dat;
     dat.miembro=aux;
     dat.abdico = FALSE;
     dat.actualMonarca = TRUE;
     dat.aspTrono = FALSE;
     dat.fallecio = FALSE;
     dat.fechAbd=fechaNula();
     dat.fechFall=fechaNula();
     dat.fechAsc = aux.nacimiento;
     dat.fueMonarca = TRUE;
     cargar(ls,dat);
}


void nacimiento(arbol &a, listaSuc &ls, listaStr &lstr) {
    //Cargar datos en una persona AUX
    persona aux;
    lstr = lstr->sig;
    aux.nacimiento = stringFecha(lstr->str1);
    lstr = lstr->sig;
    strcop(aux.progenitor,lstr->str1);
    mayus(aux.progenitor);
    aux.primerMonarca = FALSE;
    lstr = lstr->sig->sig;
    strcop(aux.nombre,lstr->str1);
    mayus(aux.nombre);
    cargar(a, aux); //Cargar datos al ABB
    //Cargar datos a la lista
    //me falta la parte de dnde colocarlo
    ls->dat.abdico = FALSE;
    ls->dat.actualMonarca = FALSE;
    ls->dat.aspTrono = TRUE;
    ls->dat.fallecio = FALSE;
    ls->dat.fueMonarca = FALSE;
    ls->dat.miembro = aux;
    ls->sig = NULL;
}

void fallecimiento(listaSuc &ls, listaStr lstr) {
    printf("\nentre a fall");
    listaSuc aux;
    aux = ls;
    fecha auxi;
    lstr = lstr->sig;
    auxi = stringFecha(lstr->str1);
    lstr = lstr->sig;
    mayus(lstr->str1);
    string nombre;
    strcop(nombre,lstr->str1);
    boolean encontre=FALSE;

    printf("\nprevia while");
    while(aux!=NULL && encontre!=TRUE){
         printf("\nentre while");
         print(aux->dat.miembro.nombre);
        if(streq(nombre,aux->dat.miembro.nombre)==TRUE){
            encontre=TRUE;
            printf("\npuse encontre en true");
        }else
            aux=aux->sig;
            printf("\navance puntero");
    }

    aux->dat.fallecio = TRUE;
    aux->dat.fechFall = auxi;
    printf("\nNombre:");
    print(aux->dat.miembro.nombre);
    printf("\nfecha fallecimiento:");
    mostrar(aux->dat.fechFall);
    if(esMonarca(aux->dat) == TRUE) {
        printf("\nentre al if esmonarca");
        aux->dat.actualMonarca = FALSE;
        aux = aux->sig;
        boolean encontre=FALSE;
        do {
            printf("\nentre al dowhile");
            if(aux->dat.fallecio==FALSE)    //test
                printf("Palmo");        //test
            else                    //test
                printf("ta vacio");     //test
            if(aux->dat.fallecio == FALSE ){
                printf("\npase primer if");
                if(aux->dat.abdico == FALSE){
                    printf("\nentre al if del dowhile");
                    aux->dat.actualMonarca = TRUE;
                    aux->dat.fueMonarca=TRUE;
                    aux->dat.fechAsc = auxi;
                    encontre = TRUE;
                    }
                }
          aux = aux->sig;
        }while(encontre == FALSE && aux!= NULL);

        if(encontre == FALSE)
            printf("\nLa monarquia termino ya que no hay sucesores");
        ls = aux;
    }
}


void abdicacion(listaSuc &ls, listaStr &lstr) {
    listaSuc aux;
    aux = ls;
    fecha auxi;
    lstr = lstr->sig;
    auxi = stringFecha(lstr->str1);
    printf("\nFecha auxi;");
    mostrar(auxi);
    lstr = lstr->sig;
    mayus(lstr->str1);
    string nombre;
    strcop(nombre,lstr->str1);
    printf("\nNombre;");
    print(nombre);
    while(streq(nombre,aux->dat.miembro.nombre) == FALSE) {
      aux = aux->sig;
    }
    printf("\nSali del while");
    aux->dat.abdico = TRUE;
    printf("\n abdico; ");
    mostrar(aux->dat.abdico);
    aux->dat.fechAbd = auxi;
    printf("\nFecha abd:");
    mostrar(aux->dat.fechAbd);
    printf("\nprevia if");
    if(esMonarca(aux->dat) == TRUE) {
            printf("\nEntre al if");
        aux->dat.actualMonarca = FALSE;
        printf("\nDONDE TOY;");
        print(aux->dat.miembro.nombre);
        boolean encontre=FALSE;
        do {
            printf("\nentre al dowhile");
            if(aux->dat.abdico==FALSE) //test
                printf("\nabdico");     //test
            else                        //test
                printf("\nta vacio");   //test
            if(aux->dat.fallecio == FALSE ){
                printf("\npase primer if");
                if(aux->dat.abdico == FALSE){
                    printf("\nentre al if del dowhile");
                    aux->dat.actualMonarca = TRUE;
                    aux->dat.fueMonarca=TRUE;
                    aux->dat.fechAsc = auxi;
                    encontre = TRUE;
                    }
                }
            aux=aux->sig;
        }while(encontre != TRUE && aux!= NULL);
        if(encontre == FALSE)
            printf("\nLa monarquia termino ya que no hay sucesores");
    }
}

void miembros(arbol a) {
    printf("\nMiembros:");
    mostrarArbol(a);
}

void monarcas(listaSuc ls) {
    listaSuc aux=ls;
    printf("\nMonarcas:");
    boolean encontre = FALSE;
    do{
        if(esMonarca(aux->dat) == TRUE)
            encontre = TRUE;
        else ls = aux->sig;
    } while(encontre != TRUE);
    int contador = 1;
    do{
        if(fueMonarca(aux->dat) == TRUE) {
            printf("\n%d - ",contador);
            mostrarMonarca(darDatos(aux));
        } else
            aux = aux->sig;
    } while(aux=NULL);
}

void aspirantes(listaSuc ls){
    listaSuc aux=ls;
    int contador = 1;
    while(esMonarca(aux->dat) == TRUE) {
        aux = aux->sig;
    }
    while(aux != NULL) {
        if(fallece(aux->dat) == FALSE && abdica(aux->dat) == FALSE) {
            printf("\n-%d ",contador);
            mostrarAspirante(aux->dat);
            contador++;
        }
    }
}
void historial(listaSuc ls){
    listaSuc aux=ls;
    int contador = 1;

    while(aux != NULL){
        printf("\n %d - ",contador);
        mostrarDatos(darDatos(aux));
        aux = aux->sig;
        contador++;
    }
}
