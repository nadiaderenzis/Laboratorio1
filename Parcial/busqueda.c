#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANTPERS 20
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "busqueda.h"

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param mensaje, texto para solicitar el ID
 * \param mensajeError, texto si el dato es invalido
 * \param mensajeNoEncontrado, texto si no se encontro el ID
 * \return indice del ID encontrado
 *
 */

int obtenerIndicePorId(S_Usuarios usuario[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdUsuario(usuario,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}

/**
 * \brief Obtiene el indice del ID
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param mensaje, texto para solicitar el ID
 * \param mensajeError, texto si el dato es invalido
 * \param mensajeNoEncontrado, texto si no se encontro el ID
 * \return indice del ID encontrado
 *
 */

int obtenerIndiceProductoId(S_Productos producto[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdProducto(producto,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}



/**
 * \brief busca el primer espacio libre
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param si se encuentra ocupado o no
 * \return -1 si no hay espacio libre o indice libre
 *
 */

int obtenerEspacioLibreProducto(S_Productos producto[], int cantidad_elementos, int estado)
{
    int i;
    int retorno=-1;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(producto[i].isEmpty==estado)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param si se encuentra ocupado o no
 * \return -1 si no hay espacio libre o indice libre
 *
 */

int obtenerEspacioLibre(S_Usuarios usuario[], int cantidad_elementos, int estado)
{
    int i;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(usuario[i].isEmpty==estado)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Obtiene id
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param dato a comparar
 * \return indice o -1 si no se encontro el id
 *
 */

int buscarPorIdProducto(S_Productos producto[], int cantidad,int idProducto)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idProducto==producto[i].id) && producto[i].isEmpty==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param id a comparar
 * \return indice del ID encontrado o -1 si no se encuentra
 *
 */
int buscarPorIdUsuario(S_Usuarios usuario[], int cantidad,int idUsuario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idUsuario==usuario[i].id) && usuario[i].isEmpty==0)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}






