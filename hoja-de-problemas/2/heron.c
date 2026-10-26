/**
 * @file Heron.c
 *
 * @brief Calculo del area de un triangulo
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-09-29
 *
 *
 **/

#include "intro.h"
#include <math.h>
#include <stdio.h>

int main() {
  // Var delcaration
  int a; // Side A
  int b; // Side B
  int c; // Side C
  float perimeter;
  float s;
  float area;

  // Get user input
  printf("Introduzca la longitud del primer lado:");
  a = get_user_int();
  printf("\n Intruduzca la longitud del segundo lado:");
  b = get_user_int();
  printf("\n Intruduzca la longitud del tercer lado:");
  c = get_user_int();

  // Math
  perimeter = a + b + c;
  s = perimeter / 2;
  area = sqrt(s * (s - a) * (s - b) * (s - c));

  // print
  printf("\n El area del triangulo de lados a = %d b = %d c = %d es %f u² \n ",
         a, b, c, area);
  return 0;
}
