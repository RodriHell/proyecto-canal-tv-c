/*
Se quiere crear un programa para administrar un Canal Infantil. Del canal nos interesa conocer el nombre, la web y su año de creación. El canal publica cerca de 100 caricaturas online.

De las Caricaturas se quiere guardar los datos de género, nombre y pais de origen.
Cada Caricatura tiene un array de Personajes, como maximo 10 personajes. De los Personajes interesa trabajar con nombre, tipo y altura.

1- Crear las siguientes caricaturas y agregarle estos personajes:
Caricatura:
-"Serie de TV", "Plim Plim", "Argentina"

Personajes:
- "Arafa", "Jirafa", 3.55
-"Acuarella", "Conejo", 0.45
-"Mei-Li", "Gato", 0.65
- "Hoggie", "Cerdo", 1.12
-"Wichiwi", "Pajaro", 0.22


Caricatura:
-"Serie animada", "Bluey", "Australiana"

Personajes:
- "Bluey", "Cachorra",0.95
-"Bingo", "Cachorra", 0.45
-"Bandit", "Perro",1.23
- "Chili", "Perra", 1.12

2- Agregar las caricaturas al Canal (Cartoon Network,www.cartoonnetwork.com,1992)
3- Mostrar el canal con sus caricaturas y personajes
4- Ordenar los personajes de la caricatura Bluey por altura y ordenar los personajes de Plim Plim por nombre.
5- Eliminar los personajes que midan menos de 1, en ambas series.
6- Buscar a Hoggie por medio de una busqueda binaria.
7- Crear un unico arreglo con todos los personajes y calcular el promedio de las alturas de los mismos.



NOTAS: Es obligatorio el uso de bibliotecas, el uso de punteros y manejo de la memoria, el programa debe funcionar y se debe realizar en menos de 2hs.
*/


#include <stdio.h>
#include <stdlib.h>
#include "personajes.h"
#include "caricaturas.h"
#include "canaltv.h"

int main()
{
    CaricaturaPtr c = crearCaricatura("Serie de TV", "Plim Plim", "Argentina");
    PersonajePtr p = crearPersonaje("Arafa", "Jirafa", 3.55);
    PersonajePtr p1 = crearPersonaje("Acuarella", "Conejo", 0.45);
    PersonajePtr p2 = crearPersonaje("Mei-Li", "Gato", 0.65);
    PersonajePtr p3 = crearPersonaje("Hoggie", "Cerdo", 1.12);
    PersonajePtr p4 = crearPersonaje("Wichiwi", "Pajaro", 0.22);

    agregarPersonaje(c, p);
    agregarPersonaje(c, p1);
    agregarPersonaje(c, p2);
    agregarPersonaje(c, p3);
    agregarPersonaje(c, p4);

    //mostrarCaricatura(c);

    CaricaturaPtr c1 = crearCaricatura("Serie animada", "Bluey", "Australiana");

    PersonajePtr p5 = crearPersonaje("Bluey", "Cachorra",0.95);
    PersonajePtr p6 = crearPersonaje("Bingo", "Cachorra", 0.45);
    PersonajePtr p7 = crearPersonaje("Bandit", "Perro",1.23);
    PersonajePtr p8 = crearPersonaje("Chili", "Perra", 1.12);

    agregarPersonaje(c1,p5);
    agregarPersonaje(c1,p6);
    agregarPersonaje(c1,p7);
    agregarPersonaje(c1,p8);
    mostrarCaricatura(c1);

    CanalPtr canal = crearCanal("Cartoon Network","www.cartoonnetwork.com",1992);

    agregarACanal(canal, c);
    agregarACanal(canal, c1);

    mostrarCanal(canal);

    ordenarPorAltura(c1);
    mostrarCanal(canal);

    ordenarPorNombre(c);
    mostrarCanal(canal);

    eliminarPersonajeAltura(c, 1.0);
    eliminarPersonajeAltura(c1, 1.0);
    mostrarCanal(canal);

    busquedaBinariaNombre(c, "Hoggie");

    PersonajePtr *vector = NULL;
    int totalPersonajes = 0;

    vector = personajes(canal, &totalPersonajes);

    mostrarVectorPersonajes(vector, totalPersonajes);

    return 0;
}
