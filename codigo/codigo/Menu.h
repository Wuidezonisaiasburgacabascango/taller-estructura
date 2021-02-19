#include <iostream>
#include <string>
#include <stdio.h>
#include "DoubleList.h"
#include "Inventario.h"
using namespace std;
void Menu(){
	int opcion,cantidad; 
	string nombre;
	float precio;
	Inventario inventario;
	DoubleList<Inventario> list;
	
	do{

	cout<<"1.Agregar herramienta (Al final)"<<endl;
	cout<<"2. Eliminar herramienta (Al inicio)"<<endl;
	cout<<"3. Imprimir inventario de herramientas"<<endl;
	cout<<"4. Imprimir el valor total en dinero que suman todas las herramientas en inventario"<<endl;
	cout<<"5. Acceder al  menu de  ordenamiento"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"Sleccione una opcion:"<<endl; 
	cin>>opcion; 


switch (opcion){

	case 1:{
		cout<<"Agregar herramienta (Al final) "<<endl;
		cin>>nombre;
		fflush(stdin);
		cout<<"Agregar cantidad"<<endl;
		cin>>cantidad;					
		cout<<"Agregar el precio "<<endl;
		cin>>precio;
		inventario.setNombre(nombre);inventario.setCantidad(cantidad);inventario.setPrecio(precio);
		list.addBack(inventario);
		break;
	}
	
	case 2:{
		
		break;
	}
	
	case 3:{
			cout<<list.sizeList();
			cout<<list.get(0).toString()<<endl;
			cout<<list.get(1).toString()<<endl;
			cout<<list.get(2).toString()<<endl;

		
		break;
	}
	
	case 4:{
		
		break;
	}
	
	case 5:{
		
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

