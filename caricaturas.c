#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caricaturas.h"

CaricaturaPtr crearCaricatura (char *genero, char *nombre,char *paisDeOrigen){
    CaricaturaPtr c = (CaricaturaPtr) malloc (sizeof(struct Caricatura));
    if (c == NULL) {
        printf("Error: no se pudo asignar memoria para la caricatura.\n");
        return NULL;
    }
    c->genero = strdup (genero);
    c->nombre = strdup (nombre);
    c->paisDeOrigen = strdup (paisDeOrigen);

    inicializarPersonajes(c->p);

    return c;
}

void mostrarCaricatura (CaricaturaPtr c){
    printf ("GENERO: %s - NOMBRE CARICATURA: %s -  PAIS DE ORIGEN: %s",c->genero, c->nombre, c->paisDeOrigen);
    printf ("\n--------------------------------------------------------------------------------------------\n");
    mostrarPersonajes(c->p);
    printf ("\n\n");

}

void inicializarPersonajes (PersonajePtr p[]){
    for (int i= 0; i< TAM; i++){
        p[i] = NULL;
    }
}

void agregarPersonaje (CaricaturaPtr c, PersonajePtr p){
    for (int i=0; i<TAM; i++){
        if (c->p[i] == NULL){
            c->p[i] = p;
            return;
        }
    }
}

void mostrarPersonajes (PersonajePtr p[]){
    for (int i=0; i<TAM; i++){
        if (p[i] != NULL){
            mostrarPersonaje(p[i]);
        }
    }
}

void liberarPersonajes (CaricaturaPtr c){
    for (int i = 0; i < TAM; i++){
        liberarPersonaje(c->p[i]);
    }
}

void liberarCaricatura (CaricaturaPtr c){
    if (c != NULL){
        free (c->genero);
        free (c->nombre);
        free (c->paisDeOrigen);
        liberarPersonajes(c);
        free (c);
    }

}
