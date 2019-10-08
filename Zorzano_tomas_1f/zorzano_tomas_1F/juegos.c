#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "juegos.h"


void viewJuego(eJuego list)
{
    printf("\n%d\t%s\t%s\t%s\n",list.codigoJuego,list.name,list.descripcion,list.importe);

}

void viewJuegos(eJuego list[],int len)
{
    printf("\n\nCODIGO\tNOMBRE         DESCRIPCION    IMPORTE\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            viewJuego(list[i]);
        }
    }
};


void hardcodeoJuegos(eJuego* list)
{

    eJuego x[]={
    {001,"FIFA 20             ","Futbol   ","60.00",0},
    {002,"CALL OF DUTY        ","Disparos ","50.00",0},
    {003,"PES 20              ","Futbol   ","72.00",0},
    {004,"Grand Theft Auto V  ","Simulador","85.00",0},
    {005,"Red Dead Redemption ","Simulador ","47.00",0},
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
};

int findJuegoById(eJuego list[], int len, int id)
{

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoJuego == id)
        {
            return i;
            break;
        }
    }
    return -1;

};

int sortJuegos(eJuego list[], int len)
{
    eJuego auxJuego;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].descripcion,list[j].descripcion) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxJuego = list[i];
                    list[i] = list[j];
                    list[j] = auxJuego ;
                }


            }

            ret = 1;

        }
    }
    else
    {
        ret = -1;
    }


    return ret;

};
