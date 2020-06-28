#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empresas.h"
#include "Validaciones.h"
#include <string.h>
#include "parser.h"
#include <ctype.h>



int buscarLibre( int* indice, Empresa** vec, int tam)
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

int mostrarEmpresas( LinkedList* lista)
{
    int todoOk=1;
    int tam;
    tam = ll_len(lista);
    printf("  Id          Nombre     Cant.Empleados    Valor de mercado(millones de dolares)\n");

    for (int i=0; i<tam; i++)
    {
        mostrarEmpresa(lista, i);
        todoOk=0;
    }
    return todoOk;
}

void mostrarEmpresa( LinkedList* lista,int indice)
{
   Empresa* empresa;

    empresa = ll_get(lista, indice);
    printf("%4d    %12s   %12d      %12d \n", empresa->id, empresa->nombre, empresa->cantidadEmpleados, empresa->valorMercado);

}

int empresa_setId(Empresa* this,int id)
{
    int todoOk = 1;
    if(this != NULL && id>0)
    {
        this->id = id;
        todoOk=0;
    }
    return todoOk;
}

int empresa_getId(Empresa* this,int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
       *id = this->id;
       todoOk = 0;
    }
    return todoOk;
}

int empresa_setNombre(Empresa* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL && strlen(nombre) <= 127)
    {
        strcpy(this->nombre,nombre);
        todoOk = 0;
    }
    return todoOk;
}

 int empresa_getNombre(Empresa* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 0;
    }
    return todoOk;
}

int empresa_setCantidadEmpleados(Empresa* this,int cantidadEmpleados)
{
    int todoOk = 1;

    if(this != NULL && cantidadEmpleados >= 0)
    {
        this->cantidadEmpleados = cantidadEmpleados;
        todoOk = 0;
    }
    return todoOk;
}

int empresa_getCantidadEmpleados(Empresa* this,int* cantidadEmpleados)
{
    int todoOk = 1;

    if(this != NULL && cantidadEmpleados != NULL)
    {
        *cantidadEmpleados = this->cantidadEmpleados;
        todoOk = 0;
    }
    return todoOk;
}

int empresa_setValorMercado(Empresa* this,int valorMercado)
{
    int todoOk = 1;
    if(this != NULL && valorMercado>0)
    {
        this->valorMercado = valorMercado;
        todoOk=0;
    }
    return todoOk;
}

int empresa_getValorMercado(Empresa* this,int* valorMercado)
{
    int todoOk = 1;

    if(this != NULL && valorMercado != NULL)
    {
       *valorMercado = this->valorMercado;
       todoOk = 0;
    }
    return todoOk;
}

Empresa* empresa_new()
{
    Empresa* newEmpresa = (Empresa*) malloc(sizeof(Empresa));

    return newEmpresa;
}

Empresa* empresa_newParametros(char* idStr,char* nombreStr,char* cantidadEmpleadosStr, char* valorMercadoStr)
{
    Empresa* newEmpresa = empresa_new();

        if(newEmpresa != NULL)
        {
            empresa_setId(newEmpresa, atoi(idStr));
            empresa_setNombre(newEmpresa, nombreStr);
            empresa_setCantidadEmpleados(newEmpresa, atoi(cantidadEmpleadosStr));
            empresa_setValorMercado(newEmpresa, atoi(valorMercadoStr));
        }
        return newEmpresa;
}

int empresa_delete(Empresa* empresa)
{
    int retorno=1;
    if(empresa != NULL)
    {
        free(empresa);
        empresa = NULL;
        retorno=0;
    }
    return retorno;
}

int empresaComparaId(void* a, void* b)
{
    int retorno=0;
    Empresa* e1;
    Empresa* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Empresa*)a;
        e2 = (Empresa*)b;

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

int empresaComparaNombre(void* a, void* b)
{
     int retorno;
    Empresa* e1;
    Empresa* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Empresa*)a;
        e2 = (Empresa*)b;

        retorno = strcmp(e1->nombre,e2->nombre);
    }

    return retorno;
}
int empresaComparaCE(void* a, void* b)
{
    int retorno=0;
    Empresa* e1;
    Empresa* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Empresa*)a;
        e2 = (Empresa*)b;

        if(e1->cantidadEmpleados > e2->cantidadEmpleados)
        {
           retorno=1;
        }
        else
        {
            if(e1->cantidadEmpleados < e2->cantidadEmpleados)
            {
                retorno= -1;
            }
        }
    }

    return retorno;
}
 int empresaComparaVM(void* a, void* b)
{
    int retorno=0;
    Empresa* e1;
    Empresa* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (Empresa*)a;
        e2 = (Empresa*)b;

        if(e1->valorMercado > e2->valorMercado)
        {
           retorno=1;
        }
        else
        {
            if(e1->valorMercado < e2->valorMercado)
            {
                retorno= -1;
            }
        }
    }

    return retorno;
}


