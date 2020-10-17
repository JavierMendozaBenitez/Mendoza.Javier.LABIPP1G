#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "servicio.h"
#include "marca.h"
#include "color.h"
#include "auto.h"

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
