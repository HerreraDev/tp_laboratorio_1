#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "herrera.h"


int ingreseUnNumero()
{
    int numero;
    printf("            Ingrese un numero: ");
    scanf("%d", &numero);
    system("pause");
    return numero;
}


int suma(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 + numero2;
    return resultado;
}


int resta(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 - numero2;
    return resultado;
}


int multiplicacion(int numero1, int numero2)
{
    int resultado;
    resultado = numero1 * numero2;
    return resultado;
}


float division(int numero1, int numero2)
{
    float resultado;
    resultado = (float)numero1 / numero2;

    return resultado;
}


int factoreo(int numero1)
{
    int contadorFactoreo;
    unsigned long long factorial;
    factorial=1;
    if(numero1==0)
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


void animacionApagado()
{
    printf("##################################################################\n");
    printf("Hasta luego.\n");
    printf("Apagando..\n");
    printf("##################################################################\n");
    Beep(1500,200);
    system("color 1");
    Beep(1500,200);
    system("color 2");
    Beep(1500,200);
    system("color 3");
    Beep(1500,200);
    system("color 4");
}



int menu(int numero1, int numero2, int flagNum1, int flagNum2)
{
    int opcion;
    system("cls");
    printf("##################################################################\n");
    printf("#                       Calculadora                              #\n");
    printf("##################################################################\n");
    printf("#                      Menu de opciones                          #\n");
    printf("##################################################################\n");
    if(flagNum1==0)
    {
        printf("******************************************************************\n");
        printf("                 1- Ingrese el 1er operando (A=x)                 \n");
        printf("******************************************************************\n");
    }
    else
    {
        printf("******************************************************************\n");
        printf("                 1- Ingrese el 1er operando (A=%d)             \n",numero1);
        printf("******************************************************************\n");
    }
    if(flagNum2==0)
    {
        printf("******************************************************************\n");
        printf("                 2- Ingrese el 2do operando (B=y)                 \n");
        printf("******************************************************************\n");
    }
    else

    {
        printf("******************************************************************\n");
        printf("                 2- Ingrese el 2do operando (B=%d)             \n",numero2);
        printf("******************************************************************\n");
    }
    printf("##################################################################\n");
    printf("#                3- Calcular todas las operaciones               #\n");
    printf("#                4- Mostrar las operaciones                      #\n");
    printf("#                5- Salir                                        #\n");
    printf("##################################################################\n");
    printf("                 Elija una opcion: ");

    scanf("%d", &opcion);

    return opcion;
}


void resetearFlags(int* flag)
{

    *flag = 0;
}
