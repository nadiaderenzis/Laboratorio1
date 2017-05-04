typedef struct
{
    char nombre[50];
    char password[10];
    int id;
    int isEmpty;
} S_Usuarios;

typedef struct
{
    char nombre[150];
    float precio;
    int id;
    int isEmpty;
    int idUsuario;
    int contador;
    int stock;
} S_Productos;


typedef struct
{
    char tipo[15];
} EMotivo;


int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
int getNumeroAleatorio(int desde, int hasta, int iniciar);
void getString(char mensaje[],char arrayChar[]);
int getNumerosChar (char array[],char mensaje[]);
int getStringLetras(char mensaje[],char input[]);



int ingresarSoloLetras (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarPassword (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarNumero (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[],int minimo, int maximo);


void inicializarListaDeUsuarios(S_Usuarios usuario[],int cantidad,int estado);
void inicializarListaDeProductos(S_Productos producto[],int cantidad,int estado);


