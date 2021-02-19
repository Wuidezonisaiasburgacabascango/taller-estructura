#include <iostream>
#include <windows.h>
using namespace std;
class ShellSort{
public:
 int vector[100],temp,inc,i,j;
 
 void shellSort(int[], int );
 void mostrar(int[], int );
};
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
void ShellSort::shellSort(int V[], int N){
	
 for(inc = 1 ; inc<N;inc=inc*3+1);
   while (inc > 0){
    for ( i=inc; i < N; i++){
    j = i;
    temp = V[i];
    while ((j >= inc) && (V[j-inc] > temp)){
     V[j] = V[j - inc];
     j = j - inc;
    }
    V[j] = temp;
    }
    inc/= 2;
   }
}

void ShellSort::mostrar(int V[],int N){
 for(int i=0;i<N;i++){
  cout<<V[i]<<" ";
 }
}
