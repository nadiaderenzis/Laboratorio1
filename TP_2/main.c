#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define QTYPERSONAS 20
#define ESPACIOLIBRE 0


int main()
{
    EPersona persona[QTYPERSONAS];
    EPersona auxiliarPersona;

    char seguir='s';
    int opcion=0;
    int indiceLibre;
    char auxNombre[50];
    char auxEdad[4];
    char auxDni[10];
    int i,j;
    int indiceDniEncontrado;
    int dniAbuscar;


    inializarArray(persona,QTYPERSONAS,0);

    while(seguir=='s')
    {
        opcion=getInt("\n\nIngrese la opcion deseada:\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n\n");
        switch(opcion)
        {
        case 1:
            indiceLibre=obtenerEspacioLibre(persona,QTYPERSONAS,ESPACIOLIBRE);
            if(indiceLibre==-1)
            {
                printf("NO QUEDAN LUGARES LIBRES");
                break;
            }
            printf("\nAGREGAR PERSONA");
            if(getStringLetras("\nIngrese el nombre:",auxNombre)==0)
            {
                printf("\nERR0R,EL NOMBRE SOLO DEBE CONTENER LETRAS! Ud. Sera redirigido al menu principal");
                break;
            }
            if((getStringNumeros("\nIngrese la edad:",auxEdad))==0)
            {
                printf("\nERROR, LA EDAD DEBE SER UN VALOR NUMERIC0! Ud. Sera redirigido al menu principal");
                break;
            }
            else
            {
                rangoEdad(auxEdad);

            }
            if((getStringNumeros("\nIngrese el DNI: ",auxDni))==0)
            {
                printf("\nERROR, EL DNI DEBE SER NUMERICO! Ud. Sera redirigido al menu principal");
                break;
            }
            dniAbuscar=atoi(auxDni);

            if(buscarPorDni(persona,dniAbuscar,QTYPERSONAS)!=-1)
            {
                printf("EL DNI YA EXISTE!\n");
                break;
            }
            strcpy(persona[indiceLibre].nombre,auxNombre);
            strcpy(persona[indiceLibre].edad,auxEdad);
            strcpy(persona[indiceLibre].dni,auxDni);
            persona[indiceLibre].estado=1;
            break;

        case 2:
            printf("\n\nBORRAR PERSONA");
            dniAbuscar=getInt("\nIngrese el nro de DNI que desea buscar: ");
            indiceDniEncontrado=buscarPorDni(persona,dniAbuscar,QTYPERSONAS);
            if(indiceDniEncontrado==-1)
            {
                printf("\nEl DNI que ud ingreso no se encuentra en sistema.");
            }
            else
            {
                printf("\nEL REGISTRO DEL DNI INGRESADO SERA BORRADO.");
                persona[indiceDniEncontrado].estado=-1;
            }
            break;
        case 3:
            printf("\nLISTADO ORDENADO POR APELLIDO\n");
            printf("\n\nNOMBRE\t EDAD\t DNI\n");
            for(i=0; i<QTYPERSONAS-1; i++)
            {
                {
                    if(persona[i].estado==-1)
                        continue;
                }
                for(j=i+1; j<QTYPERSONAS; j++)
                {
                    {
                        if(persona[j].estado==-1)
                            continue;
                    }
                    if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                    {
                        auxiliarPersona=persona[j];
                        persona[j]=persona[i];
                        persona[i]=auxiliarPersona;
                    }
                }
            }

            for(i=0; i<QTYPERSONAS; i++)
            {
                if(persona[i].estado==1)
                {
                    printf("\n%s\t%s\t%s",persona[i].nombre,persona[i].edad,persona[i].dni);
                }
            }
            break;
        case 4:
            graficoEdad(persona,QTYPERSONAS);
            break;
        case 5:
            if(seguir == 'n')
                break;
        }
    }

    return 0;
}
