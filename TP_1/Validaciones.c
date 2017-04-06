/**
*\brief Valida por medio de un flag si el usuario ingreso valores para realizar los calculos correspondientes
*\flag bandera utilizada para saber si se ingreso o no un nro
*\return devuelve 1 una vez q ingreso un nro. y si el nro estaba ingresado la validacion devuelve 0
*
*/

float numeroEsInvalido(int flag, int n)
{
    if (flag==0)
    {
        printf("\nDebe ingresar el operando nro %d para realizar el calculo seleccionado: ",n);
        return 1;
    }
    else
        return 0;
}

/**
*\brief toma valor ingresado por el usuario y los guarda en una variable
*\return devuelve el numero obtendo
*
*/

float tomarValor()
{
    float num;
    scanf("%f",&num);
    return num;
}

/**
*\brief valida si el numero ingresado por el usuario es un numero entero y si es positivo
*\entero guarda la parte entera del nro decimal ingresado, si fuese el caso
*\return devuelve 0 o 1 dependiendo el caso como bandera para saber que ejecutar despues.
*
*/

int esEntero(float n)
{
    int entero;
    if(n<0)
    {
        return 0;
    }
    else
    {
        entero=(int)n;
        if(n-entero!=0)
        {
            return 0;
        }
        else
            return 1;
    }

}
