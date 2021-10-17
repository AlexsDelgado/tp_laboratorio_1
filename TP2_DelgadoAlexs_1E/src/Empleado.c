#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Empleado.h"
#define TAM 1000


/// \fn void inicializarEmpleados(Empleado[], int)
/// \brief inicializa los campos de isEmpty en toda la lista de empleados
/// \param listaEmpleados
/// \param tam
void inicializarEmpleados(Empleado listaEmpleados[],int tam)
{
    for(int i = 0;i < tam; i++)
    {
        listaEmpleados[i].isEmpty = 0;
    }
}
/// \fn int BuscarPrimerEspacioLibre(Empleado[], int)
/// \brief busca el primer empleado que este con el campo isEmpty
/// \param listaEmpleado
/// \param tam
/// \return devuelve la posicion en el array del empleado libre
int BuscarPrimerEspacioLibre(Empleado listaEmpleado[],int tam){
	int i;
	int index;

	index = -1;
	for(i = 0; i<tam; i++){
		if(listaEmpleado[i].isEmpty == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}
/// \fn int cargarEmpleado(Empleado[], int, int)
/// \brief busca el primer espacio libre y llama a la funcion de alta de empleado
/// \param listaEmpleados
/// \param id
/// \param tam
/// \return devuelve el estado de la carga 0 para error y 1 para OK
int cargarEmpleado(Empleado listaEmpleados[],int id,int tam)
{
	int index;
	int estadoCarga;
	estadoCarga=0;
	index = BuscarPrimerEspacioLibre(listaEmpleados, tam);
	   if(index != -1)
	   {
	      listaEmpleados[index] = altaEmpleado(listaEmpleados, index, id);
	      estadoCarga=1;

	   }
	return estadoCarga;
}
/// \fn Empleado altaEmpleado(Empleado[], int, int)
/// \brief carga los datos de la estructura empleados
/// \param listaEmpleados
/// \param posicion
/// \param id
/// \return devuelve el struct cargado
Empleado altaEmpleado(Empleado listaEmpleados[],int posicion, int id){
	Empleado empleadoNuevo;
    	empleadoNuevo.id=id;
        getString(empleadoNuevo.nombre,"Ingresar nombre del empleado\n", 51);
        getString(empleadoNuevo.apellido,"Ingresar apellido del empleado\n", 51);
        empleadoNuevo.salario=IngresarFlotante("Ingrese el salario del empleado\n");
        empleadoNuevo.sector=ingresarEntero("Ingresar el sector para el empleado\n");
    	empleadoNuevo.isEmpty = 1;

    	return empleadoNuevo;
}
/// \fn int buscarEmpleadoPorId(Empleado[], int, int)
/// \brief busca en el array un empleado que tenga el id recibido por paramtetro
/// \param listaEmpleados
/// \param id
/// \param tam
/// \return devuelve la posicion del array del id seleccionado o -1 si no lo encuentrra
int buscarEmpleadoPorId(Empleado listaEmpleados[],int id,int tam){
	int i;
	int posicionBusqueda;
	posicionBusqueda= -1;
	for(i=0;i<tam;i++)
	    {
	        if(listaEmpleados[i].isEmpty==1 && listaEmpleados[i].id==id)
	        {
	        	posicionBusqueda=i;
	        	break;
	        }
	    }
	return posicionBusqueda;
}
/// \fn int modificarEmpleado(Empleado[])
/// \brief se busca el id ingresado en el array y luego se pregunta que campos desea modificar para luego modificar unicanmente esos campos
/// \param listaEmpleados
/// \return devuelve -1 si no se modifico correctamente o 1 cuando se realiza la modificacion
int modificarEmpleado(Empleado listaEmpleados[]){
    int posicionID;
    int idEmpleado;
    char flagNombre;
    char flagApeliido;
    char flagSalario;
    char flagSector;
    flagApeliido='n';
    flagNombre='n';
    flagSalario='n';
    flagSector='n';

    int estadoModificacion;
    estadoModificacion = -1;

    idEmpleado = ingresarEntero("Ingrese el ID del empleado a modificar");
    posicionID=buscarEmpleadoPorId(listaEmpleados, idEmpleado, TAM);
        if(posicionID!=-1)
        {
        	printf("Desea modificar el NOMBRE del empleado %s %s ? \n", listaEmpleados[posicionID].nombre, listaEmpleados[posicionID].apellido);
        	flagNombre = confirmar();
        	printf("Desea modificar el APELLIDO del empleado %s %s ?\n", listaEmpleados[posicionID].nombre, listaEmpleados[posicionID].apellido);
        	flagApeliido = confirmar();
        	printf("Desea modificar el SALARIO del empleado %s %s ?\n", listaEmpleados[posicionID].nombre, listaEmpleados[posicionID].apellido);
        	flagSalario = confirmar();
        	printf("Desea modificar el SECTOR del empleado %s %s ?\n", listaEmpleados[posicionID].nombre, listaEmpleados[posicionID].apellido);
        	flagSector = confirmar();
        	if(flagNombre =='y'){
				getString(listaEmpleados[posicionID].nombre,"Ingrese el nuevo nombre para el empleado\n", 51);
			}
			if(flagApeliido == 'y'){
				getString(listaEmpleados[posicionID].apellido,"Ingrese el nuevo apellido para el empleado\n", 51);
			}
			if(flagSalario == 'y'){
				listaEmpleados[posicionID].salario=IngresarFlotante("Ingrese nuevo salario para el empleado\n");
			}
			if(flagSector == 'y'){
				listaEmpleados[posicionID].sector=ingresarEntero("Ingrese el nuevo sector para el empleado\n");
			}
			estadoModificacion = 1;
        }else{
         printf("no se encontro el empleado seleccionado\n");
        }
    return estadoModificacion;
}

/// \fn int bajaEmpleado(Empleado[], int)
/// \brief se busca el id ingresado en el array y luego se pregunta si realmente desea eliminarlo para luego cambiar el campo isEmpty
/// \param listaEmpleados
/// \param tam
/// \return devuelve -1 si no se elimino correctamente o 1 cuando se realiza la baja del empleado
int bajaEmpleado(Empleado listaEmpleados[], int tam){
    int posicionID;
    int idEmpleado;
    int estadoBaja;
    char confirmacionUsuario;
    estadoBaja = -1;

    idEmpleado = ingresarEntero("Ingrese el ID del empleado a eliminar\n");
    posicionID=buscarEmpleadoPorId(listaEmpleados, idEmpleado, tam);
    if(posicionID!=-1){
    	printf("Desea eliminar al empleado %s %s \n?", listaEmpleados[posicionID].nombre, listaEmpleados[posicionID].apellido);
    	confirmacionUsuario=confirmar();
		if(confirmacionUsuario=='y'){
			listaEmpleados[posicionID].isEmpty=0;
			estadoBaja = 1;
		}
    }

    return estadoBaja;
}
/// \fn int contadorEmpleados(Empleado[], int)
/// \brief recorre el array de empleados y revisa el campo isEmpty para aumentar el contador de empleados
/// \param listaEmpleados
/// \param tam
/// \return devuelve la cantidad de empleados generados
int contadorEmpleados(Empleado listaEmpleados[], int tam){
	int i;
	int contadorEmpleados;
	contadorEmpleados =0;
	for(i=0;i<tam;i++){
		if(listaEmpleados[i].isEmpty !=0){
			contadorEmpleados++;
		}
	}
	return contadorEmpleados;
}
/// \fn float contadorSalarioTotal(Empleado[], int)
/// \brief recorre el array de empleados y revisa el campo salario para crear un contador acumulativo para conseguir el total de salario
/// \param listaEmpleados
/// \param tam
/// \return devuelve la sumatoria de los salarios
float contadorSalarioTotal(Empleado listaEmpleados[],int tam){
	int i;
	float salarioTotal;
	salarioTotal =0;
	for(i=0;i<tam;i++){
		if(listaEmpleados[i].isEmpty !=0){
			salarioTotal= salarioTotal+ listaEmpleados[i].salario;
		}
	}
	return salarioTotal;
}
/// \fn int empleadosMayorSalario(Empleado[], int, float)
/// \brief compara los salarios de los empleados con el promedio y aumenta un contador en el caso de que sea mayor
/// \param listaEmpleados
/// \param tam
/// \param promedio
/// \return devuelve el contador de empleados con un salario mayor al promedio
int empleadosMayorSalario(Empleado listaEmpleados[], int tam, float promedio){
	int i;
	int contadorEmpleadosConMayorSalario;
	contadorEmpleadosConMayorSalario=0;
	for(i=0;i<tam;i++){
		if(listaEmpleados[i].salario>promedio && listaEmpleados[i].isEmpty==1){
			contadorEmpleadosConMayorSalario++;
		}
	}
	return contadorEmpleadosConMayorSalario;
}
