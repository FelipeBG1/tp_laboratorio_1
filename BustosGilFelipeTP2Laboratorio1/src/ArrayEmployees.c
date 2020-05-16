/*
 * ArrayEmployees.c
 *
 *  Created on: 16 may. 2020
 *      Author: felib
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

void inicializarEmpleados(eEmployee vec[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty = 1;
    }
}

int altaEmpleado(int idX,eEmployee vec[], int tam)
{
    int todoOk = -1;
    int indice = buscarLibre(vec,tam);
    char auxChar[51];
    int auxInt;
    float auxFloat;

    eEmployee auxEmpleado;
    system("cls");

    printf("\n****Alta empleado****\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
    	while(todoOk==-1)
    	{
    		if((utn_getCadena(auxChar,51,2,"\nIngrese el nombre: ","\nError reingrese el nombre: "))==0)
			{
			   strcpy(auxEmpleado.name,auxChar);
			}
			else
			{
			   printf("\nTe quedaste sin intentos\n\n");
			   todoOk=0;
			   break;
			}


			if((utn_getCadena(auxChar,51,2,"\nIngrese el apellido: ","\nError reingrese el apellido: "))==0)
			{
			  strcpy(auxEmpleado.lastName,auxChar);
			}
			else
			{
			  printf("\nTe quedaste sin intentos\n\n");
			  todoOk=0;
			  break;
			}

			if((utn_getEntero(&auxInt,2,"\nIngrese el sector: ","\nError reingrese el sector: ",1,1000))==0)
			{
			   auxEmpleado.sector=auxInt;
			}
			else
			{
				printf("\nTe quedaste sin intentos\n\n");
				todoOk=0;
				break;
			}

			if((utn_getFlotante(&auxFloat,2,"\nIngrese el salario: ","\nError reingrese el salario: ",1,999999999))==0)
			{
			   auxEmpleado.salary=auxFloat;
			   todoOk=1;
			}
			else
			{
			   printf("\nTe quedaste sin intentos\n\n");
			   todoOk=0;
			   break;
			}
    	}
    	if(todoOk==1)
    	{
    		auxEmpleado.id = idX;
    		auxEmpleado.isEmpty = 0;
    		vec[indice] = auxEmpleado;
    		printf("\nEl id del nuevo empleado es: %d\n\n",idX);

    	}

        }

    return todoOk;
}

void bajaEmpleado(eEmployee vec[], int tam)
{
    int indice;
    int id;
    char confirma;
    int auxInt;

    system("cls");
    printf("\n****Baja empleado****\n\n");

    mostrarEmpleados(vec,tam);
    if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,1000))==0)
    {
    	id=auxInt;
    }
    else
    {
    	printf("\nTe quedaste sin intentos\n\n");
    }


    indice = buscarEmpleado(id,vec,tam);

    if(indice== -1)
    {
        printf("No hay registro de algun empleado con el id: %d\n", id);
    }
    else
    {
        printf("id   Apellido Nombre Sector  Salario  \n");
    	mostrarEmpleado(vec[indice]);

        printf("Confirma la baja? : ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion\n\n");
        }

    }

}

int buscarEmpleado(int id, eEmployee vec[], int tam)
{
   int indice = -1;

    for(int i=0;i<tam;i++)
    {
       if(vec[i].id == id && vec[i].isEmpty == 0)
       {
           indice = i;
           break;
       }
    }

    return indice;

}

int buscarLibre(eEmployee vec[],int tam)
{
    int indice = -1;

    for(int i=0;i<tam;i++)
    {
       if(vec[i].isEmpty == 1)
       {
           indice = i;
           break;
       }
    }

    return indice;

}

void ordenarEmpleados(eEmployee vec[], int tam)
{
    eEmployee auxEmpleado;
    int orden;
    int auxInt;

    if((utn_getEntero(&auxInt,2,"\nIngrese 1 para ordenar de forma ascendente o 0 para descendente: ","\nError reingrese: ",0,1))==0)
    {
    	orden=auxInt;
    }
    else
    {
    	printf("\nTe quedaste sin intentos\n\n");
    }

     for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(orden==1)
            {
                if(vec[i].isEmpty==0 && vec[i].sector>vec[j].sector)
                {
                    auxEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmpleado;
                }
                else
                {
                    if(vec[i].isEmpty==0 && vec[i].sector==vec[j].sector && (strcmp(vec[i].lastName,vec[j].lastName)>0))
                    {
                        auxEmpleado=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmpleado;
                    }
                }
            }
            else
            {
                if(vec[i].isEmpty==0 && vec[i].sector<vec[j].sector)
                {
                    auxEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmpleado;
                }
                else
                {
                    if(vec[i].isEmpty==0 && vec[i].sector==vec[j].sector && (strcmp(vec[i].lastName,vec[j].lastName)== -1))
                    {
                        auxEmpleado=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmpleado;
                    }
                }
            }
        }
    }
    mostrarEmpleados(vec,tam);


}

void mostrarEmpleado(eEmployee x)
{
    printf("%d    %7s   %7s      %d     %6.2f\n", x.id,x.lastName, x.name, x.sector, x.salary);

}
void mostrarEmpleados(eEmployee vec[],int tam)
{
    int flag=0;
    system("cls");
    printf("\n****Listado de empleados****\n");
    printf("id   Apellido   Nombre    Sector  Salario  \n");

    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag=1;
        }
    }
    if(flag==0)
        {
            printf("\nNo hay empleados que listar\n\n");
        }

}


int mostrarMenu()
{
    int opcion;
    system("cls");
    printf("\n**** Menu de opciones ****\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("\n\nIngrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void modificarEmpleado(eEmployee vec[],int tam)
{
    int indice;
    int id;
    char auxChar[51];
    int auxInt;
    float auxFloat;
    char confirma;
    float nuevoSalario;
    char nuevoNombre[51];
    char nuevoApellido[51];
    int nuevoSector;

    system("cls");
    printf("****Modificar empleado****\n\n");

    mostrarEmpleados(vec,tam);

    if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","\nError reingrese el id: ",1,1000))==0)
    {
    	id=auxInt;
    }
    else
    {
    	printf("\nTe quedaste sin intentos\n\n");
    }


    indice = buscarEmpleado(id,vec,tam);

    if(indice== -1)
    {
        printf("No hay registro de algun empleado con el id: %d\n", id);
    }
    else
    {
        system("cls");
        mostrarEmpleado(vec[indice]);
        printf("\n Si quiere modificar a este empleado ingrese s: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            switch(menuModificar())
            {
                case 'a':
                	if((utn_getCadena(auxChar,51,2,"\nIngrese el nuevo nombre: ","\nError reingrese el nombre: "))==0)
					{
                		strcpy(nuevoNombre, auxChar);
                		strcpy(vec[indice].name, nuevoNombre);
                		printf("\nSe modifico el nombre con exito\n\n");
					}
					else
					{
					   printf("\nTe quedaste sin intentos\n\n");
					   break;
					}

                	break;

                case 'b':
                	if((utn_getCadena(auxChar,51,2,"\nIngrese el nuevo apellido: ","\nError reingrese el apellido: "))==0)
					{
						strcpy(nuevoApellido, auxChar);
						strcpy(vec[indice].lastName, nuevoApellido);
						printf("\nSe modifico el apellido con exito\n\n");
					}
					else
					{
					   printf("\nTe quedaste sin intentos\n\n");
					   break;
					}
                    break;

                case 'c':
                	if((utn_getFlotante(&auxFloat,2,"\nIngrese el salario: ","\nError reingrese el salario: ",1,999999999))==0)
					{
					   nuevoSalario=auxFloat;
					   vec[indice].salary = nuevoSalario;
					   printf("\nSe modifico el salario con exito\n\n");
					}
					else
					{
					   printf("\nTe quedaste sin intentos\n\n");
					   break;
					}
                    break;

                case 'd':
                	if((utn_getEntero(&auxInt,2,"\nIngrese el nuevo sector: ","\nError reingrese el sector: ",1,1000))==0)
					{
					   nuevoSector=auxInt;
					   vec[indice].sector = nuevoSector;
					   printf("\nSe modifico el sector con exito\n\n");
					}
					else
					{
						printf("\nTe quedaste sin intentos\n\n");
						break;
					}
                    break;

                default:
                    printf("La opcion no es valida");
                    break;

            }
        }
        else
        {
            printf("Se cancelo la operacion\n\n");
        }

    }
}

char menuModificar()
{
    char opcion;
    printf("\n****Menu Modificar***\n\n");
    printf("a-Modificar nombre\n");
    printf("b-Modificar apellido\n");
    printf("c-Modificar salario\n");
    printf("d-Modificar sector\n");
    printf("e-Salir\n\n");
    printf("\n\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
int menuInformes()
{
    int opcion;
    system("cls");
    printf("\n****Menu de informes****\n\n");
    printf("1- Ordenar por apellido y sector\n");
    printf("\n2- Informar total de sueldos, el promedio y cuantos empleados lo superan\n");
    printf("\n3-Salir\n");
    printf("\nIngrese una opcion: ");
    scanf("%d",&opcion);


    return opcion;
}

void informarTotalSueldos(eEmployee vec[], int tam)
{
    float sumaSalarios=0;
    float promedio;
    int contadorEmpleados=0;
    int contadorSuperanPromedio=0;

    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty == 0)
        {
            contadorEmpleados++;
            sumaSalarios=sumaSalarios + vec[i].salary;
        }
    }

    promedio = sumaSalarios/contadorEmpleados;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].salary > promedio)
        {
            contadorSuperanPromedio++;
        }
    }


    printf("\nSalarios totales    Promedio salarios    Empleados que superan el promedio\n");
    printf("    %.2f               %.2f                       %d\n\n",sumaSalarios,promedio,contadorSuperanPromedio);

}

void informar(eEmployee vec[], int tam)
{
   char seguir ='s';
   char confirma;

   do
    {
        fflush(stdin);
        switch(menuInformes())
        {
            case 1:
                 ordenarEmpleados(vec,tam);
                 system("pause");
                 break;
            case 2:
                 informarTotalSueldos(vec,tam);
                 system("pause");
                 break;
            case 3:
                 printf("Confirma salida: ");
                 fflush(stdin);
                 scanf("%c",&confirma);
                 if(confirma=='s')
                 {
                    seguir='n';
                 }
                 break;
            default:
            	printf("\nLa opcion no es valida\n\n");
        }
    }
    while(seguir =='s');

}



int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero!= NULL&& msg != NULL && msgError!= NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt<=max)
            {
                *pEntero= auxInt;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}
int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max)
{
    int todoOk = -1;
    float auxFloat;

    if(pFloat!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat<=max)
            {
                *pFloat= auxFloat;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getCadena(char* pAux,int limite)
{
    char auxString[2000];
    int todoOk =-1;
    if (pAux != NULL && limite >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux,auxString,limite);
            todoOk=0;
        }
    }
    return todoOk;
}

int getInt(int* pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(getCadena(auxString,200)==0 && isInt(auxString)==0)
    {
        *pAux=atoi(auxString);
        todoOk=0;
    }
    return todoOk;
}
int isInt(char *pAux)
{
    int todoOk=-1;
    int i=0;
    do
    {
        if(*(pAux+i)<48||*(pAux+i)>57)
        {
            break;
        }
        i++;
    }while (i<strlen(pAux));
    if(i==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}

int isFloat(char* pAux)
{
    int todoOk=-1;
    int i=0;
    int contadorDePuntos=0;
    do
    {
        if(*(pAux+i)=='.')
        {
            contadorDePuntos++;
            if(contadorDePuntos==2)
            {
                break;
            }
        }
        else if(*(pAux+i)<48||*(pAux+i)>57)
        {
            break;
        }
        i++;
    }while (i<strlen(pAux));
    if(i==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(getCadena(auxString,200)==0 && isFloat(auxString)==0)
    {
        *pAux=atof(auxString);
        todoOk=0;
    }
    return todoOk;
}

int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError){
    int todoOk=-1;
    char auxString[limite];
    if(pAux!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("%s",msj);
            if(getCadena(auxString,limite)==0 && isLetras(auxString)==0){
                strncpy(pAux,auxString,limite);
                todoOk=0;
                break;
            }else
                printf("%s",msjError);
        }while(reintentos>=0);
    }
    return todoOk;
}

int isLetras(char*pAux){
    int todoOk=-1;
    int i=0;
    if(pAux!=NULL){
        do{
            if((*(pAux+i)<65||*(pAux+i)>90) && (*(pAux+i)<97||*(pAux+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pAux));
        if(i==strlen(pAux)){
            todoOk=0;
        }
    }
    return todoOk;
}





