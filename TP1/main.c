#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "herrera.h"

int main()
{

//Variables que contendran los numeros a operar.
    int num1=0, num2=0;
    int resultadoSuma,resultadoResta,resultadoMultiplicacion;
    float resultadoDivision;
//Variables para los factoriales
    int factorialNum1;
    int factorialNum2;
//Banderas
    int flagNumero1 = 0;
    int flagNumero2 = 0;
    int flagOperaciones = 0;
//Variable del bucle
    char seguir = 's';

    do
    {
        switch(menu(num1,num2,flagNumero1,flagNumero2))
        {
        case 1:
            num1 = ingreseUnNumero();
            flagNumero1 = 1;
            break;
        case 2:
            if(flagNumero1 == 0)
            {
                printf("No se puede ingresar el segundo operando, ya que no se ingreso el primero\n");
                system("pause");
            }
            else
            {
                num2 = ingreseUnNumero();
                flagNumero2 = 1;
            }

            break;
        case 3:
            if (flagNumero1==0 && flagNumero2==0)
            {
                printf("No se pueden calcular las operaciones ya que no ingreso los dos operandos.\n");
                system("pause");
            }
            else
            {
                printf("##################################################################\n");
                printf("Se calculara la suma (%d + %d)\n",num1,num2);
                resultadoSuma = suma(num1,num2);
                printf("Se calculara la resta(%d - %d)\n",num1,num2);
                resultadoResta = resta(num1,num2);
                printf("Se calculara la division(%d / %d)\n",num1,num2);
                resultadoDivision = division(num1,num2);
                printf("Se calculara la multiplicación (%d * %d)\n",num1,num2);
                resultadoMultiplicacion = multiplicacion(num1,num2);
                printf("Se calculara el factorial (A=%d)!  (B=%d)!\n",num1,num2);
                printf("##################################################################\n");
                factorialNum1 = factoreo(num1);
                factorialNum2 = factoreo(num2);
                if(num2==0)
                {
                    printf("Recuerde que el segundo operando es 0, por lo que no se podra dividir.\n");
                }
                system("pause");
                system("cls");
                flagOperaciones = 1;
            }
            break;
        case 4:
            if(flagOperaciones == 0)
            {
                printf("No se pueden mostrar los resultados ya que no se realizaron las operaciones previamente\n");
                system("pause");
            }
            else
            {
                printf("##################################################################\n");
                printf("El resultado de %d + %d es: %d \n", num1,num2,resultadoSuma);
                printf("El resultado de %d - %d es: %d \n", num1,num2,resultadoResta);

                if(num2==0)
                {
                    printf("No es posible dividir por cero\n");
                }
                else
                {
                    printf("EL resultado de %d / %d es: %.2f \n", num1,num2,resultadoDivision);
                }

                printf("El resultado de %d * %d es: %d \n", num1,num2,resultadoMultiplicacion);

                if(num1 >= 0 && num1<=12)
                {
                    printf("El factorial de %d es: %d\n",num1,factorialNum1);
                }
                else if(num1 < 0)
                {
                    printf("No se puede calcular el factorial de numeros negativos.\n");
                }
                else
                {
                    printf("El factorial de %d excede el espacio de la variable.\n",num1);
                }

                if(num2 >= 0 && num2 <= 12)
                {
                    printf("El factorial de %d es: %d\n",num2,factorialNum2);
                }
                else if (num2 < 0)
                {
                    printf("No se puede calcular el factorial de numeros negativos.\n");
                }
                else
                {
                    printf("El factorial de %d excede el espacio de la variable.\n",num2);
                }
                printf("##################################################################\n");
                printf("       RECUERDE QUE UNA VEZ MOSTRADOS LOS RESULTADOS              \n");
                printf("       SE REINICIARAN LOS VALORES                                 \n");
                printf("##################################################################\n");
                resetearFlags(&flagNumero1);
                resetearFlags(&flagNumero2);
                resetearFlags(&flagOperaciones);
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

    return 0;
}






