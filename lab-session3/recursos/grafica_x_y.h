/**
@file    grafica_x_y.h
@brief   Librería para hacer gráficas X-Y sencillas


@author  Michael Gonzalez <mgh@unican.es>
@version 0.1
@date    oct 2020

Copyright (C)
Universidad de Cantabria, SPAIN

Licencia: GPL
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.



Esta librería ofrece una interfaz sencilla con facilidades para
 - almacenar puntos
 - mostrarlos como una grafica de puntos o lineas
 - se pueden mostrar varias graficas en la misma ventana

Esta librería requiere tener la utilidad gnuplot instalada.

Ejemplo básico: Gráfica de la función raíz cuadrada para unos pocos puntos

@code

#include <math.h>
#include "grafica_x_y.h"

int main (void) {
    // Insertar los puntos en la gráfica 
    inserta (0.0, sqrt (0.0));
    inserta (2.0, sqrt (2.0));
    inserta (8.0, sqrt (8.0));
    inserta (64.0, sqrt (32.0));
    // Pintar la gráfica y acabar
    pinta();
    return 0;
}

@endcode



Ejemplo avanzado: gráficas de las funciones seno y coseno en una ventana,
                  y gráfica de la función raíz cuadrada en otra

@code

#include <math.h>
#include "grafica_x_y.h"

int main (void) {

    pon_titulos ("Seno y Coseno", "x", "y");
    // El primer gráfico
    pon_leyenda ("Seno");
    pon_estilo (ESTILO_LINEAS);
    // Ángulos desde 0 a 3*PI con incremento de PI/16
    for (float x1 = 0.0; x1 <= M_PI * 3.0; x1 = x1 + M_PI / 16.0) {
        inserta (x1, sin (x1));
    }
    
    // El segundo gráfico
    otra_grafica();
    pon_leyenda ("Coseno");
    pon_estilo (ESTILO_PUNTOS);
    // Ángulos desde 0 a 10 radianes con incremento
    // de 0.1 radianes
    for (int i = 0; i <= 100; i++) {
        float x2 = i / 10.0;
        inserta (x2, cos (x2));
    }
    pinta();


    // Ahora pintamos una tercera gráfica en una ventana aparte
    // Siempre que se usa el "pinta()" se cambia de ventana
    pon_titulos ("Raíz Cuadrada", "x", "raíz");
    // Números de 0 a 64
    for (int x = 0; x <= 64; x++) {
        inserta (x, sqrt (x));
    }
    pinta();
    
    return 0;
}

@endcode

Limitaciones
------------

El número máximo de gráficas en la misma ventana es de 4 (MAX_GRAFICAS)

El número máximo de puntos en una gráfica es de 20000 (MAX_PUNTOS)

*/


#ifndef GRAFICA_X_Y_H
#define GRAFICA_X_Y_H

/**
 * @name Constante configurable MAX_GRAFICAS
 * Máximo número de gráficas representables en una misma ventana
 * @{
 */
#define MAX_GRAFICAS 4
/** @} */

/**
 * @name Constante configurable MAX_PUNTOS
 * Máximo número de puntos en cada gráfica
 * @{
 */
#define MAX_PUNTOS 200000
/** @} */

/**
 * @name Constantes de la librería
 * Códigos de error, etc
 * @{
 */

/*
 * Códigos de estilo
 */

#define ESTILO_PUNTOS 1                     /**< Se marcan los puntos con símbolos */
#define ESTILO_LINEAS 2                     /**< Se ponen líneas entre los puntos de la gráfica */
#define ESTILO_LINEAS_Y_PUNTOS 3            /**< Se ponen líneas y símbolos en los puntos de la gráfica. 
                                                 Estilo por defecto */

/*
 * Códigos de error
 */

#define CORRECTO 0                          /**< Operación ejecutada correctamente */
#define ERROR_MAX_GRAFICAS_SOBREPASADO -1   /**< Se ha sobrepasado el número máximo de gráficas */
#define ERROR_MAX_PUNTOS_SOBREPASADO -2     /**< Se ha sobrepasado el número máximo de puntos en una gráfica */
#define ERROR_ESTILO_INCORRECTO -3          /**< Se ha especificado un estilo incorrecto */
#define ERROR_POCOS_PUNTOS -4               /**< Se ha especificado un estilo incorrecto */

/** @} */

/**
 * Tipo que representa un texto (string)
 */
typedef char *texto_t;


/**
 * Inserta un punto X-Y en la gráfica. 
 *
 * Los puntos deben estar ordenados por el eje X
 *
 * @param x La coordenada x del punto
 * @param y La coordenada y del punto
 *
 * @returns CORRECTO si todo fue bien o 
 *          ERROR_MAX_PUNTOS_SOBREPASADO si se ha sobrepasado
 *          el máximo número de puntos de la gráfica actual 
 */
int inserta (float x, float y);
  

/**
 * Muestra la gráfica y reinicializa los datos por si
 * queremos mostrar una nueva ventana con una gráfica
 *
 * @returns CORRECTO si todo fue bien o 
 *          ERROR_POCOS_PUNTOS si se ha insertado solo un punto o menos
 *          en alguna de las gráficas a representar
 */
int pinta (void);


/**
 * Pone los títulos de la gráfica y los ejes. Si alguno supera los 20 caracteres se truncará.
 * @param titulo_grafica texto que contiene el título de la gráfica
 * @param titulo_eje_x texto que contiene el título del eje x de la gráfica
 * @param titulo_eje_y texto que contiene el título del eje y de la gráfica
 * 
 */

void pon_titulos 
    (texto_t titulo_grafica, 
     texto_t titulo_eje_x, 
     texto_t titulo_eje_y);      

/**
 * Comienza una nueva grafica con los mismos ejes
 *  
 * Se usa un unico pinta() para todas las graficas.
 *
 * @returns  CORRECTO si todo fue bien o 
 *     ERROR_MAX_GRAFICAS_SOBREPASADO si se ha sobrepasado
 *     el máximo número de gráficas de una ventana
 */

int otra_grafica (void);           

  
/**
 * Cambia el estilo de la gráfica actual 
 *
 * Cambia el estilo según el valor del parámetro estilo, que deberá ser una de 
 * las siguientes constantes:
 *    ESTILO_PUNTOS: Marca los puntos con símbolos
 *    ESTILO_LINEAS: Pone líneas entre cada punto
 *    ESTILO_LINEAS_Y_PUNTOS: Pone líneas y marca los puntos (por defecto)
 *
 * @param estilo el estilo a utilizar
 *
 * @returns CORRECTO si todo ha ido bien, o ERROR_ESTILO_INCORRECTO si el 
 *          estilo indicado no es una de las constantes señaladas arriba
 */

int pon_estilo (int estilo);

  
/**
 * Pone la leyenda de la grafica actual. Si excede de 20 caracteres se truncará.
 *
 * @param leyenda texto que contiene la leyenda a aplicar a la gráfica actual
 *        
 */

void pon_leyenda (texto_t leyenda);

#endif // GRAFICA_X_Y_H
