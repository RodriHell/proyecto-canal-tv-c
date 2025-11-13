#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED

struct Personaje {
    char *nombre;
    char *tipo;
    float altura;
};

typedef struct Personaje *PersonajePtr;

PersonajePtr crearPersonaje (char *nombre, char *tipo, float altura);
void mostrarPersonaje (PersonajePtr p);

///5- Eliminar los personajes que midan menos de 1, en ambas series.

void liberarPersonaje (PersonajePtr p);
#endif // PERSONAJES_H_INCLUDED
