#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "utn.h"
#define TAM 1000

int main()
{
    int banderaPrimerIngreso = 0;
    int auxId;
    int proxId = 1000; //las Ids comenzaran en 1000.
    char seguir = 's';
    int id;
    int auxInit; //Verifica si se pudo inicializar isEmpty en 1.
    eEmployee lista[TAM];

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
            altaEmpleado(lista,TAM,&proxId,&banderaPrimerIngreso);
            break;
        case 2:
            if(banderaPrimerIngreso == 0)
            {
                printf("Sistema vacio, debe ingresar un empleado al menos.\n");
                system("pause");
            }
            else
            {
                modificarEmpleado(lista,TAM);
            }
            break;
        case 3:
            if(banderaPrimerIngreso == 0)
            {
                printf("Sistema vacio, debe ingresar un empleado al menos.\n");
                system("pause");
            }
            else
            {
            //El minimo es 1000 ya que la primer id es 1000, y en el maximo se pongo un numero grande que nunca se alcanzara.
            utn_getNumero(&id,"Ingrese id a eliminar: \n","Error, ingrese un numero mayor a 999",1000,20000000,3);
            auxId=id;
            removeEmployee(lista,TAM,auxId);
            }
            break;
        case 4:
            if(banderaPrimerIngreso == 0)
            {
                printf("Sistema vacio, debe ingresar un empleado al menos.\n");
                system("pause");
            }
            else
            {
            informes(lista,TAM);
            }
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

