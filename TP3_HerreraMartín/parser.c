#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int cant;
    char buffer[4][1000];

    Employee* auxEmployee;

    //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]); //devuelve un entero con la cantidad de variables que cargo.

    while(!feof(pFile)) //feof es find end of file, mientras no haya llegado al final del archivo, avanzar linea a linea.
    {
        auxEmployee = employee_new();
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]); //devuelve un entero con la cantidad de variables que cargo.
        if(cant == 4)//cantidad de variables a cargar es cant.
        {
            auxEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            ll_add(pArrayListEmployee,auxEmployee);
            retorno = 0;
        }
        else
        {
            break;
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pEmpleado;
    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        while(!feof(pFile))
        {
            pEmpleado=employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee,pEmpleado);
            }
            else
            {
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}
