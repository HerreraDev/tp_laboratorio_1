#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "validacionesHerrera.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }

            fclose(pFile);
        }
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"rb");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }

            fclose(pFile);
        }
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int succes = -1;
    int index = -1;
    int id;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(utn_getNumero(&id,"Ingrese el id a eliminar: ","\nError, por favor ingrese un id valido.\n",0,20000,3) != -1)
        {

            index = ll_indexOf(pArrayListEmployee,(Employee*) ll_get(pArrayListEmployee,id));

            if(index == 0)
            {
                printf("No hay empleados con el id: %d .\n",id);
                system("pause");
            }
            else
            {

                printf("El empleado a eliminar es el siguiente: \n\n");

                printf("ID                       NOMBRE                  HORAS TRABAJADAS       SUELDO\n");

                mostrarEmpleado((Employee*) ll_get(pArrayListEmployee,index));

                ll_remove(pArrayListEmployee, index);
                printf("\nEmpleado eliminado!!\n");
                succes = 0;
            }
        }
        else
        {
            printf("Error. Gastaste los intentos\n");
        }
    }

    return succes;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int flag = 0;
    if(pArrayListEmployee != NULL)
    {
        printf("ID                       NOMBRE                  HORAS TRABAJADAS       SUELDO\n");
        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if( ((Employee*) ll_get(pArrayListEmployee,i)) != NULL) //devuelve puntero a void casteada a puntero empleado
            {
                mostrarEmpleado((Employee*) ll_get(pArrayListEmployee,i));
                flag = 1;
            }

        }
        if(flag==0)
        {
            printf("No hay personas para mostrar\n");
        }
    }
    return flag;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        int orden;
        if(utn_getNumero(&orden,"1-Ascendente\n 0-Descendente\n","Error, opcion invalida\n",0,1,3)!= -1)
        {
            if(orden == 0)
            {
                ll_sort(pArrayListEmployee,compararEmpleadosNombre,0);
            }
            if(orden == 1)
            {
                ll_sort(pArrayListEmployee,compararEmpleadosNombre,1);
            }
        }
        else
        {
            printf("No te quedan intentos\n");
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pArrayListEmployee != NULL)
    {
        FILE* archivo =  fopen(path,"w");
        Employee* auxEmployee;
        if(archivo!=NULL)
        {
            for(int i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);
                if(auxEmployee!=NULL)
                {
                    fprintf(archivo,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                    error = 0;
                }
            }
        }
        fclose(archivo);

    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pArrayListEmployee != NULL)
    {
        FILE* archivo =  fopen(path,"wb");
        Employee* auxEmployee;
        if(archivo!=NULL)
        {
            for(int i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);
                if(auxEmployee!=NULL)
                {
                    fwrite(auxEmployee,sizeof(Employee),1,archivo);
                    error = 0;
                }
            }
        }
        fclose(archivo);

    }
    return error;
}

