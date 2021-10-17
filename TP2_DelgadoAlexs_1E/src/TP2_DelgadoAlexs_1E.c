
#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"
#include "Empleado.h"
#define TAM 1000
int main(void) {
	setbuf (stdout, NULL);
		int idEmpleado;
		idEmpleado = 100;
		int estadoAux;
		int opcInformes;
		int metodoOrd;

		Empleado listaEmpleados[TAM];
		inicializarEmpleados(listaEmpleados, TAM);
		int opcionMenu;
		char terminar='n';
		do{
			opcionMenu = menu();
			switch(opcionMenu){
				case 1:
					//Alta empleado
					estadoAux=cargarEmpleado(listaEmpleados, idEmpleado, TAM);
					if(estadoAux!=0){
						printf("Se agrego el cliente %d correctamente\n", idEmpleado);
						idEmpleado++;
					}else{
						printf("Error al dar de alta al cliente. \n");
					}
					system("pause");
					system("cls");
				break;
				case 2:
					//Modificar datos empleados
					estadoAux= modificarEmpleado(listaEmpleados);
					if(estadoAux!=-1){
						printf("Se modifico correctamente el empleado seleccionado\n");
					}else{
						printf("Error al modificar el empleado seleccionado\n");
					}

					system("pause");
					system("cls");
				break;
				case 3:
					//Baja de empleado
					estadoAux=bajaEmpleado(listaEmpleados, TAM);
					if(estadoAux!=-1){
						printf("Se elimino correctamente el cliente seleccionado\n");
					}else{
						printf("Error al eliminar el cliente seleccionado\n");
					}
					system("pause");
					system("cls");
				break;
				case 4:
					//Crear pedido recoleccion
					opcInformes=menuInformes();
					switch(opcInformes){
					case 1:
						imprimirEmpleados(listaEmpleados, TAM);
						break;
					case 2:
						imprimirPromedioSalario(listaEmpleados, TAM);
						break;
					case 3:
						metodoOrd = menuOrdenamiento();
						ordenarEmpleados(listaEmpleados, TAM, metodoOrd);
						break;
					}


					system("pause");
					system("cls");
				break;
				case 5:
					terminar=confirmar();
				break;
			}
		}while(terminar!='y');


	return EXIT_SUCCESS;
}
