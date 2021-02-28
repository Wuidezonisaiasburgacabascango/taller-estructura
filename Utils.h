#include <iostream>
using namespace std;
class Utils{
public:
	int textoMenu();
	void limpiarPantalla(int);
};

int Utils::textoMenu()
{
	int opcion;
	
	cout<< "________________________________________________________\n";
    cout<< "                   MENU DE OPCIONES                     \n";
    cout<< "________________________________________________________\n";
	cout<< "                 Registro de Alumnos                    "
		<< "\n   1. Nuevo Archivo"
		<< "\n   2. Registrar Estudiante"
		<< "\n   3. Actualizar Estudiante"
		<< "\n   4. Mostrar Estudiantes"
		<< "\n   5. Ordenamiento externo"
		<< "\n   0. Salir\n"
		<< "________________________________________________________" <<endl
		<< "\nDigite su opcion: ";
	cin>>opcion;
	return opcion;
}

