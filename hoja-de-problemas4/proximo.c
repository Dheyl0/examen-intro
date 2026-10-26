/**
 * @file proximo.c
 *
 * @brief print proximidad a jugador
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-17
 *
 *@compile gcc -Wall -Werror -o proximo proximo.c -lm -lintro libequipos.a
 **/
#include "equipos.h"
#include "intro.h"
#include <math.h>
#include <stdio.h>

float distancia_jugador (int x1, int y1, int x2, int y2);

int main (void) {
    int id; // id del player
    int i;  // int del contador
    int equipo;
    int mejor_id = -1; // id del compañero más cercano
    float mejor_dist = 0.0f;
    float d; // Distancia real

    printf ("Introduzca el id de su jugador: ");
    id = get_user_int();

    if (id < 1 || id > MAX_JUGADOR_ID) {
        printf ("Error: el identificador debe estar en el rango [1, %d]\n", MAX_JUGADOR_ID);
        return 1;
    }

    equipo = obten_equipo (id);

    for (i = 1; i <= MAX_JUGADOR_ID; i++) {        // checkqueo jugador por jugador
        if (i == id || obten_equipo (i) != equipo) // descarta a si mismo y a otros equipos
            continue;

        d = distancia_jugador (obten_coordx (id), obten_coordy (id), obten_coordx (i),
                               obten_coordy (i)); // Distancia utilizando funcion

        if (mejor_id == -1 || d < mejor_dist) {
            mejor_id = i;
            mejor_dist = d;
        }
    }

    if (mejor_id == -1) {
        printf ("No hay otros jugadores en su equipo\n");
        return 1;
    }

    printf ("El jugador más próximo de su equipo es el id=%d y está a %.1f m\n", mejor_id,
            mejor_dist);

    return 0;
}

/**
 * @brief obten distancia
 * @param x1 distancia
 * @param y1 distancia
 * @param x2 distancia
 * @param y2 distancia
 * @return distancia total
 */
float distancia_jugador (int x1, int y1, int x2, int y2) {
    float dx = (float) (x1 - x2);
    float dy = (float) (y1 - y2);

    return sqrtf (dx * dx + dy * dy);
}
