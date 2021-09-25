#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * ingresarOperando pide por pantalla un numero, lo guarda y lo retorna para su utilizacion
 * @return numero a calcular.
 */
int ingresarOperando();
/**
 * menu muestra por pantalla las opciones de la calculadora
 * @return devuelve un int con la opcion a realizar
 */
int menu();
/**
 * suma 2 operandos
 * @param a operando A de la suma
 * @param b operando B de la suma
 * @return el resultado de la operacion.
 */
int sumar(int a, int b);
/**
 * resta 2 operandos
 * @param a operando A de la resta
 * @param b operando B de la resta
 * @return el resultado de la operacion.
 */
int restar(int a, int b);
/**
 * divide 2 operandos
 * @param a operando A de la divide
 * @param b operando B de la divide
 * @return el resultado de la operacion.
 */
int dividir(int a, int b);
/**
 * multiplicar 2 operandos
 * @param a operando A de la multiplicacion
 * @param b operando B de la multiplicacion
 * @return el resultado de la operacion.
 */
int multiplicar(int a, int b);
/**
 * factorizar un numero
 * @param a operando del factorial
 * @return el resultado de la operacion.
 */
long int factorizar(int a);
/**
 * Funcion que verifica el fin del programa
 * @return devuelve char Y / N
 */
char salir();
/**
 * Funcion que muestra todas las operaciones realizadas;
 * @param suma el resultado de la suma
 * @param resta el resultado de la resta
 * @param multiplicacion el resultado de la multiplicacion
 * @param division el resultado de la division
 */
void mostrarResultados(int suma, int resta, int multiplicacion, int division, long long int factorial1, long long int factorial2);



#endif /* CALCULOS_H_ */
