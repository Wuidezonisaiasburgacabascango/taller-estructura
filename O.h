#include <fstream>
#include <string.h>
#include <iomanip>
#include <iostream>

using namespace std;

class Estudiante{
private:
	
	char nombreAlumno[31];
	char Apellido[31];
	int matricula;
	int numeroMateriasAprobadas;
	float promedio;
public:
	Estudiante();
	char *obtenerNombreAlumno(){return nombreAlumno;}
	char *obtenerApellido(){return Apellido;}
	int obtenerMatricula(){return matricula;}
	int obtenerMateriasA(){return numeroMateriasAprobadas;}
	float obtenerPromedio(){return promedio;}
	void almacenarEstudiante(char*,char*, int, int, float);
	friend ostream &operator<<(ostream &ostreamA, Estudiante &EstudianteA);
};


class DatosArchivo: private fstream{
private:
	Estudiante estudiante;
	char nombreArchivo[15];/*Nombre del archivo*/
	void escribir();/*Escribir alumnos en el archivo*/
public:
	DatosArchivo(char *nombreA = '\0');
	char *obtenerNombre(){return nombreArchivo;}
	int crearNuevo();/*Crear un archivo*/
	int agregar();/*Agregar alumnos al archivo*/
	int actualizar();/*Actualizar un alumno*/
	int leerArchivo();/*Leer Archivo*/
};


Estudiante::Estudiante()
{
	for(int i=0;i<31;i++)
	{
		nombreAlumno[i]='\0';		
	}
	for(int i=0;i<31;i++)
	{
		Apellido[i]='\0';		
	}
	matricula =0 ;
	numeroMateriasAprobadas = 0;
	promedio = 0.0F;
}

void Estudiante::almacenarEstudiante(char *_nombreAlumno,char *_Apellido, int _matricula, int _numeroMateriasAprobadas, float _promedio)
{
	strcpy(nombreAlumno,_nombreAlumno);
	strcpy(Apellido,_Apellido);
	matricula = _matricula;
	numeroMateriasAprobadas = _numeroMateriasAprobadas;
	promedio = _promedio;
}

//sobrecarga operador <<
ostream &operator<<(ostream &ostreamA, Estudiante &estudianteA){
	ostreamA<<setiosflags(ios::fixed); 
	ostreamA<<setiosflags(ios::left) 
			<<"\nAlumno: "				 		         
			<<estudianteA.obtenerNombreAlumno()
			<<" "				 	         
			<<estudianteA.obtenerApellido()
			<<"\nMatricula: "			 	         
			<<estudianteA.obtenerMatricula()
			<<"\nN de materias aprobadas: "				 	         
			<<estudianteA.obtenerMateriasA() 
			<<resetiosflags(ios::left)                 
			<<setprecision(2)
			<<"\nPromedio: "  			
			<<estudianteA.obtenerPromedio()<<endl;
	return ostreamA;
}

DatosArchivo::DatosArchivo(char *nombreA)
{
	if(!nombreA)
		strcpy(nombreArchivo,"dato00._xx");
	else
		strcpy(nombreArchivo,nombreA);
}

int DatosArchivo::crearNuevo()
{
	open(nombreArchivo,ios::out|ios::binary);
	if(fail() || bad())
		return 0;
	escribir();
	close();
	return 1;
}

int DatosArchivo::agregar()
{
	
	open(nombreArchivo,ios::app|ios::out|ios::binary);
	if(fail() || bad())
		return 0;
	escribir();
	close();
	return 1;
}

void DatosArchivo::escribir()
{
	int tamanioArchivo = sizeof(estudiante);
	char _nombre[30];
	char _Apellido[30];
	int _matricula;
	int _numeroMateriasAprobadas;
	float _promedio;
	
	seekp(0L,ios::end);
	cout<<"\nIngresar datos. Para finalizar digite * en la referencia\n";
	cout<<"Registrar Alumno: "<<endl;
	for(;;)
	{	
       
		cout<<"\nNombre: ";
		cin>>_nombre;
		if(!strcmp(_nombre,"*"))
			break;
		cout<<"Apellido: ";
		cin>>_Apellido;
		cout<<"Matricula: ";
		fflush(stdin);
		cin>>_matricula;
		cout<<"No. Materias Aprobadas: ";
		fflush(stdin);
		cin>>_numeroMateriasAprobadas;
		cout<<"Promedio: ";
		fflush(stdin);
		cin>>_promedio;
		estudiante.almacenarEstudiante(_nombre,_Apellido,_matricula,_numeroMateriasAprobadas,_promedio);
		write((const char*)&estudiante,tamanioArchivo);
	}
	
}

