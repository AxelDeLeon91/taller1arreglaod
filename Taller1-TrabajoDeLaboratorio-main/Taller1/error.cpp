#include "error.h"

void mostrarError(error e){

    switch(e){
        case error1:
            printf("\n El comando cuenta con una cantidad de parametros incorrecta");
            break;
        case error2:
            printf("\n La fecha es invalida");
            break;
        case error3:
            printf("\n La fecha ingresada es anterior a la ultima ingresada");
            break;
        case error4:
            printf("\n El nombre no es alfabetico");
            break;
        case error5:
            printf("\n El nombre ingresado no se encuentra en el ABB");
            break;
        case error6:
            printf("\n El comando no cuenta con '->' como 4to parametro");
            break;
        case error7:
            printf("\n El nombre ya existe");
            break;
        case error8:
            printf("\n El Arbol de Personas se encuentra vacio");
            break;
        case error9:
            printf("\n La lista de sucesion se encuentra vacia");
            break;
        case error10:
            printf("\n No hay aspirantes al trono");
            break;
        case error11:
            printf("\n el Arbol de Personas no se encuentra vacio");
            break;
        case error12:
            printf("\n La lista de sucesion no se encuentra vacia");
            break;
        default:
            break;
    }
}