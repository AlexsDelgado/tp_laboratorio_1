
#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

#include "Empleado.h"

int menu();
int menuOrdenamiento();
int menuInformes();
void imprimirPromedioSalario(Empleado listaEmpleados[],int tam);
void ordenarEmpleados(Empleado listaEmpleados[], int tam, int metodoOrdenamiento);
void MostrarProducto(Empleado empleado);
void imprimirEmpleados(Empleado listaEmpleados[], int tam);

#endif /* INFORMES_H_ */
