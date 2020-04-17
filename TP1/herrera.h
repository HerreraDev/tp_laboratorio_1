#ifndef HERRERA_H_INCLUDED
/**
*
*\brief pide un ingreso de numero entero al usuario
*\return retorna el numero ingresado
*
*/
int ingreseUnNumero();


/**
*
*\brief suma dos numeros entero
*\param numero1, es el primero numero entero a operar
*\param numero2, es el segundo numero entero a operar
*\return retorna el resultado de la suma
*
*/
int suma(int numero1, int numero2);


/**
*
*\brief resta dos numeros enteros
*\param numero1, es el primero numero entero a operar
*\param numero2, es el segundo numero entero a operar
*\return retorna el resultado de la resta
*
*/
int resta(int numero1, int numero2);


/**
*
*\brief multiplica dos numeros enteros
*\param numero1, es el primero numero entero a operar
*\param numero2, es el segundo numero entero a operar
*\return retorna el resultado de la multiplicacion
*
*/
int multiplicacion(int numero1, int numero2);


/**
*
*\brief divide dos numeros enteros
*\param numero1, es el primero numero entero a operar
*\param numero2, es el segundo numero entero a operar
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
*\brief despliega un menu con opciones
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



