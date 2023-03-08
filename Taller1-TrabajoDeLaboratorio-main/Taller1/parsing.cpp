#include "parsing.h"

void mostrarError(listaStr str, comando com, arbol abb,listaSuc lsuc) {
    switch(com) {
        case Nacimiento:
                if(contarNodos(str) != 5) {
                    printf("Quede en contar nodos");
                    mostrarError(error1);
                }else{
                    str = str->sig;
                    if(valida(stringFecha(str->str1))==FALSE){
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==FALSE){
                            mostrarError(error3);
                            printf("Quede en ultima fecha");
                        }else{
                            mostrarError(error2);
                            printf("Quede en fecha invalida");
                            }
                    }else{
                        str = str->sig;
                        if(alfabetico(str->str1)==FALSE){
                            mostrarError(error4);
                        }else{
                            mayus(str->str1);
                            if(buscarPersona(abb,str->str1)==FALSE){
                                mostrarError(error5);
                            }else{
                                str = str->sig;
                                if(streq(str->str1,"->")==FALSE){
                                    mostrarError(error6);
                                }else{
                                    str = str->sig;
                                    if(alfabetico(str->str1)==FALSE){
                                        mostrarError(error4);
                                    }else{
                                            if(buscarPersona(abb,str->str1)==TRUE){
                                                mostrarError(error7);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
            break;
        case Iniciar:
                if(contarNodos(str) != 3){
                  mostrarError(error1);
                }else{
                    str=str->sig;
                    if(valida(stringFecha(str->str1))==FALSE){
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==FALSE)
                            mostrarError(error3);
                        else
                            mostrarError(error2);
                    }else{
                        str=str->sig;
                        if(alfabetico(str->str1)==FALSE)
                            mostrarError(error4);
                    }
                }
            break;
        case Fallecimiento:
        case Abdicacion: // abdicacion 1/1/1 Axel
                if(contarNodos(str) != 3) {
                    mostrarError(error1);
                } else {
                    str=str->sig;
                    if(valida(stringFecha(str->str1))==FALSE) {
                        mostrarError(error2);
                    } else {
                        if(esUltimaFecha(stringFecha(str->str1), lsuc)==FALSE){
                        printf("llego");
                            mostrarError(error3);
                        } else {
                            str=str->sig;
                            if(alfabetico(str->str1)==FALSE) {
                                mostrarError(error4);
                            } else {
                                string pAux; strcop(pAux, str->str1); mayus(pAux);
                                if(buscarPersona(abb, pAux)==FALSE)
                                    mostrarError(error5);
                            }
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
                    }
                }
            break;
        case Monarcas:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(lsuc==NULL) {
                       mostrarError(error9);
                    }
                }
            break;
        case Aspirantes:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(hayAspirantes(lsuc)==FALSE) {
                        mostrarError(error10);
                    }
                }
            break;
        case Historial:
                if(contarNodos(str)!=1) {
                    mostrarError(error1);
                } else {
                    if(lsuc==NULL) {
                        mostrarError(error9);
                    }
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
                        }
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
                        }
                    }
                }
            break;
        case Salir:
                if(contarNodos(str) != 1)
                    mostrarError(error1);
            break;

        default:
            break;
    }
}

boolean verificarComando(listaStr str,comando com,arbol abb,listaSuc lsuc) {
      boolean comValido=FALSE;
      fecha auxi, auxi2;
        switch(com) {
        case Iniciar:
                if(contarNodos(str) == 3){
                    str=str->sig;
                    auxi=stringFecha(str->str1);
                    if(valida(auxi)==TRUE)
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==TRUE){
                            str=str->sig;
                            if(alfabetico(str->str1)==TRUE)
                                comValido=TRUE;
                }
                }
            break;

        case Nacimiento:
                   if(contarNodos(str) == 5) {
                    str = str->sig;
                    if(valida(stringFecha(str->str1))==TRUE) {
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==TRUE) {
                            str = str->sig;
                            if(alfabetico(str->str1)==TRUE) {
                                string pAux; strcop(pAux,str->str1);mayus(pAux);
                                if(buscarPersona(abb,pAux)==TRUE) {
                                    str = str->sig;
                                    if(streq(str->str1,"->")==TRUE) {
                                        str = str->sig;
                                        if(alfabetico(str->str1)==TRUE) {
                                            if(buscarPersona(abb,str->str1)==FALSE)
                                                comValido=TRUE;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            break;

        case Fallecimiento:
        case Abdicacion:
                if(contarNodos(str)==3){
                    str=str->sig;
                    auxi=stringFecha(str->str1);
                    if(valida(auxi)==TRUE){
                        if(esUltimaFecha(auxi,lsuc)==TRUE){
                            str=str->sig;
                            mayus(str->str1);
                            if(alfabetico(str->str1)==TRUE){
                                if(buscarPersona(abb,str->str1)==TRUE){
                                    comValido=TRUE;
                                    }
                            }
                        }
                    }
                }
                break;
        case Miembros:
                if(contarNodos(str)==1) {
                    if(abb!=NULL)
                        comValido=TRUE;
                }
            break;
        case Monarcas:
                if(contarNodos(str)==1)
                    if(lsuc!=NULL)
                       comValido=TRUE;
            break;
        case Aspirantes:
                if(contarNodos(str)==1)
                    if(hayAspirantes(lsuc)==TRUE)
                        comValido=TRUE;
            break;
        case Historial:
                if(contarNodos(str)==1)
                    if(lsuc!=NULL)
                        comValido=TRUE;

            break;
        case Respaldar:
                if(contarNodos(str)==1)
                    if(abb!=NULL)
                        if(lsuc!=NULL)
                            comValido=TRUE;

            break;
        case Recuperar:
                if(contarNodos(str)==1)
                    if(abb==NULL)
                        if(lsuc==NULL)
                            comValido=TRUE;

                break;
        case Salir:
                if(contarNodos(str) == 1)
                    comValido=TRUE;
            break;

        default:
                comValido=FALSE;
            break;
    }
    return comValido;
}


comando reconocerCom(string str) {
    comando c;
    mayus(str);

    if(streq(str, Ini)){
        c = Iniciar;
    }else if(streq(str, Naci))
        c = Nacimiento;
    else if(streq(str, Falle))
        c = Fallecimiento;
    else if(streq(str, Abdi))
        c = Abdicacion;
    else if(streq(str, Miem))
        c = Miembros;
    else if(streq(str, Mona))
        c = Monarcas;
    else if(streq(str, Asp))
        c = Aspirantes;
    else if(streq(str, Histo))
        c = Historial;
    else if(streq(str, Resp))
        c = Respaldar;
    else if(streq(str, Recu))
        c = Recuperar;
    else if(streq(str, Sal))
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
    strcop(aux.progenitor,aux.nombre);

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
    printf("\nEngre a Nacimiento");
    listaSuc lAux=ls;
    datos DatoAux;

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

    //Cargar datos al ABB
    printf("\nPre carga abb");
    cargar(a, aux);
    printf("\nPost carga abb");

    //Cargar datos a la lista

    string padre;
    strcop(padre,aux.progenitor);
    DatoAux.abdico = FALSE;
    DatoAux.actualMonarca = FALSE;
    DatoAux.aspTrono = TRUE;
    DatoAux.fallecio = FALSE;
    DatoAux.fueMonarca = FALSE;
    DatoAux.miembro = aux;

    //Buscar donde colocarlo
    printf("\nPre carga lista");
    cargarNacimiento(lAux,padre,DatoAux);
    printf("\n Post carga lista");

}

void fallecimiento(listaSuc &ls, listaStr lstr) {
    listaSuc aux;
    aux = ls;
    fecha auxi;
    lstr = lstr->sig;
    auxi = stringFecha(lstr->str1);
    lstr = lstr->sig;
    mayus(lstr->str1);
    string nombre;
    strcop(nombre,lstr->str1);
    while(streq(nombre,aux->dat.miembro.nombre) == FALSE) {
      aux = aux->sig;
    }
    aux->dat.fallecio = TRUE;
    aux->dat.fechFall = auxi;
    if(esMonarca(aux->dat) == TRUE) {
        aux->dat.actualMonarca = FALSE;
        boolean encontre=FALSE;
        do {
            if(aux->dat.fallecio == FALSE ){
                if(aux->dat.abdico == FALSE){
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


void abdicacion(listaSuc &ls, listaStr &lstr) {
    listaSuc aux;
    aux = ls;
    fecha auxi;
    lstr = lstr->sig;
    auxi = stringFecha(lstr->str1);
    lstr = lstr->sig;
    mayus(lstr->str1);
    string nombre;
    strcop(nombre,lstr->str1);
    while(streq(nombre,aux->dat.miembro.nombre) == FALSE) {
      aux = aux->sig;
    }
    aux->dat.abdico = TRUE;
    aux->dat.fechAbd = auxi;
    if(esMonarca(aux->dat) == TRUE) {
        aux->dat.actualMonarca = FALSE;
        boolean encontre=FALSE;
        do {
            if(aux->dat.fallecio == FALSE ){
                if(aux->dat.abdico == FALSE){
                    aux->dat.actualMonarca = TRUE;
                    aux->dat.fueMonarca=TRUE;
                    aux->dat.aspTrono=FALSE;
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
        else aux = aux->sig;
    } while(encontre != TRUE);
    int contador = 1;
    do{
        if(fueMonarca(aux->dat) == TRUE) {
            printf("\n%d - ",contador);
            mostrarMonarca(darDatos(aux));
        } else
            aux = aux->sig;
    }while(aux==NULL);
}

void aspirantes(listaSuc ls){
    listaSuc aux=ls;
    int contador = 1;
    while(esMonarca(aux->dat) == TRUE) {
        aux = aux->sig;
    }
    while(aux != NULL) {
        if(fallece(aux->dat)==FALSE && abdica(aux->dat)==FALSE && aspirante(aux->dat)==TRUE){
            printf("\n %d - ",contador);
            mostrarAspirante(aux->dat);
            contador++;
        }
    aux=aux->sig;
    }
    if(contador==1){
        printf("\nNo hay aspirantes al trono actualmente");
    }
}

void historial(listaSuc ls){
    listaSuc aux=ls;
    int contador = 1;

    while(aux != NULL){
        printf("\n %d - ",contador);
        mostrarDatos(darDatos(aux));
        contador++;
        aux = aux->sig;
    }
}
