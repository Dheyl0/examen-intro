/**
 * @file ejemplo_grafica_avanzada.c
 *
 * @brief Ejemplo de una gráfica usando la interfaz avanzada de la librería
 *
 * Se hace una gráfica de las funciones seno y coseno en la misma ventana
 * Además, se hace una gráfica de la función raíz cuadrada en otra ventana
 *
 * @author  Intro_SW <>
 * @version 2025-10-11
 *
 **/

#include <math.h>
#include "grafica_x_y.h"

int main (void) {

    pon_titulos ("Seno y Coseno", "x", "y");
    // El primer gráfico
    pon_leyenda ("Seno");
    pon_estilo (ESTILO_LINEAS);
    // Ángulos desde 0 a 3*PI con incremento de PI/16
    for (float x1 = 0.0; x1 <= M_PI * 3.0; x1 = x1 + M_PI / 16.0) {
        inserta (x1, sin (x1));
    }

    // El segundo gráfico
    otra_grafica();
    pon_leyenda ("Coseno");
    pon_estilo (ESTILO_PUNTOS);
    float x2;
    // Ángulos desde 0 a 10 radianes con incremento
    // de 0.1 radianes
    for (int i = 0; i <= 100; i++) {
        x2 = i / 10.0;
        inserta (x2, cos (x2));
    }
    pinta();

    // Ahora pintamos una tercera gráfica en una ventana aparte
    // Siempre que se usa el "pinta()" se cambia de ventana
    pon_titulos ("Raíz Cuadrada", "x", "raíz");
    // Números de 0 a 64
    for (int x = 0; x <= 64; x++) {
        inserta (x, sqrt (x));
    }
    pinta();

    return 0;
}

