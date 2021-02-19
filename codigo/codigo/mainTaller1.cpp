#include "Inventario.h"
#include "DoubleList.h"
#include <string.h>
#include<cstring>
#include <iostream>
using namespace std;


int main(){
	Inventario inventario;
    char archivo[] = "CORREO";
	DoubleList<Inventario> list;
		inventario.setNombre("lefa");inventario.setCantidad(17);inventario.setPrecio(06);
		list.addFront(inventario);
            
            
        inventario.setNombre("pato");inventario.setCantidad(7);inventario.setPrecio(2);
		list.addFront(inventario);    
        
        inventario.setNombre("sierra");inventario.setCantidad(56);inventario.setPrecio(92);
		list.addFront(inventario);
		
		inventario.setNombre("g");inventario.setCantidad(56);inventario.setPrecio(92);
		list.addFront(inventario);
		
		inventario.setNombre("b");inventario.setCantidad(56);inventario.setPrecio(92);
		list.addFront(inventario);
		
		list.printFromHead();
		cout<<"\n-------------------"<<endl;
		list.binarySearch();
		cout<<"\n-------------------"<<endl;
		list.binarySearch();
	/*	list.registrarDatos();
        list.imprimirRegistro();
        int n= list.contarRegistros(archivo);
        cout<<n;
        list.imprimirRegistro();
   	//	list.mezclaDirecta(n);*/
   		cout<<"\n-------------------"<<endl;
		list.printFromHead();
}
