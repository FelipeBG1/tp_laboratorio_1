#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empresas.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    int cant;
    char cadena[4][128];

    Empresa* newEmpresa = (Empresa*) empresa_new();

    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return todoOk;
    }
    else
    {
        ll_clear(pArrayListEmployee);
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",cadena[0], cadena[1], cadena[2], cadena[3]);

    while(!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",cadena[0], cadena[1], cadena[2], cadena[3]);

        if (cant == 4)
        {
            newEmpresa = empresa_newParametros(cadena[0], cadena[1], cadena[2], cadena[3]);

            if (newEmpresa != NULL)
            {
                ll_add(pArrayListEmployee, newEmpresa);
                todoOk = 0;
            }
        }

    }


    return todoOk;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
	Empresa* auxEmpresa;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
	    ll_clear(pArrayListEmployee);
		do
		{
			auxEmpresa = empresa_new();
			if(fread(auxEmpresa, sizeof(Empresa), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, auxEmpresa);
				todoOk = 0;
			}
		}while(!feof(pFile));
	}


    return todoOk;
}
