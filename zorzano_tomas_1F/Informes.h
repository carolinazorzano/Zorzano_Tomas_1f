
int menuInformes();
void listarClienteDeJuego(eJuego listJuego[],int lenJuego,eClientes listClientes[],int lenClientes,eAlquileres lisAlq[],int lenAlq);
int listarJuegosPorImporteBurbujeo(eJuego list[], int len);
void listarClientesPorApellidoInsercion(eClientes list[], int len);
void listarJuegosDeClientes(eJuego listJuego[],int lenJuego,eClientes listClientes[],int lenClientes,eAlquileres lisAlq[],int lenAlq);
void listarJuegoEnFechaDeterminada(eAlquileres lisAlq[],int lenAlq,eJuego listJuego[],int lenJuego);
void listarClienteEnFechaDeterminada(eAlquileres lisAlq[],int lenAlq,eClientes listClientes[],int lenClientes);
float listarPromedioyTotalImportes (eJuego listJuegos[],int lenJuegos, eAlquileres listAlq[],int lenAlq);
void listarjuegosNoSuperanPromedio(eJuego listJuegos[],int lenJuegos,float promedio);

