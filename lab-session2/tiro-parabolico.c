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
    const int h = 12;
    const float kmhms = 3.6;
    const float g = 9.81;
    const float rad = 1.35;

    // Declaration of var
    srand (clock());
    int min = 10;
    int max = 20;
    float v;
    float vsi;                                       // User speed
    float Ldiana = min + (rand() % (max + 1 - min)); // Distancia a la diana (random)
    float ax;                                        // Alcance del tiro
    float mindiana = Ldiana - rad;
    float maxdiana = Ldiana + rad;

    // Get speed
    printf ("Estas a 12m de altura y la diana se encuentra a %f \n", Ldiana);
    printf ("introduzca la velocidad del disparo (km/h):");
    v = get_user_int();
    vsi = v / kmhms;
    printf ("la velocidad del disparo en S.I. es %f \n", vsi);

    // Calculation of shot and report
    ax = vsi * sqrt ((2 * h) / g);
    if (mindiana <= ax && maxdiana >= ax) { // Ax comprendido entre ldiana +- radio
        printf ("El alcance del disparo a %f es de %f : Objetivo alcanzado \n", vsi, ax);
    }

    else {
        printf ("El alcance del disparo a %f es de %f : Objetivo no alcanzado \n", vsi, ax);
    }

    return 0;
}
