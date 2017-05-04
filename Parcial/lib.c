#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "busqueda.h"
/**
 * \brief Carga y valida datos ingresados por usuario
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param Id pasado por parametro
 */
int alta (S_Usuarios usuario[],int cantidad,int id)
{
    int retorno=0;
    int indiceVacio;
    char auxNombre[50];
    char auxpassword[10];

    indiceVacio=obtenerEspacioLibre(usuario,cantidad,1);
    if(indiceVacio!=-1)
    {
        retorno = ingresarSoloLetras(auxNombre,"\nIngrese su nombre: ","\nCaracteres invalidos para un nombre.\n");
        if(retorno)
        {
            retorno = cargarPassword(auxpassword,"\nIngrese su password: ","\nLa password solo debe ser numerica.\n");
        }
    }
    if(retorno==1)
    {
        strcpy(usuario[indiceVacio].nombre,auxNombre);
        strcpy(usuario[indiceVacio].password,auxpassword);
        usuario[indiceVacio].id=id;
        usuario[indiceVacio].isEmpty=0;

    }
    return retorno;
}
/**
 * \brief Busca por indice y realiza baja lógica
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param mensaje para el usuario
 */
void baja (S_Usuarios usuario[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[])
{
    int indiceId;
    char continuar;
    int cargaExitosa;
    char id[3];
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdUsuario(usuario,cantidad,atoi(id));
            if(indiceId!=-1)
            {
                usuario[indiceId].isEmpty=1;
                cargaExitosa =1;
            }
            else
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(cargaExitosa==0 && continuar=='s');
}
/**
 * \brief Busca por indice y realiza carga de datos a modificar
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param mensaje para el usuario
 */
void modificar (S_Usuarios usuario[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[])
{
    int indiceId;
    int cargaExitosa;
    char auxNombre[50];
    char auxpassword[10];
    char opcion;
    if((indiceId =obtenerIndicePorId(usuario,cantidad,mensaje,mensajeError,mensajeNoEncontrado))!=-1)
    {
        opcion=getChar("Ingrese la opcion a modificar, \n\n 1-Nombre.\n 2-Password.\n");
        switch(opcion)
        {
        case '1':
            cargaExitosa = ingresarSoloLetras(auxNombre,"\nNombre: ","\nCaracteres invalidos para un nombre.\n");
            if(cargaExitosa==1)
            {
                strcpy(usuario[indiceId].nombre,auxNombre);
            }
            break;
        case '2':
            cargaExitosa = cargarPassword(auxpassword,"\nPassword: ","\nLa password solo debe ser numerica.\n");
            if(cargaExitosa==1)
            {
                strcpy(usuario[indiceId].password,auxpassword);
            }
            break;
        default :
            printf("Error. Opcion incorrecta.");
            break;
        }
    }


}

/**
 * \brief Busca por indice activo en dos estructuras y crea una entrada para productos
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param array de datos a comparar
 * \param cantidad de posiciones que tiene el array.
 * \param dato pasado como parametro
 */
int nuevoProducto (S_Usuarios usuario[],int cantidad, S_Productos producto[], int cantidadProductos,int id)
{
    int retorno=0;
    int indiceId;
    int indiceVacio;
    char auxNombre[50];
    float auxPrecio;
    int auxStock;
    indiceVacio=obtenerEspacioLibreProducto(producto,cantidadProductos,1);
    if(indiceVacio!=-1)
    {
        indiceId = obtenerIndicePorId(usuario,cantidad,"Ingrese ID de usuario","ID invalido","ID no encontrado");
    }
    if(indiceId!=-1)
    {
        producto[indiceVacio].idUsuario=usuario[indiceId].id;
        producto[indiceVacio].id=id;
        producto[indiceVacio].isEmpty=0;
        retorno=ingresarSoloLetras(auxNombre,"\nIngrese nombre del producto: ","\nCaracteres invalidos para el nombre de producto.\n");
        if(retorno)
        {
            auxPrecio=getFloat("Ingrese precio: ");
            auxStock=getInt("Ingrese stock: ");
        }
        if(retorno==1)
        {
            strcpy(producto[indiceVacio].nombre,auxNombre);
            producto[indiceVacio].precio=auxPrecio;
            producto[indiceVacio].stock=auxStock;
        }
    }

    return retorno;
   }



