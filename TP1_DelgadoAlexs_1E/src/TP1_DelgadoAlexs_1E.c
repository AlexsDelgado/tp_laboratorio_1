#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu;
	int a;
	int b;
	int rSuma;
	int rResta;
	int rMultiplicacion;
	float rDivision;
	int calculosRealizados=0;
	int flagOperandoA=0;
	int flagOperandoB=0;
	long long int rFactorial1;
	long long int rFactorial2;
	char terminar='n';

	do{
		opcionMenu = menu();
		switch(opcionMenu){
			case 1:
				printf("Ingrese un operador\n");
				a = ingresarOperando();
				flagOperandoA=1;
				printf("Se ingreso el primer operando correctamente\n");
				system("pause");
				system("cls");
			break;
			case 2:
				printf("Ingrese un segundo operador\n");
				b = ingresarOperando();
				flagOperandoB=1;
				printf("Se ingreso el segundo operando correctamente\n");
				system("pause");
				system("cls");
			break;
			case 3:
				if(flagOperandoA==0 || flagOperandoB==0){
					printf("Ingrese los dos operandos antes de calcular\n");
				}else{
					rSuma=sumar(a,b);
					rResta=restar(a,b);
					rMultiplicacion=multiplicar(a,b);
					rDivision = dividir(a,b);
					rFactorial1=factorizar(a);
					rFactorial2=factorizar(b);
					calculosRealizados=1;
					printf("\nSe realizaron los calculos\n");
				}
				system("pause");
				system("cls");
			break;
			case 4:
				if(calculosRealizados==0){
					printf("Primero realice los calculos\n");
				}else{
					mostrarResultados(rSuma,rResta,rMultiplicacion,rDivision,rFactorial1,rFactorial2);
				}

				system("pause");
				system("cls");
			break;
			case 5:
				terminar=salir();
			break;
			system("pause");
			system("cls");
		}
	}while(terminar!='y');
	return 0;
}
