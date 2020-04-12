#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "herrera.h"

//Variables que contendran los numeros a operar.
float num1=0, num2=0;
float resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision;
//Variables para los factoriales
int factorialNum1;
int factorialNum2;
//Banderas
int flagNumero1 = 0;
int flagNumero2 = 0;
int flagOperaciones = 0;
int flagVistaResultados = 0;

float ingreseUnNumero()
{
    float resultadoValido;
    char numero1[6];
    int auxiliarValidacion;
    do
    {
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%s", numero1);
        auxiliarValidacion=validar_numero(numero1);
    }while(auxiliarValidacion==0);

    resultadoValido = atof(numero1);
    return resultadoValido;
}


float suma(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 + numero2;
    return resultado;
}

float resta(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 - numero2;
    return resultado;
}

float multiplicacion(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 * numero2;
    return resultado;
}

float division(float numero1, float numero2)
{
    float resultado;
    resultado = (float)numero1 / numero2;

    return resultado;
}

int factoreo(int numero1){
	 int contadorFactoreo;
	 unsigned long long factorial;
	 factorial=1;
        if(numero1<0)
        {
            factorial =0;
        }
        else if(numero1==0)
        {
            factorial=1;
        }
        else
        {
             for (contadorFactoreo = 1; contadorFactoreo <= numero1; contadorFactoreo++)
             {
                    factorial = factorial * contadorFactoreo;
             }
	    }

	  return factorial;
}




void mostrarResultados()
{
    printf("El resultado de %.2f + %.2f es: %.2f \n", num1,num2,resultadoSuma);
    printf("El resultado de %.2f - %.2f es: %.2f \n", num1,num2,resultadoResta);
    printf("EL resultado de %.2f / %.2f es: %.2f \n", num1,num2,resultadoDivision);
    printf("El resultado de %.2f * %.2f es: %.2f \n", num1,num2,resultadoMultiplicacion);
    printf("El factorial de %.2f es: %d\n",num1,factorialNum1);
    printf("El factorial de %.2f es: %d\n",num2,factorialNum2);
    flagVistaResultados = 1;
    system("pause");
}

int menu()
{
    int opcion;
    system("cls");
    printf("Menu de opciones\n\n");
    printf("1- Ingrese el 1er operando (A=%.2f)\n",num1);
    printf("2- Ingrese el 2do operando (B=%.2f)\n",num2);
    printf("3- Calcular todas las operaciones\n");
    printf("4- Mostrar las operaciones\n");
    printf("5- Salir\n\n");
    scanf("%d", &opcion);

    return opcion;
}

int animacionApagado()
{
    system("cls");
    printf("Apagando..");
    return 0;
}

void calculadoraFinal()
{
    char seguir = 's';
    do{
    switch(menu())
    {
    case 1:
         ingresoPrimerNumero();
         break;
    case 2:
         if(flagNumero1==0)
            {
                printf("Debe ingresar el primero numero antes que el segundo\n");
                system("pause");
            }
         else
            {
                ingresoSegundoNumero();
            }
         break;
    case 3:
            if (flagNumero1==1 && flagNumero2==1)
            {
                if(num2 == 0)
                    {
                        system("cls");
                        printf("Error no se puede dividir por 0\n");
                        printf("A continuacion debera ingresar los operadores nuevamente\n");
                        system("pause");
                        reseteoVariables();
                        calculadoraFinal();
                    }
                else
                    {
                        printf("Calcular la suma (%.2f + %.2f)\n",num1,num2);resultadoSuma = suma(num1,num2);
                        printf("Calcular la resta(%.2f - %.2f)\n",num1,num2);resultadoResta = resta(num1,num2);
                        printf("Calcular la division(%.2f / %.2f)\n",num1,num2);resultadoDivision = division(num1,num2);
                        printf("Calcular la multiplicación (%.2f * %.2f)\n",num1,num2);resultadoMultiplicacion = multiplicacion(num1,num2);
                        printf("Calcular el factorial (A=%.2f)!  (B=%.2f)!\n",num1,num2);factorialNum1 = factoreo(num1);
                        factorialNum2 = factoreo(num2);
                        printf("Operaciones realizadas con exito\n");
                        system("pause");
                        system("cls");
                    }
             flagOperaciones = 1;
            }
            else
            {
                printf("No se pueden realizar las operaciones ya que no ingreso los dos operandos\n");
                system("pause");
            }

         break;
    case 4:
         if(flagOperaciones == 1)
         {
            mostrarResultados();
         }
         else
         {
             printf("No se pueden mostrar los resultados ya que no se realizaron las operaciones previamente\n");
             system("pause");
         }
         break;

    case 5:
         animacionApagado();
         seguir = 'n';
        break;
    default:
        printf("Error. Ingrese una opcion correcta\n");
        system("pause");
        fflush(stdin);
        break;
    }

    }while(seguir=='s');
}

void ingresoPrimerNumero()
{
    num1 = ingreseUnNumero();
    flagNumero1 = 1;
}

void ingresoSegundoNumero()
{
    num2 = ingreseUnNumero();
    flagNumero2 = 1;

}

void reseteoVariables()
{
    num1 = 0;
    num2 = 0;
    resultadoSuma = 0;
    resultadoResta = 0;
    resultadoMultiplicacion = 0;
    resultadoDivision = 0;
    factorialNum1 = 0;
    factorialNum2 = 0;
    flagNumero1 = 0;
    flagNumero2 = 0;
    flagOperaciones = 0;
    flagVistaResultados = 0;
}

int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("\nINGRESA SOLO NUMEROS\n");
            system("pause");
            return 0;
        }
    }
    return 1;
}
