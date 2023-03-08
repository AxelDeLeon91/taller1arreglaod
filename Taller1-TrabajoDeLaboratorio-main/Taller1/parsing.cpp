#include "parsing.h"

void mostrarError(listaStr str, comando com, arbol abb,listaSuc lsuc) {
    fecha auxi, auxi2;
    switch(com) {
        case Nacimiento:
                if(contarNodos(str) != 5) {
                    mostrarError(error1);
                }else{
                    str = str->sig;
                    if(valida(stringFecha(str->str1))==FALSE){
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==FALSE)
                            mostrarError(error3);
                        else
                            mostrarError(error2);
                    }else{
                        str = str->sig;
                        if(alfabetico(str->str1)==FALSE){
                            mostrarError(error4);
                        }else{
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
        case Abdicacion:
                if(contarNodos(str) != 3) {
                    mostrarError(error1);
                } else {
                    str=str->sig;
                    auxi=stringFecha(str->str1);
                    if(esUltimaFecha(auxi,lsuc)==FALSE) {
                        printf("\nEntre valida");
                        if(esUltimaFecha(auxi,lsuc)==FALSE){
                            printf("\nEntre ultima");
                            mostrarError(error3);
                        }
                        else
                            mostrarError(error2);
                    } else {
                        str=str->sig;
                        if(alfabetico(str->str1)==FALSE) {
                            mostrarError(error4);
                        } else {
                            if(buscarPersona(abb,str->str1)==FALSE) {
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

boolean verificarComando(listaStr str,comando com,arbol abb,listaSuc lsuc){
      boolean comValido=FALSE;
      listaStr aux=str;
      fecha auxi, auxi2;
        switch(com) {
        case Iniciar:
                if(contarNodos(str) == 3){
                    str=str->sig;
                    auxi=stringFecha(str->str1);
                    if(valida(auxi)==TRUE)
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==TRUE)
                            str=str->sig;
                            if(alfabetico(str->str1)==TRUE)
                                comValido=TRUE;
                }
            break;

        case Nacimiento:
                if(contarNodos(str) == 5)
                    str = str->sig;
                    if(valida(stringFecha(str->str1))==TRUE)
                        if(esUltimaFecha(stringFecha(str->str1),lsuc)==TRUE)
                            str = str->sig;
                            if(alfabetico(str->str1)==TRUE)
                                if(buscarPersona(abb,str->str1)==TRUE)
                                    str = str->sig;
                                    if(streq(str->str1,"->")==TRUE)
                                        str = str->sig;
                                        if(alfabetico(str->str1)==TRUE)
                                            if(buscarPersona(abb,str->str1)==FALSE)
                                                comValido=TRUE;
            break;

        case Fallecimiento:
        case Abdicacion:
                if(contarNodos(str)==3){
                    str=str->sig;
                    auxi=stringFecha(str->str1);
                    if(valida(auxi)==TRUE){
                        auxi2=stringFecha(str->str1);
                        if(esUltimaFecha(auxi2,lsuc)==TRUE)
                            str=str->sig;
                            if(alfabetico(str->str1)==TRUE)
                                if(buscarPersona(abb,str->str1)==TRUE)
                                    comValido=TRUE;
                    }
                }
                break;
        case Miembros:
                if(contarNodos(str)==1)
                    if(abb!=NULL)
                        comValido=TRUE;
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
    str=aux;
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
    printf("\nEntre a Funcioniniciar");
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
     printf("\nSali Funcioniniciar");
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
    aux->dat.fallecio = TRUE;
    printf("\n fallecio; ");
    mostrar(aux->dat.fallecio);
    aux->dat.fechFall = auxi;
    printf("\nFecha fall:");
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
            if(aux->dat.fallecio==FALSE) //test
                printf("\nfallecio");     //test
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
        else aux = aux->sig;
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
