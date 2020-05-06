#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define TAM 2

int main()
{
    int proxId = 1000;
    char seguir = 's';
    int id;
    int auxInit; //Verifica si se pudo inicializar isEmpty en 1.
    eEmployee lista[TAM]; //{{1000,"Juan","Pedro",2000,2}};
    auxInit = initEmployees(lista,TAM); //Inicializo el vector y si hubo error, devuelve -1.
    if(auxInit != 0)
    {
        printf("Error, no se pudieron inicializar los isEmpty en 1");
    }

    do
    {
        switch(menu())
        {
        case 1 :
            altaEmpleado(lista,TAM,&proxId);
            break;
        case 2:
            printf("Modificar\n");
            break;
        case 3:
            printf("Ingrese id a eliminar: \n");
            scanf("%d",&id);
            removeEmployee(lista,TAM,id);

            break;
        case 4:
            printf("Ordenar\n");
            printEmployees(lista,TAM);
            break;
        case 5:
            seguir = 'n';
            printf("Hasta luego.\n");
            system("pause");
            break;
        default:
            printf("No es una opcion.\n\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');
    return 0;
}

