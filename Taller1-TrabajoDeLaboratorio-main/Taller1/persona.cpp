#include "persona.h"

// Selectoras
void mostrarPersona(persona p) {
    printf("\nEntre a mostrarPersona");
    printf("\n");
	print(p.nombre);
		if(p.primerMonarca)
			printf(" primer monarca");
		else {
			printf(" hijo/a de ");
			print(p.progenitor);
		}
	printf(" nacio el ");
	mostrar(p.nacimiento);
	printf("\n");
}
void darNombre(persona p, string &s) {
	strcop(s, p.nombre);
}
fecha darNacimiento(persona p) {
	return p.nacimiento;
}
boolean primerMonarca(persona p) {
	return p.primerMonarca;
}
void nombreProg(persona p, string &s) {
	strcop(s, p.progenitor);
}

// Archivos
void bajar(persona p, FILE *a) {
	bajar(p.nombre, a);
	bajar(p.nacimiento, a);
	fwrite(&p.primerMonarca, sizeof(boolean), 1, a);
	bajar(p.progenitor, a);
}
void levantar(persona &p, FILE *a) {
	levantar(p.nombre, a);
	levantar(p.nacimiento, a);
	fread(&p.primerMonarca, sizeof(boolean), 1, a);
	levantar(p.progenitor, a);
}
