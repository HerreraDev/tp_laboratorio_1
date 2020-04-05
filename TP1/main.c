#include <stdio.h>
#include <stdlib.h>
#include "herrera.h"

int menu();
float num1, num2, resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision;
int main()
{
    char seguir = 's';
    do{


    switch(menu())
    {
    case 1:
         num1 = ingreseUnNumero();
         break;
    case 2:
         num2 = ingreseUnNumero();
         break;
    case 3:
         resultadoSuma = suma(num1,num2);
         resultadoResta = resta(num1,num2);
         resultadoMultiplicacion = multiplicacion(num1,num2);
         resultadoDivision = division(num1,num2);
         printf("Las operaciones se realizaron con exito!\n");
         system("pause");
         break;
    case 4:
         mostrarResultados();
         break;
    }


    }while(seguir=='s');


    return 0;
}
//x

int menu()
{
    int opcion;
    system("cls");
    printf("Menu de opciones\n\n");
    printf("1- Ingrese el 1er operando\n");
    printf("2- Ingrese el 2do operando\n");
    printf("3- Calcular todas las operaciones\n");
    printf("4- Mostrar las operaciones\n");
    printf("5- Desea continuar operando? s/n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
