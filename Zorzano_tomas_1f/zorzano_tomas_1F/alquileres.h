typedef struct
{
    int codigoAlquiler;
    eJuego AlquilerJuego;
    eClientes AlquilerCliente;
    eFecha fechaAlquiler;
    int isEmpty;

} eAlquileres;

int initAlquileres(eAlquileres list[], int len);
int searchEmptyAlquiler(eAlquileres list[],int len);
int addAlquiler(eClientes listClientes[],int tamSoc,eJuego listJuegos[],int tamJuego,eAlquileres listAlq[],int tamAlq);
void mostrarAlquiler(eAlquileres listAlq,int lenPrest,eJuego listJuegos[],int lenJuegos,eClientes listClientes[],int lenClientes);
void mostrarAlquileres(eAlquileres listAlq[],int lenPrest,eJuego listJuegos[],int lenJuegos,eClientes listClientes[],int lenClientes);
int menuAlquileres();
