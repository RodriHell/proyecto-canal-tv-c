# Administrador de Canal de TV (C)

Aplicación de consola desarrollada en C para gestionar la programación de un canal infantil, demostrando el manejo de estructuras de datos anidadas y gestión manual de memoria.

# Descripción
El programa permite administrar un Canal, sus Caricaturas asociadas y los Personajes de cada una. Permite dar de alta entidades, listarlas, realizar búsquedas y ordenamientos.

# Habilidades Técnicas Demostradas
* Structs Anidadas: Manejo de punteros a estructuras dentro de otras estructuras (`Canal` -> `Caricaturas` -> `Personajes`).
* Gestión de Memoria Dinámica: Uso correcto de `malloc`, `realloc` y `free` para evitar fugas de memoria (Memory Leaks).
* Modularidad: Código organizado en múltiples archivos (`.c` y `.h`) respetando el principio de ocultamiento de información.
* Algoritmos: Implementación de Bubble Sort para ordenar personajes por altura/nombre y Búsqueda Binaria para localización eficiente.
* Manejo de Arrays de Punteros: Uso de arrays estáticos de punteros para gestionar colecciones de datos.

# Compilación y Ejecución
El proyecto puede compilarse con GCC:

```bash
gcc main.c canaltv.c caricaturas.c personajes.c -o administrar_tv
./administrar_tv
