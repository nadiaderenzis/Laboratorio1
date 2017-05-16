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


int modificarPublicacion (S_Usuarios listaUsuarios[],int cantidadUsuarios,S_Productos listaProductos[],int cantidadProductos)
{

    int retorno=0;
    int i;
    int indiceId;
    int cargaExitosa;
    char auxNombre[20];
    float auxPrecio;
    int auxStock;
    char opcion;
    indiceId=obtenerIndicePorId(listaUsuarios,cantidadUsuarios,"Ingrese ID de usuario","ID invalido","ID no encontrado");
    if(indiceId!=-1)
    {
        printf("USUARIO: %s\n\n",listaUsuarios[indiceId].nombre);
        for(i=0; i<cantidadProductos; i++)
        {
            /** Acá se van a imprimir todas los productos del usuario **/
            if(listaProductos[i].idUsuario==listaUsuarios[indiceId].id && listaProductos[i].isEmpty==0)
            {
                printf("PRODUCTO: %s -ID: %d -\n",listaProductos[i].nombre,listaProductos[i].id);
            }
        }
    }
    if((indiceId=obtenerIndiceProductoId(listaProductos,cantidadProductos,"Ingrese el ID del producto que desea modificar: ","ID invalido","IDde producto no encontrado")!=-1 ))
    {
        opcion=getChar("Ingrese la opcion a modificar, \n\n 1-Nombre.\n 2-Precio.\n3-Stock.\n");
        switch(opcion)
        {
        case '1':
            getString("\nNombre del producto: ",auxNombre);
            strcpy(listaProductos[indiceId].nombre,auxNombre);
            break;
        case '2':
            printf("Ingrese nuevo precio: \n");
            scanf("%f",&auxPrecio);
            listaProductos[indiceId].precio=auxPrecio;
            break;
        case '3':
            printf("Ingrese nuevo stock: \n");
            scanf("%f",&auxStock);
            listaProductos[indiceId].stock=auxStock;
            break;
        default :
            printf("Error. Opcion incorrecta.");
            break;
        }

        return retorno;
    }
}

int eliminarPublicacion (S_Usuarios listaUsuarios[],int cantidadUsuarios,S_Productos listaProductos[],int cantidadProductos)
{

    int retorno=0;
    int i;
    int indiceId;
    indiceId=obtenerIndicePorId(listaUsuarios,cantidadUsuarios,"Ingrese ID de usuario","ID invalido","ID no encontrado");
    if(indiceId!=-1)
    {
        printf("USUARIO: %s\n\n",listaUsuarios[indiceId].nombre);
        for(i=0; i<cantidadProductos; i++) /** Acá se va aimprimir todas la lista **/
        {
            if(listaProductos[i].idUsuario==listaUsuarios[indiceId].id && listaProductos[i].isEmpty==0)
            {
                printf("PRODUCTO: %s -ID: %d -\n",listaProductos[i].nombre,listaProductos[i].id);
            }
        }
    }
    /**Este es igual, pero más facil, una vez que encontras un ID valido y listas los productos, pedis el id del producto
    buscas su indices por ID y vas al producto con ese indice y cambias isEmpty y lo pones vacio (0 o 1)**/


    return retorno;
}

int compraProducto(S_Usuarios listaUsuarios[],int cantidadUsuarios,S_Productos productos[],int cantidadProductos)
{
    int idProducto;
    int compraExitosa=0;
    int retorno=0;
    int i;
    int indiceId;
    printf("\nSeleccione el producto que desea comprar por ID.\n\n\n");
    printf("PRODUCTO  \tID  \tStock  \tPrecio\n\n");
    for(i=0; i<cantidadProductos; i++) /** Acá se va aimprimir todas las listas **/
    {
        if(productos[i].isEmpty==0)
        {
            printf("%s  \t%d  \t%d  \t%.2f\n",productos[i].nombre,productos[i].id,productos[i].stock,productos[i].precio);
        }
    }
    idProducto = getInt("\nID: ");
    if(idProducto!=-1)
    {
        if(productos[idProducto].stock>0)
        {
         productos[idProducto].contador++;
         productos[idProducto].stock--;
         compraExitosa=1;
        }
    }
    if(compraExitosa)
    {
        carg
    }





    return retorno;
}


int listarPublicacionesDeUsuario(S_Usuarios listaUsuarios[],int cantidadUsuarios,S_Productos productos[],int cantidadProductos)
{

    int retorno=0;
    int i;
    int indiceId;
    indiceId=obtenerIndicePorId(listaUsuarios,cantidadUsuarios,"Ingrese ID de usuario","ID invalido","ID no encontrado");
    if(indiceId!=-1)
    {
        printf("USUARIO: %s\n\n",listaUsuarios[indiceId].nombre);
        printf("PRODUCTO  \tID  \tStock  \tPrecio \tVENDIDOS\n\n");
        for(i=0; i<cantidadProductos; i++)
        {
            /** Acá se va aimprimir todas los productos del usuario **/
            if(productos[i].idUsuario==listaUsuarios[indiceId].id && productos[i].isEmpty==0)
            {
                printf("%s  \t%d  \t%d  \t%.2f \t%d\n",productos[i].nombre,productos[i].id,productos[i].stock,productos[i].precio,productos[i].contador);
            }
        }
    }

    cualquierTeclaContinnuar();
    system("cls");
    return retorno;
}

int listarPublicaciones(S_Usuarios listaUsuarios[],int cantidadUsuarios,S_Productos productos[],int cantidadProductos)
{

    int retorno=0;
    int i;
    int indiceID;
    printf("PRODUCTO  \tID  \tStock  \tPrecio \tVENDIDOS\tUSUARIO\n\n");
    for(i=0; i<cantidadProductos; i++)
    {
        if(productos[i].isEmpty==0)
        {
            indiceID=buscarPorIdUsuario(listaUsuarios,cantidadUsuarios,(productos[i].idUsuario));
            printf("%s  \t%d  \t%d  \t%.2f \t%d\t\t%s\n",productos[i].nombre,productos[i].id,productos[i].stock,productos[i].precio,productos[i].contador,listaUsuarios[indiceID].nombre);
        }
    }
    cualquierTeclaContinnuar();
    system("cls");
    return retorno;
}
