#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

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
//Variable del bucle
char seguir = 's';


float ingreseUnNumero()
{
    float numero1;
    printf("            Ingrese un numero: ");
    scanf("%f", &numero1);
    /*float resultadoValido;
    char numero1[6];
    int auxiliarValidacion;
    do
    {
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%s", numero1);
        auxiliarValidacion=validar_numero(numero1);
    }
    while(auxiliarValidacion==0);

    resultadoValido = atof(numero1);*/
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


int factoreo(int numero1)
{
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


void calculadoraFinal()
{
    do
    {
        switch(menu())
        {
        case 1:
            ingresoPrimerNumero();
            break;
        case 2:
            ingresoSegundoNumero();
            break;
        case 3:
            calcularOperaciones();
            break;
        case 4:
            mostrarResultados();
            break;

        case 5:
            animacionApagado();
            break;
        default:
            printf("Error. Ingrese una opcion correcta\n");
            system("pause");
            fflush(stdin);
            break;
        }

    }
    while(seguir=='s');
}


void ingresoPrimerNumero()
{
    num1 = ingreseUnNumero();
    flagNumero1 = 1;
}


void ingresoSegundoNumero()
{
    if(flagNumero1==0)
    {
        printf("Debe ingresar el primero numero antes que el segundo\n");
        system("pause");
    }
    else
    {
        num2 = ingreseUnNumero();
        flagNumero2 = 1;
    }

}


void calcularOperaciones()
{
    if (flagNumero1==1 && flagNumero2==1)
    {
        system("cls");
        printf("Calcular la suma (%.2f + %.2f)\n",num1,num2);
        resultadoSuma = suma(num1,num2);
        printf("Calcular la resta(%.2f - %.2f)\n",num1,num2);
        resultadoResta = resta(num1,num2);
        printf("Calcular la division(%.2f / %.2f)\n",num1,num2);
        resultadoDivision = division(num1,num2);
        printf("Calcular la multiplicación (%.2f * %.2f)\n",num1,num2);
        resultadoMultiplicacion = multiplicacion(num1,num2);
        printf("Calcular el factorial (A=%.2f)!  (B=%.2f)!\n",num1,num2);
        factorialNum1 = factoreo(num1);
        factorialNum2 = factoreo(num2);
        flagOperaciones = 1;
        if(num2==0)
        {
            printf("Recuerde que el segundo operando es 0, por lo que no se podra dividir ni factorial");
        }
        system("pause");
        system("cls");
    }
    else
    {
        printf("No se pueden calcular las operaciones ya que no ingreso los dos operandos.");
        system("pause");
    }
}


void mostrarResultados()
{
    if(flagOperaciones == 1)
    {
        /////////
        printf("El resultado de %.2f + %.2f es: %.2f \n", num1,num2,resultadoSuma);
        /////////
        printf("El resultado de %.2f - %.2f es: %.2f \n", num1,num2,resultadoResta);
        /////////
        if(num2==0)
        {
            printf("No es posible dividir por cero\n");
        }
        else
        {
            printf("EL resultado de %.2f / %.2f es: %.2f \n", num1,num2,resultadoDivision);
        }
        ////////
        printf("El resultado de %.2f * %.2f es: %.2f \n", num1,num2,resultadoMultiplicacion);
        ////////
        if(num1 >= 0 && num1<12)
        {
            printf("El factorial de %.2f es: %d\n",num1,factorialNum1);
        }
        else if(num1 < 0)
        {
            printf("No se puede calcular el factorial de numeros negativos.");
        }
        else
        {
            printf("El factorial de %.2f excede el espacio de la variable.\n",num1);
        }

        ///////
        if(num2 >= 0 && num2 < 12)
        {
            printf("El factorial de %.2f es: %d\n",num2,factorialNum2);
        }
        else if (num2 < 0)
        {
            printf("No se puede calcular el factorial de numeros negativos.\n");
        }
        else
        {
            printf("El factorial de %.2f excede el espacio de la variable.\n",num2);
        }
        flagVistaResultados = 1;
        system("pause");
    }
    else
    {
        printf("No se pueden mostrar los resultados ya que no se realizaron las operaciones previamente\n");
        system("pause");
    }

}


int animacionApagado()
{
    Beep(1500,200);
    Beep(1500,200);
    system("cls");
    system("color 5");
    printf("Apagando..");
    seguir = 'n';
    return 0;
}


int menu()
{

    int opcion;
    system("cls");
    printf("            ##################################################################\n");
    printf("            #                       Calculadora                              #\n");
    printf("            ##################################################################\n");
    printf("            #                      Menu de opciones                          #\n");
    printf("            ##################################################################\n");
    if(flagNumero1==0)
    {
        printf("            ******************************************************************\n");
        printf("                             1- Ingrese el 1er operando (A=x)                 \n");
        printf("            ******************************************************************\n");
    }
    else
    {
        printf("            ******************************************************************\n");
        printf("                             1- Ingrese el 1er operando (A=%.2f)             \n",num1);
        printf("            ******************************************************************\n");
    }
    if(flagNumero2==0)
    {
        printf("            ******************************************************************\n");
        printf("                             2- Ingrese el 2do operando (B=y)                 \n");
        printf("            ******************************************************************\n");
    }
    else

    {
        printf("            ******************************************************************\n");
        printf("                             2- Ingrese el 2do operando (B=%.2f)             \n",num2);
        printf("            ******************************************************************\n");
    }
    printf("            ##################################################################\n");
    printf("            #                3- Calcular todas las operaciones               #\n");
    printf("            #                4- Mostrar las operaciones                      #\n");
    printf("            #                5- Salir                                        #\n");
    printf("            ##################################################################\n");
    printf("            Elija una opcion: ");

    scanf("%d", &opcion);

    return opcion;
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


/*int validar_numero(char numero[])
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
}*/
