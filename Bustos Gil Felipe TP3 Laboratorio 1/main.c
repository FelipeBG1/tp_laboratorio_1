#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"
#include <string.h>
#include "parser.h"
#include <ctype.h>
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menuPrincipal();
char menuModificar();
char menuOrdenar();

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
               if(controller_loadFromText("data.csv",lista)==0)
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
                if(controller_loadFromBinary("data.bin",lista)==0)
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
               controller_addEmployee(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 4:
           if(flagIngreso || flagIngresoB)
           {
               controller_editEmployee(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 5:
           if(flagIngreso || flagIngresoB)
           {
               controller_removeEmployee(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 6:
           if(flagIngreso || flagIngresoB)
           {
               controller_ListEmployee(lista);
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
               controller_sortEmployee(lista);
           }
           else
           {
               printf("Primero debe cargar los datos del archivo\n\n");
           }

        break;
       case 8:
           if(flagIngreso || flagIngresoB)
           {
               if(controller_saveAsText("data.csv",lista)==0)
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
       case 9:
           if(flagIngreso || flagIngresoB)
           {
               if(controller_saveAsBinary("data.bin",lista)==0)
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
       case 10:
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
    printf("1- Cargar datos de los empleados (Modo texto)\n");
    printf("2- Cargar datos de los empleados (Modo binario)\n");
    printf("3- Alta de empleado\n");
    printf("4- Modificar datos de un empleado\n");
    printf("5- Baja de empleado\n");
    printf("6- Listar empleados\n");
    printf("7- Ordenar empleados\n");
    printf("8- Guardar los datos de los empleados (Modo texto)\n");
    printf("9- Guardar los datos de los empleados (Modo binario)\n");
    printf("10- Salir\n\n");

    printf("Indique la opcion: ");
    scanf("%d",&opcion);


    return opcion;
}

char menuModificar()
{
    char opcion;
    printf("\n***Menu Modificar***\n");
    printf("a-Modificar id\n");
    printf("b-Modificar nombre\n");
    printf("c-Modificar horas trabajadas\n");
    printf("d-Modificar sueldo\n");
    printf("e-Salir\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);

    return opcion;
}

char menuOrdenar()
{
    char opcion;
    printf("a-***Ordenar por id***\n");
    printf("b-Ordenar por nombre\n");
    printf("c-Ordenar por horas trabajadas\n");
    printf("d-Ordenar por sueldo\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);

    return opcion;
}








