#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_STRING_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_STRING_H

#include "boolean.h"

const int MAX = 80;
typedef char *string;

void strcrear(string &s);
void strdestruir(string &s);
int strlar(string s);
void strcop(string &s1, string s2);
void scan(string &s);
void strcon(string &s1, string s2);
void strswp(string &s1, string &s2);
void print(string s);
boolean strmen(string s1, string s2); // prim < segun
boolean streq(string s1, string s2);


// Funcionalidades
void mayus(string &S);
boolean alfabetico(string s);

// Archivos
void bajar(string s, FILE *a);
void levantar(string &s, FILE *a);

#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_STRING_H
