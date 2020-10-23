#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dataStore.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "validaciones.h"

#include "trabajo.h"

char menuChar()
{
    char opcion;
    system("cls");

    printf("*** ABM coches ***\n\n");
    printf("A.	ALTA AUTO\n");
    printf("B.	MODIFICAR AUTO\n");
    printf("C.	BAJA AUTO\n");
    printf("D.	LISTAR AUTOS\n");
    printf("E.	LISTAR  MARCAS \n");
    printf("F.	LISTAR COLORES\n");
    printf("G.	LISTAR SERVICIOS\n");
    printf("H.	ALTA TRABAJO\n");
    printf("I.	LISTAR TRABAJOS\n");
    printf("J.	INFORMES\n");
    printf("Z.	SALIR\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = toupper(getchar());

    return opcion;
}

int subMenuInt()
{
    int opcion;
    system("cls");

    printf("*** Sub Menu ***\n\n");
    printf("1.	LISTAR AUTOS POR COLOR SELECCIONADO\n");
    printf("2.	LISTAR AUTOS POR MARCA SELECCIONADO\n");
    printf("3.	AUTO O AUTOS MAS VIEJOS\n");
    printf("4.	LISTAR AUTOS SEPARADOS POR MARCAS\n");
    printf("5.	CONTAR AUTOS POR COLOR Y MARCA\n");
    printf("6.	MARCA FAVORITA\n");
    printf("7.	TRABAJOS HECHOS A UN AUTO\n");
    printf("8.	IMPORTE TOTAL DE LOS TRABAJOS HECHOS.\n");
    printf("9.	AUTOS A LOS QUE SE LE HIZO UN SERVICIO ELEGIDO.\n");
    printf("10.	TRABAJOS HECHOS EN UNA FECHA ELEGIDA.\n");
    printf("11.	SALIR\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int inicializarAutos(eAuto coche[], int tam)
{
    int error = 1;
    if(coche != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            coche[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void mostrarAuto(eAuto coche, eMarca marca[], eColor color[], int tam)
{
    char descMarca[30];
    char descColor[30];


    if((obtenerDescripcionColor(color, tam, coche.idColor, descColor) == 0) && (obtenerDescripcionMarca(marca, tam, coche.idMarca, descMarca) == 0))
    {
        printf(" %5d     %10s    %5d       %10s           %10s\n",
               coche.id,
               coche.patente,
               coche.modelo,
               descMarca,
               descColor);
    }
}

int mostrarAutos(eAuto coche[], eMarca marca[], eColor color[], int tam)
{
    int error = 1;
    int flag = 0;

    if(coche != NULL && tam > 0)
    {
        printf("   *** Listado de autos ***\n");
        printf("----------------------------------------------------------------------\n");
        printf(" Id           Patente     Modelo        idMarca              idColor  \n\n");


        for(int i = 0; i < tam; i++)
        {
            if(coche[i].isEmpty == 0)
            {
                mostrarAuto(coche[i], marca, color, tam);
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

int harcodearDatos(eAuto coche[], int tam, int cantidad)
{
    int error = 1;

    if(coche != NULL && cantidad > 0 && cantidad <= tam)
    {
        for(int i = 0; i < cantidad; i++)
        {
            coche[i].id = ids[i];
            strcpy(coche[i].patente, patentes[i]);
            coche[i].idMarca = idMarcas[i];
            coche[i].idColor = idColores[i];
            coche[i].modelo = modelos[i];
            coche[i].isEmpty = 0;
            error++;
        }
    }
    return error;
}

int buscarLibre(eAuto coche[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(coche[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC, int id)
{
    int error = -1;
    int lugarVacio;
    int auxMarca;
    int auxColor;
    char auxPatente[7];

    eAuto nuevoAuto;

    if(coche != NULL && tam > 0 && id > 0)
    {
        system("cls");
        printf("   *** ALTA DE Auto ***\n\n");
        lugarVacio = buscarLibre(coche, tam);

        if(lugarVacio == -1)
        {
            printf("ESTA LLENO, NO HAY LUGARES.\n\n");
        }
        else
        {
            nuevoAuto.id = id;

            largoCadena(auxPatente, 8, "Ingrese patente de 7 caracteres\n", "Error, reingrese patente\n");
            strcpy(nuevoAuto.patente, auxPatente);
            printf("\nLa patente ingresada es: %s\n\n", nuevoAuto.patente);
            system("pause");


            system("cls");
            mostrarMarcas(marca,tamM);

            printf("Ingrese idMarca\n");
            fflush(stdin);
            scanf("%d", &auxMarca);
            while(validarMarca(marca, tamM, auxMarca) == 0)
            {
                printf("Id Marca invalido no coincide con los registros. Reingrese id Marca: ");
                fflush(stdin);
                scanf("%d", &auxMarca);
            }
            nuevoAuto.idMarca = auxMarca;
            printf("\nEl id Marca ingresado es: %d\n\n", nuevoAuto.idMarca);
            system("pause");


            system("cls");
            mostrarColores(color, tamC);

            printf("Ingrese idColor\n");
            fflush(stdin);
            scanf("%d", &auxColor);
            while(validarColor(color, tamC, auxColor) == 0)
            {
                printf("Id Color invalido. Reingrese id Color: ");
                fflush(stdin);
                scanf("%d", &auxColor);
            }
            nuevoAuto.idColor = auxColor;
            printf("\nEl id Color ingresado es: %d\n\n", nuevoAuto.idColor);
            system("pause");


            system("cls");
            printf("   *** MODELO ***\n\n");
            utn_getNumeroConScanf(&nuevoAuto.modelo, "Ingrese modelo (anio de fabricacion)\n", "Reingrese modelo, debe ingresar anios desde 1900 hasta 2020.\n", 1900, 2020, 10);
            printf("\nEl Modelo ingresado es: %d\n\n", nuevoAuto.modelo);
            system("pause");

            nuevoAuto.isEmpty = 0;

            coche[lugarVacio] = nuevoAuto;

            error = 0;
        }
    }
    return error;
}

int buscarAuto(eAuto coche[], int tam, char patente[])
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if((strcmp(coche[i].patente, patente)==0)&&(coche[i].isEmpty == 0))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaAutos(eAuto coche[], eMarca marca[], eColor color[], int tam)
{
    char patente[8];
    int indice;
    int error = 1;
    int confirma;

    if(coche != NULL && tam > 0)
    {
        system("cls");
        printf("   *** BAJA AUTOS ***\n\n");
        mostrarAutos(coche, marca, color, tam);
        printf("\nIngrese la patente del auto a bajar\n\n");
        fflush(stdin);
        gets(patente);

        while(validarPatente(coche, tam, patente) == 0)
        {
            printf("Patente invalida. Reingrese patente del auto: ");
            fflush(stdin);
            gets(patente);
        }
        printf("\nPatente ingresada: %s\n\n", patente);
        system("pause");


        indice = buscarAuto(coche, tam, patente);


        if(indice == -1)
        {
            printf("\nNo existe esa patente\n\n");
            system("pause");
        }
        else
        {
            system("cls");
            printf("\nEliminara el siguiente auto\n\n");
            mostrarAuto(coche[indice], marca, color, tam);

            utn_getNumeroConScanf(&confirma, "\nPara eliminar presione 1, para cancelar, 2\n\n", "\nOpcion incorrecta, debe ingresar 1 o 2, reintente\n", 1, 2, 10);

            if(confirma == 1)
            {
                coche[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}

int modificarAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC)
{
    char patente[8];
    int indice;
    int error = 1;
    int confirmaModelo;
    int confirmaColor;
    int respuesta;

    eAuto modificadoAuto;
    eColor modificadoColor;

    if(coche != NULL && tam > 0)
    {
        system("cls");
        printf("   *** MODIFICAR AUTOS ***\n\n");
        mostrarAutos(coche, marca, color, tam);

        printf("\nIngrese la patente del auto a modificar\n\n");
        fflush(stdin);
        gets(patente);
        while(validarPatente(coche, tam, patente) == 0)
        {
            printf("Patente invalida. Reingrese patente del auto a modificar: ");
            fflush(stdin);
            gets(patente);
        }
        printf("\nPatente ingresada: %s\n\n", patente);
        system("pause");

        system("cls");
        utn_getNumeroConScanf(&respuesta, "\nQue desea modificar? *** COLOR *** presione 1, *** MODELO *** presione 2\n\n", "Ingreso una opcion incorrecta.\n\n", 1, 2, 10);
        printf("\nLa opcion ingresada es: %d\n\n", respuesta);
        system("pause");

        indice = buscarAuto(coche, tam, patente);

        if(indice == -1)
        {
            printf("\nNo existe esa patente\n\n");
            system("pause");
        }
        else if(respuesta == 1)
        {
            system("cls");
            printf("   *** AUTO A MODIFICAR ***\n");
            printf("---------------------------\n\n");
            mostrarAuto(coche[indice], marca, color, tam);

            printf("\n\n");
            mostrarColores(color, tamC);

            printf("\nIngrese ID del nuevo color\n\n");
            fflush(stdin);
            scanf("%d", &modificadoColor.id);
            while(validarColor(color, tamC, modificadoColor.id) == 0)
            {
                printf("Id Color invalido. Reingrese id Color: ");
                fflush(stdin);
                scanf("%d", &modificadoColor.id);
            }
            printf("\nEl nuevo id Color ingresado es: %d\n\n", modificadoColor.id);
            system("pause");


            utn_getNumeroConScanf(&confirmaColor, "\n\nPara modificar presione 1, para cancelar, 2\n", "\nOpcion incorrecta, debe ingresar 1 o 2, reintente\n", 1, 2, 10);

            if(confirmaColor == 1)
            {
                coche[indice].idColor = modificadoColor.id;

                error = 0;
            }
            else
            {
                error = 2;
            }

        }
        else
        {
            system("cls");
            printf("   *** MODELO ***\n\n");
            utn_getNumeroConScanf(&modificadoAuto.modelo, "Ingrese modelo (anio de fabricacion)\n", "Reingrese modelo, debe ingresar anios desde 1900 hasta 2020.\n", 1900, 2020, 10);
            printf("\nEl Modelo ingresado es: %d\n\n", modificadoAuto.modelo);
            system("pause");


            utn_getNumeroConScanf(&confirmaModelo, "\n\nPara modificar presione 1, para cancelar, 2\n", "\nOpcion incorrecta, debe ingresar 1 o 2, reintente\n", 1, 2, 10);

            if(confirmaModelo == 1)
            {
                coche[indice].modelo = modificadoAuto.modelo;

                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }
    return error;
}

int obtenerDescripcionColor(eColor color[], int tam, int id, char nombreColor[])
{
    int error = 1;

    if(color != NULL && tam > 0 && id >= 1 && nombreColor != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(color[i].id == id)
            {
                strcpy(nombreColor, color[i].nombreColor);
                error = 0;
                break;
            }
        }
    }
    return error;
}

int obtenerDescripcionMarca(eMarca marca[], int tam, int id, char descripcion[])
{
    int error = 1;

    if(marca != NULL && tam > 0 && id >=1 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(marca[i].id == id)
            {
                strcpy(descripcion, marca[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}

int ordenarAutosMarcaPatente(eAuto coche[], eMarca marca[], int tam, int criterioM, int criterioP)
{
    int error = 1;
    eAuto auxAuto;
    char marcaI[20];
    char marcaJ[20];

    if(coche != NULL && tam > 0 && criterioM >= 0 && criterioM <= 1 && criterioP >= 0 && criterioP <= 1)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                obtenerDescripcionMarca(marca, tam, coche[i].idMarca, marcaI);
                obtenerDescripcionMarca(marca, tam, coche[j].idMarca, marcaJ);

                if(strcmp(marcaI, marcaJ) > 0 && criterioM == 1)//menor a mayor
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if(strcmp(marcaI, marcaJ) < 0 && criterioM == 0)//Mayor a menor
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if((strcmp(marcaI, marcaJ) == 0) &&(strcmp(coche[i].patente, coche[j].patente) > 0 && criterioP == 1))
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
                else if((strcmp(marcaI, marcaJ) == 0) &&(strcmp(coche[i].patente, coche[j].patente) < 0 && criterioP == 0))
                {
                    auxAuto = coche[i];
                    coche[i] = coche[j];
                    coche[j] = auxAuto;
                }
            }
        }
        error = 0;
    }
    return error;
}

int validarPatente(eAuto coche[], int tamA, char patente[])
{
    int esValido = 0;
    if(coche != NULL && tamA > 0 && patente != NULL)
    {
        for(int i=0; i < tamA; i++)
        {
            if(strcmp(coche[i].patente, patente) == 0)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
////////////////////////////////////////
int listarAutosXColor(eAuto coche[], int tamA, eColor color[], int tamC, eMarca marca[], int tamM)
{
    int error = -1;
    int idColor;
    int flag = 0;
    char nombreColor[20];

    if(coche != NULL && color != NULL && tamA >0 && tamC > 0)
    {
        system("cls");
        printf("   *** Listado de Autos por color elegido ***\n\n");
        mostrarColores(color, tamC);
        printf("Ingrese id color.\n");
        fflush(stdin);
        scanf("%d", &idColor);

        while(validarColor(color, tamC, idColor) == 0)
        {
            printf("Id invalido. Reingrese id color: ");
            fflush(stdin);
            scanf("%d", &idColor);
        }

        obtenerDescripcionColor(color, tamC, idColor, nombreColor);

        system("cls");
        printf("Autos con el color %s:\n\n", nombreColor);

        for(int i=0; i<tamA; i++)
        {
            if(coche[i].isEmpty == 0 && coche[i].idColor == idColor)
            {
                mostrarAuto(coche[i], marca, color, tamA);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay Autos con el color %s\n\n", nombreColor);
        }

        printf("\n\n");

        error = 0;
    }

    return error;
}

int listarAutosXMarca(eAuto coche[], int tamA, eColor color[], int tamC, eMarca marca[], int tamM)
{
    int error = -1;
    int idMarca;
    int flag = 0;
    char nombreMarca[20];

    if(coche != NULL && marca != NULL && tamA >0 && tamM > 0)
    {
        system("cls");
        printf("   *** Listado de Autos por Marca elegida ***\n\n");
        mostrarMarcas(marca, tamM);
        printf("Ingrese id Marca.\n");
        fflush(stdin);
        scanf("%d", &idMarca);

        while(validarMarca(marca, tamM, idMarca) == 0)
        {
            printf("Id invalido. Reingrese id Marca: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }

        obtenerDescripcionMarca(marca, tamM, idMarca, nombreMarca);

        system("cls");
        printf("Autos con la Marca %s:\n\n", nombreMarca);

        for(int i=0; i<tamA; i++)
        {
            if(coche[i].isEmpty == 0 && coche[i].idMarca == idMarca)
            {
                mostrarAuto(coche[i], marca, color, tamA);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay Autos con la marca %s\n\n", nombreMarca);
        }

        printf("\n\n");

        error = 0;
    }

    return error;
}

int autoMasViejo(eAuto coche[], int tamA, eColor color[], eMarca marca[])
{
    int error = 1;
    int mayor;
    int contadores[tamA];
    int flag = 0;

    for(int i=0; i<tamA; i++)
    {
        contadores[i] = 0;
    }

    if(coche != NULL && tamA >0)
    {
        system("cls");
        printf("   *** Auto mas viejo ***\n\n");

        for(int i=0; i < tamA; i++)
        {
            for(int j=0; j < tamA; j++)
            {
                if(coche[j].isEmpty == 0 && coche[j].modelo > coche[i].modelo)
                {
                    contadores[i]++;
                }
            }
        }

        for(int i=0; i<tamA; i++)
        {
            if(contadores[i] > mayor || flag == 0)
            {
                mayor = contadores[i];
                flag = 1;
            }
        }

        printf(" Id           Patente     Modelo        idMarca              idColor  \n\n");

        for(int i=0; i<tamA; i++)
        {
            if(contadores[i] == mayor)
            {
                mostrarAuto(coche[i], marca, color, tamA);
            }
        }

        printf("\n\n");
        error = 0;
    }

    return error;
}

int listarAutosSeparadosXMarca(eAuto coche[], int tamA, eColor color[], int tamC, eMarca marca[], int tamM)
{
    int error = -1;
    int flag = 0;
    char descMarca[20];

    if(coche != NULL && marca != NULL && tamA >0 && tamM > 0)
    {
        system("cls");
        printf("   *** Listado de Autos separados por Marca ***\n\n");
        for(int m = 0; m < tamM; m++)
        {
            flag = 0;
            obtenerDescripcionMarca(marca, tamM, marca[m].id, descMarca);

            printf("Marca: %s\n", descMarca);
            for(int i=0; i<tamA; i++)
            {
                if(coche[i].isEmpty == 0 && coche[i].idMarca == marca[m].id)
                {
                    mostrarAuto(coche[i], marca, color, tamA);
                    flag = 1;
                }
            }

            if(flag == 0)
            {
                printf("No hay autos con la marca %s\n\n", descMarca);
            }

            printf("\n\n");
        }
        error = 0;
    }
    return error;
}

int contarAutosXColorYMarca(eAuto coche[], int tamA, eColor color[], int tamC, eMarca marca[], int tamM)
{
    int error = -1;
    int idColor;
    int idMarca;
    char nombreColor[20];
    char nombreMarca[20];

    int contadorColor = 0;
    int contadorMarca = 0;

    if(coche != NULL && color != NULL && marca != NULL && tamA >0 && tamC > 0 && tamM > 0)
    {
        system("cls");
        printf("   *** Cantidad de Autos de un color y marca ***\n");
        mostrarColores(color, tamC);
        printf("Ingrese id Color.\n");
        fflush(stdin);
        scanf("%d", &idColor);

        while(validarColor(color, tamC, idColor) == 0)
        {
            printf("Id invalido. Reingrese id Color: ");
            fflush(stdin);
            scanf("%d", &idColor);
        }

        system("cls");
        mostrarMarcas(marca, tamM);
        printf("Ingrese id Marca.\n");
        fflush(stdin);
        scanf("%d", &idMarca);

        while(validarMarca(marca, tamM, idMarca) == 0)
        {
            printf("Id invalido. Reingrese id Marca: ");
            fflush(stdin);
            scanf("%d", &idMarca);
        }

        for(int i=0; i<tamA; i++)
        {
            if(coche[i].isEmpty == 0 && coche[i].idColor == idColor)
            {
                contadorColor++;
            }
        }

        for(int i=0; i<tamA; i++)
        {
            if(coche[i].isEmpty == 0 && coche[i].idMarca == idMarca)
            {
                contadorMarca++;
            }
        }
        obtenerDescripcionColor(color, tamC, idColor, nombreColor);
        obtenerDescripcionMarca(marca, tamM, idMarca, nombreMarca);

        printf("\nCantidad Autos con el color %s: %d\n\n", nombreColor, contadorColor);
        printf("Cantidad Autos con la Marca %s: %d\n\n", nombreMarca, contadorMarca);

        error = 0;
    }

    return error;
}

int marcaFavorita(eAuto coche[], int tamA, eMarca marca[], int tamM)
{
    int error = 1;
    int mayor;
    int contadores[tamM];
    int flag = 0;

    for(int i=0; i<tamM; i++)
    {
        contadores[i] = 0;
    }

    if(coche != NULL && marca != NULL && tamA >0 && tamM > 0)
    {
        system("cls");
        printf("   *** Marca favorita ***\n");
        for(int m = 0; m < tamM; m++)
        {
            for(int i=0; i<tamA; i++)
            {
                if(coche[i].isEmpty == 0 && coche[i].idMarca == marca[m].id)
                {
                    contadores[m]++;
                }
            }
        }

        for(int i=0; i<tamM; i++)
        {
            if(contadores[i] > mayor || flag == 0)
            {
                mayor = contadores[i];
                flag = 1;
            }
        }

        printf("La o las marcas favoritas son: \n\n");

        for(int i=0; i<tamM; i++)
        {
            if(contadores[i] == mayor)
            {
                printf("%s\n", marca[i].descripcion);
            }
        }

        printf("\n\n");
        error = 0;
    }

    return error;
}



