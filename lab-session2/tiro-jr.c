/**
 * @file tiro-jr.c
 *
 * @brief TODO
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-14
 *
 **/

#include "intro.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int difficulty;
    int shotNumber;
    int speed;
    int score;
    int randomValue;

    float targetHeight;
    float targetDistance;
    float speedMs;
    float shotDistance;

    const float gravity = 9.81f;
    const float targetRadius = 1.35f;
    const float centerRadius = 0.50f;

    printf("Seleccione el nivel de dificultad: Fácil => 1, Difícil => 2: ");
    difficulty = get_user_int();

    if (difficulty != 1 && difficulty != 2) {
        printf("Valor introducido no válido.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    if (difficulty == 1) {
        targetHeight = 12.0f;
    } else {
        randomValue = 1000 + rand() % 1001;
        targetHeight = randomValue / 100.0f;
    }

    for (shotNumber = 1; shotNumber <= 3; shotNumber++) {
        randomValue = 1000 + rand() % 1001;
        targetDistance = randomValue / 100.0f;

        printf("\nTiro %d de 3\n", shotNumber);
        printf("Estás a %.2f m de altura y la diana se encuentra a %.2f m.\n",
               targetHeight, targetDistance);

        do {
            printf("Introduzca la velocidad del disparo (km/h): ");
            speed = get_user_int();

            if (speed < 2 || speed > 70) {
                printf("Velocidad inválida. Introduzca un valor entre 2 y 70.\n");
            }
        } while (speed < 2 || speed > 70);

        speedMs = speed / 3.6f;
        shotDistance = speedMs * sqrtf((2.0f * targetHeight) / gravity);

        printf("La velocidad del disparo en S.I. es %.2f m/s.\n", speedMs);

        score = 0;

        if (shotDistance >= targetDistance - centerRadius &&
            shotDistance <= targetDistance + centerRadius) {
            score = 3;
        } else if (shotDistance >= targetDistance - targetRadius &&
                   shotDistance <= targetDistance + targetRadius) {
            score = 1;
        }

        if (difficulty == 2) {
            score = score * 2;
        }

        if (score == 0) {
            printf("El alcance del disparo a %.2f m/s es de %.2f m: "
                   "objetivo no alcanzado.\n",
                   speedMs, shotDistance);
        } else {
            printf("El alcance del disparo a %.2f m/s es de %.2f m: "
                   "objetivo alcanzado.\n",
                   speedMs, shotDistance);
            printf("Has obtenido una puntuación de %d.\n", score);
        }
    }

    return 0;
}
