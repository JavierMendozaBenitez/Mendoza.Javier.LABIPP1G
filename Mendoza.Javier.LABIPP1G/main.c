#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "servicio.h"
#include "marca.h"
#include "auto.h"
#include "color.h"
#include "trabajo.h"

#define TAM_A 10
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_T 10

int main()
{
    char seguir = 's';
    char confirma;
    int proximoLegajo = 1;
    int criterioM;
    int criterioP;
    int idTrabajo = 1;
    int contadorAlta = 0;

    eAuto automovil[TAM_A];

    eMarca marca[TAM_M] =
    {
        {1004, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1000, "Chevrolet"},
        {1003, "Peugeot"}
    };

    eColor color[TAM_C] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eServicio servicio[TAM_S] =
    {
        {2000, "Lavado", 250},
        {2001, "Pulido", 300},
        {2002, "Encerado", 400},
        {2003, "Completo", 600}
    };

    eTrabajo trabajo[TAM_T];

    if(inicializarAutos(automovil, TAM_A) == 0 && inicializarTrabajos(trabajo, TAM_T) == 0)
    {
        printf("Autos inicializados con exito.\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar coches");
    }
    system("pause");
    harcodearDatos(automovil, TAM_A, 8);

    do
    {
        switch(menuChar())
        {
        case 'A':
            if(altaAuto(automovil, TAM_A, marca, TAM_M, color, TAM_C, proximoLegajo) == 0)
            {
                proximoLegajo++;
                printf("\n\nALTA EXITOSA\n\n");
                contadorAlta++;
            }
            else
            {
                printf("Error al dar el alta.\n\n");
            }
            break;
        case 'B':
            if(contadorAlta == 0)
            {
                printf("\nPrimero debe dar de alta un auto.\n\n");
            }
            else if(modificarAuto(automovil, TAM_A, marca, TAM_M, color, TAM_C) == 0)
            {
                printf("Se modifico correctamente.\n\n");
            }
            else
            {
                if(modificarAuto(automovil, TAM_A, marca, TAM_M, color, TAM_C) == 2)
                {
                    printf("Modificacion cancelada por el usuario\n\n");
                }
                else
                {
                    printf("Error\n\n");
                }
            }
            break;
        case 'C':
            if(contadorAlta == 0)
            {
                printf("\nPrimero debe dar de alta un auto.\n\n");
            }
            else if(bajaAutos(automovil, marca, color, TAM_A) == 0)
            {
                printf("Se elimino correctamente.\n\n");
            }
            else
            {
                if(bajaAutos(automovil, marca, color, TAM_A) == 2)
                {
                    printf("Baja cancelada por el usuario\n\n");
                }
                else
                {
                    printf("Error\n\n");
                }
            }
            break;
        case 'D':
            if(contadorAlta == 0)
            {
                printf("\nPrimero debe dar de alta un auto.\n\n");
            }
            else
            {
                system("cls");
                printf("   *** Ordenar autos ***\n");
                printf("------------------------\n\n");

                printf("Como desea ver Marcas? Si hay mismas Marcas, desempata Patente. Para ordenados descendentes 0 o ascendentes 1.\n");
                fflush(stdin);
                scanf("%d", &criterioM);
                printf("\n");

                printf("Como ordenar Patentes si hay mismas Marcas? Ordenados descendentes 0 o ascendentes 1?\n");
                fflush(stdin);
                scanf("%d", &criterioP);

                printf("\n");
                system("cls");

                while(ordenarAutosMarcaPatente(automovil, marca, TAM_A, criterioM, criterioP) == 1)
                {
                    system("cls");
                    printf("\nError, ingreso una opcion invalida. Reintente.\n\n");
                    printf("Como desea ver Marcas? Si hay mismas Marcas, desempata Patente. Para ordenados descendentes 0 o ascendentes 1.\n");
                    fflush(stdin);
                    scanf("%d", &criterioM);
                    printf("\n");
                    printf("Como ordenar Patentes si hay mismas Marcas? Ordenados descendentes 0 o ascendentes 1?\n");
                    fflush(stdin);
                    scanf("%d", &criterioP);
                    printf("\n");
                }

                system("cls");
                mostrarAutos(automovil, marca, color, TAM_A);
            }

            break;
        case 'E':
            system("cls");
            mostrarMarcas(marca, TAM_M);
            break;
        case 'F':
            system("cls");
            mostrarColores(color, TAM_C);
            break;
        case 'G':
            system("cls");
            mostrarServicios(servicio, TAM_S);
            break;
        case 'H':

            if(altaTrabajo(trabajo, servicio, automovil, marca, color, TAM_T, TAM_S, TAM_A, TAM_M, TAM_C, idTrabajo) == 0)
            {
                idTrabajo++;
                printf("\n\n   *** ALTA DE TRABAJO EXITOSA ***\n\n");
            }
            else
            {
                printf("Error al dar el alta el trabajo.\n\n");
            }
            break;
        case 'I':
            system("cls");
            mostrarTrabajos(trabajo, servicio, TAM_T, TAM_S);
            break;
        case 'Z':
            printf("Confirma salida? Presione s para si o n para no: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");

        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}



