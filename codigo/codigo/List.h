#if !defined(__List_h)
#define __List_h
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class List{
	public:
		List();
		~List(){}
		virtual bool isEmpty() = 0;
};
template <class T>
List<T>::List(){
	
}
template <class T>
bool List<T>::isEmpty(){
	
}
#endif
