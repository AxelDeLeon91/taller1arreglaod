#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_LISTASUC_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_LISTASUC_H

#include "datosSuce.h"
#include "persona.h"

typedef struct nodoL {
    datos dat;
    nodoL *sig;
}nodoL;

typedef nodoL *listaSuc;

void crear(listaSuc &lsuc);
void cargar(listaSuc &ls, datos dat);

// Funcionalidades
boolean hayAspirantes(listaSuc ls);
datos darDatos(listaSuc ls);
void historial(listaSuc ls);
void agregarDatos(datos d, listaSuc &ls);
boolean esUltimaFecha(fecha f, listaSuc lsuc);
void mostrarAspirante(datos d);

// Archivos
void bajar(listaSuc p);
void levantar(listaSuc &p);

#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_LISTASUC_H
