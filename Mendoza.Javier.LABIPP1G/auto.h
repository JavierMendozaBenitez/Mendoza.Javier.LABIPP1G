#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "marca.h"
#include "color.h"

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;// 1 esta vacia 0 esta llena
} eAuto;

#endif // AUTO_H_INCLUDED

/** \brief menu con opciones char
 *
 * \return char retorna la opcion elegida
 *
 */
char menuChar();


/** \brief inicializa el campo isEmpty en 1 toda la entidad eAutos
 *
 * \param coche[] eAuto entidad a inicializar
 * \param tam int tamanio de la entidad
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int inicializarAutos(eAuto coche[], int tam);


/** \brief muestra un auto
 *
 * \param coche eAuto entidad a mostrar
 * \param marca[] eMarca allí busca la descripcion de la marca
 * \param color[] eColor allí busca la descripcion del color
 * \param tam int tamanio de eAuto
 * \return void
 *
 */
void mostrarAuto(eAuto coche, eMarca marca[], eColor color[], int tam);


/** \brief mustra todos los autos
 *
 * \param coche[] eAuto entidad a mostra
 * \param marca[] eMarca allí busca la descripcion de la marca
 * \param color[] eColor allí busca la descripcion del color
 * \param tam int tamanio de eAuto
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int mostrarAutos(eAuto coche[], eMarca marca[], eColor color[], int tam);


/** \brief datos harcodeados
 *
 * \param coche[] eAuto entidad a harcodear
 * \param tam int tamanio de la entidad
 * \param cantidad int cantidad a harcodear
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int harcodearDatos(eAuto coche[], int tam, int cantidad);


/** \brief busca un lugar libre en la entidad
 *
 * \param coche[] eAuto entidad donde buscar
 * \param tam int tamanio de la entidad
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int buscarLibre(eAuto coche[], int tam);


/** \brief da de alta un auto
 *
 * \param coche[] eAuto entidad en donde dar de alta
 * \param tam int tamanio de eAuto
 * \param marca[] eMarca donde buscar la descripcion de la marca
 * \param tamM int tamanio de eMarca
 * \param color[] eColor donde buscar la descripcion del color
 * \param tamC int tamanio del eColor
 * \param id int id a dar de alta
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int altaAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC, int id);


/** \brief busca un auto activo
 *
 * \param coche[] eAuto entidad en donde buscar
 * \param tam int tamanio de la entidad
 * \param patente[] char patente del auto
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int buscarAuto(eAuto coche[], int tam, char patente[]);


/** \brief da de baja un auto
 *
 * \param coche[] eAuto entidad en donde dar de baja
 * \param marca[] eMarca entidad necesaria para mostrar los autos
 * \param color[] eColor entidad necesaria para mostrar los autos
 * \param tam int tamanio de eAuto
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int bajaAutos(eAuto coche[], eMarca marca[], eColor color[], int tam);


/** \brief modifica un auto
 *
 * \param coche[] eAuto entidad a modificar
 * \param tam int tamanio de eAuto
 * \param marca[] eMarca entidad necesaria para mostrar los autos
 * \param tamM int tamanio de eMarca
 * \param color[] eColor entidad necesaria para mostrar los autos
 * \param tamC int tamanio de eColor
 * \return int  retorna 0 si se hizo correctamente y 1 sino
 *
 */
int modificarAuto(eAuto coche[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);


/** \brief ordena la entidad eAuto
 *
 * \param coche[] eAuto entidad a ordenar
 * \param marca[] eMarca entidad donde busca la descripcion de la marca
 * \param tam int tamanio de la entidad eAuto
 * \param criterioM int criterio de ordenamiento de marca
 * \param criterioP int criterio de ordenamiento de patente
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int ordenarAutosMarcaPatente(eAuto coche[], eMarca marca[], int tam, int criterioM, int criterioP);


/** \brief obtiene descripcion de eMarca
 *
 * \param marca[] eMarca entidad
 * \param tam int tamnio de eMarca
 * \param id int id a obtener la descripcion
 * \param descripcion[] char donde guardar la descripcion
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int obtenerDescripcionMarca(eMarca marca[], int tam, int id, char descripcion[]);


/** \brief obtiene descripcion de eColor
 *
 * \param color[] eColor entidad
 * \param tam int tamanio de eColor
 * \param id int id a obtener la descripcion
 * \param nombreColor[] char donde guardar el nombre del color
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int obtenerDescripcionColor(eColor color[], int tam, int id, char nombreColor[]);


/** \brief valida que exista la patente
 *
 * \param coche[] eAuto entidad donde buscar
 * \param tamA int tamanio de eAuto
 * \param patente[] char patente a validar
 * \return int retorna 0 si se hizo correctamente y 1 sino
 *
 */
int validarPatente(eAuto coche[], int tamA, char patente[]);
