/**
 * @file tiros.c
 *
 * @brief Juego de disparo con diana y grafico en caso de fallar
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-16
 *
 * @compile gcc -Wall -Werror  -g -o "%e" "%f" -lintro -ldibujo -lm libplot.a
 **/

#include "grafica_x_y.h"
#include "intro.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY      9.81
#define TARGETRADIUS 1.35
#define CENTERRADIUS 0.5
#define EASY         1
#define HARD         2
#define CONVERSION   3.60
#define STEP         0.3 // Pasos dibujo de diana

int main (void) {
    srand (clock());
    // Variables
    int difficulty;
    int shotNumber;
    int speed;
    int score;

    float targetHeight = 0.0;
    float targetDistance;
    float speedMs;
    float shotDistance;

    // User input
    printf ("Seleccione el nivel de difficultad de juego: (Facil => 1, Dificil => "
            "2):");
    difficulty = get_user_int();
    if (difficulty != EASY && difficulty != HARD) {
        printf ("Valor introducido erroneo \n ");
        return EXIT_FAILURE; // exit de libreria stdlib
    }

    // for para 3 tiros
    for (shotNumber = 1; shotNumber <= 3; shotNumber++) {
        targetDistance = (2000 + rand() % 1001) / 100.0;
        switch (difficulty) {
            case 1:
                targetHeight = 12.0;
                break;
            case 2:
                targetHeight = (2000 + rand() % 1001) / 100.0;
                break;
        }

        // speed check
        do {
            printf ("Estás a %.2f m de altura y la diana se encuentra a %.2f m.\n",
                    targetHeight, targetDistance);
            printf ("Introduzca la velocidad de disparo (km/h): ");
            speed = get_user_int();
        } while (speed < 2 || speed >= 70);
        speedMs = (float) speed / CONVERSION;
        shotDistance = speedMs * sqrtf ((2.0 * targetHeight) / GRAVITY);
        printf ("La velocidad del tiro en (m/s): %.2f\n", speedMs);

        // Algorithm
        score = 0;
        if (shotDistance >= targetDistance - CENTERRADIUS &&
            shotDistance <= targetDistance + CENTERRADIUS) {
            score = 3;
        }
        else if (shotDistance >= targetDistance - TARGETRADIUS &&
                 shotDistance <= targetDistance + TARGETRADIUS) {
            score = 1;
        }

        if (difficulty == 2) {
            score = score * 2;
        }

        if (score == 0) {
            printf ("El alcance del disparo a %.2f m/s es de %.2f m: "
                    "objetivo no alcanzado.\n",
                    speedMs, shotDistance);

            // Graph: trayectory
            pon_titulos ("Trayectoria del disparo", "x (m)", "y (m)");
            pon_leyenda ("Disparo");
            pon_estilo (ESTILO_LINEAS);
            for (int x = 0; x <= 25; x++) {
                float y = targetHeight - (1.0 / (2.0 * speedMs * speedMs)) * GRAVITY * x * x;
                inserta ((float) x, y);
            }

            // Graph: Diana
            otra_grafica();
            pon_leyenda ("Diana");
            pon_estilo (ESTILO_PUNTOS);
            float ini = targetDistance - TARGETRADIUS;
            float end = targetDistance + TARGETRADIUS;
            for (int i = 0; ini + i * STEP <= end; i++) {
                inserta (ini + i * STEP, 0.0);
            }

            pinta();
        }
        else {
            printf ("El alcance del disparo a %.2f m/s es de %.2f m: "
                    "objetivo alcanzado.\n",
                    speedMs, shotDistance);
            printf ("Has obtenido una puntuación de %d.\n", score);
        }

    }
    printf ("Has obtenido una puntuacion total de %d puntos \n", score);
    return EXIT_SUCCESS; // Exit libreria stdlib
}
