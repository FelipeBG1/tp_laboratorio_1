#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empresas.h"
#include "Validaciones.h"
#include <string.h>
#include "parser.h"
#include <ctype.h>

int menuPrincipal();

int main()
{

    char seguir = 's';
    char confirma;
    int flagIngreso=0;
    int flagIngresoB=0;
    LinkedList* lista = ll_newLinkedList();

    do
    {
        switch(menuPrincipal())
        {
       case 1:
           if(!flagIngreso)
           {
               if(controller_loadFromText("empresas.csv",lista)==0)
                {
                    printf("\nSe cargaron los datos con exito\n\n");
                    flagIngreso=1;
                }
                else
                {
                    printf("Nose pudieron cargar los datos\n\n");
                }
           }
           else
           {
               printf("Los datos ya han sido sido cargados\n\n");
           }

        break;
       case 2:
           if(!flagIngresoB)
           {
                if(controller_loadFromBinary("empresas.bin",lista)==0)
                {
                    if(flagIngreso==0)
                    {
                        printf("\nSe cargaron los datos con exito\n\n");
                        flagIngresoB=1;
                    }
                    else
                    {
                        printf("Se sustituyeron los datos del texto por el binario\n\n");
                        flagIngresoB=1;
                    }
                }
                else
                {
                    printf("Nose pudieron cargar los datos\n\n");
                }
           }
           else
           {
                printf("Los datos ya han sido sido cargados\n\n");
           }

        break;
       case 3:
           if(flagIngreso || flagIngresoB)
           {
               controller_addEmpresa(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 4:
           if(flagIngreso || flagIngresoB)
           {
               controller_editEmpresa(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 5:
           if(flagIngreso || flagIngresoB)
           {
               controller_removeEmpresa(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 6:
           if(flagIngreso || flagIngresoB)
           {
               controller_ListEmpresas(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }
            printf("\n");
        break;
       case 7:
           if(flagIngreso || flagIngresoB)
           {
               controller_sortEmpresas(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 8:
            if(ll_isEmpty(lista)==1)
            {
                printf("Primero se deben cargar los datos\n\n");
            }
            else
            {
             controller_MoverEmpresaAlaPosicionDeseada(lista);
            }
            break;
       case 9:
        if(ll_isEmpty(lista)==1)
        {
            printf("Primero se deben cargar los datos\n\n");
        }
        else
        {
            controller_copiaDeSeguridadGral(lista);
        }
        break;
       case 10:
           if(flagIngreso || flagIngresoB)
           {
               if(controller_saveAsText("empresas.csv",lista)==0)
               {
                   printf("Se guardaron los datos con exito\n\n");
               }
               else
               {
                   printf("No se pudieron guardar los datos\n\n");
               }
           }
           else
           {
               printf("Antes de guardar primero debe cargar los datos\n\n");
           }

        break;
       case 11:
           if(flagIngreso || flagIngresoB)
           {
               if(controller_saveAsBinary("empresas.bin",lista)==0)
               {
                   printf("Se guardaron los datos con exito\n\n");
               }
               else
               {
                   printf("No se pudieron guardar los datos\n\n");
               }
           }
           else
           {
               printf("Antes de guardar primero debe cargar los datos\n\n");
           }

        break;
       case 12:
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
        break;
       default:
        printf("Ingrese una opcion valida\n");
        }
        system("pause");
    }while(seguir=='s');

    ll_deleteLinkedList(lista);
    return 0;
}

int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("**** MENU DE OPCIONES ****\n\n");
    printf("1- Cargar datos de las empresas (Modo texto)\n");
    printf("2- Cargar datos de las empresas (Modo binario)\n");
    printf("3- Alta de empresas\n");
    printf("4- Modificar datos de una empresa\n");
    printf("5- Baja de empresa\n");
    printf("6- Listar empresas\n");
    printf("7- Ordenar empresas\n");
    printf("8- Mover empresa a una posicion determinada\n");
    printf("9- Hacer una copia de seguridad\n");
    printf("10- Guardar los datos de las empresas (Modo texto)\n");
    printf("11- Guardar los datos de las empresas (Modo binario)\n");
    printf("12- Salir\n\n");

    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;
}












