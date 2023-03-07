#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_DATOSSUCE_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_DATOSSUCE_H

#include "persona.h"

typedef struct {
    persona miembro;
    boolean actualMonarca;
    boolean fueMonarca;
    boolean aspTrono;
    fecha fechAsc;
    boolean abdico;
    fecha fechAbd;
    boolean fallecio;
    fecha fechFall;
}datos;

// Cargar-Mostrar
void mostrarDatos(datos dat);
void mostrarMonarca(datos dat);

// Funcionalidades
persona darPersona(datos d);
boolean esMonarca(datos d);
boolean fueMonarca(datos d);
boolean aspirante(datos d);
fecha fehcaAsciende(datos d);
boolean abdica(datos d);
fecha fechaAbdica(datos d);
boolean fallece(datos d);
fecha fechaFallece(datos d);

// Archivos
void bajar(datos d, FILE *a);
void levantar(datos &d, FILE *a);

#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_DATOSSUCE_H
