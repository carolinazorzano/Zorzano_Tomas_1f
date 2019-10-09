typedef struct
{
    int file;
    char name[51];
    char lastName[51];
    char gender[51];
    char telefono[21];
    char domicilio[71];
    eFecha fechaClientes;
    int isEmpty;
} eClientes;

int initClientes(eClientes list[], int len);
int findEmpty(eClientes list[],int len);
int findCliente(eClientes list[],int len, int file);
void viewCliente(eClientes aClientes);
void viewClientes(eClientes list[], int len);
int addClientes(eClientes list[], int len);
int removeCliente(eClientes* list, int len);
int funcion_opciones();
int funcion_opcionesModificacion();
void modifyCliente(eClientes list[], int len);
int sortClientes(eClientes list[], int len);
void hardcodeoClientes(eClientes* list);
