/*******************************************************************
*Programa: Primer Parcial
*
*Objetivo:
*Sistema de venta de productos
* Version:0.1 4 de mayo de 2017
*Autor:Nadia De Renzis
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "lib.h"
#include "busqueda.h"

#define CANT 100
#define CANTPROD 1000


int main()
{
    char seguir='s';
    char opcion='0';
    S_Usuarios usuario[CANT];
    S_Productos producto[CANTPROD];

    int generadorId=3;
    int generadorIdProducto=0;
    //int generadorIdAmbulancia=0;//Cantidad maxima de ambulancias es 9.
    //int afiliadosConMasLlamadas[CANT];
    int i;
    //int listaUsuariosMayorEdad[CANT];

    inicializarListaDeUsuarios(usuario,CANT,1);
    inicializarListaDeProductos(producto,CANTPROD,1);
    //inicializarArrayDeIndices(afiliadosConMasLlamadas,CANT,-1);
    //strcpy(motivos[0].tipo,"INFARTO");
    //strcpy(motivos[1].tipo,"ACV");
    //strcpy(motivos[2].tipo,"GRIPE");


    //-----------------------------------------------------------------------------------------------------------------
    /* strcpy(usuario[0].nombre,"hola");
     strcpy(usuario[0].password,"12345");
     usuario[0].isEmpty=0;
     usuario[0].id=0;

     strcpy(usuario[1].nombre,"nadia");
     strcpy(usuario[1].password,"56893");
     usuario[1].isEmpty=0;
     usuario[1].id=1;

     strcpy(usuario[2].nombre,"Soledad");
     strcpy(usuario[2].password,"78942");
     usuario[2].isEmpty=0;
     usuario[2].id=2;

     strcpy(producto[0].nombre,"secador");
     producto[0].precio=100;
     producto[0].id=0;
     producto[0].idUsuario=2;
     producto[0].contador=5;
     producto[0].stock=10;
     producto[0].isEmpty=0;

     strcpy(producto[1].nombre,"planchita");
     producto[1].precio=50;
     producto[1].id=1;
     producto[1].idUsuario=1;
     producto[1].contador=4;
     producto[1].stock=15;
     producto[1].isEmpty=0;

     strcpy(producto[2].nombre,"peluca");
     producto[2].precio=50;
     producto[2].id=2;
     producto[2].idUsuario=
     producto[2].contador=4;
     producto[2].stock=15;
     producto[2].isEmpty=0;

    //--------------------------------------------------------------------------------*/

    do
    {

        printf("SISTEMA DE VENTA DE PRODUCTOS.\n\n");
        printf("1- Alta de Usuario.\n");
        printf("2- Modificar datos de usuario.\n");
        printf("3- Baja de Usuario.\n");
        printf("4- Publicar producto.\n");
        printf("5- Modificar puclicacion.\n");
        printf("6- Cancelar Publicacion.\n");
        printf("7- Comprar producto.\n");
        printf("8- Listar publicaciones de Usuario.\n");
        printf("9- Listar Publicaciones.\n");
        printf("10- Listar Usuarios.\n");
        printf("11- Salir.\n");
        fflush(stdin);
        opcion=getChar("\nElija una opcion: ");

        switch(opcion)
        {
        case '1':
            if(alta(usuario,CANT,generadorId))
            {
                generadorId++;
            }
            break;
        case '2':
            modificar (usuario,CANT,"Ingrese ID del usuario a modificar","\nId erroneo.\n","ID no encontrado");
            break;
        case '3':
            baja(usuario,CANT,"ingresar ID  del usuario:","ID incorrecto","El ID no pertenece a ningún afiliado activo.");
            break;
        case 4:
            nuevoProducto(usuario,CANT,producto,CANTPROD,generadorIdProducto);
            break;
        case '5':

            break;
        case '6':

            break;
        case '7':

            break;
        case '8':

            break;
        case '9':

            break;
        case '10':
            system("cls");
            printf("\n");
            for(i=0; i<CANT; i++)
            {
                if(usuario[i].isEmpty==0)
                {
                    printf("Nombre %s --Password %s -- ID: %d\n\n",usuario[i].nombre,usuario[i].password,usuario[i].id);
                }
            }
            break;
        case 11:
            break;
        default :
            printf("Opcion incorrecta.\n");
            system("cls");
            break;
        }

    }
    while(seguir=='s');

    return 0;
}
