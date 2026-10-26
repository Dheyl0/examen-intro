/**
 * @file abono.c
 *
 * @brief calculo abono en funcion de años
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-10-17
 *
 *@compile -Wall -Werror -o abono abono.c -lintro
 **/

#include "intro.h"
#include <stdio.h>
#include <stdlib.h>

#define NOMINAL_PRICE 500.00 // Precio regular
#define MIN_PRICE     300.00 // Precio minimo

float obten_descuento (int anhos_en_club);

int main (void) {
    int age;
    float final_price, descuento;
    char consulta;

    do {
        // Get años socio
        printf ("Introduzca los años que ud ha sido socio:");
        age = get_user_int();

        if (age < 0) {
            printf ("El valor es erroneo");
            return EXIT_FAILURE;
        }
        else if (age > 120) {
            printf ("El valor es erroneo");
            return EXIT_FAILURE; // Exit libreria stdlib
        }
        descuento = obten_descuento (age);
        // Calculo del precio
        final_price = NOMINAL_PRICE * (1 - (NOMINAL_PRICE * descuento) / 100);

        if (final_price < MIN_PRICE) {
            final_price = MIN_PRICE;
        }
        // Printout
        printf ("El precio final del abono es: %.2f\n", final_price);
        printf ("Desea hacer otra consulta?:");
        consulta = get_user_char();
    } while (consulta == 's' || consulta == 'S');

    return EXIT_SUCCESS; // Exit libreria stdlib
}

/**
 * @brief Obtiene descuento
 * @param anhos_en_club en el club
 * @return descuento devuelto
 */
float obten_descuento (int anhos_en_club) {
    // Variables
    float descuento = 0.0;

    // Algorithm
    if (anhos_en_club < 3) {
        descuento = 0.0;
    }
    else if (anhos_en_club < 5) {
        descuento = 5.0;
    }
    else {
        descuento = 5.0 + (2.0 * (anhos_en_club - 5));
    }
    return descuento;
}
