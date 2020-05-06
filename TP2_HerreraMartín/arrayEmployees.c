#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
int menu()
{
    int opcion;
    system("cls");
    printf("*********** Gestion de Empleados ***********\n");
    printf("1-Alta de empleado\n");
    printf("2-Modificacion de empleado\n");
    printf("3-Baja de empleado\n");
    printf("4-Informes\n");
    printf("Ingrese una opcion:");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int initEmployees(eEmployee listado[], int len)
{
    int retorno = -1;
    if(listado != NULL && len > 0)
    {
        for (int i = 0; i <  len; i++)
        {
            listado[i].isEmpty = 1;
        }
        retorno = 0;
    }

    return retorno;
}


//devuelve el indice del id ingresado
int findEmployeeById(eEmployee* lista, int len, int id)
{
    int indice = -1;
    if(lista != NULL && len > 0)
    {
        for(int i = 0; i<len; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty==0)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

//busca lugar libre en listado
int buscarLibre(eEmployee vec[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmployee vec[], int tam,int* proxId)
{
    int existe;
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;

    id=*proxId;

    existe = findEmployeeById(vec,tam,id);

    system("cls");
    printf("****Alta Empleado****\n\n");
    if(existe != -1)
    {
        printf("Ya existe un empleado con ese ID.\n");
    }
    else
    {

        printf("Ingerse nombre: ");
        fflush(stdin);
        gets(name);

        printf("Ingerse apellido: ");
        fflush(stdin);
        gets(lastname);

        printf("Ingerse sueldo: ");
        scanf("%f",&salary);

        printf("Ingrese sector: ");
        scanf("%d",&sector);
        addEmployee(vec,tam,id,name,lastname,salary,sector);

        //auxEmpleado.isEmpty = 0;
        //vec[indiceVacio] = auxEmpleado;
        (*proxId)++;

    }
    system("pause");

}

//Le tiene que llegar esos parametros y los tiene que meter en la indiveVacio posicion del vector lista de empleados
int addEmployee(eEmployee* lista, int len, int id, char name[],char lastname[],float salary, int sector)
{
    int retorno = -1;
    int indiceVacio;
    eEmployee auxEmpleado;

    indiceVacio = buscarLibre(lista,len);

    auxEmpleado.id = id;
    strcpy(auxEmpleado.name,name);
    strcpy(auxEmpleado.lastName,lastname);
    auxEmpleado.salary = salary;
    auxEmpleado.sector = sector;
    auxEmpleado.isEmpty = 0;

    if(lista != NULL && len > 0 && indiceVacio != -1)
    {
        lista[indiceVacio] = auxEmpleado;
    }


    return retorno;
}



void mostrarEmpleado(eEmployee empleado)
{
    printf("%d    %10s    %10s    %.2f    %2d\n",empleado.id,empleado.name,empleado.lastName,empleado.salary,empleado.sector);
}

int printEmployees(eEmployee* lista, int length)
{
    system("cls");
    int flag = 0;
    printf("******** Listado Empleados **********\n\n");
    printf("Id          Nombre      Apellido    Sueldo      Sector\n\n");
    for(int i = 0; i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i]);
            flag = 1 ;
        }
    }
    if(flag == 0)
    {
        printf("No hay empleados que listar\n\n");
    }
    system("pause");
    return 0;
}


int removeEmployee(eEmployee* lista, int len, int id)
{
    int retorno = -1;
    int indice;
    char confirma = 's';
    indice= findEmployeeById(lista,len,id);

    if(indice == -1)
    {
        printf("No hay registro de un empleado con el ID: %d \n",indice);
    }
    else
    {
        mostrarEmpleado(lista[indice]);
        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma== 's')
        {
            lista[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito!!\n");
            retorno = 0;
            system("pause");
        }
        else
        {
            system("cls");
            printf("Operacion cancelada\n");
            system("pause");
        }
    }
    return retorno;
}
