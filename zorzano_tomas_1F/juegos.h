typedef struct
{
    int codigoJuego;
    char name[31];
    char descripcion[31];
    char importe[31];
    int isEmpty;

} eJuego;

void viewJuego(eJuego list);
void viewJuegos(eJuego list[],int len);

int findJuegoById(eJuego list[], int len, int id);
int sortJuegos(eJuego list[], int len);

