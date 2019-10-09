#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"

int menuInformes()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** INFORMES ***\n\n");
    printf("1-Promedio y total de los importes de los juegos alquilados\n") ;
    printf("2-La cantidad de juegos cuyo importe NO superan el promedio del item anterior\n") ;
    printf("3-Listar todos los clientes que alquilaron un juego determinado\n") ;
    printf("4-Listar todos los juegos que fueron alquilados por un cliente en particular\n") ;
    printf("5-Listar juegos menos alquilados\n") ;
    printf("6-Listar todos los clientes con menos alquileres\n") ;
    printf("7-Listar todos los juegos alquilados en una fecha determinada\n") ;
    printf("8-Listar todos los clientes que realizaron al menos un alquiler en una fecha determinada\n") ;
    printf("9-Listar todos los juegos ordenados por importe (Burbujeo)\n") ;
    printf("10-Listar todos los clientes ordenados por Apellido (insercion)\n") ;
    printf("11-Volver a inicio\n\n") ;
    while(!funcion_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
};

void listarClienteDeJuego(eJuego listJuego[],int lenJuego,eClientes listClientes[],int lenClientes,eAlquileres lisAlq[],int lenAlq)
{
    char auxCodigoJuego[5];
    int indexJuego,indexCliente,codigoCliente;
    int contadorCliente = 0;

    system("cls");
    printf("Seleccione el juego a buscar:\n");
    viewJuegos(listJuego,lenJuego);
    while(!funcion_getStringNumeros("Ingrese el codigo del juego: ",auxCodigoJuego))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexJuego = findJuegoById(listJuego,lenJuego,atoi(auxCodigoJuego));
    printf("\n\nEl juego %s fue solicitado por: \n",listJuego[indexJuego].name);

    for(int i = 0; i < lenAlq; i++)
    {
        if(atoi(auxCodigoJuego) == lisAlq[i].AlquilerJuego.codigoJuego)
        {
            codigoCliente = lisAlq[i].AlquilerCliente.file;
            indexCliente = findCliente(listClientes,lenClientes,codigoCliente);
            printf("\n");
            viewCliente(listClientes[indexCliente]);
            printf("\n");
            contadorCliente++;
        }


    }

    if(contadorCliente == 0)
    {
        printf("Nadie");
    }

};
void listarJuegosDeClientes(eJuego listJuego[],int lenJuego,eClientes listClientes[],int lenClientes,eAlquileres lisAlq[],int lenAlq)
{
    char auxcodigoCliente[5];
    int indexJuego,indexCliente,codigoJuego;
    int contadorCliente = 0;

    system("cls");
    printf("Seleccione el cliente a buscar:\n");
    viewClientes(listClientes,lenClientes);
    while(!funcion_getStringNumeros("Ingrese el codigo del cliente: ",auxcodigoCliente))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexCliente = findCliente(listClientes,lenClientes,atoi(auxcodigoCliente));
    printf("\n\nEl cliente %s %s solicito los juegos: \n",listClientes[indexCliente].name,listClientes[indexCliente].lastName);


    for(int i = 0; i < lenAlq; i++)
    {
        if(atoi(auxcodigoCliente) == lisAlq[i].AlquilerCliente.file)
        {
            codigoJuego = lisAlq[i].AlquilerJuego.codigoJuego;
            indexJuego = findJuegoById(listJuego,lenJuego,codigoJuego);
            printf("\n");
           viewJuego(listJuego[indexJuego]);
            printf("\n");
            contadorCliente++;
        }


    }

    if(contadorCliente == 0)
    {
        printf("\nNingun juego solicitado.\n");
        system("pause");
    }


}

int listarJuegosPorImporteBurbujeo(eJuego list[], int len)
{
    eJuego auxJuego;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].importe,list[j].importe) < 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxJuego   = list[i];
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

}


void listarClientesPorApellidoInsercion(eClientes list[], int len)
{

    int i, j;
    eClientes auxCliente;

    for (i = 1; i < len; i++)
    {
        auxCliente = list[i];
        j = i - 1;
        while (j>=0 && strcmp(auxCliente.lastName,list[j].lastName) < 0)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = auxCliente;
    }
}

