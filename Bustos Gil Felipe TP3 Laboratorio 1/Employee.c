#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"
#include <string.h>
#include "parser.h"
#include <ctype.h>



int buscarLibre( int* indice, Employee** vec, int tam)
{
    *indice = -1;
    int todoOk = 0;

    if( vec != NULL && indice != NULL)
    {
        todoOk=1;
        for(int i=0; i < tam;i++)
        {
            if( *(vec + i) == NULL)
            {
                *indice = i;
                break;
            }
        }
    }

    return todoOk;
}

int mostrarEmployees( LinkedList* lista)
{
    int todoOk=1;
    int tam;
    tam = ll_len(lista);
    printf("  Id         Nombre    Horas Trabajadas    Sueldo\n");

    for (int i=0; i<tam; i++)
    {
        mostrarEmployee(lista, i);
        todoOk=0;
    }
    return todoOk;
}

void mostrarEmployee( LinkedList* lista,int indice)
{
   Employee* employee;

    employee = ll_get(lista, indice);
    printf("%4d  %12s  %12d    %12d \n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);

}

int employee_setId(Employee* this,int id)
{
    int todoOk = 1;
    if(this != NULL && id>0)
    {
        this->id = id;
        todoOk=0;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
       *id = this->id;
       todoOk = 0;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL && strlen(nombre) <= 127)
    {
        strcpy(this->nombre,nombre);
        todoOk = 0;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 0;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 1;

    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 0;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 0;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 1;
    if(this != NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        todoOk=0;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 1;

    if(this != NULL && sueldo != NULL)
    {
       *sueldo = this->sueldo;
       todoOk = 0;
    }
    return todoOk;
}

Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee = employee_new();

        if(newEmployee != NULL)
        {
            employee_setId(newEmployee, atoi(idStr));
            employee_setNombre(newEmployee, nombreStr);
            employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
            employee_setSueldo(newEmployee, atoi(sueldoStr));
        }
        return newEmployee;
}

int employee_delete(Employee* employee)
{
    int retorno=1;
    if(employee != NULL)
    {
        free(employee);
        employee = NULL;
        retorno=0;
    }
    return retorno;
}

int employeeComparaId(void* a, void* b)
{
    int retorno=0;
    Employee* e1;
    Employee* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Employee*)a;
        e2 = (Employee*)b;

        if(e1->id > e2->id)
        {
           retorno=1;
        }
        else
        {
            if(e1->id < e2->id)
            {
                retorno= -1;
            }
        }
    }

    return retorno;
}

int employeeComparaNombre(void* a, void* b)
{
     int retorno;
    Employee* e1;
    Employee* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Employee*)a;
        e2 = (Employee*)b;

        retorno = strcmp(e1->nombre,e2->nombre);
    }

    return retorno;
}
int employeeComparaHT(void* a, void* b)
{
    int retorno=0;
    Employee* e1;
    Employee* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Employee*)a;
        e2 = (Employee*)b;

        if(e1->horasTrabajadas > e2->horasTrabajadas)
        {
           retorno=1;
        }
        else
        {
            if(e1->horasTrabajadas < e2->horasTrabajadas)
            {
                retorno= -1;
            }
        }
    }

    return retorno;
}
int employeeComparaSueldo(void* a, void* b)
{
    int retorno=0;
    Employee* e1;
    Employee* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Employee*)a;
        e2 = (Employee*)b;

        if(e1->sueldo > e2->sueldo)
        {
           retorno=1;
        }
        else
        {
            if(e1->sueldo < e2->sueldo)
            {
                retorno= -1;
            }
        }
    }

    return retorno;
}


int altaEmployee(LinkedList* lista)
{
    int todoOK = -1;
    char auxChar[128];
    int auxInt;

    Employee* auxEmployee = (Employee*)employee_new();
    system("cls");

    printf("****Alta Empleado****\n");

    if(auxEmployee == NULL)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        while(todoOK==-1)
        {
           if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,100000))==0)
           {
               if(buscarId(lista,auxInt)!=0)
               {
                    employee_setId(auxEmployee,auxInt);
               }
               else
               {
                   printf("Ese id ya se encuentra en la lista\n\n");
                    todoOK=1;
                    break;
               }

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=1;
                break;
           }

           if(utn_getCadena(auxChar,128,2,"\nIngrese el nombre: ","\nError reingrese el id: ")==0)
           {
                employee_setNombre(auxEmployee,auxChar);

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=1;
                break;
           }

           if((utn_getEntero(&auxInt,2,"\nIngrese las horas trabajadas: ","\nError reingrese las horas trabajadas: ",1,1000000))==0)
           {
                employee_setHorasTrabajadas(auxEmployee,auxInt);
           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=1;
                break;
           }

            if((utn_getEntero(&auxInt,2,"\nIngrese el sueldo: ","\nError reingrese el sueldo: ",1,1000000))==0)
           {
                employee_setSueldo(auxEmployee,auxInt);
                todoOK=0;

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=1;
                break;
           }
        }
        if(todoOK==0)
        {
           if(ll_add(lista,auxEmployee)==0)
           {
               printf("Se realizo el alta con exito\n\n");
           }
           else
           {
               printf("No se pudo efectuar el alta\n\n");
               free(auxEmployee);
           }
        }
        else
        {
            printf("No se pudo efectuar el alta\n\n");
            free(auxEmployee);
        }


    }

    return todoOK;
}

