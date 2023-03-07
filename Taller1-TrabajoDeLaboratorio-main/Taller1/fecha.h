#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_FECHA_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_FECHA_H

#include "boolean.h"
#include "string.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} fecha;

// Selectoras
int darDia(fecha f);
int darMes(fecha f);
int darAnio(fecha f);

// Cargar - Mostrar
void cargar(fecha &f);
void mostrar(fecha f);

// Funcionalidades
fecha stringFecha(string s);
boolean menor(fecha f, fecha g); // Si f < g
boolean iguales(fecha f, fecha g);
boolean valida(fecha f);
fecha fechaNula();

// Archivos
void bajar(fecha e, FILE *a);
void levantar(fecha &e, FILE *a);

#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_FECHA_H
