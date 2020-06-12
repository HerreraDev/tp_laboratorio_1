#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesHerrera.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int menu();

int main()
{
    char continuar = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    /*eEmpleado* auxEmpleado; //creo empleado

    auxEmpleado = new_EmpleadoParam(1111,"Pepe",'m',32500.60); //lo hardcodeo
    ll_add(listaEmpleados,auxEmpleado); //lo añado a la lista de linkedlist

    auxEmpleado = new_EmpleadoParam(1188,"Ana",'f',45500.50); //lo hardcodeo
    ll_add(listaEmpleados,auxEmpleado); //lo añado a la lista de linkedlist

    auxEmpleado = new_EmpleadoParam(1155,"Miguel",'m',50500.50); //lo hardcodeo
    ll_add(listaEmpleados,auxEmpleado); //lo añado a la lista de linkedlist

    auxEmpleado = new_EmpleadoParam(1133,"Juan",'m',38500.60); //lo hardcodeo
    ll_add(listaEmpleados,auxEmpleado); //lo añado a la lista de linkedlist

    //printf("%d\n",ll_len(listaEmpleados)); //veo la cantidad de elementos que hay en la lista

    //mostrarEmpleados(listaEmpleados);

    //ll_remove(listaEmpleados,2); //Eliminar

    auxEmpleado = (eEmpleado*) ll_get(listaEmpleados,2);

    auxEmpleado->sueldo = 40000; //Modificar dato

    ll_sort(listaEmpleados,compararEmpleadosId,0);

    mostrarEmpleados(listaEmpleados);*/
//  initPersonas(listaEmpleados);


    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("Problemas para cargar los empelados.\n");

            }
            else
            {
                printf("Empelados cargados con exitos.\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("Problemas para cargar los empelados.\n");
            }
            else
            {
                printf("Empelados cargados con exitos.\n");
            }
            break;
        case 3:
            break;
        case 4:
            if(ll_isEmpty(listaEmpleados)!=1)
            {
                printf("Puedo modif.\n");
            }
            else
            {
                printf("vacio");
            }
            break;
        case 5:
            if(ll_isEmpty(listaEmpleados)!=1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 6:
            if(ll_isEmpty(listaEmpleados)!=1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 7:
            if(ll_isEmpty(listaEmpleados)!=1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 8:
            if(ll_isEmpty(listaEmpleados)!=1)
            {
            controller_saveAsText("data.csv",listaEmpleados);

            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 9:
            if(ll_isEmpty(listaEmpleados)!=1)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 10:
            continuar = 'n';
            break;
        }
        system("pause");
        system("cls");
    }
    while(continuar == 's');

//    ll_deleteLinkedList(listaEmpleados);

    return 0;
}






int menu()
{
    int option;
    printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3- Alta de empleado.\n");
    printf("4- Modificar datos de empleado.\n");
    printf("5- Baja de empleado.\n");
    printf("6- Listar empleados.\n");
    printf("7- Ordenar empleados.\n");
    printf("8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9- Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10- Salir.\n");
    utn_getNumero(&option,"Elija una opcion: ","Error, opcion incorrecta.\n",1,10,3);
    return option;
}


