#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int);

int main(){
	
	int num = 5;
	int *p_num = &num;
	
	cout << "Direccion de memoria de num: " << &num << endl;
	cout << "Direccion de memoria de *p_num: " << p_num << endl;
	cout << "Contenido de p_num: " << *p_num << endl; 
	
	Nodo *pila = NULL;
	int dato;
	
	cout << "Ingrese un numero: ";
	cin >> dato;
	cout << dato << endl;
	agregarPila(pila,dato);
	cout << "Ingrese un numero: ";
	cin >> dato;
	cout << dato << endl;
	agregarPila(pila,dato);
	
	while(pila != NULL){
		sacarPila(pila,dato);
		if(pila != NULL){
			cout << dato << " , ";
		}else{
			cout << dato << ".";
		}
	}
	
	
	
	return 0;
}

void agregarPila(Nodo *&pila, int dato){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	return;
}

void sacarPila(Nodo *&pila, int dato){
	Nodo *nodo_aux = pila;
	dato = nodo_aux->dato;
	pila = nodo_aux->siguiente;
	delete nodo_aux;
	return;
}

