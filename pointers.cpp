#include <iostream>
using namespace std;

//Estructuras
struct info{
	int valor;
	char caracter;
};
struct Nodo{
	char data;
	Nodo* next;
};


//Proptotipos de funciones
void agregarPila(Nodo *&,char);
void sacarPila(Nodo *&,char &);

int main(){
	/*	
	char letra = 'A';
	char *ptr_letra = &letra;
	int a = 16;
	int *ptr_a = &a;
	
	Nodo nodo;
	nodo.data.caracter = 'B';
	nodo.data.valor = 6;
	
	Nodo *ptr_nodo = &nodo;
	
	cout << "Valor de a: " << a << endl;
	cout << "Direccion de memoria de a: " << &a << endl;
	cout << "Valor de *ptr_a: " << ptr_a << endl;
	cout << "Valor donde apunta la direccion de memoria de *ptr_a: " << *ptr_a << endl;
	cout << "Direccion de memoria de *ptr_a: " << &ptr_a << endl;
	//++*ptr_a;
	*ptr_a = a*2;
	cout << "Nuevo valor de a: " << a << endl;

	cout << "sizeof(a) " << sizeof(a) << endl; 
	cout << "sizeof(&a) " << sizeof(&a) << endl;
	cout << "sizeof(ptr_a) " << sizeof(ptr_a) << endl;
	cout << "sizeof(*ptr_a) " << sizeof(*ptr_a) << endl;
	cout << "sizeof(*ptr_a) " << sizeof(*ptr_nodo) << endl;
	cout << "sizeof(*ptr_letra) " << sizeof(*ptr_letra) << endl;
	cout << "sizeof(letra) " << sizeof(letra) << endl;
	
	cout << "sizeof(nodo) " << sizeof(nodo) << endl;
	cout << "sizeof(*ptr_nodo) " << sizeof(*ptr_nodo) << endl;
	*/
	char dato;
	Nodo *pila = NULL;
	cout << "Ingrese un numero: " << endl;
	cin >> dato;
	agregarPila(pila,dato);
	cout << "Ingrese un numero: " << endl;
	cin >> dato;
	agregarPila(pila,dato);
	cout << "Ingrese un numero: " << endl;
	cin >> dato;
	agregarPila(pila,dato);
	cout << "Ingrese un numero: " << endl;
	cin >> dato;
	agregarPila(pila,dato);
	
	cout << "Sacando elementos de la pila: ";
	while(pila !=NULL){
		sacarPila(pila,dato);
		if(pila != NULL){
			cout << dato << " , ";
		}else{
			cout << dato << "." ;
		}
	}
	
	return 0;
}

void agregarPila(Nodo *&pila, char dato){
	
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->data = dato;
	nuevo_nodo->next = pila;
	pila = nuevo_nodo;
	
	cout << "Elemento " << dato << " agregado correctamente" << endl;
	
}
void sacarPila(Nodo *&pila, char &dato){
	Nodo *aux_nodo = pila;
	dato = aux_nodo->data;
	pila = aux_nodo->next;
	delete aux_nodo;
	
}
