#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

int menu();

int initEmployees(eEmployee listado[], int len);

//devuelve el indice del id ingresado
int findEmployeeById(int id, eEmployee vec[], int tam);

//devuelve el indice del que esta vacio en vector lista
int buscarLibre(eEmployee vec[], int tam);

//
void altaEmpleado(eEmployee vec[], int tam);

//
int printEmployees(eEmployee* lista, int tam);

//
void mostrarEmpleado(eEmployee empleado);

//añade a la lista los valores recibidos por parametro en la primera posicion libre
//int addEmployee(eEmployee* lista, int len, int id, char name[],char lastname[],float salary, int sector);

int removeEmployee(eEmployee* lista, int len, int id);


#endif // ARRAYEMPLOYEES_H_INCLUDED