int buscarId(LinkedList* lista, int id)
{
    int todoOk=1;
    int tam;
    tam = ll_len(lista);
    Employee* employee;

        for(int i=0;i<tam;i++)
        {
            employee= ll_get(lista,i);

            if(employee->id == id)
            {
                todoOk=0;
                break;
            }
        }

    return todoOk;
}

int bajaEmployee(LinkedList* lista)
{
     int indice;
     int id;
     char confirma;
     int auxInt;
     int todoOk=1;

     if(lista!=NULL)
     {
         system("cls");
         printf("****Baja Empleado****\n\n");

        mostrarEmployees(lista);

        if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,100000))==0)
        {
            id=auxInt;

        }
        else
        {
            printf("\nTe quedaste sin intentos\n\n");
            id = -1;
        }

        indice = buscarEmployee(id,lista);

        if(indice== -1)
        {
            if(id==-1)
            {
                printf("\nSe cancelo la operacion\n\n");
            }
            else
            {
                printf("No hay registro de algun empleado con el id: %d\n", auxInt);
            }

        }
        else
        {   system("cls");
            printf("  Id         Nombre    Horas Trabajadas    Sueldo\n");
            mostrarEmployee(lista,indice);
            printf("\nConfirma la baja? : ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                if(ll_remove(lista,indice)==0)
                {
                    printf("\nSe ha realizado la baja con exito\n\n");
                    todoOk=0;
                }
                else
                {
                    printf("\nNo se pudo realizar la baja\n\n");
                }

            }
            else
            {
                printf("Se cancelo la operacion\n\n");
            }

        }
     }
    return todoOk;
}
int buscarEmployee(int id, LinkedList* lista)
{
    int indice= -1;
    int tam = ll_len(lista);
    int idAux;
    Employee* employee;

    for(int i=0;i<tam;i++)
    {
        employee = ll_get(lista,i);
       if((employee_getId(employee,&idAux))==0 && idAux == id)
       {
           indice=i;
           break;
       }
    }

    return indice;
}

