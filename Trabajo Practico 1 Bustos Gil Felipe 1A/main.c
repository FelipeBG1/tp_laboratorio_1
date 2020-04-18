#include <stdio.h>
#include <stdlib.h>
#include "TP1BustosGil.h"


int main()
{
    int operandoUno;
    int operandoDos;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    int resultadoFactUno;
    int resultadoFactDos;
    char seguir = 's';
    int flagIngresoNumero1 = 0;
    int flagIngresoNumero2 = 0;
    int flagOperaciones = 0;


    do
    {
        switch(mostrarMenu(operandoUno,operandoDos,flagIngresoNumero1,flagIngresoNumero2))
        {
        case 1:
            printf("Ingrese el primer numero: ");
            scanf("%d",&operandoUno);               //Pido el primer operando y lo guardo en su correspondiente variable
            flagIngresoNumero1 = 1;
            break;

        case 2:
            printf("Ingrese el segundo numero: ");
            scanf("%d",&operandoDos);               //Pido el segundo operando y lo guardo en su correspondiente variable
            flagIngresoNumero2 = 1;
            break;

        case 3:
            if(flagIngresoNumero1 && flagIngresoNumero2)
            {
                resultadoSuma = sumar(operandoUno,operandoDos);
                resultadoResta = restar(operandoUno,operandoDos);       //Invoco a todas las funciones que llevan a cabo las operaciones matematicas
                resultadoDivision = dividir(operandoUno,operandoDos);
                resultadoMultiplicacion = multiplicar(operandoUno,operandoDos);
                resultadoFactUno = factorial(operandoUno);
                resultadoFactDos = factorial(operandoDos);
                flagOperaciones = 1;
                printf("Ya se realizaron todas las operaciones, elija la opcion 4 para mostrar los resultados\n\n");
            }
            else    //Verifico que tenga los operandos antes de realizar las operaciones
            {
                if(flagIngresoNumero1==0 && flagIngresoNumero2==0)
                {
                    printf("Para poder realizar las operaciones debe ingresar primero los operandos. Le faltan ambos\n\n");
                }
                else
                {
                    if(flagIngresoNumero1==0 && flagIngresoNumero2)
                    {
                        printf("Debe ingresar los numeros para operar. Le falta el primero\n\n");
                    }
                    else
                    {
                        if(flagIngresoNumero2 == 0 && flagIngresoNumero1)
                        {
                            printf("Debe ingresar los numeros para operar. Le falta el segundo\n\n");
                        }
                    }
                }
            }
            system("pause");
            break;


        case 4:
            if(flagOperaciones)     //Muestro los resultados de las operaciones
            {
                printf("\nEl resultado de %d + %d es: %d\n",operandoUno,operandoDos,resultadoSuma);
                printf("El resultado de %d - %d es: %d\n",operandoUno,operandoDos,resultadoResta);
                if(operandoDos == 0)
                {
                    printf("No es posible dividir por cero\n"); // Contemplo el caso de la division por cero
                }
                else
                {
                    printf("El resultado de %d/%d es %.2f\n",operandoUno,operandoDos,resultadoDivision);
                }

                printf("El resultado de %d*%d es: %d\n",operandoUno,operandoDos,resultadoMultiplicacion);
                printf("El factorial de %d es %d y el de %d es %d\n\n",operandoUno,resultadoFactUno,operandoDos,resultadoFactDos);

                reset(&flagIngresoNumero1);
                reset(&flagIngresoNumero2);
                reset(&flagOperaciones);       //Reseteo los operandos y sus respectivas banderas
                reset(&operandoUno);
                reset(&operandoDos);
            }
            else
            {
                printf("Para poder mostrar los resultados debe primero realizar las operaciones\n\n");  //Verifico que haya realizado las operaciones antes de mostrar los resultados
            }
            system("pause");
            break;

        case 5:
            seguir = 'n';       // Cambio el valor de la variable seguir para poder salir de la calculadora
            system("pause");
            break;

        default:
            printf("\nNo es una opcion valida\n\n"); //Verifico que ponga los numeros correspondientes
            system("pause");
            break;
        }
    fflush(stdin);//Limpio el buffer de entrada por cualquier error
    }
    while(seguir == 's');


    return 0;
}

