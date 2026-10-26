/**
 * @file abono.c
 *
 * @brief subscription price check
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-03
 *
 *
 **/

#include "intro.h"
#include <stdio.h>

#define NOMINAL_PRICE 500.00
#define MIN_PRICE     300.00

int main() {
    // Var declaration
    int age;
    float final_price;

    // Get User input
    printf ("Intruduzca los años que ud ha sido socio:");
    age = get_user_int();

    // Error handling
    if (age < 0) {
        printf ("El valor introducido es incorrecto \n");
        return 1;
    }

    else if (age > 120) {
        printf ("La tarjeta de socio no es centenaria \n");
        return 1;
    }

    // Algorithm
    if (age >= 0 && age < 3) {
        final_price = NOMINAL_PRICE;
        printf ("%.2f es el precio del abono. \n", final_price);
    }
    else if (age >= 3 && age < 5) {
        final_price = NOMINAL_PRICE * (1 - (5.0 / 100));
        printf ("%.2f esl el precio del abono. \n", final_price);
    }
    else {
        final_price = NOMINAL_PRICE * (1 - (5.0 / 100) - ((2.0 / 100) * age));
        if (final_price < MIN_PRICE) {
            final_price = MIN_PRICE;
        }
        printf ("%.2f es el precio del abono. \n", final_price);
    }
}
