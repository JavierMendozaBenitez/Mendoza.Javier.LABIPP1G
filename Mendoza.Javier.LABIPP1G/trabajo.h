#include "fecha.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "auto.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;//1 vacio, 0 lleno
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief muestra un trabajo
 *
 * \param trabajo eTrabajo entidad a mostrar
 * \param servicioT[] eServicio allí busca la descripcion del servicio
 * \param tamT int tamanio de eTrabajo
 * \param tamS int tamanio de eServicio
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio servicioT[], int tamT, int tamS);

/** \brief inicializa el campo isEmpty en 1 toda la entidad eTrabajo
 *
 * \param trabajo[] eTrabajo entidad a inicializar
 * \param tamT int tamanio de la entidad
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int inicializarTrabajos(eTrabajo trabajo[], int tamT);


/** \brief muestra todos los trabajos
 *
 * \param trabajo[] eTrabajo entidad a mostrar
 * \param servicioT[] eServicio allí busca la descripcion
 * \param tamT int tamanio de eTrabajo
 * \param tamS int tamanio de eServicio
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int mostrarTrabajos(eTrabajo trabajo[], eServicio servicioT[], int tamT, int tamS);


/** \brief busca lugares libres para de eTrabajo
 *
 * \param trabajo[] eTrabajo lugar donde buscar
 * \param tamT int tamanio de la entidad
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int buscarLibreTrabajo(eTrabajo trabajo[], int tamT);


/** \brief da de alta un trabajo
 *
 * \param trabajo[] eTrabajo entidad a donde da de alta
 * \param servicioT[] eServicio entidad que brinda el servicio a elegir
 * \param cocheT[] eAuto entidad al que hacerle el trabajo
 * \param marcaT[] eMarca marca del auto
 * \param colorT[] eColor color del auto
 * \param tamT int tamanio de eTrbajo
 * \param tamS int tamanio de eServicio
 * \param tamA int tamanio de eAuto
 * \param tamM int tamanio de eMarca
 * \param tamC int tamanio de eColor
 * \param id int id del trabajo nuevo
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int altaTrabajo(eTrabajo trabajo[], eServicio servicioT[], eAuto cocheT[], eMarca marcaT[], eColor colorT[], int tamT, int tamS, int tamA, int tamM, int tamC, int id);


/** \brief mustra los trabajos hechos a un auto seleccionado
 *
 * \param coche[] eAuto entidad donde buscar el auto
 * \param tamA int tamanio de eAuto
 * \param trabajo[] eTrabajo entidad donde busca el trabajo hecho
 * \param tamT int tamanio de eTrabajo
 * \param servicio[] eServicio entidad donde busca que tipo de servicio es
 * \param tamS int tamanio de eServicio
 * \param color[] eColor entidad necesaria para mostrar todos los datos del auto
 * \param marca[] eMarca entidad necesaria para mostrar todos los datos del auto
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int mostrarTrabajosDeUnAuto(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[]);


/** \brief calcula el importe total de todos los trabajos que se le hicieron a un auto
 *
 * \param coche[] eAuto entidad donde busca el auto
 * \param tamA int tamanio de eAuto
 * \param trabajo[] eTrabajo entidad donde busca el trabajo hecho
 * \param tamT int tamanio de eTrabajo
 * \param servicio[] eServicio entidad donde busca que tipo de servicio es
 * \param tamS int tamanio de eServicio
 * \param color[] eColor entidad necesaria para mostrar todos los datos del auto
 * \param marca[] eMarca entidad necesaria para mostrar todos los datos del auto
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int informeImporteTotalAuto(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[]);


/** \brief elegis un servicio y muestra los autos a los que se le hizo ese servicio
 *
 * \param coche[] eAuto entidad donde busca el auto
 * \param tamA int tamanio de eAuto
 * \param trabajo[] eTrabajo entidad donde busca el trabajo hecho
 * \param tamT int tamanio de eTrabajo
 * \param servicio[] eServicio entidad donde busca que tipo de servicio es
 * \param tamS int tamanio de eServicio
 * \param color[] eColor entidad necesaria para mostrar todos los datos del auto
 * \param marca[] eMarca entidad necesaria para mostrar todos los datos del auto
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int mostrarAutosDeUnServicio(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[]);


/** \brief elegis una fecha y muestra los trabajos que se hicieron en esa fecha
 *
 * \param coche[] eAuto entidad donde busca el auto
 * \param tamA int tamanio de eAuto
 * \param trabajo[] eTrabajo entidad donde busca el trabajo hecho
 * \param tamT int tamanio de eTrabajo
 * \param servicio[] eServicio entidad donde busca que tipo de servicio es
 * \param tamS int tamanio de eServicio
 * \param color[] eColor entidad necesaria para mostrar todos los datos del auto
 * \param marca[] eMarca entidad necesaria para mostrar todos los datos del auto
 * \param fecha[] eFecha entidad necesaria para mostrar la fecha
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int mostrarTrabajosDeUnaFecha(eAuto coche[], int tamA, eTrabajo trabajo[], int tamT, eServicio servicio[], int tamS, eColor color[], eMarca marca[], eFecha fecha[]);


/** \brief valida que la fecha ingresada sea una fecha donde se haya hecho un trabajo
 *
 * \param fecha[] eFecha entidad donde buscar la fecha
 * \param trabajo[] eTrabajo entidad donde buscar la fecha
 * \param tamF int tamanio de eFecha
 * \param dia int dia ingresado
 * \param mes int mes ingresado
 * \param anio int anio ingresado
 * \return int devuelve 0 si se hizo correctamente y 1 sino
 *
 */
int validarFechaDeTrabajo(eFecha fecha[], eTrabajo trabajo[], int tamF, int dia, int mes, int anio);
