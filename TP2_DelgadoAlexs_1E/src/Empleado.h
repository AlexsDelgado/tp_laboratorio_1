#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "BibliotecaUTN.h"

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;

}Empleado;


void inicializarEmpleados(Empleado listaEmpleados[],int tam);
int BuscarPrimerEspacioLibre(Empleado listaEmpleado[],int tam);
int cargarEmpleado(Empleado listaEmpleados[],int id,int tam);
Empleado altaEmpleado(Empleado listaEmpleados[],int posicion, int id);
int buscarEmpleadoPorId(Empleado listaEmpleados[],int id,int tam);
int modificarEmpleado(Empleado listaEmpleados[]);
int bajaEmpleado(Empleado listaEmpleados[], int tam);
int contadorEmpleados(Empleado listaEmpleados[], int tam);
float contadorSalarioTotal(Empleado listaEmpleados[],int tam);
int empleadosMayorSalario(Empleado listaEmpleados[], int tam, float promedio);
#endif /* EMPLEADO_H_ */
