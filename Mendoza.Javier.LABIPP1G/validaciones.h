#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el numero minimo a ser aceptado
 * \param maximo int Es el numero maximo a ser aceptado
 * \param reintentos int Es el numero de reintentos para el usuario
 * \return int Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumeroConScanf(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);


/** \brief Chequea el largo de una cadena
 *
 * \param cadena[] char Es la cadena a chequear
 * \param tamanio int tamanio que deseas analizar
 * \param mensaje[] char mensaje para el usuario
 * \param errorMensaje[] char mensaje de error
 * \return void
 *
 */
void largoCadena(char cadena[],int tamanio,char mensaje[],char errorMensaje[]);


/** \brief Chequea que la fecha ingresada sea correcta
 *
 * \param pDia int* dia a ingresar
 * \param pMes int* mes a ingresar
 * \param pAnio int* anio a ingresar
 * \return int devuelve 0 si se hixo correctamente o 1 sino
 *
 */
int validarFecha(int* pDia, int* pMes, int* pAnio);