int DatosArchivo::leerArchivo()
{
	open(nombreArchivo,ios::in|ios::binary);
	if(fail()||bad())
		return 0;
		
	int tamanioArchivo = sizeof(estudiante);
	while(read((char *)&estudiante,tamanioArchivo))
		cout<<estudiante;
	close();
	return 1;
		

}

int DatosArchivo::actualizar()
{
	open(nombreArchivo,ios::in | ios::out | ios::binary);
	if(fail() || bad())
		return 0;
		
	seekp(0L, ios::end);
	int tamanioArchivo = sizeof(estudiante);
	int totalEstudiantes = (int)(tellp()/tamanioArchivo);
	int numeroAlumno;
	long desplazamiento;
	
	do{
		cout<<"Numero de Alumnos entre 1 y "<<totalEstudiantes<<"\n (0. Salir): ";
		cin>>numeroAlumno;
		if(!cin.fail() && (numeroAlumno >= 1) && (numeroAlumno <= totalEstudiantes))
		{
			desplazamiento = (long)(numeroAlumno - 1)*tamanioArchivo;
			seekp(desplazamiento,ios::beg);
			read((char *)&estudiante,tamanioArchivo);
			cout<<estudiante;
			
			int opcion;
			char nom[30];
			char ape[30];
			int _matricula;
			int _numeroMateriasAprobadas;
			float _promedio;
			
			do
			{
				cout<< "\n________________________________________________________\n";
    			cout<< "                   Modificar datos                        \n";
    			cout<< "__________________________________________________________\n";
				cout<< "\t1. Nombre\n";
				cout<< "\t2. Apellido\n";
				cout<< "\t3. Matricula\n";
				cout<< "\t4. No. Materias Aprobadas\n";
				cout<< "\t5. Promedio\n";
				cout<< "\t6. Guardar Datos\n";
				cout<< "__________________________________________________________" <<endl;
				cout<<"\t\n Digite su opcion: ";
				while(!(cin>>opcion) || opcion < 1 || opcion > 6)
				{
					if(cin.fail()){
						cin.clear();
						cin.ignore();
					}
					cout<<"\t\nDigite su opcion: ";
				}
				switch(opcion)
				{
					case 1:{
						cout<<"Nombre: ";
						cin>>nom;
						estudiante.almacenarEstudiante(nom,estudiante.obtenerApellido(),estudiante.obtenerMatricula(),estudiante.obtenerMateriasA(),estudiante.obtenerPromedio());
						break;
					}
					case 2:{
						cout<<"Apellido: ";
						cin>>ape;
						estudiante.almacenarEstudiante(estudiante.obtenerNombreAlumno(),ape,estudiante.obtenerMatricula(),estudiante.obtenerMateriasA(),estudiante.obtenerPromedio());
						break;
						break;
					}
					case 3:{
						cout<<"Matricula: ";
						cin>>_matricula;
						estudiante.almacenarEstudiante(estudiante.obtenerNombreAlumno(),estudiante.obtenerApellido(),_matricula,estudiante.obtenerMateriasA(),estudiante.obtenerPromedio());
						break;
					}
					case 4:{
						cout<<"No. Materias Aprobadas: ";
						cin>>_numeroMateriasAprobadas;
						estudiante.almacenarEstudiante(estudiante.obtenerNombreAlumno(),estudiante.obtenerApellido(),estudiante.obtenerMatricula(),_numeroMateriasAprobadas,estudiante.obtenerPromedio());
						break;
					}
					case 5:{
						cout<<"Promedio: ";
						cin>>_promedio;
						estudiante.almacenarEstudiante(estudiante.obtenerNombreAlumno(),estudiante.obtenerApellido(), estudiante.obtenerMatricula(),estudiante.obtenerMateriasA(),_promedio);
						break;
					}
					case 6:{
						/*Guardar los cambios*/
						break;
					}	
				}
			}while(opcion!=6);
				
			seekp(-tamanioArchivo,ios::cur);
			write((const char *)&estudiante,tamanioArchivo);
		}
			else
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					numeroAlumno = -1;
				}
		
	}while(numeroAlumno);
	close();
	return 1;
}
