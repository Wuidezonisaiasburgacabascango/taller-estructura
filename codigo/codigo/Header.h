#pragma once
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Inventario.h"
using namespace std;
Inventario inventario;
/* Funcion para elegir la opcion. */

char opcion(char* opciones)
{
    char s;

    printf("Elija una opcion. ");
    do {
        cin>>s;
    } while (!strchr(opciones, toupper(s)));
    cout<<s<<endl;
    return s;
}

/* Funcion para continuar (S/N). */

bool continuar(void)
{
    char ch;

    cout<<"Desea continuar (S/N)? . ";
    do {
        cin >> ch;
        ch = toupper(ch);
    } while (ch != 'S' && ch != 'N');
    printf("%c\n", ch);
    return (ch == 'S') ? true : false;
}

/* Selecciona una opcion del menu. */
char menu()
{
    char s;
    printf("REGISTRO DE PERSONAS\n\n\n");
    printf("(1) Inicializar archivo.\n");
    printf("(2) Ingresar informacion.\n");
    printf("(3) Consulta individual.\n");
    printf("(4) Consulta del Directorio.\n");
    printf("(5) Modificar un dato.\n");
    printf("(6) Ordenacion por mezcla directa.\n");
    printf("(0) Terminar.\n");
    do {
        printf("Elija una opcion. ");
        cin >> s;
    } while (!strchr("1234560", s));
    cout << s << endl;
    return s;   
}

/* Abre un archivo con nombre nom_archivo y modo modo. */

FILE* abrir_archivo(char *nom_archivo, char *modo)
{
    FILE* F;
    errno_t err;

    //if ((err = fopen_s(&F,nom_archivo, modo)) != 0) {
    F=fopen(nom_archivo, modo);
    if (F==NULL) {
        printf("No se puede abrir el archivo %s.\n",nom_archivo);
        exit(1);
    }
    return F;
}

/* Inicializar el archivo. CREACION SINO EXISTE, SI EXISTE ARCHIVO SE BORRA*/

void inicializar(FILE* F,char *archivo, char *modo)
{
    printf("\n\nCrea el archivo %s.\n",archivo);
    printf("La informacion se pierde.\n");
    if (continuar()) {
        F = abrir_archivo(archivo, modo);
        fclose(F);
    }
}
/* Inicializar el archivos PARA ORDENAMIENTO*/

