#ifndef TALLER1_AXELDELEON_IGNACIOPERCIATNE_PARSING_H
#define TALLER1_AXELDELEON_IGNACIOPERCIATNE_PARSING_H

#include "arbolPersonas.h"
#include "listaSuc.h"
#include "listaStr.h"
#include "comando.h"
#include "error.h"

boolean verificarComando(listaStr str, comando com, arbol abb,listaSuc lsuc);
void mostrarError(listaStr str, comando com, arbol abb,listaSuc lsuc);
comando reconocerCom(string s);
void iniciar(arbol &a, listaSuc &ls, listaStr &lstr);
void nacimiento(arbol &a, listaSuc &ls, listaStr &lstr);
void fallecimiento(listaSuc &ls, listaStr lstr);
void abdicacion(listaSuc &ls, listaStr &lstr);
void miembros(arbol a);
void monarcas(listaSuc ls);
void aspirantes(listaSuc ls);
void historial(listaSuc ls);

#endif //TALLER1_AXELDELEON_IGNACIOPERCIATNE_PARSING_H
