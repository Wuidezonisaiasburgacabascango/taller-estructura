#include "List.h"
#include "Inventario.h"
#include "DoubleList.h"
#include <string.h>
#include<cstring>
#include <iostream>
using namespace std;


int menuBusqueda(){
	int opcion;
	system("cls");
	cout<<"\nBienvenido a los algoritmos de busqueda"<<endl;
	cout<<"\n1. Secuencial "<<endl;
	cout<<"2. Binaria"<<endl;
	cout<<"3. Hash"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Seleccione una opcion:"<<endl; 
	cin>>opcion; 
	
	return opcion;
}

int menuOrdenamientoExterno(){
	int opcion;
	system("cls");
	cout<<"\nBienvenido a los algoritmos de ordenamiento externo"<<endl;
	cout<<"\n1. Mescla directa"<<endl;
	cout<<"2. Mescla natural"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Seleccione una opcion:"<<endl; 
	cin>>opcion; 
	return opcion;
}

int menuOrdenamientoInterno(){
	int opcion;
	system("cls");
	cout<<"\nBienvenido a los algoritmos de ordenamiento interna"<<endl;
	cout<<"\n1. Intercambio"<<endl;
	cout<<"2. Burbuja"<<endl;
	cout<<"3. Quitsort"<<endl;
	cout<<"4. ShellSort"<<endl;
	cout<<"5. Distribuicion"<<endl;
	cout<<"6. Radix"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Seleccione una opcion:"<<endl; 
	cin>>opcion; 
	return opcion;
}

int menuOrdenamientoBusqueda(){
	int opcion;
	system("cls");
	cout<<"\nBienvenido al metodo de ordenamiento y busqueda"<<endl;
	cout<<"\n1. Algoritmos de ordenacion interna"<<endl;
	cout<<"2. Algoritmo de ordenacion externa"<<endl;
	cout<<"3. Algotimo de busqueda"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Seleccione una opcion:"<<endl; 
	cin>>opcion; 	
	return opcion;
}

int main(){
	int opcion,cantidad; 
	string nombre;
	
	float precio;
	Inventario inventario;
	DoubleList<Inventario> list;
	do{
	system("cls");
	cout<<"\n1.Agregar herramienta (Al final)"<<endl;
	cout<<"2. Eliminar herramienta (Al inicio)"<<endl;
	cout<<"3. Imprimir inventario de herramientas"<<endl;
	cout<<"4. Imprimir el valor total en dinero que suman todas las herramientas en inventario"<<endl;
	cout<<"5. Acceder al  menu de  ordenamiento"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Sleccione una opcion:"<<endl; 
	cin>>opcion; 


switch (opcion){

	case 1:{
		system("cls");
		cout<<"\nInserte el nombre de la herramienta : ";
		cin>>nombre;
		fflush(stdin);
		cout<<"\nInserte la cantidad : ";
		cin>>cantidad;					
		cout<<"\nInserte el precio : ";
		cin>>precio;
		inventario.setNombre(nombre);
		inventario.setCantidad(cantidad);
		inventario.setPrecio(precio);
		list.addFront(inventario);
		break;
	}
	
	case 2:{
		system("cls");
		list.deleteBack();
		cout<<"Ord.\t\tDescripcion\t\tCantidad\t\tCosto\t\t\tObservacion";
		list.printFromHead();
		break;
	}
	case 3:{
		system("cls");
		cout<<"Ord.\t\tDescripcion\t\tCantidad\t\tCosto\t\t\tObservacion";
		list.printFromHead();
		
		break;
	}
	case 4:{
		system("cls");
		list.printFromHead1();
		break;
	}
	
	case 5:{
		int opcion1,opcion2;
		do{
		opcion1=menuOrdenamientoBusqueda();
		switch (opcion1){
			case 1:{
				do{
				opcion2=menuOrdenamientoInterno();
				switch (opcion2){
					case 1:{	
						cout<<"\nInter";	
						system("PAUSE");
						break;
					}
					case 2:{
						cout<<"\nBur";	
						system("pause");
						
						break;
					}
					case 3:{
						cout<<"\nQuit";	
						system("pause");
						break;
					}
					case 4:{
						system("cls");
						cout<<"\nBienvenido al metodo de ordenamiento shellSort ";
						cout<<"\n(Se a ordenado por descripcion)";	
						list.shellSort();
						list.printFromHead();
						break;
					}
					case 5:{
						system("cls");
						cout<<"\nBienvenido al metodo de ordenamiento por distribucion ";
						cout<<"\n(Se a ordenado por descripcion)";
						list.toDistribute();
						list.printFromHead();
						break;
					}
					case 6:{
						system("cls");
						cout<<"\nBienvenido al metodo de ordenamiento radixShort ";
						cout<<"\n(Se a ordenado por descripcion)";
						list.radixShort();
						list.printFromHead();
						break;
					}
				
			}
			}while(0!=opcion2);
			break;
		}
			
			case 2:{
				do{
				opcion2=menuOrdenamientoExterno();
				switch (opcion2){
					case 1:{
						cout<<"\ndirecta";	
						system("pause");		
						break;
					}
					case 2:{
						cout<<"\nnatural";	
						system("pause");
						break;
					}		
				}
			}while(0!=opcion2);
			break;
		}
			case 3:{
				do{
				opcion2=menuBusqueda();
				switch (opcion2){
					case 1:{
						system("cls");
						cout<<"\nBienvenido al metodo de busqueda secuencial "<<endl;
						list.sequentialSearch();	
						break;
					}
					case 2:{
						system("cls");
						cout<<"\nBienvenido al metodo de busqueda secuencial "<<endl;
						
						system("pause");
						break;
					}
					case 3:{
						cout<<"\nHash";	
						system("pause");
						break;
					}		
				}
			}while(0!=opcion2);
			break;
		}
			
	}
		}while(0!=opcion1);
		break;
	}
	case 0:{
		cout<<"Gracias :)";
		break;
	}
	default:{
		cout<<"\nSeleccione una opcion valida";
	break;
	}
	
}
}while(opcion!=0);

}
