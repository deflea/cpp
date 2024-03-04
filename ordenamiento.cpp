#include <iostream>
using namespace std;

int main(){
	int numeros[] = {4,1,3,2,5};
	int numeros1[] = {2,5,4,3,1};
	//Burbuja
	for(int i = 0;i<5;i++){
		for(int j = 0;j<5;j++){
			if(numeros[j]>numeros[i]){
				swap(numeros[j],numeros[i]);
			}
		}
	}
	
	for(int i=0;i<5;i++){
		cout << numeros[i];
	}
	cout << endl;
	//Insercion
	int pos;
	int aux;
	for(int i=0;i<5;i++){
		pos = i;
		aux = numeros1[i];
		while((pos>0) && (numeros1[pos-1]> aux)){
			numeros1[pos]= numeros1[pos-1];
			pos--;
		}
		numeros1[pos] = aux;
	}
	
	for(int i=0;i<5;i++){
		cout << numeros1[i];
	}
	cout << endl;
	//Seleccion
	int min;
	for(int i = 0; i<5;i++){
		min = i;
		for(int j = i+1; j<5; j++){
			if(numeros1[j]<numeros1[min]){
				min = j;
			}
		swap(numeros1[i],numeros1[min]);
		}
	}
	for(int i=0;i<5;i++){
		cout << numeros1[i];
	}
	cout << endl;
	//Busqueda binaria
	int dato = 5;
	bool band = false;
	int inf = 0;
	int sup = 4;
	int mitad;
	
	while(inf <= sup){
		mitad = inf + (sup-inf)/2;
		if(numeros[mitad]== dato){
			band = true;
			break;
		}
		if(numeros[mitad]<dato){
			inf = mitad + 1;
		}
		if(numeros[mitad]> dato){
			sup = mitad - 1;
		}
	}
	if(band){
		cout << "Numero encontrado" << endl;
	}else{
		cout << "Numero no encontrado" << endl;
	}
	
	
	return 0;
}
