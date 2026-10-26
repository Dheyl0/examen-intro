/**
 * @file consumo.c
 *
 * @brief Calcular el consumo medio y precio del viaje
 *
 * @author  Prisco González Fernández <pgf81@proton.me>
 * @version 2026-09-29
 *
 *
 **/

#include "intro.h"
#include <stdio.h>

int main() {
    // Var declaration
    float avgconsumption;
    float distance;
    float fuel_price;
    float burned_fuel;
    float cost;

    // Input
    printf ("Introduzca la distancia transcurrida: \n");
    distance = get_user_float();
    printf ("Introduzca los litros de combustible utilizados: \n");
    burned_fuel = get_user_float();
    printf ("Introduzca el precio actual del combustible (€) \n");
    fuel_price = get_user_float();

    // Math
    avgconsumption = (burned_fuel / distance) * 100;
    cost = burned_fuel * fuel_price;

    // out
    printf ("Has tenido un consumo medio de %f litros cada 100 Km \n", avgconsumption);
    printf ("El viaje ha tenido un coste de %f \n", cost);

    return 0;
}
