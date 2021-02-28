#include "Utils.h"
#include "DatosArchivo.h"

using namespace std;
class Menu{
public:
	void menu();
	Utils utils;
};

void Menu::menu()
{
	char nombreArchivo[20];
	int opcion;
	cout<<"\nNombre del archivo: ";
	cin>>nombreArchivo;
	DatosArchivo datosArchivo(nombreArchivo);
	do{
		system("cls");
		opcion = utils.textoMenu();
		switch(opcion)
		{
			case 1:{
				/*Creamos el Archivo*/
				if(!datosArchivo.crearNuevo())
					cout<<"\nNo se puede abrir el archivo: "<<datosArchivo.obtenerNombre();
				break;
			}
			case 2:{
				
        			if(!datosArchivo.agregar())
						cout<<"\nNo se puede abrir el archivo: "<<datosArchivo.obtenerNombre();
				
				break;
			}
			case 3:{
				if(!datosArchivo.actualizar())
					cout<<"\nNo se puede abrir el archivo: "<<datosArchivo.obtenerNombre();
				break;
			}
			case 4:{
				if(!datosArchivo.leerArchivo())
					cout<<"\nNo se puede abrir el archivo: "<<datosArchivo.obtenerNombre();
				break;
			}
			case 5:{
				if(!datosArchivo.mezclaDirecta())
					cout<<"\nNo se puede abrir el archivo: "<<datosArchivo.obtenerNombre();

				break;
			}
			case 0:{
				cout<<"\nSalio con exito!";
				break;
			}
			default:{
				cout<<"No se encontro la opcion.";
				break;
			}
		}
		system("pause");
	}while(opcion!=0);
}
