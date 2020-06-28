#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empresas.h"
#include "parser.h"
#include <string.h>
#include "Validaciones.h"


/** \brief Carga los datos de las empresas desde el archivo empresas.csv (modo texto).
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

/** \brief Carga los datos de las empresas desde el archivo empresas.bin (modo binario).
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

/** \brief Alta de empresa
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmpresa(LinkedList* pArrayListEmployee)
{
    int todoOk=1;
   if(altaEmpresa(pArrayListEmployee)==0)
   {
       todoOk=0;
   }
    return todoOk;
}

/** \brief Modificar datos de una empresa
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmpresa(LinkedList* pArrayListEmployee)
{
     int todoOk=1;
   if(modificarEmpresa(pArrayListEmployee)==0)
   {
       todoOk=0;
   }
    return todoOk;

}

/** \brief Baja de una empresa
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmpresa(LinkedList* pArrayListEmployee)
{
    int todoOk=1;
    if(bajaEmpresa(pArrayListEmployee)==0)
    {
        todoOk=0;
    }
    return todoOk;
}

/** \brief Listar empresas
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmpresas(LinkedList* pArrayListEmployee)
{
    int todoOk=1;
    if(mostrarEmpresas(pArrayListEmployee)==0)
    {
        todoOk=0;
    }

    return todoOk;
}

/** \brief Ordenar empresas
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmpresas(LinkedList* pArrayListEmployee)
{
    int todoOk=1;
    if(ordenarEmpresas(pArrayListEmployee)==0)
    {
        todoOk=0;
    }

    return todoOk;

}

/** \brief Guarda los datos de las empresas en el archivo empresas.csv (modo texto).
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
	int auxCE;
	int auxVM;
	Empresa* pEmpresa;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{

			fprintf(pFile, "id,Nombre,Cant.Empleados,Valor de mercado(millones)\n");
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				pEmpresa = ll_get(pArrayListEmployee, i);

				if(!empresa_getId(pEmpresa, &auxId) &&
				   !empresa_getNombre(pEmpresa, auxNombre) &&
				   !empresa_getCantidadEmpleados(pEmpresa, &auxCE) &&
				   !empresa_getValorMercado(pEmpresa, &auxVM))
				{
                    fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxCE, auxVM);
                    todoOk = 0;

				}
			}
			fclose(pFile);
		}
	}

    return todoOk;
}

/** \brief Guarda los datos de las empresas en el archivo empresas.bin (modo binario).
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
	Empresa* pEmpresa;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmpresa = (Empresa*) ll_get(pArrayListEmployee, i);
			fwrite(pEmpresa, sizeof(Empresa), 1, pFile);
		}
		fclose(pFile);

		todoOk = 0;
	}

    return todoOk;

}

/** \brief Guarda una copia de seguridad de los datos de las empresas en un archivo nuevo (modo texto).
 *
 * \param pArrayListEmployee LinkedList*
 *
 */
void controller_copiaDeSeguridadTxt(LinkedList* pArrayListEmpresas)
{
     FILE* pFile;
	 char nombreArchivo[51];
	 LinkedList* auxList;

	if(pArrayListEmpresas != NULL )
	{
	    if((utn_getCadena(nombreArchivo,51,1,"\nIngrese el nombre del archivo: ","\nError reingrese el nombre del archivo: "))==0)
        {
            strcat(nombreArchivo,".csv");

            pFile = fopen(nombreArchivo, "w");

            if(pFile != NULL)
            {
                auxList = ll_clone(pArrayListEmpresas);
                if(auxList != NULL)
                {
                    if(ll_containsAll(pArrayListEmpresas,auxList)==1)
                    {
                        if(!controller_saveAsText(nombreArchivo,auxList))
                        {
                            printf("Se pudo crear la copia con exito\n\n");
                        }
                        else
                        {
                            printf("No se pudo crear la copia\n\n");
                        }
                    }
                    else
                    {
                        printf("La copia no tiene todos los datos\n\n");
                    }

                }

                fclose(pFile);
		    }
        }
    }

}

