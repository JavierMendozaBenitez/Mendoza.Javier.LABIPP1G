
#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief muestra un servicio
 *
 * \param servicio eServicio la entidad a mostrar
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief muestra todas los servicios
 *
 * \param servicio[] eServicio es la entidad a mostar
 * \param tam int tamanio de la entidad
 * \return int devuelve o si se hizo correctamente o 1 sino
 *
 */
int mostrarServicios(eServicio servicio[], int tam);

/** \brief chequea que el servicio exista
 *
 * \param servicio[] eServicio entidad a chequear
 * \param tamS int tamanio de la entidad
 * \param id int id a chequear
 * \return int devuelve o si se hizo correctamente o 1 sino
 *
 */
int validarServicio(eServicio servicio[], int tamS, int id);


/** \brief obtiene la descripcion de un servicio mediante su id
 *
 * \param servicio[] eServicio entidad donde buscar el servicio
 * \param tamS int tamanio de eServicio
 * \param id int id a buscar
 * \param nombreServicio[] char cadena donde guardar la descripcion
 * \return int devuelve o si se hizo correctamente o 1 sino
 *
 */
int obtenerDescripcionServicio(eServicio servicio[], int tamS, int id, char nombreServicio[]);

