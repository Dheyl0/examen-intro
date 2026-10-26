/**
 * @file
 * @brief Librería para acceder a los datos simulados del juego de equipo
 *
 * Author:  Intro_SW
 * Version: 1.0
 *
*/

#define MAX_JUGADOR_ID  30


/**
* @brief Obtiene la coordenada x (en metros) de un jugador a partir de su identificador
* @param jugador_id El identificador del jugador (rango [1, MAX_JUGADOR_ID])
* @returns la coordenada x del jugador, termina en caso de error
*/
int obten_coordx (int jugador_id);

/**
* @brief Obtiene la coordenada y (en metros) de un jugador a partir de su identificador
* @param jugador_id El identificador del jugador (rango [1, MAX_JUGADOR_ID])
* @returns la coordenada x del jugador, termina en caso de error
*/
int obten_coordy (int jugador_id);

/**
* @brief Obtiene el identificador del equipo a partir del identificador de un jugador
* @param jugador_id El identificador del jugador (rango [1, MAX_JUGADOR_ID])
* @returns el identificador del equipo del jugador, termina en caso de error
*/
int obten_equipo (int jugador_id);