int altaEmpresa(LinkedList* lista)
{
    int todoOK = -1;
    char auxChar[128];
    int auxInt;
    int siguienteId;

    Empresa* auxEmpresa = (Empresa*)empresa_new();
    system("cls");

    printf("****Alta Empresa****\n");

    if(auxEmpresa == NULL)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        while(todoOK==-1)
        {

           if(utn_getCadena(auxChar,128,2,"\nIngrese el nombre de la empresa: ","\nError reingrese el nombre de la empresa: ")==0)
           {
                empresa_setNombre(auxEmpresa,auxChar);

           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=1;
                break;
           }

           if((utn_getEntero(&auxInt,2,"\nIngrese la cantidad de empleados: ","\nError reingrese la cantidad de empleados: ",10000,50000))==0)
           {
                empresa_setCantidadEmpleados(auxEmpresa,auxInt);
           }
           else
           {
                printf("\nTe quedaste sin intentos\n\n");
                todoOK=1;
                break;
           }

            if((utn_getEntero(&auxInt,2,"\nIngrese el valor de mercado(millones de dolares): ","\nError reingrese el valor de mercado(millones de dolares): ",10,100))==0)
           {
                empresa_setValorMercado(auxEmpresa,auxInt);
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
            obtenerId(&siguienteId);
            empresa_setId(auxEmpresa,siguienteId);
            actualizarId(siguienteId);
           if(ll_add(lista,auxEmpresa)==0)
           {
               printf("Se realizo el alta con exito\n\n");
           }
           else
           {
               printf("No se pudo efectuar el alta\n\n");
               free(auxEmpresa);
           }
        }
        else
        {
            printf("No se pudo efectuar el alta\n\n");
            free(auxEmpresa);
        }


    }

    return todoOK;
}

