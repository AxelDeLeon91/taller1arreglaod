#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_PERSONA_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_PERSONA_H

#include "string.h"
#include "fecha.h"

typedef struct {
    string nombre;
    fecha nacimiento;
    boolean primerMonarca;
    string progenitor;
}persona;

// Selectoras
void mostrarPersona(persona p);
void darNombre(persona p, string &s);
fecha darNacimiento(persona p);
boolean primerMonarca(persona p);
void nombreProg(persona p, string &s);

// Archivos
void bajar(persona p, FILE *a);
void levantar(persona &p, FILE *a);

#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_PERSONA_H
