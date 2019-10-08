#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "juegos.h"
#include "Fecha.h"
#include "clientes.h"
#include "alquileres.h"

int initAlquileres(eAlquileres list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    }
    else
    {
        ret = -1;
    }

    return ret;

};

int searchEmptyAlquiler(eAlquileres list[],int len)
{
    int index = -1;
    for(int i=1; i<len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
};

int addAlquiler(eClientes listClientes[],int tamClie,eJuego listJuegos[],int tamJuego,eAlquileres listAlq[],int tamAlq)
{
    int ret,index,indexJuegos,indexClientes;
    eAlquileres newAlquiler;
    char auxJuego[3];
    char auxClienteCod[4];
    char anio[5];
    char mes[5];
    char dia[5];


    if(listAlq != NULL && tamAlq > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmptyAlquiler(listAlq,tamAlq);
        printf("\t\t***ALTA DE Alquiler***");
        if(index == -1)
        {
            printf("\nNo hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {


            printf("\nNuevo Alquiler, CODIGO numero %d. \n\n",index) ;


            do
            {
                printf("\nSeleccionar el Juego correspondiente:\n");
                viewJuegos(listJuegos,tamJuego);
                while(!funcion_getStringNumeros("\n\nIngrese el numero de codigo del Juego: ",auxJuego))
                {
                    printf("Error el codigo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexJuegos = findJuegoById(listJuegos,tamJuego,atoi(auxJuego));
                if(indexJuegos == -1)
                {
                    printf("\n***ERROR*** El codigo del Juego es incorrecto");
                }
                else
                {
                    system("cls");
                    printf("\n\nEl Juego seleccionado es:\n");
                    printf("\nCODIGO\tTITULO          APELLIDO    NOMBRE\n");

                    viewJuego(listJuegos[indexJuegos]);
                }

            }
            while(indexJuegos == -1);


            printf("\nSeleccionar Cliente:\n");
            viewClientes(listClientes,tamClie);
            do
            {
                while(!funcion_getStringNumeros("\nIngrese el numero de codigo del Cliente/a: ",auxClienteCod))
                {
                    printf("\nError el codigo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexClientes = findCliente(listClientes,tamClie,atoi(auxClienteCod));
                if(indexClientes == -1)
                {
                    printf("\n***ERROR*** Codigo incorrecto\n");
                    system("pause");
                }
                else
                {
                    printf("\nEl Cliente seleccionado es:\n");
                    viewCliente(listClientes[indexClientes]);
                }

            }
            while(indexClientes == -1);

            printf("****** Fecha de Alquiler ******\n\n");
                       while(!funcion_getStringNumeros("Ingrese dia: ", dia))
                        {
                            printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese mes: ", mes))
                        {
                            printf("ERROR- EL MES TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");

                        };
                        while(!funcion_getStringNumeros("Ingrese anio: ", anio))
                        {
                            printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                            system("pause");
                            system("cls");
                        };


            newAlquiler.codigoAlquiler = index;
            newAlquiler.AlquilerJuego = listJuegos[indexJuegos];
            newAlquiler.AlquilerCliente = listClientes[indexClientes];
            newAlquiler.fechaAlquiler.dia = atoi(dia);
            newAlquiler.fechaAlquiler.mes = atoi(mes);
            newAlquiler.fechaAlquiler.anio = atoi(anio);
            newAlquiler.isEmpty = 0;
            listAlq[index] = newAlquiler;
            system("cls");
            mostrarAlquiler(listAlq[index],tamAlq,listJuegos,tamJuego,listClientes,tamClie);
            printf("\n\n");


        }
    }
    else
    {
        ret = -1 ;
    }
    return ret;
};

void mostrarAlquiler(eAlquileres listAlq,int lenAlq,eJuego listJuegos[],int lenJuegos,eClientes listClientes[],int lenClientes)
{
    int indexJuego,indexCliente;

    printf("\t\t-Alquiler-\n\nCodigo del Alquiler: %d\nFecha del Alquiler: %d/%d/%d\n\n",listAlq.codigoAlquiler,listAlq.fechaAlquiler.dia,listAlq.fechaAlquiler.mes,listAlq.fechaAlquiler.anio);

    indexJuego = findJuegoById(listJuegos,lenJuegos,listAlq.AlquilerJuego.codigoJuego);
    printf("\t\t Juego \nTitulo: %s\nDescripcion: %s\nImporte: %s \n\n",listJuegos[indexJuego].name,listJuegos[indexJuego].descripcion,listJuegos[indexJuego].importe);

    indexCliente = findCliente(listClientes,lenClientes,listAlq.AlquilerCliente.file);
    printf("\t\t Cliente \nApellido y nombre: %s %s\nCodigo de Cliente: %d",listClientes[indexCliente].lastName,listClientes[indexCliente].name,listClientes[indexCliente].file);

};
void mostrarAlquileres(eAlquileres listAlq[],int lenAlq,eJuego listJuegos[],int lenJuegos,eClientes listClientes[],int lenClientes)
{

    for(int i = 0; i < lenAlq; i++)
    {

        if(listAlq[i].isEmpty == 0)
        {
            printf("_________________________________________\n\n");
            mostrarAlquiler(listAlq[i],lenAlq,listJuegos,lenJuegos,listClientes,lenClientes);
            printf("\n");
        }
    }

};

int menuAlquileres()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU Alquileres ***\n\n");
    printf("1-ALTAS \n");
    printf("2-LISTAR \n\n") ;
    printf("3-VOLVER AL MENU PRINCIPAL\n\n") ;
    while(!funcion_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}
