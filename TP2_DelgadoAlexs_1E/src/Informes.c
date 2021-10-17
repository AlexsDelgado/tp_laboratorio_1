#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Informes.h"
/// \fn int menu()
/// \brief imprime menu de opciones generales y en el caso de no ingresar una de estas se imprime un error
/// \return devuelve una de las opciones listadas
int menu(){
	int opcionMenu;
	printf("\n *********************************\nIngrese: \n 1_Alta de Empleado\n 2_ Modificar datos Empleado \n 3_ Baja de empleado \n 4_ Informar datos\n 5_ Salir\n *********************************\n ");
	scanf("%d",&opcionMenu);
	fflush(stdin);
	while(opcionMenu<1 || opcionMenu>11){
		system("cls");
		printf("Error al ingresar una opcion, intente nuevamente \n\n *********************************\nIngrese: \n 1_Alta de Empleado\n 2_ Modificar datos Empleado \n 3_ Baja de empleado \n 4_ Informar datos\n 5_ Salir\n *********************************\n ");
		scanf("%d",&opcionMenu);
		fflush(stdin);
	}
	return opcionMenu;
}

/// \fn int menuInformes()
/// \brief pequeño submenu para elegir una de las opciones a informar
/// \return devuelve una de las opciones listadas
int menuInformes(){
	int opcionMenu;
	printf("\n Ingrese: \n 1_Imprimir lista de Empleados\n 2_ Imprimir promedio de salarios de los empleados \n 3_ Ordenamiento de empleados\n ");
	scanf("%d",&opcionMenu);
	fflush(stdin);
	while(opcionMenu<1 || opcionMenu>3){
		system("cls");
		printf("Error al ingresar una opcion, intente nuevamente \n\n Ingrese: \n 1_Imprimir lista de Empleados\n 2_ Imprimir promedio de salarios de los empleados \n 3_ Ordenamiento de empleados\n ");
		scanf("%d",&opcionMenu);
		fflush(stdin);
	}
	return opcionMenu;
}
/// \fn int menuOrdenamiento()
/// \brief pequeño submenu con las 2 opciones de ordenamiento (ASCENDENTE Y DESCENDENTE)
/// \return devuelve una de las 2 opciones listadas
int menuOrdenamiento(){
	int opcionMenu;
	printf("\n Ingrersar 1 para ordenamiento ASC o 2 para ordenamiento DESC\n ");
	scanf("%d",&opcionMenu);
	fflush(stdin);
	while(opcionMenu<1 || opcionMenu>2){
		system("cls");
		printf("Error al ingresar una opcion, intente nuevamente Ingrersar 1 para ordenamiento ASC o 2 para ordenamiento DESC\n ");
		scanf("%d",&opcionMenu);
		fflush(stdin);
	}
	return opcionMenu;
}
/// \fn void imprimirPromedioSalario(Empleado[], int)
/// \brief con el contador de salario total y contador de empleados se calcula el promedio y luego imprime estos datos por consola
/// \param listaEmpleados
/// \param tam
void imprimirPromedioSalario(Empleado listaEmpleados[],int tam){
	int contEmpleados;
	float SalarioTotal;
	float promedio;
	int contadorEmpleadosConMayorPromedio;

	contadorEmpleadosConMayorPromedio=0;
	contEmpleados=0;
	SalarioTotal=0;

	contEmpleados=contadorEmpleados(listaEmpleados, tam);
	if(contEmpleados==0){
		printf("Error. No se cargaron empleados\n");
	}else{
		SalarioTotal = contadorSalarioTotal(listaEmpleados, tam);

		promedio = (float)(SalarioTotal/contEmpleados);
		contadorEmpleadosConMayorPromedio= empleadosMayorSalario(listaEmpleados, tam, promedio);


		printf("El salario total de los empleados es de: %f\n",SalarioTotal);
		printf("El promedio de los salarios es de : %.2f\n",promedio);
		printf("La cantidad de empleados con salarios mayores al promedio es: %d\n", contadorEmpleadosConMayorPromedio);

	}

}
/// \fn void ordenarEmpleados(Empleado[], int, int)
/// \brief ordena la lisgta de empleados por apellido y sector de manera asc o desc segun  la opcion seleccionada
/// \param listaEmpleados
/// \param tam
/// \param metodoOrdenamiento
void ordenarEmpleados(Empleado listaEmpleados[], int tam, int metodoOrdenamiento){
	int i;
	int j;
	int ordenAux;

	Empleado auxiliarEmpleado;
	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			ordenAux= strcmp(listaEmpleados[i].apellido,listaEmpleados[j].apellido);
			if(metodoOrdenamiento == 1){

				if( listaEmpleados[i].sector>listaEmpleados[j].sector || ordenAux>0)
				{
					auxiliarEmpleado = listaEmpleados[i];
					listaEmpleados[i] = listaEmpleados[j];
					listaEmpleados[j] = auxiliarEmpleado;
				}
			}else{
				if( listaEmpleados[i].sector<listaEmpleados[j].sector || ordenAux<0)
				{
					auxiliarEmpleado = listaEmpleados[i];
					listaEmpleados[i] = listaEmpleados[j];
					listaEmpleados[j] = auxiliarEmpleado;
				}
			}
		}
	}
}
/// \fn void imprimirEmpleado(Empleado)
/// \brief imprime los datos que recibe por parametro de un empleado de manera encolumnada
/// \param empleado
void imprimirEmpleado(Empleado empleado)
{
	printf("%d \t %-15s %-15s %4.2f \t %4d \n", empleado.id, empleado.nombre,  empleado.apellido,
			empleado.salario, empleado.sector);
}
/// \fn void imprimirEmpleados(Empleado[], int)
/// \brief imprime las columnas de los datos de los empleados y luego recorre el array para llamar a la funcion imprimir empleado en el caos de que encuentre uno
/// \param listaEmpleados
/// \param tam
void imprimirEmpleados(Empleado listaEmpleados[], int tam){
	int i;
	int flagvacio = 0;
	printf("Id \t Nombre \t Apellido\t Salario\t Sector\n");
	for (i = 0; i < tam; i++)
	{
		if(listaEmpleados[i].isEmpty == 1){
			imprimirEmpleado(listaEmpleados[i]);
			flagvacio=1;
		}
	}

	if(flagvacio == 0){
		printf("Error. No se cargaron empleados.\n");
	}
}

