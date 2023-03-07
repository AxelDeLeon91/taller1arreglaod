#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_ERROR_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_ERROR_H

#include <stdio.h>

typedef enum {
    error1, //Mensaje hay mas parametros
    error2, //Fecha Invalida
    error3, //Fecha anterior a una escrita
    error4, //No alfabetico
    error5, //Nombre no se encuentra abb
    error6, //Error ->
    error7, //Nombre ya existe
    error8, //ABB Vacio
    error9, //Lista vacia
    error10, // No hay aspirantes
    error11, //ABB no vacio
    error12, // ABB lista no vacia
    error13,
    error14,
    error15,
    error16,

}error;

void mostrarError(error e);

#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_ERROR_H
