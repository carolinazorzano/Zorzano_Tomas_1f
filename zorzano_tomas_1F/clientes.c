#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#include "Fecha.h"
#include "clientes.h"

#define MAX 1001

int initClientes(eClientes list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=1; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};
int findEmpty(eClientes list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};
int findCliente(eClientes list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].file == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewCliente(eClientes aClientes)
{

    printf(" \nLegajo:%d - Nombre:%s -  Apellido:%s- Genero:%s - Telefono:%s-  domicilio:%s-  Dia:%d-  Mes:%d-  Anio:%d \n ",aClientes.file , aClientes.name, aClientes.lastName, aClientes.gender, aClientes.telefono,aClientes.domicilio,aClientes.fechaClientes.dia,aClientes.fechaClientes.mes,aClientes.fechaClientes.mes);
};

void viewClientes(eClientes list[], int len)
{

    system("cls");


    for(int i=1; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewCliente(list[i]);
        }
    }

};
int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA \n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA \n");
    printf(" 4- INFORMAR \n");
    printf(" 5- SALIR \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-6 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 6\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};

int funcion_opcionesModificacion()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES *******");
    printf("\n Que desea modificar?\n");
    printf(" 1- NOMBRE \n");
    printf(" 2- APELLIDO \n");
    printf(" 3- TELEFONO \n");
    printf(" 4- DIRECCION \n");
    printf(" 5- GENERO \n");
    printf(" 6- NO MODIFICAR NADA \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-6 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 6\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
int addClientes(eClientes list[], int len)
{
    eClientes newCliente;

    int index;
    char auxName[51];
    char auxLastName[51];
    char auxTelefono[21];
    char auxGender[51];
    char auxDom[71];
    char auxDia[11];
    char auxMes[11];
    char auxAnio[11];
    float ret;
    int fechaCorrecta=-1;
    int nombre=0,apellido=0,telefono=0,genero=0,fecha=0;
    int domicilio=0;

    if(list != NULL && MAX > 0 )
    {
        system("cls");
        fflush(stdin);
        index = findEmpty (list, len);
        printf("*** ALTA Cliente ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Cliente nuevo, su legajo es : %d \n",index);
            newCliente.file = index ;




            if(nombre == 0 )
            {
                while(!funcion_getStringLetras("Ingrese Nombre: ",auxName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    nombre=1;


                };
                 nombre=1;

            }


            printf("\nNombre: %s \n",auxName);

            if(apellido==0)
            {
                while(!funcion_getStringLetras("Ingrese Apellido: ",auxLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s \n",auxName);
                    apellido=1;

                };
                apellido=1;

            }
            printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
            if(telefono == 0)
            {
                while(!funcion_getStringTelefono("Ingrese Telefono: ",auxTelefono))
                {
                    printf("ERROR- EL TELEFONO TIENE QUE CONTENER ESTE FORMATO XXXX-XXXX \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
                    telefono=1;
                };
                telefono=1;

            }
            printf("\nNombre: %s - Apellido: %s - Telefono: %s \n",auxName,auxLastName,auxTelefono);

            if( domicilio== 0)
            {
                while(!funcion_getStringAlfaNumerica("Ingrese Domicilio: ",auxDom))
                {
                    printf("ERROR- EL DOMICILIO TIENE QUE CONTENER SOLO LETRAS Y NUMEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Telefono: %s \n\n",auxName,auxLastName,auxTelefono);
                    domicilio=1;
                };
                domicilio=1;

            }
            printf("\nNombre: %s - Apellido: %s - Telefono: %s - Domicilio %s \n",auxName,auxLastName,auxTelefono,auxDom);

            if(genero == 0)
            {
                while(!funcion_getStringLetras("Ingrese genero: ",auxGender))
                {
                    printf("ERROR- EL GENERO TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Telefono: %s - Domicilio %s \n",auxName,auxLastName,auxTelefono,auxDom);
                    genero=1;
                };
                genero=1;

            }
           printf("\nNombre: %s - Apellido: %s - Telefono: %s - Genero %s - Domicilio: %s \n",auxName,auxLastName,auxTelefono,auxDom,auxDom);

            if(fecha == 0)
            {
                do
                {
                       system("cls");
                       printf("****** Fecha de Ingreso ******\n\n");
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

                        fechaCorrecta = funcion_ValidarFecha(auxDia,auxMes,auxAnio);

                    }
                    while(fechaCorrecta == 0);

                fecha=1;


            }

                printf("\nNombre: %s - Apellido: %s - Telefono: %s - Genero %s- Domicilio: %s\n\nFecha de Ingreso\n\nDia %s - Mes %s - Anio %s \n\n",auxName,auxLastName,auxTelefono,auxGender,auxDom,auxDia,auxMes,auxAnio);
                system("pause");

            while((nombre == 1) && (apellido == 1) && (telefono == 1) && (genero == 1) && (fecha == 1) && (domicilio == 1))
            {
                strcpy(newCliente.name,auxName);
                strcpy(newCliente.lastName,auxLastName);
                strcpy(newCliente.gender,auxGender);
                strcpy(newCliente.telefono,auxTelefono);
                strcpy(newCliente.domicilio,auxDom);
                newCliente.fechaClientes.dia = atoi(auxDia);
                newCliente.fechaClientes.mes = atoi(auxMes);
                newCliente.fechaClientes.anio = atoi(auxAnio);


                newCliente.isEmpty = 0;
                list[index] = newCliente ;
                system("cls");
                printf("\n\n********NUEVO Cliente, BIENVENIDO*********\n\n");
                viewCliente(list[index]);
                printf("\n\n\n");
                ret=0;
                break;

            }
        }
    }
    else
    {
        ret =-1;
    }
    return ret;

};

int removeCliente(eClientes* list, int len)
{

    int index;
    char next[3];
    int id;
    char auxId[4];



    system("cls");
    printf("  *** BAJA Cliente ***\n\n");

    while(!funcion_getStringNumeros("Ingrese Legajo: ", auxId))
    {
        printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findCliente(list, len, id);

    while (index == 0)
    {
        printf("NO HAY NINGUN Cliente CON ESE LEGAJO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un legajo existente: ", auxId))
        {
            printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findCliente(list, len, id);

    }



    while (index == 1)
    {
        viewCliente(list[index]);

        while(!funcion_getStringLetras("\nQUIERE BORRAR USUARIO DEL SISTEMA? si/no: ",next))
        {
            printf("\n ERROR DEBE CONTENER SOLO LETRAS");
        }

        fflush(stdin);



        if(strcmp(next,"si") && strcmp(next,"SI"))
        {
            printf("NO SE REALIZO LA BAJA\n\n");
            break;


        }
        else if(strcmp(next,"no")&& strcmp(next,"NO"))
        {

            list[index].isEmpty = 1;
            printf("SE HIZO LA BAJA DEL Cliente CORRECTAMENTE\n\n");
            break;


        }

    }
    return -1;
};

void modifyCliente(eClientes list[], int len)
{

    int id;
    char auxId[5];
    int index;
    char newTelefono[21];
    char newdomicilio[51];
    char newName[51];
    char newLastName[51];
    char newGender[31];
    char seguir='s';
    int exit = 1;

    system("cls");
    printf("  *** Modificar  Cliente ***\n\n");

    while(!funcion_getStringNumeros("Ingrese legajo: ", auxId))
    {
        printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findCliente(list, len, id);

    while (index == -1)
    {
        printf("NO HAY NINGUN Cliente CON ESE LEGAJO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un legajo existente: ", auxId))
        {
            printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findCliente(list, len, id);

    }


    while ((index >= 0) && (index <=1000))
    {
        viewCliente(list[index]);

        do
        {
            switch (funcion_opcionesModificacion())
            {
            case 1:
                fflush(stdin);
                viewCliente(list[index]);

                while(!funcion_getStringLetras("Ingrese nombre nuevo: ", newName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].name,newName);
                exit = 0;
                break;
            case 2:
                fflush(stdin);
                viewCliente(list[index]);
                while(!funcion_getStringLetras("Ingrese apellido nuevo: ",newLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].lastName,newLastName);
                exit = 0;

                break;
            case 3:
                fflush(stdin);
                viewCliente(list[index]);

                while(!funcion_getStringTelefono("Ingrese telefono: ", newTelefono))
                {
                    printf("ERROR- EL TELEFONO TIENE QUE CONTENER ESTE FORMATO XXXX-XXXX \n\n");
                    system("pause");
                    system("cls");

                };

                strcpy(list[index].telefono,newTelefono);
                exit = 0;
                break;
            case 4:
                fflush(stdin);
                viewCliente(list[index]);


                while(!funcion_getStringAlfaNumerica("Ingrese domicilio nuevo: ", newdomicilio))
                {
                    printf("ERROR- EL DOMICILIO TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].domicilio,newdomicilio);
                exit = 0;
                break;
                case 5:
                fflush(stdin);
                viewCliente(list[index]);
                while(!funcion_getStringLetras("Ingrese genero nuevo: ", newGender))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                };
                 strcpy(list[index].gender,newGender);
                exit = 0;
                break;
            case 6:
                printf("Volviendo a menu principal");
                exit = 1;

                break;
            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 6\n\n");
                system("pause");
                break;


            }

            if(exit==0)

            {
                printf("\n     *** MODIFICACCION EXITOSA ***");
                printf("\nDesea continuar modificando? \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");
                break;
            }

            else
            {
                printf("\n\nEsta por salir de modificacion esta seguro? s/n \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");

            }
            return;
        }
        while (seguir == 's' || seguir == 'S');


    }
    };
int sortClientes(eClientes list[], int len)
{
    eClientes auxCliente;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente ;
                }
                else if(strcmp(list[i].lastName,list[j].lastName) == 0 && strcmp(list[i].name,list[j].name)>0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente ;
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

void hardcodeoClientes(eClientes* list)
{

    eClientes clientes[]=
    {
        {001,"Tomas  ","Zorzano   ","Masculino","4214-2256","Pilar 916   ",{12,05,2001},0},
        {002,"Joaquin","Nunez     ","Masculino","1589-9696","Diomede 73  ",{23,04,2011},0},
        {003,"Ramon  ","Perez     ","Masculino","5815-9898","Morel 21    ",{01,07,2019},0},
        {004,"Esteban","Aguero    ","Masculino","7878-9696","Prieto 1882 ",{22,11,2003},0},
        {005,"Juan   ","Carballo  ","Masculino","1423-8756","Rosales 1212",{03,10,2015},0},
    };
    for(int i = 1; i< 5;i++)
    {
        list[i] = clientes[i];
    }
};
