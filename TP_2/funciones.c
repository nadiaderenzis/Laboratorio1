#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(EPersona lista[], int cantidad_elementos, int estado)
{
    int i;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].estado==estado)
        {
            return i;
        }
    }
    return -1;
}
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni sino devuelve -1
*/
int buscarPorDni(EPersona persona[],int dni,int QTYPERSONAS)
{
    int i;
    for(i=0; i<QTYPERSONAS; i++)
    {
        int dniArray=atoi(persona[i].dni);
        if(dni==dniArray)
        {
            return i;

        }
    }
    return -1;

}
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringNumeros(char mensaje[],char input[])
{
    getString(mensaje,input);
    if(esNumerico(input))
    {
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y valida si se encuentra dentro de un rango de edad lógico
 * \param input Array donde se cargará el texto ingresado
 * \return -
 */

void rangoEdad (char input[])
{
    int edad=atoi(input);
    if(edad<0 || edad>150)
    {
        printf("\nLA EDAD INGRESADA ES INVALIDA");
    }
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */


int getStringLetras(char mensaje[],char input[])
{
    getString(mensaje,input);
    if(esSoloLetras(input))
    {
        return 1;
    }
    return 0;
}
/**
 * \brief Inicializa un array de enteros con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidad_de_elementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posicion
 * \return -
 *
 */

void inializarArray(EPersona persona[],int cantidadElementos,int valor)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        persona[i].estado=valor;
    }
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
/**getString
 * \brief verifica si el dato ingresado es un numero
 * \param str es la cadena a ser analizada
 * \return devuelve 1 si es numerico 0 sino lo es
 *
 */

int esNumerico(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
        {
            return 0;
        }

        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
*/
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
/**
 * \brief imprime grafico utilizando cantidad de personas por edad
 * \param estructura y cantidad de personas
 * \return -
 *
*/

void graficoEdad(EPersona persona[],int QTYPERSONAS)
{
    int contMenos18=0;
    int contEntre18y35=0;
    int contMas35=0;
    int i;
    int edad;

    for(i=0; i<QTYPERSONAS; i++)
    {
        if(persona[i].estado==1)
        {


            edad=atoi(persona[i].edad);
            if(edad<=18)
            {
                contMenos18++;
            }
            else if(edad>18 && edad<35)
            {
                contEntre18y35++;
            }
            else
            {
                contMas35++;
            }
        }
    }
    for(i=QTYPERSONAS; i>0; i--)
    {
        if(!(contEntre18y35<i&&contMas35<i &&contMenos18<i))
        {
            if(i==contMenos18)
            {
                printf("\n*\t");
            }
            else
            {
                printf("\n \t");
            }

            if(i==contEntre18y35)
            {
                printf("*\t");
                contEntre18y35--;
            }
            else
            {
                printf("\t");
            }
            if(i==contMas35)
            {
                printf("*\n");
                contMas35--;
            }
            else
                printf("\n");

        }

    }
    printf("\n<18\t19-35\t>35\n");
}
