#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "validaciones.h"

void largoCadena(char cadena[],int tamanio,char mensaje[],char errorMensaje[])
{
    char auxCad[100];

    puts(mensaje);
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad) >= tamanio/* || (soloLetras(auxCad) == 0)*/)
    {
        printf("Nombre demasiado largo o con caracteres erroneos. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(cadena, auxCad);

}

int utn_getNumeroConScanf(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos >=  0);

    }
    return retorno;
}

int validarFecha(int* pDia, int* pMes, int* pAnio)
{
    int error = 1;
    int dia;
    int mes;
    int anio;

    printf("\nIntroduzca dia: ");
    fflush(stdin);
    scanf("%d", &dia );
    printf("\nIntroduzca mes: ");
    fflush(stdin);
    scanf("%d", &mes );
    printf("\nIntroduzca anio: ");
    fflush(stdin);
    scanf("%d", &anio);

    if (mes >= 1 && mes <= 12)
    {
        switch (mes)
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( dia >= 1 && dia <= 31 )
            {
                printf("\nFECHA CORRECTA\n");
                *pDia = dia;
                *pMes = mes;
                *pAnio = anio;
                error = 0;
            }
            else
            {
                printf("\nFECHA INCORRECTA\n");
                error = 1;
            }
            break;
        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( dia >= 1 && dia <= 30 )
            {
                printf("\nFECHA CORRECTA\n");
                *pDia = dia;
                *pMes = mes;
                *pAnio = anio;
                error = 0;
                error = 0;
            }
            else
            {
                printf("\nFECHA INCORRECTA\n");
                error = 1;
            }
            break;
        case  2 :
            if((anio % 4 == 0) && (anio % 100 != 0 || anio % 400 == 0))
            {
                if ( dia >= 1 && dia <= 29 )
                {
                    printf("\nFECHA CORRECTA\n");
                    *pDia = dia;
                    *pMes = mes;
                    *pAnio = anio;
                    error = 0;
                }
                else
                {
                    printf("\nFECHA INCORRECTA\n");
                    error = 1;
                    break;
                }
            }
            else if (dia >= 1 && dia <= 28)
            {
                printf("\nFECHA CORRECTA\n");
                *pDia = dia;
                *pMes = mes;
                *pAnio = anio;
                error = 0;
            }
            else
            {
                printf("\nFECHA INCORRECTA\n");
                error = 1;
                break;
            }
        }
    }
    else
    {
        printf("\nFECHA INCORRECTA\n");
    }

    system("pause");

    return error;
}
