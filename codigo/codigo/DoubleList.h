#if !defined(__DoubleList_h)

#define __DoubleList_h
#include "Node.h"
#include "List.h"
#include <iostream>
#include <stdlib.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#define inicialize 0
#define inicialize1 1
using namespace std;
template<class T>
class DoubleList : List<T>{
	public:
		//Constructor
		DoubleList();
		~DoubleList(){		};
		virtual bool isEmpty();
		int sizeList();
		//Metodos para agregar
    	void addFront(T);
    	void addBack(T);
 		void addMiddle(T, int);
 		
 		void registrarDatos();
		//Metodos para eliminar 	
    	void deleteFront();
    	void deleteBack();
   		void deleteData(T);
    	void deletePosition(int);
    	void clear();
    	//Imprimir
    	void printFromHead();
    	void printFromTail();
    	void printFromHead1();
    	void imprimirRegistro();
    	T get(int);
    	//Busqueda
    	void sequentialSearch();
    	void binarySearch();
    	//Operations
		void shellSort();
		void radixShort();
		void toDistribute();
		void directMix();
		//Operacion de archivos
		FILE* abrir_archivo(char[], char[]);
		void inicializarOrd( char[], char[]);
		void ordMezclaDirecta( int);
		int contarRegistros(char[]);
		void mezclaDirecta( int);
		void fusiona(int);
		void particiona(int);
		void consulta_total(char[]);
		/*
    	virtual T adition(int, int);
		virtual T subtraction(int, int);
		virtual T multiplication(int, int);
		virtual T division(int, int);*/
	private:
		Node<T>* head;
		Node<T>* tail;	
			
};
/**@brief  Busqueda secuencial
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::sequentialSearch() {
    
	Node<T>* aux = this->tail->getPrevious();
	int peso=1,indice=0,cont=0;
	char nombre[15],nombre1[15];
	cout<<"\nIngrese el nombre de la herramienta : ";
	cin>>nombre;
			while(aux!=this->head)
			{
				for(int t=0; t<aux->getData().getNombre().size(); t++){
        		nombre1[t]=aux->getData().getNombre()[t];
    			}
				if(strcmp(nombre1,nombre)==0)
				{
					cout<<"\nSe a encontrado la herramienta"<<endl;
					cout<<cont+1<<"\t\t"<<get(cont).toString()<<endl;
					
				}else{
					cont++;
				}
				memset(nombre1, 0,15);
				aux = aux->getPrevious();
			}
			cont++;
			if(cont>this->sizeList()){
				cout<<"\nNo se a encontrado la herramienta"<<endl;
			}
			system("pause");
}
/**@brief  busqueda binaria
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::binarySearch(){
	Node<T>* pivote= this->tail->getPrevious();
 	Node<T>* superior = this->tail;
 	Node<T>* inferior = this->head;
 	int contador,arriba=1,abajo=0;
 	char palabra[10];
 	T temp;
 	char bandera='F';
 	cout<<"Ingrese el dato que desea buscar "<<endl;
 	cin>>palabra;
 	for(int n=0;n<this->sizeList()/2;n++){
		pivote = pivote->getPrevious();
		contador++;
	}	
	while(abajo<arriba){
		if(int(pivote->getData().getNombre()[0])==int(palabra[0])){
			bandera ='V';
			break;	
		}
		
		if(int(pivote->getData().getNombre()[0])<int(palabra[0])){
 			while(superior!=this->head){
 				if(int(palabra[0])==int(superior->getData().getNombre()[0])){
 					bandera='V';
 				}
 				superior = superior->getPrevious();
			 }
		}
		if(int(pivote->getData().getNombre()[0])>int(palabra[0])){
			pivote = this->head;
 			while(inferior!=this->tail){
 				if(int(palabra[0])==int(inferior->getData().getNombre()[0])){
 					bandera='V';
 				}
 			inferior = inferior->getNext();
			 }

		}
		
		abajo++;	
	}
	if(bandera=='V')
		cout<<abajo<<"El dato se encuentra en la lista "<<endl;
		
	else
		cout<<"El dato no se encuentra en la lista"<<endl;
}
/**@brief  inicializar orden
@param  T d
@returns void
*/
template <class T>
int DoubleList<T>::contarRegistros(char *archivo) {
    FILE* F=NULL;
	T datos;
    int i = -1;
    char modo[] = "rb";
    F = abrir_archivo(archivo, modo);
    do {
        if (fread(&datos, sizeof(T), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
        i++;
    } while (!feof(F));
    fclose(F);
    return i;
}

/**@brief  inicializar orden
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::inicializarOrd(char* archivo, char* modo){
   FILE* F=NULL;
   F = abrir_archivo(archivo, modo);
   fclose(F);
   
}
/**@brief  Abrir archivo
@param  T d
@returns void
*/
template <class T>
FILE* DoubleList<T>::abrir_archivo(char *nom_archivo, char *modo){
    FILE* F=NULL;
    errno_t err;
    //if ((err = fopen_s(&F,nom_archivo, modo)) != 0) {
    F=fopen(nom_archivo, modo);
    if (F==NULL) {
        printf("No se puede abrir el archivo %s.\n",nom_archivo);
        exit(1);
    }
    return F;
}

/**@brief  Consulta
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::consulta_total(char *archivo)
{
	FILE* F=NULL;
 	T data;
  //ARCHIVO ORIGINAL
 	F=fopen(archivo,"rb");
	for(int numeroLista=0;numeroLista<this->sizeList();numeroLista++){
		fread(&data,  this->sizeList(), 1, F); //CONVERTIR EL REGISTRO EN BINARIO AL TIPO DE DATO DE LA ESTRUCTURA lista 
			cout<<numeroLista+1<<"\t"<<data.getNombre()<<"\t"<<data.getCantidad()<<"\t"<<data.getPrecio()<<endl;  
	}
	fclose(F);
}
/**@brief  Particiona
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::particiona(int part) {
	FILE* F=NULL;
	FILE* F1=NULL;
    char archivo[] = "CORREO";
	FILE* F2=NULL;
    char archivo1[] = "F1";
    char archivo2[] = "F2";
    char modo[] = "rb"; //LECTURA BINARIA
    char modo1[] = "wb"; //CREACION BINARIA
    char modo2[] = "rb+"; //AGREGAR/ESCRIBIR REGISTROS BINARIA
	T datos;
    int ord = 0,k,l;
    inicializarOrd(archivo1, modo1);
    inicializarOrd(archivo2, modo1);
    F = abrir_archivo(archivo, modo);
    F1 = abrir_archivo(archivo1, modo2);
    F2 = abrir_archivo(archivo2, modo2);
   
    if (fread(&datos,this->sizeList(), 1, F) != 1)
        if (!feof(F))
            printf("ERROR de lectura en el archivo.\n");
    for(int numeroLista=0;numeroLista<this->sizeList();numeroLista++){
        k = 0; 
		cout<<"\ncontar los archivos que se escriben en F1"<<endl;
		cout<<datos.getNombre()<<"\t"<<datos.getCantidad()<<"\t"<<datos.getPrecio()<<endl;
        while (k < part && !feof(F)) {
            fseek(F1, 0, SEEK_END);
            if (fwrite(&datos,this->sizeList(), 1, F1) != 1)
                printf("ERROR de escritura en el archivo.\n");
            if (fread(&datos, this->sizeList(), 1, F) != 1) {
                if (!feof(F))
                    printf("ERROR de lectura en el archivo.\n");
            }
            else
                k++;            
        }
        l = 0; //contar los archivos que se escriben en F2 
		cout<<"\ncontar los archivos que se escriben en F1"<<endl;       
        while (l < part && !feof(F)) {
            fseek(F2, 0, SEEK_END);
            if (fwrite(&datos,this->sizeList(), 1, F2) != 1)
                printf("ERROR de escritura en el archivo.\n");
            if (fread(&datos,this->sizeList(), 1, F) != 1) {
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
    cout<<"\nterminado proceso de particion"<<endl;
	system("pause");
	
	
    cout << "EN F1" << endl;
 	T data;
 	F1=fopen(archivo1,"rb");
 	if (fread(&datos,this->sizeList(), 1, F1) != 1) //CONVERTIR EL REGISTRO EN BINARIO AL TIPO DE DATO DE LA ESTRUCTURA lista 
        if (!feof(F1))
            printf("ERROR de lectura en el archivo.\n");
	while (!feof(F1)) {
			cout<<"\t"<<data.getNombre()<<"\t"<<data.getCantidad()<<"\t"<<data.getPrecio()<<endl;  
		if (fread(&datos,this->sizeList(), 1, F1) != 1)
            if (!feof(F1))
                printf("ERROR de lectura en el archivo.\n");
	}
	fclose(F1);
    /*consulta_total(F1,archivo1);
    system("pause");
    cout << "EN F2" << endl;
    consulta_total(F2,archivo2);*/
    system("pause");
    
}
/**@brief  Fusiona
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::fusiona(int part) {
    FILE* F=NULL;
    FILE* F1=NULL;
    FILE* F2=NULL;
    
	int k, l;
    bool b1, b2;
    char archivo[] = "CORREO";
    char archivo1[] = "F1";
    char archivo2[] = "F2";
    char modo[] = "rb";
    char modo1[] = "wb";
    char modo2[] = "rb+";
    T datos1,datos2;
    inicializarOrd( archivo, modo1);
    F = abrir_archivo(archivo, modo2);
    F1 = abrir_archivo(archivo1, modo);
    F2 = abrir_archivo(archivo2, modo);
    b1 = true;
    b2 = true;
    if (fread(&datos1,this->sizeList(), 1, F1) != 1) {
        if (!feof(F1))
            printf("ERROR de lectura en el archivo.\n");
    }        
    else
        b1 = false;            

    if (fread(&datos2,this->sizeList(), 1, F2) != 1) {
        if (!feof(F2))
            printf("ERROR de lectura en el archivo.\n");
    }
    else
        b2 = false;   
        
    while ((!feof(F1)||b1==false) && (!feof(F2) || b2 == false)) {
        k = 0; //CONTAR REGISTROS F1
        l = 0; //CONTAR REGISTROS F2
        while ((k < part && b1==false) && (l < part && b2 == false)) {
            cout << datos1.getNombre()<< " - " << datos2.getNombre() << endl;
            system("pause");
            //if (datos1.codigo <= datos2.codigo) {
           if (int(datos1.getNombre()[0])<int(datos2.getNombre()[0])) {
                fseek(F, 0, SEEK_END);
                if (fwrite(&datos1,this->sizeList(), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                else {
                    cout <<endl<< datos1.getNombre() << ". Se escribe datos1 en F\n";
                    b1 = true;
                    k++;
                }                    
                if (fread(&datos1,this->sizeList(), 1, F1) != 1)
                {
                    if (!feof(F1))
                        printf("ERROR de lectura en el archivo.\n");
                }
                else
                    b1 = false;
            }
            else {
                fseek(F, 0, SEEK_END);
                if (fwrite(&datos2,this->sizeList(), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                
                else {
                    cout << endl << datos2.getNombre() << ". Se escribe datos2 en F\n";
                    b2 = true;
                    l++;
                }                    
                if (fread(&datos2,this->sizeList(), 1, F2) != 1) {
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
            if (fwrite(&datos1, this->sizeList(), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos1.getNombre()<< ". Se escribe datos1 en F";
            b1 = true;
            k++;
            if (fread(&datos1, this->sizeList(), 1, F1) != 1) {
                if (!feof(F1))
                    printf("ERROR de lectura en el archivo.\n");
            }
            else
                b1 = false;
        }
        while (l < part && b2 == false) {
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos2, this->sizeList(), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos2.getNombre()<< ". Se escribe datos2 en F";
            b2 = true;
            l++;
            if (fread(&datos2, this->sizeList(), 1, F2) != 1) {
                if (!feof(F2))
                    printf("ERROR de lectura en el archivo.\n");
            }
            else 
                b2 = false;
        }
    }
    if (b1 == false) {
        fseek(F, 0, SEEK_END);
        if (fwrite(&datos1, this->sizeList(), 1, F) != 1)
            printf("ERROR de escritura en el archivo.\n");
        cout << endl << datos1.getNombre() << ". Se escribe datos1 en F";
    }
    if (b2 == false) {
        fseek(F, 0, SEEK_END);
        if (fwrite(&datos2,this->sizeList(), 1, F) != 1)
            printf("ERROR de escritura en el archivo.\n");
        cout << endl << datos2.getNombre() << ". Se escribe datos2 en F";
    }
    while (!feof(F1)) {
        if (fread(&datos1, this->sizeList(), 1, F1) != 1) {
            if (!feof(F1))
                printf("ERROR de lectura en el archivo.\n");
        }
        else {
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos1, this->sizeList(), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos1.getNombre() << ". Se escribe datos1 en F";
        }        
    }
    while (!feof(F2)) {
        if (fread(&datos2,this->sizeList(), 1, F2) != 1) {
            if (!feof(F2))
                printf("ERROR de lectura en el archivo.\n");
        }
        else {
            fseek(F, 0, SEEK_END);
            if (fwrite(&datos2, this->sizeList(), 1, F) != 1)
                printf("ERROR de escritura en el archivo.\n");
            cout << endl << datos2.getNombre()<< ". Se escribe datos2 en F";
        }       
    }
    fclose(F);
    fclose(F1);
    fclose(F2);
    cout << "FUCION EN F" << endl;
   // consulta_total(F,archivo);
    system("pause");
}

/**@brief  ordenar por mezcla directa
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::mezclaDirecta( int n)
{
    int part=1;
    while (part < n) {
        system("pause");
        particiona(part);
        //fusiona(part);
        part = part * 2;       
    }
}

/**@brief  ordenar por mezcla directa
@param  T d
@returns void
*/
template <class T>
void DoubleList<T>::ordMezclaDirecta(int n) { //Joyanes
    FILE* F=NULL;
    FILE* F1=NULL;
    FILE* F2=NULL;
	int i, j, lgtud;
    bool sw, fin1, fin2;
    char archivo[] = "CORREO";
    char archivo1[] = "F1";
    char archivo2[] = "F2";
    char modo[] = "rb";
    char modo1[] = "wb";
    char modo2[] = "rb+";
    T datos, datos1, datos2;
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
        
        if (fread(&datos,this->sizeList(), 1, F) != 1)
            if (!feof(F))
                printf("ERROR de lectura en el archivo.\n");
        for(int numeroLista=0;numeroLista<this->sizeList();numeroLista++){
            if (sw) {
                fseek(F1, 0, SEEK_END);
                if (fwrite(&datos,this->sizeList(), 1, F1) != 1)
                    printf("ERROR de escritura en el archivo.\n");
            }
            else
            {
                fseek(F2, 0, SEEK_END);
                if (fwrite(&datos,this->sizeList(), 1, F2) != 1)
                    printf("ERROR de escritura en el archivo.\n");
            }
            i++;
            if (i == lgtud) {
                sw = !sw;
                i = 0;
            }
            if (fread(&datos, this->sizeList(), 1, F) != 1)
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
        if (fread(&datos1,this->sizeList(), 1, F1) != 1) {
            if (!feof(F1))
                printf("ERROR de lectura en el archivo.\n");
            fin1 = true;
        }
        if (fread(&datos2, this->sizeList(), 1, F2) != 1) {
            if (!feof(F2))
                printf("ERROR de lectura en el archivo.\n");
            fin2 = true;
        }

        while (!fin1 || !fin2) {
            while (!fin1 && !fin2 && i < lgtud && j < lgtud) {
                if (datos1.codigo < datos2.codigo) {
                    if (fwrite(&datos1,this->sizeList(), 1, F) != 1)
                        printf("ERROR de escritura en el archivo.\n");
                    if (fread(&datos1, this->sizeList(), 1, F1) != 1) {
                        if (!feof(F1))
                            printf("ERROR de lectura en el archivo.\n");
                        fin1 = true;
                    }
                    i++; //F2
                }
                else {
                    if (fwrite(&datos2,this->sizeList(), 1, F) != 1)
                        printf("ERROR de escritura en el archivo.\n");
                    if (fread(&datos2,this->sizeList(), 1, F2) != 1) {
                        if (!feof(F2))
                            printf("ERROR de lectura en el archivo.\n");
                        fin2 = true;
                    }
                    j++; //F2
                }
            }
            while (!fin1 && i < lgtud) {
                if (fwrite(&datos1, this->sizeList(), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                if (fread(&datos1,this->sizeList(), 1, F1) != 1) {
                    if (!feof(F1))
                        printf("ERROR de lectura en el archivo.\n");
                    fin1 = true;
                }
                i++;
            }
            while (!fin2 && j < lgtud) {
                if (fwrite(&datos2,this->sizeList(), 1, F) != 1)
                    printf("ERROR de escritura en el archivo.\n");
                if (fread(&datos2,this->sizeList(), 1, F2) != 1) {
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





/**@brief  Registar datos
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::registrarDatos(){
 	char archivo[] = "CORREO";
 	T data;
 	FILE* F=NULL; //ARCHIVO ORIGINAL
 	F=fopen(archivo, "wb");
    fclose(F);
    Node<T>* aux = this->tail->getPrevious();
    F=fopen(archivo,"rb+");
	for(int numeroLista=0;numeroLista<this->sizeList();numeroLista++){
		data=aux->getData();
		if (fwrite(&data, this->sizeList(), 1, F) != 1) 
                cout<<"ERROR de escritura en el archivo.\n"; 
		aux = aux->getPrevious();
	}
	fclose(F);
}
/**@brief  Imprimir registro del archivo
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::imprimirRegistro(){
 	char archivo[] = "CORREO";
 	T data;
 	FILE* F=NULL; //ARCHIVO ORIGINAL
 	F=fopen(archivo,"rb");
	for(int numeroLista=0;numeroLista<this->sizeList();numeroLista++){
		fread(&data,  this->sizeList(), 1, F); //CONVERTIR EL REGISTRO EN BINARIO AL TIPO DE DATO DE LA ESTRUCTURA lista 
			cout<<numeroLista+1<<"\t"<<data.getNombre()<<"\t"<<data.getCantidad()<<"\t"<<data.getPrecio()<<endl;  
	}
	fclose(F);	
}

/**@brief  Ordenamiento por distribucion
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::toDistribute(){
	Node<T>* aux = this->tail->getPrevious();
	int numeroMayor,num;
	
			numeroMayor=int(aux->getData().getNombre()[0]);//Busca el numero mayor
			for(int i=1;i<this->sizeList();i++){
				aux = aux->getPrevious();
				if(numeroMayor<int(aux->getData().getNombre()[0]))
					numeroMayor=int(aux->getData().getNombre()[0]);
			}
			
			DoubleList<T> list[numeroMayor+1];//se agrega en listas
			aux = this->tail->getPrevious();
			for(int numeroLista=0;numeroLista<this->sizeList();numeroLista++){
				num=int(aux->getData().getNombre()[0]);
				list[num].addBack(aux->getData());
				aux = aux->getPrevious();
				}
			aux = this->tail->getPrevious();//se remplaza en la lista original
			for(int numeroLista=0;numeroLista<=numeroMayor;numeroLista++){
				if(!list[numeroLista].sizeList()==0){
				for(int i=0;i<list[numeroLista].sizeList();i++){
					aux->setData(list[numeroLista].get(i));
					aux=aux->getPrevious();
				}
			  }
			} 	
 }

/**@brief  Metodo radixShort
@param  void
@returns void
*/
template <class T>
void DoubleList<T>::radixShort(){
	
	DoubleList<T> list[10];
	Node<T>* aux = this->tail->getPrevious();
	int peso=1,indice=0,cont=0;
			while(aux!=this->head)//busca el numero con mas digitos
			{
				if(peso<(aux->getData().getNombre()[0])/10)
				{
					cont++;
					peso*=10;
				}
				aux = aux->getPrevious();
			}
			
			
		peso=1;
		for(int i=0;i<=cont+1;i++)
		{
			aux = this->tail->getPrevious();
			while(aux!=this->head)
			{
				indice=(int(aux->getData().getNombre()[0])/peso)%10;
 				list[indice].addFront(aux->getData());
				aux = aux->getPrevious();
			}
			aux = this->tail->getPrevious();
			for(int numeroLista=0;numeroLista<=9;numeroLista++)
			{
				if(!list[numeroLista].sizeList()==0)
				{
				for(int i=0;i<list[numeroLista].sizeList();i++)
					{
					aux->setData(list[numeroLista].get(i));
					aux=aux->getPrevious();
					}
			  	}
			  list[numeroLista].clear();
			}
		  peso*=10;
		}
	
 }

/**@brief  Metodo shellShort
@param  void
@returns void
*/
template <class T>
void DoubleList<T>::shellSort(){
	
	T auxData,auxData2;	
	Node<T>* aux=this->tail;
	Node<T>* aux2;
	int cont = 0;
	while (aux!=this->head)
	{
		aux = aux->getPrevious();
		cont++;
	}
	int incremento = cont / 2;
	while (incremento > 0) {
		aux= this->tail;
		for (int i = 0; i < incremento; i++) {
               aux = aux->getPrevious();
            }
        aux2= this->tail;
        while (aux!= this->head) {
        	if(int(aux->getData().getNombre()[0])<int(aux2->getData().getNombre()[0])){
        		auxData = aux->getData();
				auxData2 = aux2->getData();
				aux->setData(auxData2);
				aux2->setData(auxData);
			}
			aux = aux->getPrevious();
			aux2 = aux2->getPrevious();
		}
		incremento/=2;
	}
 }
/**@brief  Constructor
@param  void
@returns void
*/
template <class T>
DoubleList<T>::DoubleList(){
	this->head= new Node<T>;
	this->tail = new Node<T>;
	head->setNext(this->tail);
	tail->setPrevious(this->head);
	head->setPrevious(NULL);
	tail->setNext(NULL);
}
/**@brief  agregar al inicio
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::addFront(T d){
 	Node<T>* aux = new Node<T>();
 	aux->setData(d);
 	aux->setPrevious(this->head);
 	aux->setNext(this->head->getNext());
 	
 	this->head->getNext()->setPrevious(aux);
	this->head->setNext(aux);	
 }
 /**@brief  agregar en posicion
 @param  T d
@param  int position
@returns void
*/
 template <class T>
 void DoubleList<T>::addMiddle(T d, int position){
 	int index = inicialize1;
 	if(this->isEmpty() || position == 0){
 		this->addFront(d);
	 }else if(position >= this->sizeList()){
	 	cout<<"Posicion fuera del rango de la lista"<<endl;
	 }else{
		Node<T>* aux = this->head->getNext();
		while(aux!=this->tail)
 		{
 			if(index == position){
 				Node<T>* aux2 = new Node<T>(); 
				aux2->setData(d);
				aux2->setNext(aux->getNext());
				aux2->setPrevious(aux);	
				aux->getNext()->setPrevious(aux2);
				aux->setNext(aux2);
 				break;
		 	}
		 	index ++;
 			aux = aux->getNext();
		}	 	
	 }
 }
 /**@brief  agregar al final
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::addBack(T d){
 	Node<T>* aux = new Node<T>(); 
	aux->setData(d);
	aux->setPrevious(this->tail->getPrevious());
	aux->setNext(this->tail);
	
	this->tail->getPrevious()->setNext(aux);
	this->tail->setPrevious(aux);
 }
/**@brief  Imprimir desde la cola
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::printFromTail(){
 	
 	Node<T>* aux = this->tail->getPrevious();
 		cout<<" NULL ";
 	while(aux!=this->head)
 	{
 		cout<<"  " <<aux->getData();
 		aux = aux->getPrevious();
	 }
	cout<<" NULL "<<endl;
 }
 /**@brief  imprimir desde la cabeza
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::printFromHead(){
 	Node<T>* aux = this->tail;
 	aux = aux->getPrevious();
 	int orden=1;
 	if(this->sizeList()==0){
 		cout<<"Lista vacia"<<endl;
	 }else{
 	while(aux!=this->head)
 	{
 		cout<<"\n"<<orden++<<"\t\t"<<aux->getData().toString()<< "  "<<endl;
 		aux = aux->getPrevious();
	 }
	 }
	system("pause");
	orden=0;
	
 }
 /**@brief  contar en la lista
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::printFromHead1(){
 	Node<T>* aux = this->tail;
 	aux = aux->getPrevious();
 	int orden=1;
 	float totalCostos;
 	totalCostos=0;
 	while(aux!=this->head)
 	{
 		cout<<"\n"<<orden++<<"\t\t"<<aux->getData().getPrecio();
 		totalCostos+=aux->getData().getPrecio();
 		aux = aux->getPrevious();
	 }
	cout<<"\nEl total de costos de las herramientas es: "<<totalCostos;
	orden=0;
	
 }
 /**@brief  Vaciar la lista
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::clear(){
 	int dimencion=this->sizeList();
 	
 	for(int i=0;i<dimencion;i++){
 	Node<T>* aux = this->head->getNext()->getNext();
 	delete  this->head->getNext();
 	this->head->setNext(aux);
 	aux->setPrevious(this->head);
 	}
 }
/**@brief  eliminar dato de la cabeza
@param  void
@returns void
*/
template <class T>
 void DoubleList<T>::deleteFront(){
 	Node<T>* aux = this->head->getNext()->getNext();
 	delete  this->head->getNext();
 	this->head->setNext(aux);
 	aux->setPrevious(this->head);
 }
/**@brief  eliminar dato
@param  T d
@returns void
*/
template <class T>
 void DoubleList<T>::deleteData(T d){
  	if(!this->isEmpty()){
  		Node<T>* aux = this->head->getNext();
	 	while(aux!=this->tail)
 		{
			if(aux->getData() == d){
				aux->getNext()->setPrevious(aux->getPrevious());
				aux->getPrevious()->setNext(aux->getNext());
				delete aux;
 				break;	
			}
 			aux = aux->getNext();
	 	}
	}else{
		cout<<"Lista vacia"<<endl;
	}	
 }
 /**@brief  eliminar por posicion 
@param  int position
@returns void
*/
template <class T>
 void DoubleList<T>:: deletePosition(int position){
 	int index = inicialize;
 	if(this->isEmpty()){
 		cout<<"Lista Vacia"<<endl;
	 }else if(position > this->sizeList()){
	 	cout<<"Posicion fuera del rango de la lista"<<endl;
	 }else{
  		Node<T>* aux = this->head->getNext();
	 	while(aux!=this->tail)
 		{
			if(index == position){
				Node<T>* aux2 = new Node<T>(); 
				aux->getNext()->setPrevious(aux->getPrevious());
				aux->getPrevious()->setNext(aux->getNext());
				delete aux;
 				break;	
			}
		 	index ++;
 			aux = aux->getNext();
	 	}
	 }	
 }
 /**@brief  eliminar dato desde la cola
@param  void
@returns void
*/	
template <class T>
 void DoubleList<T>::deleteBack(){
 	Node<T>* aux = this->tail->getPrevious()->getPrevious();
 	delete this->tail->getPrevious();
 	this->tail->setPrevious(aux);
 	aux->setNext(this->tail);
 	
 } 
 /**@brief  verifica si la lista esta vacia 
@param  void
@returns void
*/
template<class T>
bool DoubleList<T>::isEmpty() {
	if( (head->getNext() == this->tail && tail->getPrevious() == this->head )){
		return  true;
	}else{
		return false;
	}
}
/**@brief  Numero de datos de la lista
@param  void
@returns int
*/
template <class T>
 int DoubleList<T>::sizeList(){
 	int contador = inicialize;
 	Node<T>* aux = this->head->getNext();
 	while(aux!=this->tail)
 	{
 		aux = aux->getNext();
 		contador++;
	 }
	return contador;
 }
 template <class T>
 T DoubleList<T>::get(int position){
  	int index = inicialize;
        T auxData;
 	if(this->sizeList()==0){
 		cout<<"Lista vacia"<<endl;
	 }else{
	  	if(position == 0){
	  		
            auxData = this->tail->getPrevious()->getData();
 			return auxData;
	 	}else if(position == this->sizeList()){
            auxData = this->tail->getData();
 			return auxData;
		 }else{
			Node<T>* aux = this->tail->getPrevious();
			while(aux!=this->head)
 			{
 				if(index == position){
                    auxData = aux->getData();
                    return auxData;
		 		}
			 	index ++;
 				aux = aux->getPrevious();
			}
		 }
	 }
 }
#endif
