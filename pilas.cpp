#include <iostream>
using namespace std;

//Estructuras
struct Dato{
	int numero;
	char letra;
};
struct Nodo{
	Dato dato;
	Nodo *next;
};

//Prototipos de funciones
void agregarPila(Nodo *&, Dato);
void sacarPila(Nodo *&, Dato &);

int main(){
	
	char opt;
	Dato dato;
	Nodo *pila = NULL;
	
	do{
		cout << "Ingrese un numero: ";
		cin >> dato.numero;
		cout << "Ingrese una letra: ";
		cin >> dato.letra;
		agregarPila(pila,dato);
		
		cout << "Desea continuar? (s/n): ";
		cin >> opt;
	}while((opt == 'S') || (opt == 's'));
	
	cout << "Sacando elementos de la pila: ";
	while(pila !=NULL){
		sacarPila(pila,dato);
		if(pila != NULL){
			cout << "dato.numero: " << dato.numero << " dato.letra: " << dato.letra << " , ";
		}else{
			cout << "dato.numero: " << dato.numero << "dato.letra: " << dato.letra << "." ;
		}
	}
	
	return 0;
}

void agregarPila(Nodo *&pila, Dato dato){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->next = pila;
	pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila, Dato &dato){
	Nodo *aux_nodo = pila;
	dato = aux_nodo->dato;
	pila = aux_nodo->next;	
	delete aux_nodo;
}


