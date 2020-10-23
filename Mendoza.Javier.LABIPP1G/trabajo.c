#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "trabajo.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "fecha.h"
#include "auto.h"
#include "validaciones.h"

int inicializarTrabajos(eTrabajo trabajo[], int tamT)
{
    int error = 1;
    if(trabajo != NULL && tamT > 0)
    {
        for(int i = 0; i < tamT; i++)
        {
            trabajo[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicioT[], int tamT, int tamS)
{
    char descServicio[60];

    for(int i = 0; i < tamS; i++)
    {
        if(servicioT[i].id == trabajo.idServicio)
        {
            strcpy(descServicio, servicioT[i].descripcion);
            break;
        }
    }
    printf(" %5d           %10s           %10s     %02d/%02d/%d\n",
           trabajo.id,
           trabajo.patente,
           descServicio,
           trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio);
}

int mostrarTrabajos(eTrabajo trabajo[], eServicio servicioT[], int tamT, int tamS)
{
    int error = 1;
    int flag = 0;

    if(trabajo != NULL && tamT > 0)
    {
        printf("                      *** Listado de Trabajos ***\n");
        printf("-------------------------------------------------------------------\n");
        printf("  Id                Patente            ID Servicio   Fecha\n");

        for(int i = 0; i < tamT; i++)
        {
            if(trabajo[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajo[i], servicioT, tamT, tamS);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("No hay personas en la lista");
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

int buscarLibreTrabajo(eTrabajo trabajo[], int tamT)
{
    int indice = -1;

    for(int i = 0; i < tamT; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo trabajo[], eServicio servicioT[], eAuto cocheT[], eMarca marcaT[], eColor colorT[], int tamT, int tamS, int tamA, int tamM, int tamC, int id)
{
    int error = -1;
    int lugarVacio;
    char auxPatente[8];
    int auxServicio;

    eTrabajo nuevoTrabajo;

    if(trabajo != NULL && tamT > 0 && id > 0)
    {
        system("cls");
        printf("   *** ALTA DE TRABAJO ***\n\n");
        lugarVacio = buscarLibreTrabajo(trabajo, tamT);

        if(lugarVacio == -1)
        {
            printf("ESTA LLENO, NO HAY LUGARES PARA TRABAJOS.\n\n");
        }
        else
        {
            nuevoTrabajo.id = id;

            mostrarAutos(cocheT, marcaT, colorT, tamA);

            printf("Ingrese patente\n");
            fflush(stdin);
            gets(auxPatente);
            while(validarPatente(cocheT, tamT, auxPatente) == 0)
            {
                printf("Patente invalida. Reingrese patente del auto: ");
                fflush(stdin);
                gets(auxPatente);
            }
            strcpy(nuevoTrabajo.patente, auxPatente);


            system("cls");
            mostrarServicios(servicioT, tamS);

            printf("\nIngrese idServicio\n");
            fflush(stdin);
            scanf("%d", &auxServicio);
            while(validarServicio(servicioT, tamS, auxServicio) == 0)
            {
                printf("Id Servicio invalido. Reingrese id Servicio: ");
                fflush(stdin);
                scanf("%d", &auxServicio);
            }
            nuevoTrabajo.idServicio = auxServicio;

            system("cls");
            printf("\n   *** FECHA DE INICIO DE TRABAJO ***\n");
            while(validarFecha(&nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio) == 1)
            {
                system("cls");
                printf("\nError, reingrese fecha de inicio del trabajo\n");
            }

            printf("\nLa fecha ingresada es: %d/%d/%d\n\n", nuevoTrabajo.fecha.dia, nuevoTrabajo.fecha.mes, nuevoTrabajo.fecha.anio);
            system("pause");

            nuevoTrabajo.isEmpty = 0;

            trabajo[lugarVacio] = nuevoTrabajo;

            system("cls");

            error = 0;
        }
    }
    return error;
}

int mostrarTrabajosDeUnAuto(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[])
{
    int error = 1;
    char auxPatente[8];
    char nombreServicio[20];
    int flag = 0;

    if(coche != NULL && trabajo != NULL && servicio != NULL && color != NULL && marca != NULL && tamA >0 && tamT > 0 && tamS >0)
    {
        system("cls");
        printf("Trabajos que se le hicieron al auto elegido.\n\n");

        mostrarAutos(coche, marca, color, tamA);

        printf("\nIngrese la patente del auto.\n\n");
        fflush(stdin);
        gets(auxPatente);
        while(validarPatente(coche, tamA, auxPatente) == 0)
        {
            printf("Patente invalida. Reingrese patente del auto: ");
            fflush(stdin);
            gets(auxPatente);
        }
        printf("\nPatente ingresada: %s\n\n", auxPatente);

        system("cls");
        printf("Trabajos hechos al auto\n\n");


        for(int i=0; i < tamT; i++)
        {
            if(trabajo[i].isEmpty == 0 && (strcmp(trabajo[i].patente, auxPatente) == 0))
            {
                for(int j = 0; j < tamS; j++)
                {
                    if(servicio[j].id == trabajo[i].idServicio)
                    {
                        obtenerDescripcionServicio(servicio, tamS, trabajo[i].idServicio, nombreServicio);
                        printf("%s \n\n", nombreServicio);
                        flag = 1;
                    }
                }
                if(flag == 0)
                {
                    printf("El auto no tiene trabajos hechos.\n\n");
                }

            }
        }
        error = 0;
    }
    return error;
}

int informeImporteTotalAuto(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[])
{
    int error = 1;
    char auxPatente[8];
    float total = 0;

    if(coche != NULL && trabajo != NULL && servicio != NULL && color != NULL && marca != NULL && tamA >0 && tamT > 0 && tamS >0)
    {
        system("cls");
        printf("Importe total por auto elegido\n\n");

        mostrarAutos(coche, marca, color, tamA);

        printf("\nIngrese la patente del auto.\n\n");
        fflush(stdin);
        gets(auxPatente);
        while(validarPatente(coche, tamA, auxPatente) == 0)
        {
            printf("Patente invalida. Reingrese patente del auto: ");
            fflush(stdin);
            gets(auxPatente);
        }
        printf("\nPatente ingresada: %s\n\n", auxPatente);

        for(int i=0; i < tamT; i++)
        {
            if(trabajo[i].isEmpty == 0 && (strcmp(trabajo[i].patente, auxPatente) == 0))
            {
                for(int j = 0; j < tamS; j++)
                {
                    if(servicio[j].id == trabajo[i].idServicio)
                    {
                        total += servicio[j].precio;
                    }
                }
            }
        }
        printf("El importe total es $ %.2f\n\n", total);
        error = 0;
    }
    return error;
}

int mostrarAutosDeUnServicio(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[])
{
    int error = 1;
    int auxIdServicio;
    char nombreServicio[20];
    int flag = 0;

    if(coche != NULL && trabajo != NULL && servicio != NULL && color != NULL && marca != NULL && tamA >0 && tamT > 0 && tamS >0)
    {
        system("cls");
        printf("Autos a los que se le hicieron el servicio elegido.\n\n");

        mostrarServicios(servicio, tamS);

        printf("\nIngrese el servicio.\n\n");
        fflush(stdin);
        scanf("%d", &auxIdServicio);

        while(validarServicio(servicio, tamS, auxIdServicio) == 0)
        {
            printf("Id Servicio invalido. Reingrese id servicio: ");
            fflush(stdin);
            scanf("%d", &auxIdServicio);
        }
        printf("\nId Servicio ingresado: %d\n\n", auxIdServicio);

        system("cls");
        printf("Autos a los que se le hicieron el servicio: ");

        obtenerDescripcionServicio(servicio, tamS, auxIdServicio, nombreServicio);
        printf("%s \n\n", nombreServicio);

        for(int i=0; i < tamT; i++)
        {
            if(trabajo[i].isEmpty == 0 && (trabajo[i].idServicio == auxIdServicio))
            {
                for(int j = 0; j < tamA; j++)
                {
                    if(strcmp(trabajo[i].patente, coche[j].patente) == 0)
                    {
                        printf("\n%d/%d/%d \n\n", trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);
                        mostrarAuto(coche[i], marca, color, tamA);
                        printf("\n\n");
                        flag = 1;
                    }
                }


            }
        }
        if(flag == 0)
        {
            printf("Este servicio no se le hizo a ningun auto.\n\n");
        }
        error = 0;
    }
    return error;
}

int mostrarTrabajosDeUnaFecha(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[], eFecha fecha[])
{
    int error = 1;
    int auxDia;
    int auxMes;
    int auxAnio;
    char nombreServicio[20];
    int flag = 0;

    if(coche != NULL && trabajo != NULL && servicio != NULL && color != NULL && marca != NULL && tamA >0 && tamT > 0 && tamS >0)
    {
        system("cls");
        printf("   *** FECHAS DE LOS TRABAJOS QUE SE HICIERON ***\n\n");

        for(int i=0; i < tamT; i++)
        {
            if(trabajo[i].isEmpty == 0)
            {
                printf("%d/%d/%d \n", trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);
            }
        }

        printf("\n   *** ELIJA FECHA PARA VER QUE TRABAJOS SE HICIERON ***\n");
        printf("\nDia: \n");
        fflush(stdin);
        scanf("%d", &auxDia);
        printf("\nMes: \n");
        fflush(stdin);
        scanf("%d", &auxMes);
        printf("\nAnio: \n");
        fflush(stdin);
        scanf("%d", &auxAnio);

        while(validarFechaDeTrabajo(fecha, trabajo, tamT, auxDia, auxMes, auxAnio) == 0)
        {
            system("cls");
            printf("\nError, reingrese fecha de inicio del trabajo\n");
            system("pause");
            system("cls");
            printf("   *** FECHAS DE LOS TRABAJOS QUE SE HICIERON ***\n\n");

            for(int i=0; i < tamT; i++)
            {
                if(trabajo[i].isEmpty == 0)
                {
                    printf("%d/%d/%d \n", trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);
                }
            }
            printf("\nDia: \n");
            fflush(stdin);
            scanf("%d", &auxDia);
            printf("\nMes: \n");
            fflush(stdin);
            scanf("%d", &auxMes);
            printf("\nAnio: \n");
            fflush(stdin);
            scanf("%d", &auxAnio);
        }

        printf("\nLa fecha ingresada es: %d/%d/%d\n\n", auxDia, auxMes, auxAnio);
        system("pause");


        system("cls");
        printf("A continuacion las fechas con los trabajos hechos en ese dia.\n\n");


        for(int i=0; i < tamT; i++)
        {
            if(trabajo[i].isEmpty == 0 && (trabajo[i].fecha.dia == auxDia) && (trabajo[i].fecha.mes == auxMes) && (trabajo[i].fecha.anio == auxAnio))
            {
                for(int j = 0; j < tamS; j++)
                {
                    if(trabajo[i].idServicio == servicio[j].id)
                    {
                        printf("%d/%d/%d:", trabajo[i].fecha.dia, trabajo[i].fecha.mes, trabajo[i].fecha.anio);
                        obtenerDescripcionServicio(servicio, tamS, trabajo[i].idServicio, nombreServicio);
                        printf(" %s \n\n", nombreServicio);
                        flag = 1;
                    }
                }
                if(flag == 0)
                {
                    printf("El auto no tiene trabajos hechos.\n\n");
                }

            }
        }
        error = 0;
    }
    return error;
}

int validarFechaDeTrabajo(eFecha fecha[], eTrabajo trabajo[], int tamT, int dia, int mes, int anio)
{
    int esValido = 0;
    if(trabajo != NULL && fecha != NULL && tamT > 0 && dia > 0)
    {
        for(int i=0; i < tamT; i++)
        {
            if((trabajo[i].fecha.dia == dia) && (trabajo[i].fecha.mes == mes) && (trabajo[i].fecha.anio == anio))
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
