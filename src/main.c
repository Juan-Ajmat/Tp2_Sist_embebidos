/************************************************************************************************
Copyright (c) <2023>, Juan Ignacio Ajmat <juan.ajmat@gmail.com>

Codigo desarrollado durante el cursado de la materia Sistemas embebidos, primer semestre 2023
Facultad de Ciencias Exactas y Tecnologia. Universidad Nacional de Tucumán. Tucumán. Argentina

SPDX-License-Identifier: MIT
*************************************************************************************************/


/** \brief Trabajo Práctico nª2
 **
 ** \addtogroup tp2 TPN2
 ** \brief Trabajo Práctico nª2
 ** @{ */
/* === Headers files inclusions ================================================================ */

#include "alumno.h"
#include <stdio.h>

/* === Public variable definitions ============================================================= */
int main (void){
	static const struct alumno_s yo ={
		.apellido = "Ajmat",
		.nombre = "Juan Ignacio",
		.documento = 41649548,
	};
char cadena [128];

if (serializar(&yo, cadena, sizeof(cadena)) >=0){
	printf("%s\n", cadena);
}else{
	printf("Error al serializar\n");
};
return 0;
}