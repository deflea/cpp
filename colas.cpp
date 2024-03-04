#include <iostream>
using namespace std;

//Estructuras
struct Nodo{
	int dato;
	Nodo *next;
};

//Prototipos de funcion
void insertarCola(Nodo *&, Nodo *&, int);
bool esVacia(Nodo *);
void eliminarCola(Nodo *&, Nodo *&, int &);
int main(){
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;
	
	cout << "Digite un numero: ";
	cin >> dato;
	insertarCola(frente,fin,dato);
	
	cout << "Digite un numero: ";
	cin >> dato;
	insertarCola(frente,fin,dato);
	
	cout << "Digite un numero: ";
	cin >> dato;
	insertarCola(frente,fin,dato);
	cout << "Eliminando los elementos de la cola: " << endl;
	while(frente!=NULL){
		eliminarCola(frente,fin,dato);
		if(frente != NULL){
			cout << dato << ", ";
		}else{
			cout << dato << " . ";
		}
	}
	
	return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int dato){
	
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = dato;
	nuevo_nodo->next = NULL;
	
	if(esVacia(frente)){
		frente = nuevo_nodo;
	}else{
		fin->next = nuevo_nodo;
	}
	fin = nuevo_nodo;

	cout << "Elemento " << dato << " ingresado correctamente" << endl;
}

void eliminarCola(Nodo *&frente, Nodo *&fin, int &dato){

	dato = frente->dato;
	Nodo *aux_nodo = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->next;
	}
	delete aux_nodo;
}

bool esVacia(Nodo *frente){
	return (frente==NULL) ? true : false;
}
