/**
 * @file ejemplo_grafica_simple.c
 *
 * @brief Ejemplo de una gráfica usando la interfaz básica de la librería
 *
 * Se hace una gráfica de la raíz cuadrada de algunos números
 *
 * @author  Intro_SW <>
 * @version 2025-10-11
 *
 **/

#include <math.h>
#include "grafica_x_y.h"

int main (void) {
    // Insertar los puntos en la gráfica
    inserta (0.0, sqrt (0.0));
    inserta (2.0, sqrt (2.0));
    inserta (8.0, sqrt (8.0));
    inserta (64.0, sqrt (32.0));

    // Pintar la gráfica y acabar
    pinta();
    return 0;
}

