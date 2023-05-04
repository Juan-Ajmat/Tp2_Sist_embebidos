/************************************************************************************************
Copyright (c) <2023>, Juan Ignacio Ajmat <juan.ajmat@gmail.com>

Codigo desarrollado durante el cursado de la materia Sistemas embebidos, primer semestre 2023
Facultad de Ciencias Exactas y Tecnologia. Universidad Nacional de Tucumán. Tucumán. Argentina

SPDX-License-Identifier: MIT
*************************************************************************************************/


/** \brief Trabajo Práctico nª3
 **
 ** \addtogroup tp3 TPN3
 ** \brief Trabajo Práctico nª3
 ** @{ */
/* === Headers files inclusions ================================================================ */

#include "alumno.h"
#include <stdio.h>

/* === Public variable definitions ============================================================= */
int main (void){

//	static const struct alumno_s yo ={
//		.apellido = "Ajmat",
//		.nombre = "Juan Ignacio",
//		.documento = 41649548,
//	};

char cadena [128];
alummno_t yo= CrearAlumno("Ajmat", "Juan Ignacio", 41649548);
alumno_t other= CrearAlumno("Gonzalez", "Mauro", 45555555)



if (serializar(yo, cadena, sizeof(cadena)) >=0){
	printf("%s\n", cadena);
}else{
	printf("Error al serializar\n");
}
if (serializar(otro, cadena, sizeof(cadena)) >=0){
	printf("%s\n", cadena);
}else{
	printf("Error al serializar\n");
}
return 0;
}