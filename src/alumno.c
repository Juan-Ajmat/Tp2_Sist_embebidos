/************************************************************************************************
Copyright (c) <2023>, Juan Ignacio Ajmat <juan.ajmat@gmail.com>

Codigo desarrollado durante el cursado de la materia Sistemas embebidos, primer semestre 2023
Facultad de Ciencias Exactas y Tecnologia. Universidad Nacional de Tucumán. Tucumán. Argentina

SPDX-License-Identifier: MIT
*************************************************************************************************/



/** \brief Implementacion del modulo de alumnos
 **
 ** \addtogroup alumno Alumnos
 ** \brief Modulo para la gestion de alumno
 ** @{ */
/* === Headers files inclusions ================================================================ */

#include "alumno.h"
#include <stdio.h>
/* === Private function declarations =========================================================== */
static int SerializarCadena ();
static int SerializarNumero ();

/* === Private function implementation ========================================================= */
static int SerializarCadena (const char * campo, const char * valor, char * cadena, int espacio ){
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero (const char * campo, int valor, char * cadena, int espacio ){
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

int serializar (const struct alumno_s * alumno, char cadena[], uint32_t espacio)
{
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    cadena++;
    disponibles--;
    resultado = SerializarCadena("apellido", alumno->apellido, cadena, disponibles);

    if (resultado>0){
        disponibles-= resultado;
        cadena += resultado;
        resultado = SerializarCadena("nombre", alumno->nombre, cadena, disponibles);
    }

    if(resultado>0){
        disponibles-= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento", alumno->documento, cadena, disponibles);
    }

    if (resultado>0){
        cadena += resultado;
        disponibles -=resultado;
        *(cadena -1 ) = '}';
        resultado = espacio - disponibles;
    }

    return resultado;
};