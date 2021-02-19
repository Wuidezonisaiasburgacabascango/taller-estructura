#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <sstream>
#include <iostream>
#include <string>
#include<cstring>
using namespace std; 

class Inventario
{
public:
    Inventario(string nombre, int  cantidad, float  precio)
    {
        this->nombre = nombre;
        this->cantidad = cantidad;
        this->precio = precio;
    }

    Inventario() {}
  
    ~Inventario() {}
   
    ///Getter and setter of nombre
    std::string getNombre(void)
    {
        return nombre;
    }
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    ///Getter and setter of last cantidad
    int getCantidad(void)
    {
        return cantidad;
    }
    void setCantidad(int cantidad)
    {
        this->cantidad = cantidad;
    }
    ///Getter and setter of precio
    float getPrecio(void)
    {
        return  precio;
    }
    void setPrecio(float  precio)
    {
        this->precio = precio;
    }
    string observacion(int cantidad)
    {
        if(cantidad<10)
        	return "Stock bajo";
        else
        	return "-";  
    }
    string espacios(string cadena)
    {
    	char espacios[23]=" ";
    	for(int i=0;i<(23-cadena.length());i++){
        	strcat(espacios," ");
      }
      espacios[0]=' ';
      return espacios;
    }
    
   
    string toString()
    {
    	std::stringstream sstream1;
    	std::stringstream sstream2;
    	sstream1 << this->cantidad;
    	sstream2 << this->precio;
    	string str1 = sstream1.str();
    	string str2 = sstream2.str();
    	
        return this->getNombre() +this->espacios(this->getNombre())+str1+
		this->espacios(str1)+"$"+str2+this->espacios(str2)
		+ this->observacion(this->cantidad);
    }

private:
    string nombre;
    int  cantidad;
    float  precio;

};
#endif // PERSON_H
