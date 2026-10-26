/**
 * @file penalti.c
 *
 * @brief gambling
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-10
 *
 * @compile gcc -Wall -Werror -o "%e" "%f" -lintro
 *
 **/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intro.h"

#define MAXBET 12.0 // apuesta maxima

int main (void) {
    srand (clock());
    // Variable declare
    float player_bet;
    int penalty;
    int goalkeeper;
    int scored_penalties = 0;

    printf ("Introduzca la cantidad que desea apostar: ");
    player_bet = get_user_float();

    // Error handling
    if (player_bet <= 0.0 || player_bet > MAXBET) {
        return EXIT_FAILURE;
    }

    do { // Algorithm: 3 tiros, exit en caso de fallar el penalti
        printf ("Introduzca la zona donde quiere tirar el penalti (0-4): ");
        penalty = get_user_int();

        if (penalty < 0 || penalty > 4) {
            return EXIT_FAILURE;
        }

        goalkeeper = rand() % 5;

        if (penalty != goalkeeper) {
            scored_penalties++;
            printf ("Penalti acertado\n");
        }
        else {
            printf ("Penalti fallado\n");
            printf ("Has perdido todo tu dinero\n");
            return EXIT_SUCCESS;
        }

    } while (scored_penalties < 3);

    player_bet += player_bet / 4.0;
    printf ("Has ganado %f dinero\n", player_bet);

    return EXIT_SUCCESS;
}
