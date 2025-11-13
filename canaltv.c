#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canaltv.h"


CanalPtr crearCanal (char *nombre, char *web, int anioCreacion){
    CanalPtr c = (CanalPtr) malloc (sizeof (struct Canal));
    if (c == NULL) {
        printf("Error: no se pudo asignar memoria para el canal.\n");
        return NULL;
    }

    c->nombre = strdup (nombre);
    c->web = strdup (web);
    c->anioCreacion = anioCreacion;
    inicializarCaricaturas (c->caricatura);

    return c;
}

void mostrarCanal (CanalPtr canal){
    printf ("%s ,%s, %d", canal->nombre, canal->web, canal->anioCreacion);
    printf ("\n");
    for (int i=0; i<MAX; i++){
        if (canal->caricatura[i] != NULL){
            mostrarCaricatura(canal->caricatura[i]);
        }
    }
}

void inicializarCaricaturas (CaricaturaPtr c[]){
    for (int i=0; i<MAX; i++){
        c[i] = NULL;
    }
}

void agregarACanal (CanalPtr canal, CaricaturaPtr caricatura){
    for (int i=0; i<MAX; i++){
        if (canal->caricatura[i] == NULL){
            canal->caricatura[i] = caricatura;
            return;
        }
    }
}
void ordenarPorAltura (CaricaturaPtr c){
    for (int i = 0; i<TAM; i++){
        for (int j = 0; j<TAM - i - 1; j++){
            if (c->p[j] != NULL && c->p[j+1] != NULL){
                if (c->p[j]->altura < c->p[j+1]->altura){
                    PersonajePtr aux;
                    aux = c->p[j];
                    c->p[j] = c->p[j+1];
                    c->p[j+1] = aux;
                }
            }
        }
    }
}

void ordenarPorNombre (CaricaturaPtr c){
    for (int i = 0; i<TAM; i++){
        for (int j = 0; j<TAM - i - 1; j++){
            if (c->p[j] != NULL && c->p[j+1] != NULL){
                if (strcmp(c->p[j]->nombre, c->p[j+1]->nombre) > 0){
                    PersonajePtr aux;
                    aux = c->p[j];
                    c->p[j] = c->p[j+1];
                    c->p[j+1] = aux;
                }
            }
        }

    }
}

void eliminarPersonajeAltura (CaricaturaPtr c, float altura){
    int posEscritura = 0;
    for (int i=0; i<TAM && c->p[i] != NULL; i++){

        PersonajePtr actual = c->p[i];

        if (actual->altura >= altura){
            c->p[posEscritura] = actual;
            posEscritura++;
        }
        else {
            liberarPersonaje(actual);
        }
    }
    if (posEscritura < TAM){
        c->p[posEscritura] = NULL;
    }
    printf ("\nPersonajes liberados.\n\n");
}

int busquedaBinariaNombre (CaricaturaPtr c, char *nombre){
    int izq = 0;
    int der = (cantidad(c->p)) - 1;
    int medio = (izq + der) / 2;

    while (izq <= der){
        if (strcmp (c->p[medio]->nombre, nombre)== 0){
            printf ("Personaje encontrado en:%d \n\n", medio);
            return medio;
        }
        if (strcmp (c->p[medio]->nombre, nombre) > 0 ){
            der = medio - 1;
        }
        else {
            izq = medio + 1;
        }
        medio = (izq + der) / 2;
    }
    printf ("Personaje no encontrado.\n\n");
    return -1;
}

int cantidad (PersonajePtr p[]){
    int i = 0;
    while (i < TAM && p[i] != NULL){
        i++;
    }
    return i;
}

int cantidadCaricaturas (CanalPtr c){
    int i = 0;
    while ( i < MAX && c->caricatura[i] != NULL){
        i++;
    }
    return i;
}

PersonajePtr * personajes (CanalPtr canal, int *totalPersonajes){
    int total = 0;
    int cantCaricaturas = cantidadCaricaturas (canal);

    for (int i = 0; i < cantCaricaturas; i++){
        total += cantidad(canal->caricatura[i]->p);
    }

    *totalPersonajes = total;
     PersonajePtr *vector = malloc(total * sizeof(PersonajePtr));

     if (vector == NULL){
        *totalPersonajes = 0;
        return NULL;
     }

     int pos = 0;

     for (int i = 0; i<cantCaricaturas; i++){
        CaricaturaPtr c = canal->caricatura[i];
        int cantidadEstaCaricatura = cantidad(c->p);

        for (int j = 0; j < cantidadEstaCaricatura; j++){
            vector[pos] = c->p[j];
            pos++;
        }
     }

     return vector;
}

void mostrarVectorPersonajes (PersonajePtr personajes[], int total){
    for (int i = 0; i<total; i++){
        printf ("Personaje: %s - Altura: %0.2f - Tipo: %s \n", personajes[i]->nombre, personajes[i]->altura, personajes[i]->tipo);
    }
}

void liberarCanal (CanalPtr canal){
    for (int i = 0; i < MAX; i++){
        liberarCaricatura(canal->caricatura[i]);
    }
    free (canal->nombre);
    free (canal->web);
    free (canal);
}