int modificarEmployee(LinkedList* lista)
{
    int indice;
    int id;
    int auxInt;
    char auxChar[128];
    char confirma;
    int nuevoSueldo;
    char nuevoNombre[128];
    int nuevoId;
    int nuevoHT;
    int todoOk=1;
    Employee* auxEmployee;

    if(lista!=NULL)
    {
        system("cls");
        printf("****Modificar empleado****\n\n");

        mostrarEmployees(lista);

        if((utn_getEntero(&id,2,"\n\nIngrese el id: ","\n\nError reingrese el id",1,100000))==0)
        {
            indice = buscarEmployee(id,lista);
        }
        else
        {
            printf("Te quedaste sin intentos\n\n");
        }

        if(indice== -1)
        {
            printf("No hay registro de algun empleado con ese id\n\n");
        }
        else
        {
            system("cls");
            printf("  Id        Nombre      Horas Trabajadas   Sueldo\n");
            mostrarEmployee(lista,indice);
            printf("\nQuiere modificar a este empleado (s/n): ");
            fflush(stdin);
            scanf("%c",&confirma);
            auxEmployee = ll_get(lista,indice);

            if(confirma=='s')
            {
                switch(menuModificar())
                {
                    case 'a':
                        if(utn_getEntero(&auxInt,2,"\nIngrese el nuevo id: ","\nError reingrese el nuevo id: ",1,100000)==0)
                        {
                            nuevoId=auxInt;
                            printf("Se modifico el id %d por el id %d\n\n",auxEmployee->id,nuevoId);
                            employee_setId(auxEmployee,nuevoId);
                            todoOk=0;
                        }
                        else
                        {
                            printf("Te quedaste sin intentos\n\n");
                        }

                        break;

                    case 'b':
                        if((utn_getCadena(auxChar,128,2,"\nIngrese el nuevo nombre: ","\nError reingrese el nuevo nombre: "))==0)
                        {
                            strcpy(nuevoNombre,auxChar);
                            printf("Se modifico el nombre %s por %s\n\n",auxEmployee->nombre,nuevoNombre);
                            employee_setNombre(auxEmployee,nuevoNombre);

                            todoOk=0;
                        }
                        else
                        {
                            printf("Te quedaste sin intentos\n\n");
                        }

                        break;

                    case 'c':
                        if((utn_getEntero(&auxInt,2,"\nIngrese las nuevas horas trabajadas: ","\nError reingrese el nuevo nombre: ",1,1000000))==0)
                           {
                               nuevoHT=auxInt;
                               printf("Se modifico las horas trabajadas %d por %d\n\n",auxEmployee->horasTrabajadas,nuevoHT);
                               employee_setHorasTrabajadas(auxEmployee,nuevoHT);

                               todoOk=0;
                           }
                           else
                           {
                             printf("Te quedaste sin intentos\n\n");
                           }
                        break;

                    case 'd':
                        if((utn_getEntero(&auxInt,2,"\nIngrese el nuevo sueldo: ","\nError reingrese el nuevo sueldo: ",1,1000000))==0)
                        {
                            nuevoSueldo=auxInt;
                            printf("Se modifico el sueldo %d por %d\n\n",auxEmployee->sueldo,nuevoSueldo);
                            employee_setSueldo(auxEmployee,nuevoSueldo);

                            todoOk=0;
                        }
                        else
                        {
                            printf("Te quedaste sin intentos\n\n");
                        }

                        break;

                    default:
                        printf("La opcion no es valida\n\n");
                        break;

                }
            }
            else
            {
                printf("Se cancelo la operacion\n\n");
            }

        }
    }
    return todoOk;
}

int ordenarEmployees(LinkedList* lista)
{
    int criterio;
    int auxInt;
    int todoOk=1;

    if(lista!=NULL)
    {
        system("cls");
        printf("***Menu ordenar***\n\n");

            switch(menuOrdenar())
            {
                case 'a':
                    if((utn_getEntero(&auxInt,2,"\nIngrese 1 para ordenar de forma ascendente o 0 para descendente: ","\nError solo 1 o 0: ",0,1))==0)
                    {
                        criterio=auxInt;
                        ll_sort(lista,employeeComparaId,criterio);
                        printf("\nYa se realizo el ordenamiento\n\n");
                        todoOk=0;

                    }
                    else
                    {
                        printf("\nTe quedaste sin intentos\n\n");
                    }
                    system("pause");
                break;
               case 'b':
                   if((utn_getEntero(&auxInt,2,"\nIngrese 1 para ordenar de forma ascendente o 0 para descendente: ","\nError solo 1 o 0: ",0,1))==0)
                    {
                        criterio=auxInt;
                        ll_sort(lista,employeeComparaNombre,criterio);
                        printf("\nYa se realizo el ordenamiento\n\n");
                        todoOk=0;
                    }
                    else
                    {
                        printf("\nTe quedaste sin intentos\n\n");
                    }
                    system("pause");
                    break;
               case 'c':
                   if((utn_getEntero(&auxInt,2,"\nIngrese 1 para ordenar de forma ascendente o 0 para descendente: ","\nError solo 1 o 0: ",0,1))==0)
                    {
                        criterio=auxInt;
                        ll_sort(lista,employeeComparaHT,criterio);
                        printf("\nYa se realizo el ordenamiento\n\n");
                        todoOk=0;

                    }
                    else
                    {
                        printf("\nTe quedaste sin intentos\n\n");
                    }
                    system("pause");
                    break;
               case 'd':
                   if((utn_getEntero(&auxInt,2,"\nIngrese 1 para ordenar de forma ascendente o 0 para descendente: ","\nError solo 1 o 0: ",0,1))==0)
                    {
                        criterio=auxInt;
                        ll_sort(lista,employeeComparaSueldo,criterio);
                        printf("\nYa se realizo el ordenamiento\n\n");
                        todoOk=0;
                    }
                    else
                    {
                        printf("\nTe quedaste sin intentos\n\n");

                    }
                    system("pause");
                    break;


               default:
                    printf("\nIngrese una opcion valida\n");
                    system("pause");
                    break;
            }



    }

    return todoOk;

}

