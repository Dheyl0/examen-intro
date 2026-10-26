/**
 * @file sorteo.c
 *
 * @brief check winner
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-03
 *
 *
 **/

#include "intro.h"
#include <stdio.h>

int main() {
  // Var declaration
  int ticket;
  int m4;
  int m100;
  int m400;

  // Get user input
  printf("Intruduzca su num de boleto:");
  ticket = get_user_int();

  // Error handling
  if (ticket >= 1 && ticket <= 9999) {
  } else {
    return 1;
  }

  // Algorithm
  m4 = ticket % 4;
  m100 = ticket % 100;
  m400 = ticket % 400;
  if (m4 == 0 && m100 == 0 && m400 == 0) {
    printf("Boleto premiado");
  } else if (m4 == 0 && m100 != 0 && m400 != 0) {
    printf("Boleto premiado");
  } else {
    printf("Boleto no premiado");
  }
  return 0;
}
