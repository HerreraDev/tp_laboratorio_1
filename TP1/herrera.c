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





