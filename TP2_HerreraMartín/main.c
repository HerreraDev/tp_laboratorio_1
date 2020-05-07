#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define TAM 5

int main()
{
    int proxId = 1000;
    char seguir = 's';
    int id;
    int auxInit; //Verifica si se pudo inicializar isEmpty en 1.
    eEmployee lista[TAM] = {{1000,"Juan","Berto",2000,2},
                           {1001,"Juan","Casas",2000,3},
                           {1002,"Juan","Zamuel",2000,2},
                           {1003,"Juan","Kilos",2000,3},
                           {1004,"Juan","Anastasio",2000,2}};
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
            informes(lista,TAM);
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

