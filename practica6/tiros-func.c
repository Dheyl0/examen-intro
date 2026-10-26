/**
 * @file tiros-func.c
 * @brief Juego de disparo a una diana con representación gráfica de los fallos.
 * @author Prisco González Fernández
 * @version 2026-10-20
 *
 * @compile gcc -Wall -Werror -g -o "%e" "%f" -lintro -ldibujo -lm libplot.a
 */

#include "grafica_x_y.h"
#include "intro.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY    9.81
#define EASY       1
#define HARD       2
#define CONVERSION 3.60

const float targetradius = 1.35;
const float step = 0.3;
const float centerradius = 0.5;

float generateRandomValue (int minrnd, int maxrnd);
int getScore (float targetHeight, float targetDistance, float targetradius, float speedMs,
              float centerradius);
void graph1 (float targetHeight, float targetDistance, float speedMs);
void graph2 (float targetDistance, float targetradius, float step);

/**
 * @brief Ejecuta una partida de tres tiros y muestra la puntuación total.
 *
 * @return EXIT_SUCCESS si la partida termina correctamente;
 *         EXIT_FAILURE si se introduce un nivel no válido.
 */
int main (void) {
    srand (clock());

    int difficulty;
    int shotNumber;
    int speed;
    int score;
    int totalScore = 0;
    int minrnd = 1000; // minima distancia diana
    int maxrnd = 2000; // max distancia diana

    float targetHeight = 0.0;
    float targetDistance;
    float speedMs;

    printf ("Seleccione el nivel de dificultad de juego: "
            "(Facil => 1, Dificil => 2): ");
    difficulty = get_user_int();

    if (difficulty != EASY && difficulty != HARD) {
        printf ("Valor introducido erroneo.\n");
        return EXIT_FAILURE;
    }

    // Tres tiros por partida
    for (shotNumber = 1; shotNumber <= 3; shotNumber++) {
        targetDistance = generateRandomValue (minrnd, maxrnd);

        switch (difficulty) {
            case EASY:
                targetHeight = 12.0;
                break;
            case HARD:
                targetHeight = generateRandomValue (minrnd, maxrnd);
                break;
        }

        do {
            printf ("Estas a %.2f m de altura y la diana se encuentra a %.2f m.\n",
                    targetHeight, targetDistance);
            printf ("Introduzca la velocidad de disparo (km/h): ");
            speed = get_user_int();
        } while (speed < 2 || speed >= 70);

        speedMs = (float) speed / CONVERSION;
        // Puntuacion
        score = getScore (targetHeight, targetDistance, targetradius, speedMs, centerradius);

        if (difficulty == HARD) {
            score *= 2;
        }

        if (score == 0) {
            graph1 (targetHeight, targetDistance, speedMs); // Añade lineas de alcance
            graph2 (targetDistance, targetradius, step);    // Añade puntos de la diana
            pinta();
            printf ("Has obtenido una puntuacion de %d puntos.\n", score);
        }
        else {
            printf ("Has obtenido una puntuacion de %d puntos.\n", score);
        }

        totalScore += score;
    }

    printf ("Has obtenido una puntuacion total de %d puntos.\n", totalScore);
    return EXIT_SUCCESS;
}

/**
 * @brief Genera un valor aleatorio dentro del intervalo indicado.
 *
 * @param minrnd Límite inferior del número aleatorio, en centésimas.
 * @param maxrnd Límite superior del número aleatorio, en centésimas.
 * @return Valor aleatorio convertido a punto flotante.
 */
float generateRandomValue (int minrnd, int maxrnd) {
    int random = minrnd + rand() % (maxrnd - minrnd + 1);
    return (float) random / 100.0;
}

/**
 * @brief Calcula la puntuación del disparo según su distancia a la diana.
 *
 * @param targetHeight Altura desde la que se realiza el disparo, en metros.
 * @param targetDistance Distancia horizontal hasta el centro de la diana, en metros.
 * @param targetradius Radio exterior de la diana, en metros.
 * @param speedMs Velocidad del disparo, en metros por segundo.
 * @param centerradius Radio de la zona central, en metros.
 * @return 3 puntos en el centro, 1 punto en la diana o 0 si falla.
 */
int getScore (float targetHeight, float targetDistance, float targetradius, float speedMs,
              float centerradius) {
    float shotDistance = speedMs * sqrtf ((2.0f * targetHeight) / GRAVITY);
    float distanceFromCenter = fabsf (shotDistance - targetDistance);

    if (distanceFromCenter <= centerradius) {
        return 3;
    }
    else if (distanceFromCenter <= targetradius) {
        return 1;
    }
    return 0;
}

/**
 * @brief Dibuja la trayectoria del disparo.
 *
 * @param targetHeight Altura inicial del disparo, en metros.
 * @param targetDistance Distancia horizontal hasta la diana, en metros.
 * @param speedMs Velocidad del disparo, en metros por segundo.
 */
void graph1 (float targetHeight, float targetDistance, float speedMs) {
    pon_titulos ("Trayectoria del disparo", "x (m)", "y (m)");
    pon_leyenda ("Disparo");
    pon_estilo (ESTILO_LINEAS);

    for (int x = 0; x <= 25; x++) {
        float y = targetHeight - (GRAVITY * x * x) / (2.0f * speedMs * speedMs);
        inserta ((float) x, y);
    }
}

/**
 * @brief Dibuja la diana como una serie de puntos sobre el eje horizontal.
 *
 * @param targetDistance Distancia hasta el centro de la diana, en metros.
 * @param targetradius Radio de la diana, en metros.
 * @param step Separación entre los puntos dibujados, en metros.
 */
void graph2 (float targetDistance, float targetradius, float step) {
    otra_grafica();
    pon_leyenda ("Diana");
    pon_estilo (ESTILO_PUNTOS);

    float ini = targetDistance - targetradius;
    float end = targetDistance + targetradius;

    for (float x = ini; x <= end; x += step) { // Step distancia de punto a punto
        inserta (x, 0.0);
    }
}
