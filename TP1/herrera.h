#ifndef HERRERA_H_INCLUDED
#define HERRERA_H_INCLUDED


/**
*
*\brief pide un ingreso de numero flotante al usuario
*\param numero1, es la variable donde se guarda el numero ingresado
*\return retorna el numero ingresado
*
*/
float ingreseUnNumero();


/**
*
*\brief suma dos numeros flotantes
*\param numero1, es el primero numero flotante a sumar
*\param numero2, es el segundo numero flotante a sumar
*\param resultado, es donde se guarda la suma
*\return retorna el resultado de la suma
*
*/
float suma(float numero1, float numero2);


/**
*
*\brief resta dos numeros flotantes
*\param numero1, es el primero numero flotante a restar
*\param numero2, es el segundo numero flotante a restar
*\param resultado, es donde se guarda la resta
*\return retorna el resultado de la resta
*
*/
float resta(float numero1, float numero2);


/**
*
*\brief multiplica dos numeros flotantes
*\param numero1, es el primero numero flotante a multiplicar
*\param numero2, es el segundo numero flotante a multiplicar
*\param resultado, es donde se guarda la multiplicacion
*\return retorna el resultado de la multiplicacion
*
*/
float multiplicacion(float numero1, float numero2);


/**
*
*\brief divide dos numeros flotantes
*\param numero1, es el primero numero flotante a dividir
*\param numero2, es el segundo numero flotante a dividir
*\param resultado, es donde se guarda la division
*\return retorna el resultado de la division
*
*/
float division(float numero1, float numero2);


/**
*
*\brief mostrara el menu con los resultados de las operaciones
*\return 0
*
*/
void mostrarResultados();



/**
*
*\brief despliega un menu con opciones
*\param opcion, variable donde se guardara la opcion elegida
*\return retorna el numero elegido
*
*/
int menu();


int animacionApagado();
#endif // HERRERA_H_INCLUDED
