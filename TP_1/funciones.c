/**
*\brief Toma los nros ingresados por el usuario y ejecuta una division
*\resultado guarda el valor obtenido de la division
*\return devuelve resultado
*
*/

float division (float divisor, float dividendo)
{
    float resultado;
    resultado=(float)divisor/dividendo;
    return resultado;
}

/**
*\brief Toma los nros ingresados por el usuario y ejecuta una suma
*\resultado guarda el valor obtenido de la suma
*\return devuelve resultado
*
*/

float suma (float num1, float num2)
{
    float resultado;
    resultado=num1+num2;
    return resultado;
}

/**
*\brief Toma los nros ingresados por el usuario y ejecuta una multiplicacion
*\resultado guarda el valor obtenido de la multiplicacion
*\return devuelve resultado
*
*/

float multiplicacion (float multiplicando, float multiplicador)
{
    float resultado;
    resultado=multiplicando*multiplicador;
    return resultado;
}

/**
*\brief Toma los nros ingresados por el usuario y ejecuta una resta
*\resultado guarda el valor obtenido de la resta
*\return devuelve resultado
*
*/

float resta (float minuendo, float sustraendo)
{
    float resultado;
    resultado=minuendo-sustraendo;
    return resultado;
}
/**
*\brief Toma el primer numero ingresado por el usuario y si es un nro entero calcula el factorial
*\resultado guarda el valor obtenido del factorial
*\return devuelve resultado
*
*/

int factorial (int num)
{
    int resultado;
    {
        if(num==1|| num==0)
        {
            return 1;
        }
        resultado=num* factorial(num-1);
        return (resultado);
    }
}

