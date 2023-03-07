#include <stdio.h>
#include "fecha.h"

// Selectoras
int darDia(fecha f) {
    return f.dia;
}
int darMes(fecha f) {
    return f.mes;
}
int darAnio(fecha f) {
    return f.anio;
}

// Cargar - Mostrar
void cargar(fecha &f) {
    printf("Ingrese el dia: ");
        scanf("%d", &f.dia);
    printf("Ingrese el mes: ");
        scanf("%d", &f.mes);
    printf("Ingrese el anio: ");
        scanf("%d", &f.anio);
}
void mostrar(fecha f) {
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

// Funcionalidades
fecha stringFecha(string strF) {
    fecha f;
    int i = 0;
    f.dia = 0;
    while (strF[i] != '/') {
        f.dia = f.dia * 10 + (strF[i] - '0');
        i++;
    }
    i++;
    f.mes = 0;
    while (strF[i] != '/') {
        f.mes = f.mes * 10 + (strF[i] - '0');
        i++;
    }
    i++;
    f.anio = 0;
    while (strF[i] != '\0') {
        f.anio = f.anio * 10 + (strF[i] - '0');
        i++;
    }
    return f;
}
boolean menor(fecha f, fecha g) {
    boolean es = FALSE;
        if(f.anio < g.anio)
            es = TRUE;
        else {
            if(f.anio == g.anio) {
                if(f.mes < g.mes)
                    es = TRUE;
                else {
                    if(f.mes == g.mes) {
                        if(f.dia <= g.dia)
                            es = TRUE;
                    }
                }
            }
        }
    return es;
}
boolean iguales(fecha f, fecha g) {
    boolean iguales = FALSE;
        if(f.anio == g.anio && f.mes == g.mes && f.dia == g.dia)
            iguales = TRUE;
    return iguales;
}
boolean valida(fecha f) {
    boolean valida = FALSE;
        switch(f.mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(f.dia > 0 && f.dia <= 30)
                    valida = TRUE;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(f.dia > 0 && f.dia <= 31)
                    valida = TRUE;
                break;
            case 2:
                if(f.dia > 0 && f.dia <= 28)
                    valida = TRUE;
                else if(f.anio % 4 == 0 && f.dia == 29)
                    valida = TRUE;
                break;
            default:
                break;
        }
    return valida;
}


fecha fechaNula() {
    fecha f;
    f.dia = 0;
    f.mes = 0;
    f.anio = 0;
    return f;
}

// Archivos
void bajar(fecha e, FILE *a) {
    fwrite(&e.dia, sizeof(int), 1, a);
    fwrite(&e.mes, sizeof(int), 1, a);
    fwrite(&e.anio, sizeof(int), 1, a);
}
void levantar(fecha &e, FILE *a) {
    fread(&e.dia, sizeof(int), 1, a);
    fread(&e.mes, sizeof(int), 1, a);
    fread(&e.anio, sizeof(int), 1, a);
}
