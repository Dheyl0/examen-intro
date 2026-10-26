/**
 * @file tiro-parabolico.c
 *
 * @brief practica3
 *
 * @author Prisco González Fernández <pgf81@proton.me>
 * @version 2026-09-29
 */

#include "intro.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY       9.81f
#define KMH_TO_MS     3.6f
#define TARGET_RADIUS 1.35f
#define CENTER_RADIUS 0.50f
#define MIN_SPEED     2
#define MAX_SPEED     70
#define SHOT_COUNT    3

static float random_distance(void)
{
    const int min_centi = 1000;
    const int max_centi = 2000;
    const int value = min_centi + rand() % (max_centi - min_centi + 1);

    return value / 100.0f;
}

static int get_difficulty(void)
{
    int difficulty;

    printf("Seleccione el nivel de dificultad: Fácil => 1, Difícil => 2: ");
    difficulty = get_user_int();

    if (difficulty != 1 && difficulty != 2) {
        printf("Valor introducido no válido.\n");
        return 0;
    }

    return difficulty;
}

static float get_valid_speed(void)
{
    int speed;

    do {
        printf("Introduzca la velocidad del disparo (km/h): ");
        speed = get_user_int();

        if (speed < MIN_SPEED || speed > MAX_SPEED) {
            printf("Velocidad inválida. Introduzca un valor entre %d y %d.\n",
                   MIN_SPEED, MAX_SPEED);
        }
    } while (speed < MIN_SPEED || speed > MAX_SPEED);

    return (float)speed;
}

static float calculate_range(float speed_ms, float target_height)
{
    return speed_ms * sqrtf((2.0f * target_height) / GRAVITY);
}

static int calculate_score(float shot_distance, float target_distance,
                           int difficulty)
{
    const float center_min = target_distance - CENTER_RADIUS;
    const float center_max = target_distance + CENTER_RADIUS;
    const float target_min = target_distance - TARGET_RADIUS;
    const float target_max = target_distance + TARGET_RADIUS;
    int score = 0;

    if (shot_distance >= center_min && shot_distance <= center_max) {
        score = 3;
    } else if (shot_distance >= target_min && shot_distance <= target_max) {
        score = 1;
    }

    if (difficulty == 2) {
        score *= 2;
    }

    return score;
}

static void report_shot(float speed_ms, float shot_distance,
                        float target_distance, int difficulty)
{
    const int score = calculate_score(
        shot_distance, target_distance, difficulty
    );

    if (score == 0) {
        printf("El alcance del disparo a %.2f m/s es de %.2f m: "
               "objetivo no alcanzado.\n",
               speed_ms, shot_distance);
        return;
    }

    printf("El alcance del disparo a %.2f m/s es de %.2f m: "
           "objetivo alcanzado.\n",
           speed_ms, shot_distance);
    printf("Has obtenido una puntuación de %d.\n", score);
}

int main(void)
{
    const int difficulty = get_difficulty();
    float target_height;
    int shot_number;

    if (difficulty == 0) {
        return 1;
    }

    srand((unsigned int)time(NULL));

    target_height = (difficulty == 1) ? 12.0f : random_distance();

    for (shot_number = 1; shot_number <= SHOT_COUNT; shot_number++) {
        const float target_distance = random_distance();

        printf("\nTiro %d de %d\n", shot_number, SHOT_COUNT);
        printf("Estás a %.2f m de altura y la diana se encuentra a %.2f m.\n",
               target_height, target_distance);

        const float speed_kmh = get_valid_speed();
        const float speed_ms = speed_kmh / KMH_TO_MS;
        const float shot_distance = calculate_range(speed_ms, target_height);

        printf("La velocidad del disparo en S.I. es %.2f m/s.\n", speed_ms);
        report_shot(speed_ms, shot_distance, target_distance, difficulty);
    }

    return 0;
}