int buscarId(LinkedList* lista, int id)
{
    int todoOk=1;
    int tam;
    tam = ll_len(lista);
    Empresa* empresa;

        for(int i=0;i<tam;i++)
        {
            empresa= ll_get(lista,i);

            if(empresa->id == id)
            {
                todoOk=0;
                break;
            }
        }

    return todoOk;
}

 int bajaEmpresa(LinkedList* lista)
{
     int indice;
     int id;
     char confirma;
     int auxInt;
     int todoOk=1;

     if(lista!=NULL)
     {
         system("cls");
         printf("****Baja Empresa****\n\n");

        mostrarEmpresas(lista);

        if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,100000))==0)
        {
            id=auxInt;

        }
        else
        {
            printf("\nTe quedaste sin intentos\n\n");
            id = -1;
        }

        indice = buscarEmpresa(id,lista);

        if(indice== -1)
        {
            if(id==-1)
            {
                printf("\nSe cancelo la operacion\n\n");
            }
            else
            {
                printf("No hay registro de alguna empresa con el id: %d\n", auxInt);
            }

        }
        else
        {   system("cls");
            printf("  Id          Nombre     Cant.Empleados    Valor de mercado(millones de dolares)\n");
            mostrarEmpresa(lista,indice);
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
int buscarEmpresa(int id, LinkedList* lista)
{
    int indice= -1;
    int tam = ll_len(lista);
    int idAux;
    Empresa* empresa;

    for(int i=0;i<tam;i++)
    {
        empresa = ll_get(lista,i);
       if((empresa_getId(empresa,&idAux))==0 && idAux == id)
       {
           indice=i;
           break;
       }
    }

    return indice;
}

int modificarEmpresa(LinkedList* lista)
{
    int indice;
    int id;
    int auxInt;
    char auxChar[128];
    char confirma;
    int nuevoVM;
    char nuevoNombre[128];
    int nuevoCE;
    int todoOk=1;
    Empresa* auxEmpresa;

    if(lista!=NULL)
    {
        system("cls");
        printf("****Modificar empresa****\n\n");

        mostrarEmpresas(lista);

        if((utn_getEntero(&id,2,"\n\nIngrese el id: ","\n\nError reingrese el id",1,100000))==0)
        {
            indice = buscarEmpresa(id,lista);
        }
        else
        {
            printf("Te quedaste sin intentos\n\n");
        }

        if(indice== -1)
        {
            printf("No hay registro de alguna empresa con ese id\n\n");
        }
        else
        {
            system("cls");
            printf("  Id          Nombre     Cant.Empleados    Valor de mercado(millones de dolares)\n");
            mostrarEmpresa(lista,indice);
            printf("\nQuiere modificar a esta empresa (s/n): ");
            fflush(stdin);
            scanf("%c",&confirma);
            auxEmpresa = ll_get(lista,indice);

            if(confirma=='s')
            {
                switch(menuModificar())
                {
                    case 'a':
                        if((utn_getCadena(auxChar,128,2,"\nIngrese el nuevo nombre: ","\nError reingrese el nuevo nombre: "))==0)
                        {
                            strcpy(nuevoNombre,auxChar);
                            printf("Se modifico el nombre %s por %s\n\n",auxEmpresa->nombre,nuevoNombre);
                            empresa_setNombre(auxEmpresa,nuevoNombre);

                            todoOk=0;
                        }
                        else
                        {
                            printf("Te quedaste sin intentos\n\n");
                        }

                        break;

                    case 'b':
                        if((utn_getEntero(&auxInt,2,"\nIngrese la nueva cantidad de empleados: ","\nError reingrese la nueva cantidad de empleados: ",10000,50000))==0)
                           {
                               nuevoCE=auxInt;
                               printf("Se modifico las horas trabajadas %d por %d\n\n",auxEmpresa->cantidadEmpleados,nuevoCE);
                               empresa_setCantidadEmpleados(auxEmpresa,nuevoCE);

                               todoOk=0;
                           }
                           else
                           {
                             printf("Te quedaste sin intentos\n\n");
                           }
                        break;

                    case 'c':
                        if((utn_getEntero(&auxInt,2,"\nIngrese el nuevo valor de mercado(millones de dolares): ","\nError reingrese el valor de mercado(millones de dolares): ",10,100))==0)
                        {
                            nuevoVM=auxInt;
                            printf("Se modifico el valor de mercado %d por %d\n\n",auxEmpresa->valorMercado,nuevoVM);
                            empresa_setValorMercado(auxEmpresa,nuevoVM);

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

int ordenarEmpresas(LinkedList* lista)
{
    int criterio;
    int auxInt;
    int todoOk=1;

    if(lista!=NULL)
    {
        system("cls");


            switch(menuOrdenar())
            {
                case 'a':
                    if((utn_getEntero(&auxInt,2,"\nIngrese 1 para ordenar de forma ascendente o 0 para descendente: ","\nError solo 1 o 0: ",0,1))==0)
                    {
                        criterio=auxInt;
                        ll_sort(lista,empresaComparaId,criterio);
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
                        ll_sort(lista,empresaComparaNombre,criterio);
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
                        ll_sort(lista,empresaComparaCE,criterio);
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
                        ll_sort(lista,empresaComparaVM,criterio);
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

char menuModificar()
{
    char opcion;
    printf("\n***Menu Modificar***\n");
    printf("a-Modificar nombre\n");
    printf("b-Modificar cantidad de empleados\n");
    printf("c-Modificar valor de mercado(millones de dolares)\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);

    return opcion;
}

/*int empresa_ultimoId(LinkedList* pArrayListEmployee)
{
	Empresa* empresa;
	int len = ll_len(pArrayListEmployee);
	int auxId;
	int ultimoId = 0;
	int flag = 0;

	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			empresa = (Empresa*) ll_get(pArrayListEmployee,i);
			empresa_getId(empresa, &auxId);

			if(auxId > ultimoId || flag == 0)
			{
				ultimoId = auxId;
				flag = 1;
			}
		}
	}
	return ultimoId;
}
*/
int obtenerId(int* id)
{
    int todoOk = -1;
    *id = 1001;

    FILE* f;

    f=fopen("proximoId.bin","rb");

    if(f != NULL)
    {
        fread(id,sizeof(int),1,f);

        fclose(f);
        todoOk = 0;
    }
    return todoOk;
}

int actualizarId(int id)
{
    int todoOk = -1;
    id++;

    FILE* f = fopen("proximoId.bin","wb");

    if( f != NULL )
    {
        fwrite(&id,sizeof(int),1,f);

        fclose(f);
        todoOk = 0;
    }
    return todoOk;
}

char menuOrdenar()
{
    char opcion;
    printf("***Menu ordenar***\n\n");
    printf("a-Ordenar por id\n");
    printf("b-Ordenar por nombre\n");
    printf("c-Ordenar por cantidad de empleados\n");
    printf("d-Ordenar por valor de mercado(millones)\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);

    return opcion;
}
