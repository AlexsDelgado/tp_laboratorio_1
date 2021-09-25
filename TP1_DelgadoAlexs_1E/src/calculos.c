#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ingresarOperando(){   //ok pide operando
	int operando;
	do{
		scanf("%d",&operando);
		fflush(stdin);
	}while(isdigit(operando));
	return operando;
}

int menu(){ //printf de las opciones y recupera la deseada
	int opcionMenu;
	printf("\n *********************************\nIngrese: \n 1_ Para ingresar el operando A\n 2_ Para ingresar el operando B\n 3_ Para realizar los calculos\n 4_ Para mostrar los resultados\n 5_ Para finalizar el programa\n\n *********************************\n ");
	scanf("%d",&opcionMenu);
	fflush(stdin);
	while(opcionMenu<1 || opcionMenu>5){
		system("cls");
		printf("Error al seleccionar la opcion. \n\n \n *********************************\nIngrese: \n 1_ Para ingresar el operando A\n 2_ Para ingresar el operando B\n 3_ Para realizar los calculos\n 4_ Para mostrar los resultados\n 5_ Para finalizar el programa\n \n *********************************\n");
		scanf("%d",&opcionMenu);
		fflush(stdin);
	}
	return opcionMenu;
}

int sumar(int a, int b){
	int resultado;
	resultado = a + b;
	return resultado;
}
int restar(int a, int b){
	int resultado;
	resultado = a - b;
	return resultado;
}
int multiplicar(int a, int b){
	int resultado;
	resultado = a*b;
	return resultado;
};
int dividir(int a, int b){
	int resultado =0;
	if(b==0){
		printf("No se puede realizar la division, ya que el operando B tiene valor 0\n\n");
	}else{
		resultado = a/b;
	}

	return resultado;
}
long long int factorizar(int a){

    long long int resultado=1;
    long long int factorial = a;
    while(factorial > 1) {
       resultado = resultado * factorial;
       factorial--;
    }
 return resultado;
}
void mostrarResultados(int suma, int resta, int multiplicacion, int division, long long int factorial1, long long int factorial2){
	printf("los calculos de los dos operando son:\n");
	printf("Suma = %d\n",suma);
	printf("Resta = %d\n",resta);
	printf("Multiplicacion = %d\n",multiplicacion);
	printf("Division = %d\n",division);
	printf("Factorial operando A = %ld \n",factorial1);
	printf("Factorial operando B = %lld \n",factorial2);
}
char salir(){
	char salir;
		fflush(stdin);
		printf("Desea salir del programa? (Y/N)\n");
		scanf("%c",&salir);
		fflush(stdin);
	while(salir!='y' && salir!='n'){
		printf("Error. Desea salir del programa? (Y/N)\n");
		scanf("%c",&salir);
		fflush(stdin);
	}
	return salir;
}
