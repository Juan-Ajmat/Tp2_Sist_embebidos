/************************************************************************************************
Copyright (c) <2023>, Juan Ignacio Ajmat <juan.ajmat@gmail.com>

Codigo desarrollado durante el cursado de la materia Sistemas embebidos, primer semestre 2023
Facultad de Ciencias Exactas y Tecnologia. Universidad Nacional de Tucumán. Tucumán. Argentina

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef ALUMNO_H
#define ALUMNO_H

/** \brief Declaraciones publicas del modulo de alumnos
 **
 ** \addtogroup alumno Alumnos
 ** \brief Modulo para la gestion de alumnos
 ** @{ */

/* === Headers files inclusions ================================================================ */

#include<stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

#define FIELD_SIZE 50


/* === Public data type declarations =========================================================== */
typedef struct alumno_s{
	char apellido[FIELD_SIZE];
	char nombre[FIELD_SIZE];
	uint32_t documento;
}* alumno_t;


int serializar(
    const struct alumno_s * alumno, 
    char cadena[],                  
    uint32_t espacio);
/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* ALUMNO_H */