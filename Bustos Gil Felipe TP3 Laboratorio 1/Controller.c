#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* f = fopen(path, "r");

    if (f != NULL)
    {
        if (parser_EmployeeFromText(f, pArrayListEmployee)==0)
        {

            todoOk = 0;
        }
    }
    fclose(f);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;//error
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			retorno = 0; //exito
			//printf("Archivo cargado con exito\n");
		}
		else
		{
			printf("Error\n");
		}
	}
	else
	{
		printf("Error\n");
	}
	fclose(pFile);
    return retorno;

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
    int todoOk=1;
   if(altaEmployee(pArrayListEmployee)==0)
   {
       todoOk=0;
   }
    return todoOk;
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
     int todoOk=1;
   if(modificarEmployee(pArrayListEmployee)==0)
   {
       todoOk=0;
   }
    return todoOk;

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
    int todoOk=1;
    if(bajaEmployee(pArrayListEmployee)==0)
    {
        todoOk=0;
    }
    return todoOk;
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
    int todoOk=1;
    if(mostrarEmployees(pArrayListEmployee)==0)
    {
        todoOk=0;
    }

    return todoOk;
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
    int todoOk=1;
    if(ordenarEmployees(pArrayListEmployee)==0)
    {
        todoOk=0;
    }

    return todoOk;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[128];
	int auxHT;
	int auxSueldo;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{

			fprintf(pFile, "id,nombre,horas trabajadas,sueldo\n");
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);

				if(!employee_getId(pEmployee, &auxId) &&
				   !employee_getNombre(pEmployee, auxNombre) &&
				   !employee_getHorasTrabajadas(pEmployee, &auxHT) &&
				   !employee_getSueldo(pEmployee, &auxSueldo))
				{
                    fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHT, auxSueldo);
                    todoOk = 0;

				}
			}
			fclose(pFile);
		}
	}

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
		}
		fclose(pFile);

		todoOk = 0;
	}

    return todoOk;

}