void listarJuegoEnFechaDeterminada(eAlquileres lisAlq[],int lenAlq,eJuego listJuego[],int lenJuego)
{
    char auxDia[3];
    char auxMes[3];
    char auxAnio[5];
    int codigoJuego,indexJuego;
    int contadorPrestamo = 0;

    system("cls");
    printf("****** Fecha de busqueda ******\n\n");
    while(!funcion_getStringNumeros("Ingrese dia: ", auxDia))
    {
        printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");

    };
    while(!funcion_getStringNumeros("Ingrese mes: ", auxMes))
    {
        printf("ERROR- EL MES TIENE QUE CONTENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");

    };
    while(!funcion_getStringNumeros("Ingrese anio: ", auxAnio))
    {
        printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };
    for(int i=0; i<lenAlq; i++)
    {
        if(lisAlq[i].isEmpty == 0)
        {
            if(atoi(auxDia)==lisAlq[i].fechaAlquiler.dia && atoi(auxMes)==lisAlq[i].fechaAlquiler.mes && atoi(auxAnio)==lisAlq[i].fechaAlquiler.anio)
            {
                codigoJuego = lisAlq[i].AlquilerJuego.codigoJuego;
                indexJuego = findJuegoById(listJuego,lenJuego,codigoJuego);
                viewJuego(listJuego[indexJuego]);
                system("pause");
                contadorPrestamo++;
            }


        }


    }



    if(contadorPrestamo == 0)
    {
        printf("\nNo se realizo ningun prestamo en ese dia.\n\n");
        system("pause");
    }
};
void listarClienteEnFechaDeterminada(eAlquileres lisAlq[],int lenAlq,eClientes listClientes[],int lenClientes)
{
    char auxDia[3];
    char auxMes[3];
    char auxAnio[5];
    int codigoCliente,indexCliente;
    int contadorPrestamo = 0;

    system("cls");
    printf("****** Fecha de busqueda ******\n\n");
    while(!funcion_getStringNumeros("Ingrese dia: ", auxDia))
    {
        printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");

    };
    while(!funcion_getStringNumeros("Ingrese mes: ", auxMes))
    {
        printf("ERROR- EL MES TIENE QUE CONTENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");

    };
    while(!funcion_getStringNumeros("Ingrese anio: ", auxAnio))
    {
        printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    for(int i=0; i<lenAlq; i++)
    {
        if(lisAlq[i].isEmpty == 0)
        {
            if(atoi(auxDia)==lisAlq[i].fechaAlquiler.dia && atoi(auxMes)==lisAlq[i].fechaAlquiler.mes && atoi(auxAnio)==lisAlq[i].fechaAlquiler.anio)
            {
            codigoCliente = lisAlq[i].AlquilerCliente.file;
            indexCliente = findCliente(listClientes,lenClientes,codigoCliente);
            viewCliente(listClientes[indexCliente]);
            system("pause");
            contadorPrestamo++;
            }

        }




    }
    if(contadorPrestamo == 0)
    {
        printf("\nNo se realizo ningun prestamo en ese dia.\n\n");
        system("pause");
    }


};

float listarPromedioyTotalImportes (eJuego listJuegos[],int lenJuegos, eAlquileres listAlq[],int lenAlq)
{
    float contImporte = 0,promedioFinal = 0,auxImporteJuego = 0,ret = 0;
    int codigoJuego,contJuegos = 0,indexJuego;

    for(int i = 0;i < lenAlq;i++)
    {
        if(listAlq[i].isEmpty == 0)
        {

           codigoJuego = listAlq[i].AlquilerJuego.codigoJuego ;
           indexJuego = findJuegoById(listJuegos,lenJuegos,codigoJuego);
           auxImporteJuego = atoi(listJuegos[indexJuego].importe);
           contImporte = (contImporte + auxImporteJuego);
           contJuegos++;
        }
    }
    promedioFinal = contImporte / contJuegos;
    ret = promedioFinal;
    printf("\n\nEl promedio total de los juegos alquilados es: $%0.2f\nEl total de los importes de los juegos alquilados es: $%0.2f",promedioFinal,contImporte);
    return ret;
};
void listarjuegosNoSuperanPromedio(eJuego listJuegos[],int lenJuegos,float promedio)
{
    int contadorJuegos = 0;

    for(int i = 0; i < lenJuegos;i++)
    {
        if(promedio > 0 && atoi(listJuegos[i].importe) < promedio)
        {
            contadorJuegos++;
        }
    }

    if(contadorJuegos == 0)
    {
        printf("No hay juegos que superen el importe de $%0.2f.\n\n",promedio);
        system("pause");
    }else
     {
        printf("La cantidad de juegos que no superan el importe de $%0.2f son: %d\n\n",promedio,contadorJuegos);
        system("pause");
    }
};
