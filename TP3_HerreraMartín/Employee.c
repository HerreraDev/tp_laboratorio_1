#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"

int initPersonas(LinkedList* lista)
{
    int todoOk = 0;
    if (lista != NULL)
    {
        for(int i = 0; i < ll_len(lista); i++)
        {
            lista = NULL;
        }
        todoOk = 1;
    }

    return todoOk;
}

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr) //modificar lo que ya usamos en la ultima clase.
{
    Employee* newEmployee;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if(employee_setId(newEmployee,atoi(idStr))
                || employee_setNombre(newEmployee,nombreStr)
                || employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr))
                || employee_setSueldo(newEmployee,atoi(sueldoStr))
          )
        {
            free(newEmployee);
            newEmployee = NULL;
        }
        else
        {
            newEmployee->id = atoi(idStr);
            strcpy(newEmployee->nombre,nombreStr);
            newEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
            newEmployee->sueldo =  atoi(sueldoStr);
        }

    }
    return newEmployee;
}

/*void employee_delete()
{
    int error = 1;

    if(persona != NULL)
    {
        free(persona);
        error = 0;
    }

    return error;
}*/

int employee_setId(Employee* this,int id)
{
    int error = 1;
    if(this!=NULL && id > 0 && id <= 20000)
    {
        this->id = id;
        error = 0;
    }
    return error;
}
int employee_getId(Employee* this,int* id)
{
    int error = 1;
    if(this!=NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this!=NULL && strlen(nombre) >= 3 && strlen(nombre) < 128)
    {
        strcpy(this->nombre,nombre);
        error = 0;
    }
    return error;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }
    return error;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = 1;
    if(this!=NULL && horasTrabajadas > 0 && horasTrabajadas <= 100000)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }
    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = 1;
    if(this!=NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 1;
    if(this!=NULL && sueldo > 0 && sueldo <= 100000)
    {
        this->sueldo = sueldo;
        error = 0;
    }
    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;
    if(this!=NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;
}

int mostrarEmpleado(Employee* empleado)
{
    int error = 1;

    if(empleado != NULL)
    {
        printf("%4d         %20s                %4d                   %d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
        error = 0;
    }
    return error;
}

/*int findEmployeeById(Employee* lista, int id)
{
    int pIndice = -1;
    int len = ll_len(lista);

    if(lista != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(*(lista + i) != NULL && (*(lista+i))-> id == id)
            {
                pIndice = i;
                break;
            }
        }
    }

    return pIndice;
}*/
