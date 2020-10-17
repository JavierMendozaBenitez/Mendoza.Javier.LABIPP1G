#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

#endif // FECHA_H_INCLUDED

/** \brief mustra las fechas
 *
 * \param unaFecha eFecha entidad a mostrar
 * \return void
 *
 */
void mostrarFecha(eFecha unaFecha);
