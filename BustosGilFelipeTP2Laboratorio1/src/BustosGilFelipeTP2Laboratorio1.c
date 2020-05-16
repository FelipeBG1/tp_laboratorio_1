/*
 ============================================================================
 Name        : BustosGilFelipeTP2Laboratorio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000



int main()
{
   setbuf(stdout,NULL);
   char seguir ='s';
   char confirma;
   int proximoId = 1;
   int flagIngreso = 0;
   eEmployee lista[TAM];


    inicializarEmpleados(lista,TAM);

    do
    {
        fflush(stdin);
        switch(mostrarMenu())
        {
            case 1:
                 if(altaEmpleado(proximoId,lista,TAM))
                 {
                     proximoId++;
                 }
                 flagIngreso = 1;
                 system("pause");
                break;
            case 2:
                if(flagIngreso)
                {
                    modificarEmpleado(lista,TAM);
                }
                else
                {
                    printf("\nNo se puede modificar, primero debe ingresar los datos de los empleados\n\n");
                }
                system("pause");
                break;
            case 3:
                if(flagIngreso)
                {
                    bajaEmpleado(lista,TAM);
                }
                else
                {
                    printf("\nNo se puede realizar la baja, primero debe ingresar los datos de los empleados\n\n");
                }
                system("pause");
                break;
            case 4:
             if(flagIngreso)
                {
                    informar(lista,TAM);
                }
                else
                {
                   printf("\nNo se puede ingresar a informes, primero debe ingresar los datos de los empleados\n\n");
                }

                system("pause");
                break;

            case 5:
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
                system("pause");
                break;
        }


    }while(seguir =='s');


    return 0;
}
