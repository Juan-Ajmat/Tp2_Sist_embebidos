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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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

alumno_t CrearAlumno (char * apellido, char * nombre, uint32_t documento) {
    
    alumno_t resultado; 

#if opcion == 1             

    resultado = malloc(sizeof(struct alumno_s));                   
    if (resultado != NULL) {
    strcpy(resultado->apellido, apellido);
    strcpy(resultado->nombre, nombre);
    resultado->documento = documento;
    } else {
        return NULL;
    }
#else       

static struct alumno_s instancias[50] = {0}; 
uint8_t i = 0;

for (uint8_t i = 0; i <= 50; i++) {

    if (instancias[i].ocupado == 0) {

        resultado = &instancias[i];
        strcpy(instancias[i].apellido, apellido);
        strcpy(instancias[i].nombre, nombre);
        instancias[i].documento = documento;
        instancias[i].ocupado = true;

        return resultado;   
    }
}

#endif

return resultado;

}
    
int serializar (const struct alumno_s * alumno, char cadena[], uint32_t espacio)
{
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    cadena++;
    disponibles--;
    resultado = SerializarCadena("Apellido:", alumno->apellido, cadena, disponibles);

    if (resultado>0){
        disponibles-= resultado;
        cadena += resultado;
        resultado = SerializarCadena("Nombre:", alumno->nombre, cadena, disponibles);
    }

    if(resultado>0){
        disponibles-= resultado;
        cadena += resultado;
        resultado = SerializarNumero("Documento:", alumno->documento, cadena, disponibles);
    }

    if (resultado>0){
        cadena += resultado;
        disponibles -=resultado;
        *(cadena -1 ) = '}';
        resultado = espacio - disponibles;
    }

    return resultado;
};