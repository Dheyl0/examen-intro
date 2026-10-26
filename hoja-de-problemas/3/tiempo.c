/**
 * @file TODO
 *
 * @brief TODO
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-09-29
 *
 *
 **/

#include "intro.h"
#include <stdio.h>

int main() {
  const int con = 60; // conversion ratio

  // Var declaration
  int minutes;
  int hours;
  int emins;

  // Get user minutes
  printf("Introduzca el numero de minutos:");
  minutes = get_user_int();

  // Math
  hours = minutes / con;
  emins = minutes % con;

  // Out
  printf("\n Horas: %d", hours);
  printf("\n Minutos restantes: %d \n", emins);
}
