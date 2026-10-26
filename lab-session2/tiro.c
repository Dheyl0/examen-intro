/**
 * @file tiro-parabolico.c
 *
 * @brief practica3
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-09-29
 *
 **/

#include "intro.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    // const
    const float kmhms = 3.6;
    const float g = 9.81;
    const float rad = 1.35;
    const float crad = 0.50;

    // Declaration of var
    srand (clock());
    int min = 1000;
    int max = 2000;
    int punctuation;
    int difficulty;
    int shot_number;
    float velocitty;
    float SIvelocitty;                                                    // User speed
    float Ldiana = (float) (min + (rand() % (max + 1 - min))) / 100.0;    // Distancia a la diana (random)
    float Ydiana;                                                         // Altura diana
    float shot_distance;                                                  // Alcance del tiro
    float mincentrodiana = Ldiana - crad;
    float maxcentrodiana = Ldiana + crad;
    float mindiana = Ldiana - rad;
    float maxdiana = Ldiana + rad;


    // Get user desired difficulty
    printf ("Seleccione el nivel de difficultad de juego: Facil => 1, Dificil => 2 :");
    difficulty = get_user_int ();

    do {
    switch (difficulty) {
        case 1:
            Ydiana = 12.0;
            break;
        case 2:
            Ydiana = (float) (min + (rand() % (max + 1 - min))) / 100.0;   // Altura diana (only difficult level);
            break;
        default:
            printf ("Valor introducido no valido \n ");
            return 1;
    }

    // Get speed
    do {
        printf ("Estás a %.2f m de altura y la diana se encuentra a %.2f m.\n", Ydiana, Ldiana);
        printf ("Introduzca la velocidad del disparo (km/h): ");
        velocitty = get_user_int();

        if (velocitty < 2 || velocitty > 70) {
            printf ("Velocidad inválida. Introduzca una nueva.\n");
        }
    }
    while (velocitty < 2 || velocitty > 70);
    SIvelocitty = velocitty / kmhms;
    printf ("La velocidad del disparo en S.I. es %.2f m/s.\n", SIvelocitty);

    // Calculation of shot and report
    shot_distance = SIvelocitty * sqrt ((2 * Ydiana) / g);
    if (mincentrodiana <= shot_distance && maxcentrodiana >= shot_distance) { // Ax comprendido entre ldiana +- radio
        printf ("El alcance del disparo a %.2f m/s es de %.2f m : Objetivo alcanzado \n", SIvelocitty, shot_distance);
         punctuation = 3;
        if (difficulty == 2) {
            punctuation = punctuation * 2;
        }
        printf (" Has obtenido una puntuacion de %d \n ", punctuation);
    }
    else if (mindiana <= shot_distance && maxdiana >= shot_distance) { // Ax comprendido entre ldiana +- radio
        printf ("El alcance del disparo a %.2f m/s es de %.2f  m: Objetivo alcanzado \n", SIvelocitty, shot_distance);
         punctuation = 1;
        if (difficulty == 2) {
            punctuation = punctuation * 2;
        }
            printf (" Has obtenido una puntuacion de %d \n ", punctuation);
    }
    else {
        printf ("El alcance del disparo a %.2f m/s es de %.2f m : Objetivo no alcanzado \n", SIvelocitty, shot_distance);
    }
    shot_number  = shot_number + 1;

 } while (shot_number != 3);
    return 0;
}