/** \brief Guarda una copia de seguridad de los datos de las empresas en un archivo nuevo (modo binario).
 *
 * \param pArrayListEmployee LinkedList*
 *
 */
void controller_copiaDeSeguridadBin(LinkedList* pArrayListEmpresas)
{
     FILE* pFile;
	 char nombreArchivo[51];;
	 LinkedList* auxList;

	if(pArrayListEmpresas != NULL )
	{
	    if((utn_getCadena(nombreArchivo,51,1,"\nIngrese el nombre del archivo: ","\nError reingrese el nombre del archivo: "))==0)
	    {
	        strcat(nombreArchivo,".bin");

            pFile = fopen(nombreArchivo, "wb");

            if(pFile != NULL)
            {
                auxList = ll_clone(pArrayListEmpresas);
                if(auxList != NULL)
                {
                    if(ll_containsAll(pArrayListEmpresas,auxList)==1)
                    {
                        if(!controller_saveAsText(nombreArchivo,auxList))
                        {
                            printf("Se pudo crear la copia con exito\n\n");
                        }
                        else
                        {
                            printf("No se pudo crear la copia\n\n");
                        }
                    }
                    else
                    {
                        printf("La copia no tiene todos los datos\n\n");
                    }
                }

                fclose(pFile);
            }
	    }
	}
}

/** \brief menu con los diferentes tipos de copias de seguridad
 *
 * \return la opcion elegida por el usuario
 *
 */
int menuCopiaSeguridad()
{
    int opcion;
    system("cls");
    printf("**** MENU DE COPIA DE SEGURIDAD ****\n\n");
    printf("1- Crear copia de seguridad (Modo texto)\n");
    printf("2- Crear copia de seguridad (Modo binario)\n\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

/** \brief Llama a copia de seguridad en modo texto o en modo binario.
 *
 * \param pArrayListEmployee LinkedList*
 *
 */
void controller_copiaDeSeguridadGral(LinkedList* pArrayListEmpresas)
{
    if(pArrayListEmpresas!=NULL)
    {
        switch(menuCopiaSeguridad())
        {
            case 1:
                controller_copiaDeSeguridadTxt(pArrayListEmpresas);
                break;

            case 2:
                controller_copiaDeSeguridadBin(pArrayListEmpresas);
                break;
            default:
                printf("Error opcion no valida\n\n");
                break;
        }
    }
}

/** \brief mueve una empresa a la posicion elegida por el ususario.
 *
 * \param pArrayListEmployee LinkedList*
 *
 */
void controller_MoverEmpresaAlaPosicionDeseada(LinkedList* pArrayListEmpresas)
{
    int idABuscar;
    int indice;
    int indiceAColocar;
    Empresa* empresa;

    if(pArrayListEmpresas!=NULL)
    {
        printf("\nIngrese el id de la empresa para buscarla: ");
        scanf("%d",&idABuscar);
        printf("\n");
        indice=buscarEmpresa(idABuscar,pArrayListEmpresas);
        if(indice != -1)
        {
            empresa = ll_pop(pArrayListEmpresas,indice);
            if(utn_getEntero(&indiceAColocar,2,"\nIngrese el indice donde desea colocar la empresa (comienza en 0): ","\nError reingrese el indice donde desea colocar la empresa (comienza en 0): ",0,ll_len(pArrayListEmpresas)-1)==0)
            {
                if(empresa!=NULL)
                {
                    if(ll_push(pArrayListEmpresas,indiceAColocar,empresa)==0)
                    {
                        printf("Ya se a realizado el traslado de la empresa a la posicion solicitada\n\n");
                    }

                }
            }
            else
            {
                printf("Te quedaste sin intentos\n\n");
            }
        }
        else
        {
            printf("No hay ninguna empresa con ese id\n\n");
        }
    }

}
