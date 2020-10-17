#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

#endif // MARCA_H_INCLUDED

/** \brief muestra una marca
 *
 * \param marca eMarca le entidad a mostrar
 * \return void
 *
 */
void mostrarMarca(eMarca marca);

/** \brief muestra todas la marcas
 *
 * \param marca[] eMarca es la entidad a mostar
 * \param tam int tamanio de la entidad
 * \return int devuelve o si se hizo correctamente o 1 sino
 *
 */
int mostrarMarcas(eMarca marca[], int tam);

/** \brief chequea que la marca exista
 *
 * \param marca[] eMarca entidad a chequear
 * \param tamM int tamanio de la entidad
 * \param id int id a chequear
 * \return int devuelve o si se hizo correctamente o 1 sino
 *
 */
int validarMarca(eMarca marca[], int tamM, int id);
