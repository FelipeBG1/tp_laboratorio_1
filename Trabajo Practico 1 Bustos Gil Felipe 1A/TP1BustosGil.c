#include <stdio.h>
#include <stdlib.h>
#include "TP1BustosGil.h"

int sumar(int a,int b)
{
    int resultado;

    resultado = a+b;

    return resultado;
}

int restar(int a,int b)
{
    int resultado;

    resultado = a-b;

    return resultado;
}

float dividir(int a, int b)
{
    float resultado;

    resultado =(float)a/b;

    return resultado;
}

int multiplicar(int a,int b)
{
    int resultado;

    resultado = a*b;

    return resultado;
}




int mostrarMenu(int a,int b,int flag1,int flag2)
{
    int opcion;

    system("cls");
    printf("**** Menu de opciones ****\n\n");
    if(flag1==0 && flag2==0)
    {
        printf("Tu primer numero es A = x y tu segundo es B = y\n");
    }
    else
    {
        if(flag1 && flag2==0)
        {
            printf("Tu primer numero es A = %d y tu segundo es B = y\n",a);
        }
        else
        {
            if(flag1==0 && flag2)
            {
                printf("Tu primer numero es x y tu segundo es B = %d\n",b);
            }
        }
        if(flag1 && flag2)
        {
           printf("Tu primer numero es A = %d y tu segundo es B = %d\n",a,b);
        }


    }

    printf("1- Ingresar el primer numero\n");
    printf("2- Ingresar el segundo numero\n");
    printf("3- Ejecutar todas las operaciones\n");
    printf("4- Mostrar los resultados de las operaciones\n");
    printf("5- Salir\n");
    printf("Indique la opcion: ");
    scanf("%d",&opcion);

    return opcion;

}


int factorial(int a)
{
    int fact = 0;

    if(a >= 0)
    {
       if(a==1 || a==0)
        {
            fact = 1;
        }
        else
        {
            fact = a * factorial(a-1);
        }
    }

    return fact;
}

void reset(int*p)
{
    *p = 0;
}
