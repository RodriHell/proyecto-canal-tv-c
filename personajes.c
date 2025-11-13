#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personajes.h"

PersonajePtr crearPersonaje (char *nombre, char *tipo, float altura){
    PersonajePtr personaje = (PersonajePtr) malloc (sizeof(struct Personaje));
    if (personaje == NULL) {
        printf("Error: no se pudo asignar memoria para el personaje.\n");
        return NULL;
    }
    personaje->nombre = strdup(nombre);
    personaje->tipo = strdup(tipo);
    personaje->altura = altura;

    return personaje;
}

void mostrarPersonaje (PersonajePtr p){
    printf ("Nombre personaje: %s - Tipo: %s - Altura: %.2f",p->nombre, p->tipo, p->altura);
    printf ("\n");
}

void liberarPersonaje (PersonajePtr p){
    if (p != NULL){
        free (p->nombre);
        free (p->tipo);
        free (p);

    }
}
