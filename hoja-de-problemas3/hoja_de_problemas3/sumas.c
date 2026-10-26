/**
 * @file sumas.c
 *
 * @brief blackjack
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-10
 *
 * @compile gcc -Wall -Werror -o "%e" "%f" -lintro
 *
 **/

// No se porque el is_style lee el archivo como dos chunks de codigo muy separado

#include "intro.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXPOINT 21

int main (void) {
  // Var delcaration
  int points = 0;
  int get_input;
  int card;
  int casino_points = 0;

  printf ("Bienvenido a blackjack\n");
  srand(clock());

  // Algorithm
  do {
    printf ("Tu puntuación actual es %d. Elige una opción (1-Carta, 2-Plantarse): ",points);
    get_input = get_user_int();

    // input error handling
    if (get_input != 1 && get_input != 2) {
      printf ("Opción no válida.\n");
      return EXIT_FAILURE;
    }

    if (get_input == 1) {
      card = 1 + rand() % 10;
      points += card;
      printf ("Has sacado un %d. Total: %d\n", card, points);

      // Si se pasa de 21 se acaba el programa aqui
      if (points > MAXPOINT) {
        printf ("Te has pasado.\n");
        return EXIT_SUCCESS;
      }
    }
  } while (get_input == 1); // Mientras el usuario pida cartas

  casino_points = 12 + rand() % 10;
  printf("Puntuaciones ===> Jugador: %d - Casino: %d\n", points, casino_points);

  if (points <= MAXPOINT && points > casino_points) {
    printf ("*** El jugador ganó la partida ***\n");
  } else {
    printf ("*** El jugador perdió la partida ***\n");
  }

  return EXIT_SUCCESS;
}
