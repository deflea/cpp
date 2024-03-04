#include <iostream>
using namespace std;

//Estructuras
struct Nodo{
	int dato;
	Nodo *siguiente;
};
//Prototipos de funciones
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int );

int main(){
	
	Nodo *lista=NULL;
	int dato;
	
	cout << "Digite un numero: ";
	cin >> dato;
	insertarLista(lista,dato);

	cout << "Digite un numero: ";
	cin >> dato;
	insertarLista(lista,dato);
	
	cout << "Digite un numero: ";
	cin >> dato;
	insertarLista(lista,dato);	
	
	
	buscarLista(lista,10);
	mostrarLista(lista);
	return 0;
}

void insertarLista(Nodo *&lista,int dato ){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = dato;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < dato)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(lista == aux1){
		lista = nuevo_nodo;
	}else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
	
	cout << "Numero " << dato << " insertado correctamente" << endl;
	return;
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<actual->dato<<" -> ";
		actual= actual->siguiente;
	}
}

void buscarLista(Nodo *lista, int dato){
	bool bandera = false;
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual !=NULL ) && (actual->dato <= dato)){
		if(actual->dato == dato){
			bandera = true;
		}
		actual = actual->siguiente;
	}
	if(bandera == true){
		cout << "Elemento " << dato << " ha sido encontrado" << endl;
	}else{
		cout << "Elemento " << dato << " no ha sido encontrado" << endl;
	}
}
