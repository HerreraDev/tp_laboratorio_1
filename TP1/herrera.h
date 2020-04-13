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
*\brief factoriza el numero ingresado
*\param numero1 es donde se guardara el numero a factorizar
*\return devuelve el resultado del factoreo
*/
int factoreo(int numero1);

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

/**
*
*\brief realiza una animacion de apagado
*\return 0
*
*/
int animacionApagado();

/**
*
*\brief es la funcion encargada de ejecutar todo
*
*/
void calculadoraFinal();

/**
*
*\brief ejecuta el primer ingreso
*
*/
void ingresoPrimerNumero();

/**
*
*\brief ejecuta el segundo ingreso
*
*/
void ingresoSegundoNumero();

/**
 *
 * \brief resetea todas las variables declaradas anteriormente
 *
 */
void reseteoVariables();

/**
 * \brief verifica que la cadena de caracteres ingresada no sean letras
 * \param numero[] es el vector que contiene la cadena
 * \return devuelve 0 si hubo letras, devuelve 1 si no hubo
 *
 */
int validar_numero(char numero[]);

/**
*
* \brief calcula las operaciones
*
*/
void calcularOperaciones();
#endif // HERRERA_H_INCLUDED
