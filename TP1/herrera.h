#ifndef HERRERA_H_INCLUDED
/**
*
*\brief pide un ingreso de numero flotante al usuario
*\param numero1, es la variable donde se guarda el numero ingresado
*\return retorna el numero ingresado
*
*/
int ingreseUnNumero();


/**
*
*\brief suma dos numeros flotantes
*\param numero1, es el primero numero flotante a sumar
*\param numero2, es el segundo numero flotante a sumar
*\param resultado, es donde se guarda la suma
*\return retorna el resultado de la suma
*
*/
int suma(int numero1, int numero2);


/**
*
*\brief resta dos numeros flotantes
*\param numero1, es el primero numero flotante a restar
*\param numero2, es el segundo numero flotante a restar
*\param resultado, es donde se guarda la resta
*\return retorna el resultado de la resta
*
*/
int resta(int numero1, int numero2);


/**
*
*\brief multiplica dos numeros flotantes
*\param numero1, es el primero numero flotante a multiplicar
*\param numero2, es el segundo numero flotante a multiplicar
*\param resultado, es donde se guarda la multiplicacion
*\return retorna el resultado de la multiplicacion
*
*/
int multiplicacion(int numero1, int numero2);


/**
*
*\brief divide dos numeros flotantes
*\param numero1, es el primero numero flotante a dividir
*\param numero2, es el segundo numero flotante a dividir
*\param resultado, es donde se guarda la division
*\return retorna el resultado de la division
*
*/
float division(int numero1, int numero2);

/**
*
*\brief factoriza el numero ingresado
*\param numero1 es donde se guardara el numero a factorizar
*\return devuelve el resultado del factoreo
*/
int factoreo(int numero1);


/**
*
*\brief despliega un menu con opciones y realiza
*\param numero1, guardara el valor del numero que se le paso en la llamada y sera utilizada para mostrar el numero en el menu
*\param numero2, guardara el valor del numero que se le paso en la llamada y sera utilizada para mostrar el numero en el menu
*\param flagNum1, guardara el valor de la bandera que se le paso en la llamada de la funcion y sera utilizada dentro de un if
*\param flagNum2, guardara el valor de la bandera que se le paso en la llamada de la funcion y sera utilizada en un if
*\return retorna el numero elegido
*
*/
int menu(int numero1, int numero2, int flagNum1, int flagNum2);

/**
*
*\brief realiza una animacion de apagado
*
*/
void animacionApagado();

/**
 *
 * \brief reseteara a 0 los valores de las variables que recibira
 * \param flag es la variable a la que se le cambiara el valor
 *
 */
void resetearFlags(int* flag);

#endif // HERRERA_H_INCLUDED
#define HERRERA_H_INCLUDED



