<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define TAM 1

int main()
{
    char seguir = 's';
    int id;
//    int auxInit; //Verifica si se pudo inicializar isEmpty en 1.
    eEmployee lista[TAM] = {{1000,"Juan","Pedro",2000,2}};
    //auxInit = initEmployees(lista,TAM); //Inicializo el vector.
    //if(auxInit != 0)
    //{
    //    printf("Error, no se pudieron inicializar los isEmpty en 1");
    //}

    do
    {
        switch(menu())
        {
        case 1 :
            altaEmpleado(lista,TAM);
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

=======
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
>>>>>>> c0d9e3a6ce09d9a898a33bc0fcea6b53d21a8135
