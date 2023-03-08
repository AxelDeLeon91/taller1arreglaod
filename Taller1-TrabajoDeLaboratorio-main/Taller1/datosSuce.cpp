#include "datosSuce.h"

// Cargar-Mostrar
void mostrarDatos(datos dat) {
    print(dat.miembro.nombre);

    if(primerMonarca(dat.miembro)==TRUE) {
        printf(" primer monarca ");
    } else {
        printf(" hijo/a de ");
        print(dat.miembro.progenitor);
    }
    if(fueMonarca(dat)==TRUE) {
        printf("\n     Monarca desde el ");
        mostrar(dat.fechAsc);
        printf(" hasta ");
        if(abdica(dat)==TRUE) {
            mostrar(dat.fechAbd);
            printf(" (abdico)");
        } else
            if(fallece(dat)==TRUE) {
                mostrar(dat.fechFall);
                printf(" (fallecio)");
            } else
                printf("la actualidad");
    } else
        if(fallece(dat)==TRUE) {
            printf(" fallecio el ");
            mostrar(dat.fechFall);
        } else
            if(aspirante(dat)==TRUE) {
                printf("\n      Aspirante al trono");
            } else
                if(abdica(dat)==TRUE) {
                    printf(" \n     No es aspirante, abdico el ");
                    mostrar(dat.fechAbd);
                }
}

void mostrarMonarca(datos dat){
    print(dat.miembro.nombre);
    printf(" desde el ");
    mostrar(dat.fechAsc);

    if(fallece(dat)==TRUE){
        printf(" hasta el ");
        mostrar(dat.fechFall);
        printf("    Razon: fallecio");
        }
    else
        if(abdica(dat)==TRUE){
            printf(" hasta el ");
            mostrar(dat.fechAbd);
            printf("    Razon: abdico");
            }
        else
            printf(" hasta la actualidad");
}


// Funcionalidades
persona darPersona(datos d) {
	return d.miembro;
}
boolean esMonarca(datos d) {
	return d.actualMonarca;
}
boolean fueMonarca(datos d) {
	return d.fueMonarca;
}
boolean aspirante(datos d) {
	return d.aspTrono;
}
fecha fehcaAsciende(datos d) {
	return d.fechAsc;
}
boolean abdica(datos d) {
	return d.abdico;
}
fecha fechaAbdica(datos d) {
	return d.fechAbd;
}
boolean fallece(datos d) {
	return d.fallecio;
}
fecha fechaFallece(datos d) {
	return d.fechFall;
}

// Archivos
void bajar(datos d, FILE *a) {
    bajar(d.miembro, a);
    fwrite(&d.actualMonarca, sizeof(boolean), 1, a);
    fwrite(&d.fueMonarca, sizeof(boolean), 1, a);
    fwrite(&d.aspTrono, sizeof(boolean), 1, a);
    bajar(d.fechAsc, a);
    fwrite(&d.abdico, sizeof(boolean), 1, a);
    bajar(d.fechAbd, a);
    fwrite(&d.fallecio, sizeof(boolean), 1, a);
    bajar(d.fechFall, a);
}
void levantar(datos &d, FILE *a) {
    levantar(d.miembro, a);
    fread(&d.actualMonarca, sizeof(boolean), 1, a);
    fread(&d.fueMonarca, sizeof(boolean), 1, a);
    fread(&d.aspTrono, sizeof(boolean), 1, a);
    levantar(d.fechAsc, a);
    fread(&d.abdico, sizeof(boolean), 1, a);
    levantar(d.fechAbd, a);
    fread(&d.fallecio, sizeof(boolean), 1, a);
    levantar(d.fechFall, a);
}
