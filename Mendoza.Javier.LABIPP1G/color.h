#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

#endif // COLOR_H_INCLUDED

/** \brief muestra un color
 *
 * \param color eColor la entidad a mostrar
 * \return void
 *
 */
void mostrarColor(eColor color);

/** \brief muestra todos los colores
 *
 * \param color[] eColor es la entidad a mostar
 * \param tam int tamanio de la entidad
 * \return int devuelve o si se hizo correctamente o 1 sino
 *
 */
int mostrarColores(eColor color[], int tam);

/** \brief chequea que el color exista
 *
 * \param color[] eColor entidad a chequear
 * \param tamC int tamanio de la entidad
 * \param id int id a chequear
 * \return int devuelve o si se hizo correctamente o 1 sino
 *
 */
int validarColor(eColor color[], int tamC, int id);
