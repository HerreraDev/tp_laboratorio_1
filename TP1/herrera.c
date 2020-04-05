#include <stdio.h>
#include <stdlib.h>

#include "herrera.h"

//Variables que contendran los numeros a operar.
float num1, num2,resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision;


float ingreseUnNumero()
{
    float numero1;
    printf("Ingrese un numero: ");
    scanf("%f", &numero1);
    return numero1;
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

void mostrarResultados()
{
    printf("La suma de %.2f y %.2f es: %.2f \n", num1,num2,resultadoSuma);
    printf("La resta de %.2f y %.2f es: %.2f \n", num1,num2,resultadoResta);
    printf("La multiplicacion de %.2f y %.2f es: %.2f \n", num1,num2,resultadoMultiplicacion);
    printf("La division de %.2f y %.2f es: %.2f \n", num1,num2,resultadoDivision);

    system("pause");
}

int menu()
{
    int opcion;
    system("cls");
    printf("Menu de opciones\n\n");
    printf("1- Ingrese el 1er operando\n");
    printf("2- Ingrese el 2do operando\n");
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



