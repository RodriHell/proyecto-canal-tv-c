#ifndef CANALTV_H_INCLUDED
#define CANALTV_H_INCLUDED

#include "caricaturas.h"

#define MAX 100

struct Canal {
    char *nombre;
    char *web;
    int anioCreacion;

    CaricaturaPtr caricatura [MAX];
};

typedef struct Canal *CanalPtr;

CanalPtr crearCanal (char *nombre, char *web, int anioCreacion);

void mostrarCanal (CanalPtr canal);

void inicializarCaricaturas (CaricaturaPtr c[]);

void agregarACanal (CanalPtr canal, CaricaturaPtr caricatura);

///4- Ordenar los personajes de la caricatura Bluey por altura y ordenar los personajes de Plim Plim por nombre.
void ordenarPorAltura (CaricaturaPtr c);
void ordenarPorNombre (CaricaturaPtr c);
void eliminarPersonajeAltura (CaricaturaPtr c, float altura);

int busquedaBinariaNombre (CaricaturaPtr c, char *nombre);

int cantidad (PersonajePtr p[]);
int cantidadCaricaturas (CanalPtr c);


PersonajePtr * personajes (CanalPtr canal, int *totalPersonajes);

void mostrarVectorPersonajes (PersonajePtr personajes[], int total);


///DESTRUCTOR
void liberarCanal (CanalPtr canal);

#endif // CANALTV_H_INCLUDED