void inicializarOrd(FILE* F, char* archivo, char* modo)
{
    
   F = abrir_archivo(archivo, modo);
   fclose(F);
   
}
/* Busca una estructura, si le encuentra retorna verdad, si no falso. */
bool buscar(FILE* F, char* nombre, Inventario* datos)
{
    Inventario aux_datos;
    bool esta = false;

    rewind(F); //MOVER EL ARCHIVO AL INICIO
    if (fread(&aux_datos, sizeof(Inventario), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F)) {
        if (!strcmp(nombre, aux_datos.toString())) {
             aux_datos.setNombre(*datos);
            esta = true;
            break;
        }
        if (fread(&aux_datos, sizeof(lista), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
    }

    return esta;
}
/* Imprime los datos de una estructura. */

void mostrar_datos(Inventario inventario)
{
    printf("\n(N)ombre   : %s\n", inventario.getNombre());
    printf("(C)alle    : %s\n", inventario.getCantidad());
    printf("c(I)udad   : %s\n", inventario.getPrecio());
}


/* Ingresa la informacion desde teclado y almacena en el archivo. */

void ingresar(FILE* F)
{
    Inventario datos;
    char archivo[] = "CORREO"; //ARCHIVO ORIGINAL
    char modo[] = "rb+"; //AGREGAR REGISTROS AL ARCHIVO
    printf("\n\nIngreso de datos\n");
    F = abrir_archivo(archivo, modo);
    do {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        cin >> datos.nombre;
        datos.setNombre()
        if (!buscar(F, datos.getNombre(), &datos)) {
            printf("Ingrese la calle    : ");
            cin>>datos.calle;
            printf("Ingrese la ciudad   : ");
            cin>>datos.ciudad;
            printf("Ingrese la provincia: ");
            cin>>datos.provincia;
            printf("Ingrese el codigo   : ");
            cin>>datos.codigo;
            fseek(F, 0, SEEK_END); //BUSCA EL ULTIMO REGISTRO DEL ARCHIVO
            if (fwrite(&datos, sizeof(lista), 1, F) != 1) { //CONVIERTE EN BINARIO EL CONTENIDO DE LA VARIABLE datos Y LA ALMACENA EN EL ARCHIVO
                printf("ERROR de escritura en el archivo.\n");               
            }                
        }
        else {
            printf("\nNombre repetido\n\n");
            system("pause");
        }
    } while (continuar() == true);   
    
    //printf("Ingrese el nombre con <ENTER> termina: ");    
    fclose(F);
}

/* Consulta de una estructura. */

void consulta(FILE* F)
{
    lista datos;
    char nombre[31];
    char archivo[] = "CORREO";
    char modo[] = "rb";
    printf("\n\nConsulta de una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el nombre: ");
    cin>>nombre;
    if (buscar(F, nombre, &datos))
        mostrar_datos(datos);
    else
        printf("\nNo se encuentra esa persona.\n");
    fclose(F);
    system("pause");
}

/* Realiza la consulta total de la lista de correos. */

void consulta_total(FILE* F,char *archivo,char *modo)
{
    lista datos;
    int ord = 0;
    printf("\n\nConsulta total de la lista de correos.\n\n");
    F = abrir_archivo(archivo,modo);
    puts("OR NOMBRE                         CALLE          CIUDAD         PROVINCIA  COD");
    
    if (fread(&datos, sizeof(lista), 1, F) != 1) //CONVERTIR EL REGISTRO EN BINARIO AL TIPO DE DATO DE LA ESTRUCTURA lista 
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F)) {
        printf("%02d %-30s %-14s %-14s %-10s %-4d\n",
            ++ord, datos.nombre, datos.calle, datos.ciudad, datos.provincia,
            datos.codigo);

        if (ord % 18 == 0) {
            system("pause");
            puts("OR NOMBRE                         CALLE          CIUDAD         PROVINCIA  COD");
        }
        if (fread(&datos, sizeof(lista), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
    }
    fclose(F);
    system("pause");
}

/* Modifica una estructura. */

void modificar(FILE* F)
{
    lista datos;
    char nombre[31];
    char archivo[] = "CORREO";
    char modo[] = "rb+";
    printf("\n\nModifica una estructura.\n\n");
    F = abrir_archivo(archivo, modo);
    printf("Ingrese el nombre: ");
    cin>>nombre;

    if (buscar(F, nombre, &datos))
        for (;;) {                            /* Para cambiar varios campos. */
            mostrar_datos(datos);
            printf("\nModificar:\n");

            if (continuar()) {
                char opciones[] = "NCIPD";
                switch (opcion(opciones)) {
                case 'N': printf("Ingrese el nombre   : ");
                    cin>>datos.nombre;
                    break;
                case 'C': printf("Ingrese la calle    : ");
                    cin >>datos.calle;
                    break;
                case 'I': printf("Ingrese la ciudad   : ");
                    cin >> datos.ciudad;
                    break;
                case 'P': printf("Ingrese la provincia: ");
                    cin >> datos.provincia;
                    break;
                case 'D': printf("Ingrese el c√≥digo   : ");
                    cin >> datos.codigo;
                }
            }
            else {
                if (fseek(F, ftell(F) - sizeof(lista), SEEK_SET))
                    printf("ERROR de posicionamiento del indicador de posici√≥n.\n");
                if (fwrite(&datos, sizeof(lista), 1, F) != 1)
                    printf("ERROR de lectura en el archivo.\n");
                break;
            }
        }
    else {
        printf("\nNo se encuentra esa persona.\n");
        system("pause");
    }
    fclose(F);
}

/*
    OTRO ALGORITMO DE ORDENACION DIRECTA
*/

void ordMezclaDirecta(FILE* F, FILE* F1, FILE* F2, int n) { //Joyanes
    int i, j, lgtud;
    bool sw, fin1, fin2;
    char archivo[] = "CORREO";
    char archivo1[] = "F1";
    char archivo2[] = "F2";
    char modo[] = "rb";
    char modo1[] = "wb";
    char modo2[] = "rb+";
    lista datos, datos1, datos2;
    cout << "\nInicia el proceso de ordenamiento: \n";
    system("pause");
    lgtud = 1;
    while (lgtud < n) {
        //PARTICION
        F = abrir_archivo(archivo, modo);
        inicializarOrd(F1, archivo1, modo1);
        inicializarOrd(F2, archivo2, modo1);
        F1 = abrir_archivo(archivo1, modo2);
        F2 = abrir_archivo(archivo2, modo2);
        i = 0;
        sw = true;
        
        if (fread(&datos, sizeof(lista), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
        while (!feof(F)) {
            if (sw) {
                fseek(F1, 0, SEEK_END);
                if (fwrite(&datos, sizeof(lista), 1, F1) != 1)
                    printf("ERROR de escritura en el archivo.\n");
            }
            else
            {
                fseek(F2, 0, SEEK_END);
                if (fwrite(&datos, sizeof(lista), 1, F2) != 1)
                    printf("ERROR de escritura en el archivo.\n");
            }
            i++;
            if (i == lgtud) {
                sw = !sw;
                i = 0;
            }
            if (fread(&datos, sizeof(lista), 1, F) != 1)
                if (!feof(F))
                    printf("ERROR de lectura en el archivo.\n");
        }
        fclose(F);
        fclose(F1);
        fclose(F2);
        //FUSION
        inicializarOrd(F, archivo, modo1);
        F = abrir_archivo(archivo, modo2);
        F1 = abrir_archivo(archivo1, modo);
        F2 = abrir_archivo(archivo2, modo);
        i = 0;
        j = 0;
        fin1 = false;
        fin2 = false;
        if (fread(&datos1, sizeof(lista), 1, F1) != 1) {
            if (!feof(F1))
                printf("ERROR de lectura en el archivo.\n");
            fin1 = true;
        }
        if (fread(&datos2, sizeof(lista), 1, F2) != 1) {
            if (!feof(F2))
                printf("ERROR de lectura en el archivo.\n");
            fin2 = true;
        }

        while (!fin1 || !fin2) {
            while (!fin1 && !fin2 && i < lgtud && j < lgtud) {
                if (datos1.codigo < datos2.codigo) {
                    if (fwrite(&datos1, sizeof(lista), 1, F) != 1)
                        printf("ERROR de escritura en el archivo.\n");
                    if (fread(&datos1, sizeof(lista), 1, F1) != 1) {
                        if (!feof(F1))
                            printf("ERROR de lectura en el archivo.\n");
                        fin1 = true;
                    }
                    i++; //F2
                }
                else {
                    if (fwrite(&datos2, sizeof(lista), 1, F) != 1)
                        printf("ERROR de escritura en el archivo.\n");
                    if (fread(&datos2, sizeof(lista), 1, F2) != 1) {
                        if (!feof(F2))
                            printf("ERROR de lectura en el archivo.\n");
                        fin2 = true;
                    }
                    j++; //F2
                }
            }
            while (!fin1 && i < lgtud) {
                if (fwrite(&datos1, sizeof(lista), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                if (fread(&datos1, sizeof(lista), 1, F1) != 1) {
                    if (!feof(F1))
                        printf("ERROR de lectura en el archivo.\n");
                    fin1 = true;
                }
                i++;
            }
            while (!fin2 && j < lgtud) {
                if (fwrite(&datos2, sizeof(lista), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                if (fread(&datos2, sizeof(lista), 1, F2) != 1) {
                    if (!feof(F2))
                        printf("ERROR de lectura en el archivo.\n");
                    fin2 = true;
                }
                j++;
            }
            i = 0;
            j = 0;
        }
        fclose(F);
        fclose(F1);
        fclose(F2);
        lgtud = lgtud * 2;
    }
    cout << "\nProceso de ordenamiento Finalizado. \n";
}

//MEZCLA DIRECTA
/*FUNCION DE PARTICION
{El algoritmo genera dos archivos auxiliares, F1 y F2, a partir del archivo F. PART es la
longitud de la particiÛn que se va a realizar}
{K, L y R son variables de tipo entero} */

int contarRegistros(FILE* F,char *archivo) {
    lista datos;
    int i = -1;
    char modo[] = "rb";
    F = abrir_archivo(archivo, modo);
    do {
        if (fread(&datos, sizeof(lista), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
        i++;
    } while (!feof(F));
    fclose(F);
    return i;
}
void particiona(FILE* F, FILE* F1, FILE* F2, int part) {
    char archivo[] = "CORREO";
    char archivo1[] = "F1";
    char archivo2[] = "F2";
    char modo[] = "rb"; //LECTURA BINARIA
    char modo1[] = "wb"; //CREACION BINARIA
    char modo2[] = "rb+"; //AGREGAR/ESCRIBIR REGISTROS BINARIA
    lista datos;
    int ord = 0,k,l;

    inicializarOrd(F1, archivo1, modo1);
    inicializarOrd(F2, archivo2, modo1);
    F = abrir_archivo(archivo, modo);
    F1 = abrir_archivo(archivo1, modo2);
    F2 = abrir_archivo(archivo2, modo2);
    if (fread(&datos, sizeof(lista), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    while (!feof(F)) {
        k = 0; //contar los archivos que se escriben en F1
        while (k < part && !feof(F)) {
            fseek(F1, 0, SEEK_END);
            if (fwrite(&datos, sizeof(lista), 1, F1) != 1)
                printf("ERROR de escritura en el archivo.\n");
            if (fread(&datos, sizeof(lista), 1, F) != 1) {
                if (!feof(F))
                    printf("ERROR de lectura en el archivo.\n");
            }
            else
                k++;            
        }
        l = 0; //contar los archivos que se escriben en F2        
        while (l < part && !feof(F)) {
            fseek(F2, 0, SEEK_END);
            if (fwrite(&datos, sizeof(lista), 1, F2) != 1)
                printf("ERROR de escritura en el archivo.\n");
            if (fread(&datos, sizeof(lista), 1, F) != 1) {
                if (!feof(F))
                    printf("ERROR de lectura en el archivo.\n");
            }
            else
            {
                l++;
            }            
        }       
    }
    fclose(F);
    fclose(F1);
    fclose(F2);

    cout << "EN F1" << endl;
    consulta_total(F1,archivo1,modo);
    cout << "EN F2" << endl;
    consulta_total(F2, archivo2, modo);
    
}
void fusiona(FILE* F, FILE* F1, FILE* F2, int part) {

    int k, l;
    bool b1, b2;
    char archivo[] = "CORREO";
    char archivo1[] = "F1";
    char archivo2[] = "F2";
    char modo[] = "rb";
    char modo1[] = "wb";
    char modo2[] = "rb+";
    lista datos1,datos2;
    inicializarOrd(F, archivo, modo1);
    F = abrir_archivo(archivo, modo2);
    F1 = abrir_archivo(archivo1, modo);
    F2 = abrir_archivo(archivo2, modo);
    b1 = true;
    b2 = true;
    if (fread(&datos1, sizeof(lista), 1, F1) != 1) {
        if (!feof(F1))
            printf("ERROR de lectura en el archivo.\n");
    }        
    else
        b1 = false;            

    if (fread(&datos2, sizeof(lista), 1, F2) != 1) {
        if (!feof(F2))
            printf("ERROR de lectura en el archivo.\n");
    }
    else
        b2 = false;   
        
    while ((!feof(F1)||b1==false) && (!feof(F2) || b2 == false)) {
        k = 0; //CONTAR REGISTROS F1
        l = 0; //CONTAR REGISTROS F2
        while ((k < part && b1==false) && (l < part && b2 == false)) {
            cout << datos1.codigo << " - " << datos2.codigo << endl;
            system("pause");
            //if (datos1.codigo <= datos2.codigo) {
            if (strcmp(datos1.nombre,datos2.nombre) <=0 ) {
                fseek(F, 0, SEEK_END);
                if (fwrite(&datos1, sizeof(lista), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                else {
                    cout <<endl<< datos1.codigo << ". Se escribe datos1 en F\n";
                    b1 = true;
                    k++;
                }                    
                if (fread(&datos1, sizeof(lista), 1, F1) != 1)
                {
                    if (!feof(F1))
                        printf("ERROR de lectura en el archivo.\n");
                }
                else
                    b1 = false;
            }
            else {
                fseek(F, 0, SEEK_END);
                if (fwrite(&datos2, sizeof(lista), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                
                else {
                    cout << endl << datos2.codigo << ". Se escribe datos2 en F\n";
                    b2 = true;
                    l++;
                }                    
                if (fread(&datos2, sizeof(lista), 1, F2) != 1) {
                    if (!feof(F2))
                        printf("ERROR de lectura en el archivo.\n");
                }
                else
                {
                    b2 = false;
                }               
            }           
        }
        while (k < part && b1==false) {
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos1, sizeof(lista), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos1.codigo << ". Se escribe datos1 en F";
            b1 = true;
            k++;
            if (fread(&datos1, sizeof(lista), 1, F1) != 1) {
                if (!feof(F1))
                    printf("ERROR de lectura en el archivo.\n");
            }
            else
                b1 = false;
        }
        while (l < part && b2 == false) {
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos2, sizeof(lista), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos2.codigo << ". Se escribe datos2 en F";
            b2 = true;
            l++;
            if (fread(&datos2, sizeof(lista), 1, F2) != 1) {
                if (!feof(F2))
                    printf("ERROR de lectura en el archivo.\n");
            }
            else 
                b2 = false;
        }
    }
    if (b1 == false) {
        fseek(F, 0, SEEK_END);
        if (fwrite(&datos1, sizeof(lista), 1, F) != 1)
            printf("ERROR de escritura en el archivo.\n");
        cout << endl << datos1.codigo << ". Se escribe datos1 en F";
    }
    if (b2 == false) {
        fseek(F, 0, SEEK_END);
        if (fwrite(&datos2, sizeof(lista), 1, F) != 1)
            printf("ERROR de escritura en el archivo.\n");
        cout << endl << datos2.codigo << ". Se escribe datos2 en F";
    }
    while (!feof(F1)) {
        if (fread(&datos1, sizeof(lista), 1, F1) != 1) {
            if (!feof(F1))
                printf("ERROR de lectura en el archivo.\n");
        }
        else {
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos1, sizeof(lista), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos1.codigo << ". Se escribe datos1 en F";
        }        
    }
    while (!feof(F2)) {
        if (fread(&datos2, sizeof(lista), 1, F2) != 1) {
            if (!feof(F2))
                printf("ERROR de lectura en el archivo.\n");
        }
        else {
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos2, sizeof(lista), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos2.codigo << ". Se escribe datos2 en F";
        }       
    }
    fclose(F);
    fclose(F1);
    fclose(F2);
    cout << "FUCION EN F" << endl;
    consulta_total(F, archivo, modo);
    system("pause");
}

/*ALGORITMO DE MEZCLA DIRECTA
{El algoritmo ordena los elementos del archivo F por el mÈtodo de mezcla directa. Utiliza dos
archivos auxiliares F1 y F2. N es el n˙mero de elementos del archivo F}
{PART es una variable de tipo entero}
*/
void mezclaDirecta(FILE* F, FILE* F1, FILE* F2, int n)
{
    int part=1;
    while (part < n) {
        system("pause");
        particiona(F, F1, F2, part);
        fusiona(F, F1, F2, part);
        part = part * 2;       
    }
}







