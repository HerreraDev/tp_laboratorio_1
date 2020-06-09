#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
typedef struct
{
    int id;
    char nombre[120];
    char sexo;
    float sueldo;

} eEmpleado;

eEmpleado* new_Empleado();
eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo);

int mostrarEmpleado(eEmpleado* empleado);
int mostrarEmpleados(LinkedList* lista);

int compararEmpleadosId(void* emp1, void* emp2);


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    eEmpleado* auxEmpleado; //creo empleado

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

    mostrarEmpleados(listaEmpleados);




    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

eEmpleado* new_Empleado()
{
    return (eEmpleado*) malloc(sizeof(eEmpleado));
}

eEmpleado* new_EmpleadoParam(int id, char* nombre, char sexo, float sueldo)
{
    eEmpleado* nuevaPersona;

    nuevaPersona = new_Empleado();

    if(nuevaPersona != NULL)
    {
        //Aca habria que validar todos los datos.
        /*if(personaSetId(nuevaPersona,id)
                || personaSetNombre(nuevaPersona,nombre)
                || personaSetSexo(nuevaPersona,sexo)
                || personaSetAltura(nuevaPersona,altura)
          )
        {
            free(nuevaPersona);
            nuevaPersona = NULL;
        }*/

        //si alguno de los datos fueron incorrectos se pone
        nuevaPersona->id = id;
        strcpy(nuevaPersona->nombre,nombre);
        nuevaPersona->sexo = sexo;
        nuevaPersona->sueldo = sueldo;
    }
    return nuevaPersona;
}

int mostrarEmpleado(eEmpleado* empleado)
{
    int error = 1;

    if(empleado != NULL)
    {
        printf("%d   %10s           %c          %.2f\n",empleado->id,empleado->nombre,empleado->sexo,empleado->sueldo);
        error = 0;
    }
    return error;
}

int mostrarEmpleados(LinkedList* lista)
{
    int error = 1;
    int flag = 0;
    if(lista != NULL)
    {
        printf("ID          NOMBRE          SEXO       SUELDO\n");
        for(int i=0; i < ll_len(lista); i++)
        {
            if( ((eEmpleado*) ll_get(lista,i)) != NULL) //devuelve puntero a void casteada a puntero empleado
            {
                mostrarEmpleado((eEmpleado*) ll_get(lista,i));
                flag = 1;
            }

        }
        if(flag==0)
        {
            printf("No hay personas para mostrar\n");
        }
        error = 0;
    }
    return error;
}

int compararEmpleadosId(void* emp1, void* emp2)
{
    int rta;
    eEmpleado* a = (eEmpleado*) emp1; //casteo porque vienen puntero a void
    eEmpleado* b = (eEmpleado*) emp2;

    if(a->id == b->id)
    {
        rta = 0;
    }
    else if(a->id > b->id)
    {
        rta = -1;
    }
    else
    {
        rta = 1;
    }
    return rta;
}
