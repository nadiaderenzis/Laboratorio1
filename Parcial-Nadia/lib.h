
int alta (S_Usuarios listaPersonas[],int cantidad,int id);
void baja (S_Usuarios listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void modificar (S_Usuarios listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void nuevaLlamada (S_Usuarios listaPersonas[],int cantidad, S_Productos listaLlamadas[], int cantidadLlamas,int id);

int modificarPublicacion (S_Usuarios listaUsuarios[],int cantidadUsuarios,S_Productos listaProductos[],int cantidadProductos);
int compraProducto (S_Usuarios listaUsuarios[],int cantidadUsuarios,S_Productos productos[],int cantidadProductos);
