#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[50];
    char edad[3];
    int estado;
    char dni[9];

} EPersona;

void inializarArray(EPersona persona[],int cantidadElementos,int valor);
int obtenerEspacioLibre(EPersona persona[], int cantidad_elementos, int estado );
void cargarPersona(EPersona persona[],int index);
int getInt(char mensaje[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int buscarPorDni(EPersona persona[], int dni,int QTYPERSONAS);
void rangoEdad (char input[]);
void graficoEdad(EPersona persona[],int QTYPERSONAS);
void getString(char mensaje[],char input[]);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
#endif // FUNCIONES_H_INCLUDED
