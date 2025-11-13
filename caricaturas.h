#ifndef CARICATURAS_H_INCLUDED
#define CARICATURAS_H_INCLUDED

#include "personajes.h"

#define TAM 10

struct Caricatura {
    char *genero;
    char *nombre;
    char *paisDeOrigen;

    PersonajePtr p [TAM];
};

typedef struct Caricatura *CaricaturaPtr;

CaricaturaPtr crearCaricatura (char *genero, char *nombre,char *paisDeOrigen);

void mostrarCaricatura (CaricaturaPtr c);

void inicializarPersonajes (PersonajePtr p[]);

void agregarPersonaje (CaricaturaPtr c, PersonajePtr p);
void mostrarPersonajes (PersonajePtr p[]);
///DESTRUCTOR
void liberarPersonajes (CaricaturaPtr c);
void liberarCaricatura(CaricaturaPtr c);

#endif // CARICATURAS_H_INCLUDED
