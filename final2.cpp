#include <iostream>
#include <string>
#include <string.h>
using namespace std;

template <typename T>
struct Nodo{
	T info;
	Nodo<T>* sig;
};

template <typename T>
struct infoCurso {
	int id;
	int promocionados;
	int regularizados;
	int recursantes;
	Nodo<T>* estudiantes;
};

template <typename T>
struct infoEst {
	int id;
	Nodo<T>* notas[4];
};

struct novedad {
	int idCurso;
	int idEstudiante;
	int nroEvaluacion;
	int nota;
};

struct venta {
	int nroCliente;
	char articulo[50];
	int cant;
	float precioUnitario;
};

struct infoArticulo {
	char articulo[50];
	int cant;
	float precioUnitario;
};

struct NodoArticulo {
	infoArticulo info;
	NodoArticulo* sig;
};

struct infoCliente {
	int nroCliente;
	float dineroGastado;
	NodoArticulo* articulos;
};

struct NodoCliente {
	infoCliente info;
	NodoCliente* sig;
};

struct infoSoc {
	int nroSoc;
	int estadiaTotal;
	int visitasTotales;	
};

struct NodoSocio {
	infoSoc info;
	NodoSocio* sig;	
};

struct infoSuc {
	int nroSuc;
	int cantDeVisitasDistintas;
	int cantTotalDeVisitas;
	NodoSocio* socios;
};

struct NodoSucursal {
	infoSuc info;
	NodoSucursal* sig;
};


template <typename T>
struct NodoD{
	NodoD<T>* arriba;
	T info;
	NodoD<T>* abajo;
};

struct Piso {
	int nroPiso;
	int personasQueBajan;
	int personasQueSuben;
};

struct PisoEliminado {
	int nroPiso;
	int difSubenYBajan; 		
};

struct ingreso {
	int nroSocio;
	int nroSucursal;
	int estadia;
};

struct infoItem {
	char descProducto[50];
	int cantVendida;
	float precioUnitario;
};

struct NodoItem {
	infoItem info;
	NodoItem* sig;
};

struct infoTicket {
	int idTicket;
	float montoTotal;
	NodoItem* items;
};

struct NodoTicket {
	infoTicket info;
	NodoTicket* sig;
};

struct ventaAnual {
	int idMes;
	int idTicket;
	char descProducto[50];
	int cantVendida;
	float precioUnitario;
};

struct Arbol {
	Arbol* izq;
	int info;
	Arbol* der;
};

struct huella {
	int dni;
	char apeNom[50];
	int dedo;
	int tipo;
	int subtipo;
};

struct eleccion {
	char localidad[20];
	int lista;
	int votos;
};

template <typename T> void push(Nodo<T>* &pila, T v);
template <typename T> T pop(Nodo<T>*& pila);
template <typename T> void encolar(Nodo<T>* & colafte, Nodo<T>* & colafin, T v);
template <typename T> T desencolar(Nodo<T>* & colafte, Nodo<T>* & colafin);

bool estaBalanceado(char vec[], int len);
int polacaInversa(char vec[],int len);
void pushArray(int vec[], int &len, int valor);
int popArray(int vec[], int &len);

template <typename T> void pushCola(Nodo<T>* & colafte, Nodo<T>* & colafin, T v);
template <typename T> T popCola(Nodo<T>* & colafte, Nodo<T>* & colafin);

template <typename T> T eliminarPrimerNodo(Nodo<T>*& p);
template <typename T> void agregarNodo(Nodo<T>* &p, T x);
template <typename T> Nodo<T>* insertarOrdenado(Nodo<T> *&p, T v);
template <typename T> Nodo<T>* buscar(Nodo<T> *p, T v);
template <typename T> Nodo<T>* buscaEInsertaOrdenado(Nodo<T>* &p, T v, bool & enc);

NodoCliente* buscaEInsertaOrdenado(NodoCliente* &p, infoCliente v, bool & enc);
NodoArticulo* buscaEInsertaOrdenado(NodoArticulo* &p, infoArticulo v, bool & enc);

NodoCliente* insertarOrdenado(NodoCliente *&p, infoCliente v);
NodoArticulo* insertarOrdenado(NodoArticulo *&p, infoArticulo v);

NodoCliente* buscar(NodoCliente *p, infoCliente v);
NodoArticulo* buscar(NodoArticulo *p, infoArticulo v);


NodoSucursal* buscaEInsertaOrdenado(NodoSucursal* &p, infoSuc v, bool & enc);
NodoSucursal* insertarOrdenado(NodoSucursal *&p, infoSuc v);
NodoSucursal* buscar(NodoSucursal *p, infoSuc v);

NodoSocio* buscaEInsertaOrdenado(NodoSocio* &p, infoSoc v, bool & enc);
NodoSocio* insertarOrdenado(NodoSocio *&p, infoSoc v);
NodoSocio* buscar(NodoSocio *p, infoSoc v);

NodoTicket* buscaEInsertaOrdenado(NodoTicket* &p, infoTicket v, bool & enc);
NodoTicket* insertarOrdenado(NodoTicket *&p, infoTicket v);
NodoTicket* buscar(NodoTicket *p, infoTicket v);
NodoItem* insertarOrdenado(NodoItem *&p, infoItem v);


template <typename T> void encolarLista(Nodo<T>* &lista, T v);
template <typename T> T desencolarLista(Nodo<T>*& lista);
void encolarArray(int vec[], int &len, int v);
int desencolarArray(int vec[], int &len);
template <typename T> void encolarPila(Nodo<T>* &pila, T v);
template <typename T> T desencolarPila(Nodo<T>*& pila);

template <typename T> 
int insertarPisoArribaDelActualYMedir(NodoD<T>* unNuevoPiso, NodoD<T>* unPisoActual, 
									  unsigned &distanciaMasBajo, unsigned &distanciaMasAlto);

template <typename T>
void medirDistanciaAPisosExtremos(NodoD<T>* unNuevoPiso, unsigned &distanciaMasBajo, unsigned 
&distanciaMasAlto);

template <typename T>
void agregarNodoListaDoble(NodoD<T>* &lista, T info);

template <typename T>
int EliminarLosPisosPrimosArribaDe(NodoD<T>* unPisoActual, FILE* archivo);

bool esPrimo(int numero);

template <typename T>
void eliminarPiso(NodoD<T>* &piso);

template <typename T, typename X, typename Z>
void procesarNovedades(FILE* arch, Nodo<T>* &cursos);

template <typename T, typename X, typename Z>
void agregarNota(Nodo<T>* &cursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota);

template <typename T>
int getEstado(Nodo<T>* notas[]);

template <typename T, typename X, typename Z>
void calcularEstadisticas(Nodo<T>* &cursos);

void insertarNodoEnArbol(Arbol* &raiz, int valor);
void preOrden(Arbol* raiz);
void inOrden(Arbol* raiz);
void postOrden(Arbol* raiz);

struct Dedo {
	int info;
	Dedo * sig;
};

struct infoSospe {
	int dni;
	char apeNom[50];
	Dedo* dedos;
};

struct Sospechoso {
	infoSospe info;
	Sospechoso* sig;
};

Sospechoso* buscaEInsertaOrdenado(Sospechoso* &p, infoSospe v, bool & enc);
Sospechoso* insertarOrdenado(Sospechoso *&p, infoSospe v);
Sospechoso* buscar(Sospechoso *p, infoSospe v);
Dedo* insertarOrdenado(Dedo *&p, int v);

void cargarMatrizSospechosos(Sospechoso* matriz[4][9] , FILE* arch);

void emitirSospechosos(Sospechoso* matriz[4][9], int tipo, char subtipo);

struct candidato {
	string nombreCandidato;
	int lista;
};

struct resultado {
	candidato cand;
	float pos;
};

struct localidad{
	char loc[20];
};

struct porcEleccion{
	int lista;
	float porc;
};

int votosLista1 = 50;
int votosLista2 = 35;
int votosLista3 = 15;

void GenerarListaConsejerosDocentes(candidato vecCandidatos[], int lenCandidatos, 
resultado vecResultado[], int lenResultado);
void ordenarVector(resultado vec[], int len);

void calcularListaGanadora(int mat[4][5], localidad vecLoc[], int lenLoc, FILE* arch);
void ordenarVector(porcEleccion vec[], int len);

struct NodoFinal {
	int info;
	NodoFinal* sig;
};

void push(NodoFinal* &pila, int v);
int pop(NodoFinal*& pila);
void encolar(NodoFinal* & colafte, NodoFinal* & colafin, int v);
int desencolar(NodoFinal* & colafte, NodoFinal* & colafin);
NodoFinal* unionPilaYCola(NodoFinal* &pila,NodoFinal* &colafte, NodoFinal* & colafin);

NodoFinal* buscaEInsertaOrdenado(NodoFinal* &p, int v, bool & enc);
NodoFinal* insertarOrdenado(NodoFinal *&p, int v);
NodoFinal* buscar(NodoFinal *p, int v);
int buscar(int vec[], int len, int v);
void interseccionListaYVector(NodoFinal* lista, int vec[], int len, NodoFinal* &listaInter);
void agregarNodo(NodoFinal* &p, int x);

struct ventaAnualMulti {
	int idEmpleado;
	float ventas;
	char sector;
};

struct NodoVentasAnuales {
	ventaAnualMulti info;
	NodoVentasAnuales* sig;
};

NodoVentasAnuales* insertarOrdenado(NodoVentasAnuales *&p, ventaAnualMulti v);

int main(int argc, char** argv) {
    /*//Ej 1a de Final
	 NodoFinal* pila = NULL;
     NodoFinal* colafte = NULL;
     NodoFinal* colafin = NULL;
     
     //cargar la pila
     push(pila,1);
     push(pila,5);
     push(pila,10);
     push(pila,15);
     
     //cargar la cola
     encolar(colafte,colafin,2);
     encolar(colafte,colafin,20);
     encolar(colafte,colafin,16);
     encolar(colafte,colafin,6);
     encolar(colafte,colafin,12);
     encolar(colafte,colafin,5);
     
     NodoFinal* lista = unionPilaYCola(pila,colafte,colafin);
     
     NodoFinal* aux = lista;
     
     while(aux != NULL){
     	cout << aux->info << endl;
     	aux = aux->sig;
    }	
	*/
	
	//Ejercicio 1b de Final
	/*NodoFinal* lista = NULL;
	agregarNodo(lista,20);
	agregarNodo(lista,5);
	agregarNodo(lista,10);
	agregarNodo(lista,30);
	agregarNodo(lista,15);
	
	int vec[50] = {5,30,10,16,7,9,45};
	int len = 7;
	
	NodoFinal* listaInterseccion = NULL;
	
	interseccionListaYVector(lista,vec,len,listaInterseccion);
	
	NodoFinal* aux = listaInterseccion;
	
	while(aux != NULL ){
		cout << aux->info << endl;
		aux = aux->sig;
	}
	*/
	//ej 2 final
	//llenar archivo
	/*FILE* arch = fopen("ventas20210225.dat","wb+");
	
	ventaAnualMulti reg;
	
	reg.idEmpleado = 83943;
	reg.ventas = 7835.89;
	reg.sector = 'C';
	
	fwrite(&reg,sizeof(ventaAnualMulti),1,arch);
	
	reg.idEmpleado = 43422;
	reg.ventas = 93423.89;
	reg.sector = 'P';
	
	fwrite(&reg,sizeof(ventaAnualMulti),1,arch);
	
	reg.idEmpleado = 84923;
	reg.ventas = 18293.89;
	reg.sector = 'S';
	
	fwrite(&reg,sizeof(ventaAnualMulti),1,arch);
	
	reg.idEmpleado = 72384;
	reg.ventas = 19383.89;
	reg.sector = 'C';
	
	fwrite(&reg,sizeof(ventaAnualMulti),1,arch);
	
	reg.idEmpleado = 98423;
	reg.ventas = 62813.89;
	reg.sector = 'C';
	
	fwrite(&reg,sizeof(ventaAnualMulti),1,arch);
	
	rewind(arch);
	
	fread(&reg,sizeof(ventaAnualMulti),1,arch);
	
	while(!feof(arch)){
	  cout << reg.idEmpleado << " " << reg.ventas << " " << reg.sector << endl;
	  fread(&reg,sizeof(ventaAnualMulti),1,arch);	
	}
	
	fclose(arch);
	*/

	//resuelvo el ej
	/*FILE* arch = fopen("ventas20210225.dat","rb");
	
	ventaAnualMulti reg;
	NodoVentasAnuales* lista = NULL;
	
	fread(&reg,sizeof(ventaAnualMulti),1,arch);
	
	while(!feof(arch)){
      if(reg.sector == 'C'){
      	insertarOrdenado(lista,reg); //ordenar por ventas
	  }
	  fread(&reg,sizeof(ventaAnualMulti),1,arch);	
	}
	
	fclose(arch);
	
	NodoVentasAnuales * aux = lista;
	
	while(aux != NULL){
		cout << aux->info.idEmpleado << " " << aux->info.ventas << " " << aux->info.sector << endl;
		aux = aux->sig;
	}
	*/
}

void emitirSospechosos(Sospechoso* matriz[4][9], int tipo, char subtipo){
	
	Sospechoso* lista = matriz[tipo - 1][subtipo - 'a'];
	
	Dedo* sublista;
	
	while(lista != NULL){
		cout << lista->info.dni << " " << lista->info.apeNom << endl;
		sublista = lista->info.dedos;
		while(sublista != NULL){
			switch(sublista->info){
				case 1:
					cout << "pulgar mano derecha" << endl;
					break;
				case 2:
					cout << "indice mano derecha" << endl;
					break;
				case 3:
					cout << "medio mano derecha" << endl;
					break;
				case 4:
					cout << "anular mano derecha" << endl;
					break;
				case 5:
					cout << "menique mano derecha" << endl;
					break;
				case 6:
					cout << "pulgar mano izquierda" << endl;
					break;
				case 7:
					cout << "indice mano izquierda" << endl;
					break;
				case 8:
					cout << "medio mano izquierda" << endl;
					break;
				case 9:
					cout << "anular mano izquierda" << endl;
					break;
				case 10:
					cout << "menique mano izquierda" << endl;
					break;		
			}
			sublista = sublista->sig;
		} 
		
		lista = lista->sig;
	
	}
	
	
}

void cargarMatrizSospechosos(Sospechoso* matriz[4][9] , FILE* arch){
	huella reg;
	bool enc;
	infoSospe is;
	Sospechoso* sospeBuscado;
	fread(&reg,sizeof(huella),1,arch);
	
	while(!feof(arch)){
		is.dni = reg.dni;
		strcpy(is.apeNom, reg.apeNom);
		is.dedos = NULL;
		
		sospeBuscado = buscaEInsertaOrdenado(matriz[reg.tipo - 1][reg.subtipo - 1], is , enc);
		insertarOrdenado(sospeBuscado->info.dedos, reg.dedo);
		
		fread(&reg,sizeof(huella),1,arch);	
	}
}

void preOrden(Arbol* raiz){
	if(raiz == NULL){
		return;
	} else {
		cout << raiz->info << " ";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void inOrden(Arbol* raiz){
	if(raiz == NULL){
		return;
	} else {
		inOrden(raiz->izq);
		cout << raiz->info << " ";
		inOrden(raiz->der);
	}
}

void postOrden(Arbol* raiz){
	if(raiz == NULL){
		return;
	} else {
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout << raiz->info << " ";
	}
}

void insertarNodoEnArbol(Arbol* &raiz, int valor){
	if(raiz == NULL){
		Arbol* nuevo = new Arbol();
		nuevo->info = valor;
		nuevo->der = NULL;
		nuevo->izq = NULL;
		raiz = nuevo;
	} else {
		if(valor < raiz->info){
			insertarNodoEnArbol(raiz->izq, valor);
		} else if(valor > raiz->info){
			insertarNodoEnArbol(raiz->der, valor);
		} else {
			cout << "Valor duplicado";
		}
	}		
}

template <typename T>
void push(Nodo<T>* &pila, T v){
	
	Nodo<T> * nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
	
}

template <typename T>
T pop(Nodo<T>*& pila){
	T resultado = pila->info;
	
	Nodo<T> * aux = pila;
	pila = pila->sig;
	delete aux;
	
	return resultado;
}

bool estaBalanceado(char vec[], int len){
	bool resultado = true;
	Nodo<char>* pila = NULL;
	
	for(int i=0; i < len; i++){
		switch(vec[i]) {
			case '(':
			case '{':
			case '[':
				push<char>(pila, vec[i]);
				break;
			case ')':
				if(pop<char>(pila) != '(' ){
					resultado = false;
					break;
				}
				break;
			case '}':
				if(pop<char>(pila) != '{'){
					resultado = false;
					break;
				}
				break;
			case ']':
				if(pop<char>(pila) != '['){
					resultado = false;
					break;
				}
				break;	
		}
		
	}
	
	return resultado;
}

int polacaInversa(char vec[],int len){
	
	Nodo<int>* pila = NULL;
	int op1;
	int op2;
	
	for(int i=0; i < len; i++){
		switch(vec[i]){
			case '+':
				op1 = pop<int>(pila);
				op2 = pop<int>(pila);
				push<int>(pila,op1+op2);
				break;
			case '-':
				op1 = pop<int>(pila);
				op2 = pop<int>(pila);
				push<int>(pila,op2-op1);
				break;
			case '*':
				op1 = pop<int>(pila);
				op2 = pop<int>(pila);
				push<int>(pila,op2*op1);
				break;
			default:
				push<int>(pila,vec[i] - '0');
				break;
		}
		
	}
	
	return pop<int>(pila);
	
}


void pushArray(int vec[], int &len, int valor){
	
	for(int i = len-1; i >= 0;i--){
		 vec[i+1] = vec[i];
	}
	vec[0] = valor;
	len++;
}

int popArray(int vec[], int &len){
	int ret = vec[0];
	for(int i=0; i < len; i++){
		vec[i] = vec[i+1];
	}
	len--;
	return ret;
}


template <typename T> 
void encolar(Nodo<T>* & colafte, Nodo<T>* & colafin, T v){
	Nodo<T> * nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL) {
		colafte = nuevo;
	} else{
		colafin->sig = nuevo;
	}
	
	colafin = nuevo;
}

template <typename T>  
T desencolar(Nodo<T>* & colafte, Nodo<T>* & colafin){
	T resultado = colafte->info;
	
	Nodo<T>* aux = colafte;
	colafte = colafte->sig;
	
	if(colafte == NULL){
		colafin = NULL;
	}
	
	delete aux;
	return resultado;
}

template <typename T> 
void pushCola(Nodo<T>* & colafte, Nodo<T>* & colafin, T v) {
	Nodo<T>*colafteAux = NULL;
	Nodo<T>*colafinAux = NULL;
	
	encolar<T>(colafteAux,colafinAux,v);
	
	while(colafte != NULL){
		encolar<T>(colafteAux,colafinAux,desencolar<T>(colafte,colafin));
	}
	
	colafte =  colafteAux;
	colafin =  colafinAux;
}

template <typename T> T popCola(Nodo<T>* & colafte, Nodo<T>* & colafin){
	return desencolar<T>(colafte,colafin);
}

template <typename T>
void agregarNodo(Nodo<T>* &p, T x){
	
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = x;
	nuevo->sig = NULL;
	
	if(p==NULL){
		p=nuevo;
	} else {
		Nodo<T>* aux = p;
	
		while(aux->sig != NULL){
			aux = aux->sig;
		}
	
		aux->sig = nuevo;
	}
	
};

template <typename T> 
T eliminarPrimerNodo(Nodo<T>*& p){
	T resultado = p->info;
	
	Nodo<T>* aux = p;
	p = p->sig;
	delete aux;
	
	return resultado;
}


template <typename T> 
void encolarLista(Nodo<T>* &lista, T v){
	 agregarNodo<T>(lista,v);
}

template <typename T> 
T desencolarLista(Nodo<T>*& lista){
	return eliminarPrimerNodo<T>(lista);
}

void encolarArray(int vec[], int &len, int v){
	vec[len] = v;
	len++;
}

int desencolarArray(int vec[], int &len){
	int ret = vec[0];
	for(int i=0; i < len; i++){
		vec[i] = vec[i+1];
	}
	len--;
	return ret;
}

template <typename T> 
void encolarPila(Nodo<T>* &pila, T v){
	Nodo<T>* pilaAux = NULL;
	
	while(pila != NULL){
		push<T>(pilaAux,pop<T>(pila));
	}
	
	push<T>(pilaAux,v);
	
	while(pilaAux != NULL){
		push<T>(pila,pop<T>(pilaAux));
	}
}

template <typename T> 
T desencolarPila(Nodo<T>*& pila){
	return pop<T>(pila);
}

template <typename T>
void agregarNodoListaDoble(NodoD<T>* &lista, T x){
	NodoD<T>* nuevo = new NodoD<T>();
	nuevo->info = x;
	nuevo->arriba = NULL;
	nuevo->abajo = NULL;
	
	if(lista == NULL) { 
		lista = nuevo;
	} else {
		NodoD<T>* aux = lista;
		while(aux->arriba != NULL) {
			aux = aux->arriba;
		}
		aux->arriba = nuevo;
		nuevo->abajo = aux;
	}
	
}


template <typename T>
int insertarPisoArribaDelActualYMedir(NodoD<T>* unNuevoPiso, NodoD<T>* unPisoActual, 
									  unsigned &distanciaMasBajo, unsigned &distanciaMasAlto){
									  	
	unNuevoPiso->arriba = unPisoActual->arriba;
	unNuevoPiso->abajo = unPisoActual;
	unPisoActual->arriba->abajo = unNuevoPiso;
	unPisoActual->arriba = unNuevoPiso;
	
	medirDistanciaAPisosExtremos(unNuevoPiso,distanciaMasBajo,distanciaMasAlto);
	
	int distanciaPlantaBaja = 0;
	
	NodoD<T>* aux = unNuevoPiso;
	
	while(aux != NULL && aux->info.nroPiso != 0){
		if(aux->info.nroPiso < 0){
			aux = aux->arriba;
		} else {
			aux = aux->abajo;
		}
		distanciaPlantaBaja++;
	}
	
	
	return 	distanciaPlantaBaja;							  	
}

template <typename T>
void medirDistanciaAPisosExtremos(NodoD<T>* unNuevoPiso, unsigned &distanciaMasBajo, unsigned 
&distanciaMasAlto){
	distanciaMasBajo = 0;
	distanciaMasAlto = 0;
	
	NodoD<T>* auxAbajo = unNuevoPiso->abajo;
	while(auxAbajo != NULL){
		distanciaMasBajo++;
		auxAbajo = auxAbajo->abajo;
	}
	
	NodoD<T>* auxArriba = unNuevoPiso->arriba;
	while(auxArriba != NULL){
		distanciaMasAlto++;
		auxArriba = auxArriba->arriba;
	}
}


template <typename T>
void eliminarPiso(NodoD<T>* &piso){
	
	NodoD<T>* aux = piso;
	
	piso = piso->arriba;
	
	if(aux->arriba != NULL){
		aux->arriba->abajo = aux->abajo;
	}
	
	if(aux->abajo != NULL){
		aux->abajo->arriba = aux->arriba;
	}
	
	delete(aux);
}

bool esPrimo(int numero){
	bool resultado = true;
	
	for(int i = 2; i < numero; i++){
		if(numero%i == 0){
			resultado = false;
			break;
		}
	}
	
	return resultado;
}

template <typename T>
int EliminarLosPisosPrimosArribaDe(NodoD<T>* unPisoActual, FILE* archivo){
	int cantPisosEliminados = 0;
	PisoEliminado reg;
	
	NodoD<T>* aux = unPisoActual->arriba;
	
	while(aux != NULL){
		if(esPrimo(aux->info.nroPiso)){
			reg.nroPiso = aux->info.nroPiso;
			reg.difSubenYBajan = aux->info.personasQueSuben - aux->info.personasQueBajan;
			fwrite(&reg, sizeof(PisoEliminado),1,archivo);
			
			eliminarPiso(aux);
			cantPisosEliminados++;
		} else {
			aux = aux->arriba;
		}
		
	}


	return cantPisosEliminados;
}


NodoCliente* insertarOrdenado(NodoCliente *&p, infoCliente v){
	
	NodoCliente* nuevo = new NodoCliente();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoCliente * aux = p;
	NodoCliente * ant = NULL;
	
	while(aux != NULL && aux->info.nroCliente <= v.nroCliente){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoCliente* buscar(NodoCliente *p, infoCliente v){
	NodoCliente* aux = p;
	
	while(aux != NULL && aux->info.nroCliente != v.nroCliente) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoCliente* buscaEInsertaOrdenado(NodoCliente* &p, infoCliente v, bool & enc){
	
	NodoCliente * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}

NodoArticulo* insertarOrdenado(NodoArticulo *&p, infoArticulo v){
	
	NodoArticulo* nuevo = new NodoArticulo();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoArticulo * aux = p;
	NodoArticulo * ant = NULL;
	
	while(aux != NULL && strcmp(aux->info.articulo,v.articulo)!=0){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoArticulo* buscar(NodoArticulo *p, infoArticulo v){
	NodoArticulo* aux = p;
	
	while(aux != NULL && strcmp(aux->info.articulo,v.articulo)!=0) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoArticulo* buscaEInsertaOrdenado(NodoArticulo* &p, infoArticulo v, bool & enc){
	
	NodoArticulo * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}




template <typename T>
Nodo<T>* insertarOrdenado(Nodo<T> *&p, T v){
	
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	Nodo<T> * aux = p;
	Nodo<T> * ant = NULL;
	
	while(aux != NULL && aux->info.id <= v.id){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

template <typename T>
Nodo<T>* buscar(Nodo<T> *p, T v){
	Nodo<T>* aux = p;
	
	while(aux != NULL && aux->info.id != v.id) {
		aux= aux->sig;
	}
	
	return aux;
}

template <typename T>
Nodo<T>* buscaEInsertaOrdenado(Nodo<T>* &p, T v, bool & enc){
	
	Nodo<T> * nodoBuscado = buscar<T>(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado<T>(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}


template <typename T, typename X, typename Z>
void procesarNovedades(FILE* arch, Nodo<T>* &cursos){
		
	novedad reg;
	
	fread(&reg,sizeof(novedad),1,arch);
	
	while(!feof(arch)){
	  agregarNota<T,X,Z>(cursos, reg.idCurso, reg.idEstudiante, reg.nroEvaluacion, reg.nota);		
	  fread(&reg,sizeof(novedad),1,arch);	
	}
	
}

template <typename T, typename X, typename Z>
void agregarNota(Nodo<T>* &cursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota){
	bool enc;
	
	T datosCur;
	datosCur.id = idCurso;
	datosCur.promocionados = 0;
	datosCur.recursantes = 0;
	datosCur.regularizados = 0;
	datosCur.estudiantes = NULL;
	
	Nodo<T>* curso = buscaEInsertaOrdenado<T>(cursos,datosCur,enc);
	
	X datosEst;
	datosEst.id = idEstudiante;
	datosEst.notas[0] = NULL;
	datosEst.notas[1] = NULL;
	datosEst.notas[2] = NULL;
	datosEst.notas[3] = NULL;
	
	Nodo<X>* estudiante = buscaEInsertaOrdenado<X>(curso->info.estudiantes,datosEst,enc);
	
	agregarNodo<Z>(estudiante->info.notas[nroEvaluacion-1],nota);
	
}

template <typename T>
int getEstado(Nodo<T>* notas[]){
	int estado;
	int nota;
	bool promocion = true;
	bool regulariza = true;
	
	for(int i = 0; i < 4; i++){
	   Nodo<T>* aux = notas[i];  
	   while(aux->sig != NULL){
	   		aux = aux->sig;
	   }
	   nota = aux->info;
	   if(nota < 6){
	   		regulariza = false;
	   		promocion = false;
	   } else if(nota < 8){
	   		promocion = false;
	   }
	}
	
	if(promocion){
		estado = 1;
	} else if(regulariza){
		estado = 2;
	} else {
		estado = 3;
	}
	
  	return estado;
}

template <typename T, typename X, typename Z>
void calcularEstadisticas(Nodo<T>* &cursos){
	
	Nodo<T>* auxCur = cursos;
	Nodo<X>* auxEst = NULL;
	int estado;
	
	while(auxCur != NULL){
		auxEst = auxCur->info.estudiantes;
		
		while(auxEst != NULL){
			estado = getEstado<Z>(auxEst->info.notas);
			
			switch(estado){
				case 1:
					auxCur->info.promocionados++;
					break;
				case 2:
					auxCur->info.regularizados++;
					break;
				case 3:
					auxCur->info.recursantes++;
					break;
			}
			
			auxEst = auxEst->sig;
		}
		
		auxCur = auxCur ->sig;
	}
	
}


NodoSucursal* insertarOrdenado(NodoSucursal *&p, infoSuc v){
	
	NodoSucursal* nuevo = new NodoSucursal();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoSucursal * aux = p;
	NodoSucursal * ant = NULL;
	
	while(aux != NULL && aux->info.nroSuc != v.nroSuc ){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoSucursal* buscar(NodoSucursal *p, infoSuc v){
	NodoSucursal* aux = p;
	
	while(aux != NULL && aux->info.nroSuc != v.nroSuc) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoSucursal* buscaEInsertaOrdenado(NodoSucursal* &p, infoSuc v, bool & enc){
	
	NodoSucursal * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}

NodoSocio* insertarOrdenado(NodoSocio *&p, infoSoc v){
	
	NodoSocio* nuevo = new NodoSocio();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoSocio * aux = p;
	NodoSocio * ant = NULL;
	
	while(aux != NULL && aux->info.nroSoc != v.nroSoc ){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoSocio* buscar(NodoSocio *p, infoSoc v){
	NodoSocio* aux = p;
	
	while(aux != NULL && aux->info.nroSoc != v.nroSoc) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoSocio* buscaEInsertaOrdenado(NodoSocio* &p, infoSoc v, bool & enc){
	
	NodoSocio * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}

NodoItem* insertarOrdenado(NodoItem *&p, infoItem v){
	
	NodoItem* nuevo = new NodoItem();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoItem * aux = p;
	NodoItem * ant = NULL;
	
	while(aux != NULL && strcmp(aux->info.descProducto,v.descProducto) != 0){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoTicket* insertarOrdenado(NodoTicket *&p, infoTicket v){
	
	NodoTicket* nuevo = new NodoTicket();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoTicket * aux = p;
	NodoTicket * ant = NULL;
	
	while(aux != NULL && aux->info.idTicket != v.idTicket ){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoTicket* buscar(NodoTicket *p, infoTicket v){
	NodoTicket* aux = p;
	
	while(aux != NULL && aux->info.idTicket != v.idTicket) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoTicket* buscaEInsertaOrdenado(NodoTicket* &p, infoTicket v, bool & enc){
	
	NodoTicket * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}



Sospechoso* insertarOrdenado(Sospechoso *&p, infoSospe v){
	
	Sospechoso* nuevo = new Sospechoso();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	Sospechoso * aux = p;
	Sospechoso * ant = NULL;
	
	while(aux != NULL && strcmp(aux->info.apeNom , v.apeNom) < 0 ){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

Sospechoso* buscar(Sospechoso *p, infoSospe v){
	Sospechoso* aux = p;
	
	while(aux != NULL && aux->info.dni != v.dni) {
		aux= aux->sig;
	}
	
	return aux;
}


Sospechoso* buscaEInsertaOrdenado(Sospechoso* &p, infoSospe v, bool & enc){
	
	Sospechoso * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}

Dedo* insertarOrdenado(Dedo *&p, int v){
	
	Dedo* nuevo = new Dedo();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	Dedo * aux = p;
	Dedo * ant = NULL;
	
	while(aux != NULL && aux->info < v ){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

void ordenarVector(resultado vec[], int len){
	resultado temp; 
	
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len-1; j++){
			if(vec[j].pos < vec[j+1].pos){
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}
		}
		
	}
}

void GenerarListaConsejerosDocentes(candidato vecCandidatos[], int lenCandidatos, 
resultado vecResultado[], int lenResultado){
	float votos[3] = {votosLista1, votosLista2, votosLista3};
	resultado vecAux[15];
	int k = 0;
	
	for(int i =0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			vecAux[k].cand = vecCandidatos[k];
			vecAux[k].pos = votos[i] / (j+1);
			k++;	
		}
	}
	
	int lenAux = 15;
	
	ordenarVector(vecAux, lenAux);
	
	for(int i = 0; i < 5; i++){
		vecResultado[i].pos = i+1;
		vecResultado[i].cand = vecAux[i].cand;
		lenResultado++;
	}
	
}

int buscar(localidad vecLoc[], int lenLoc, char localidad[20]){
	int i = 0;
	
	while(i < lenLoc && strcmp(vecLoc[i].loc,localidad) != 0) {
		i++;
	}
	
	return i;
}

void ordenarVector(porcEleccion vec[], int len){
	porcEleccion temp; 
	
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len-1; j++){
			if(vec[j].porc < vec[j+1].porc){
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}
		}
		
	}
}


void calcularListaGanadora(int mat[4][5], localidad vecLoc[4], int lenLoc, FILE* arch){
	eleccion reg;
	int pos;
	float totalDeVotosEscrutados = 0;
	porcEleccion vecPorc[5];
	int lenVecPorc = 0;
	
	fread(&reg,sizeof(eleccion),1,arch);
	
	while(!feof(arch)){
		pos = buscar(vecLoc, lenLoc, reg.localidad);
		mat[pos][reg.lista - 1] = reg.votos;
		totalDeVotosEscrutados += reg.votos;
		fread(&reg,sizeof(eleccion),1,arch);
	}
	
	for(int i = 0; i < 4; i++){
		cout << "Votos para " << vecLoc[i].loc << endl;
		for(int j= 0; j < 5; j++){
			cout << "Lista " << j+1 << " : " << mat[i][j] << endl;		
		}
	}
	
	int votos;
	
	for(int i=0 ; i < 5 ; i++ ){
		votos = 0;
		cout << "Votos Totales para Lista " << i+1 << " :";
		for(int j=0; j < 4; j++){
			votos += mat[j][i];
		}
		vecPorc[i].lista = i+1;
		vecPorc[i].porc = votos * 100 / totalDeVotosEscrutados;
		cout << votos << " - " <<  vecPorc[i].porc << " %"<< endl;
		lenVecPorc++;
	}
	
	
	ordenarVector(vecPorc, lenVecPorc);
	
	if(vecPorc[0].porc > 50){
		cout << "La unica lista ganadora es: " << vecPorc[0].lista << endl;
	} else if(vecPorc[0].porc - vecPorc[1].porc >= 10){  //10%
		cout << "La unica lista ganadora es: " << vecPorc[0].lista << endl;
	} else {
		cout << "Pasan a una segunda vuelta las listas: " <<  vecPorc[0].lista << " y " << vecPorc[1].lista << endl;
	}
	
}

void push(NodoFinal* &pila, int v){
	
	NodoFinal * nuevo = new NodoFinal();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
	
}

int pop(NodoFinal*& pila){
	int resultado = pila->info;
	
	NodoFinal * aux = pila;
	pila = pila->sig;
	delete aux;
	
	return resultado;
}

void encolar(NodoFinal* & colafte, NodoFinal* & colafin, int v){
	NodoFinal* nuevo = new NodoFinal();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL) {
		colafte = nuevo;
	} else{
		colafin->sig = nuevo;
	}
	
	colafin = nuevo;
}

int desencolar(NodoFinal* & colafte, NodoFinal* & colafin){
	int resultado = colafte->info;
	
	NodoFinal* aux = colafte;
	colafte = colafte->sig;
	
	if(colafte == NULL){
		colafin = NULL;
	}
	
	delete aux;
	return resultado;
}

NodoFinal* buscar(NodoFinal *p, int v){
	NodoFinal* aux = p;
	
	while(aux != NULL && aux->info != v) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoFinal* buscaEInsertaOrdenado(NodoFinal* &p, int v, bool & enc){
	
	NodoFinal * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}

NodoFinal* insertarOrdenado(NodoFinal *&p, int v){
	
	NodoFinal* nuevo = new NodoFinal();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoFinal * aux = p;
	NodoFinal * ant = NULL;
	
	while(aux != NULL && aux->info < v ){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}

NodoFinal * unionPilaYCola(NodoFinal* &pila,NodoFinal* &colafte, NodoFinal* & colafin) {
	NodoFinal *lista = NULL;
	bool enc;	
	//Opci�n con repetidos
	/*while(colafte != NULL){
		insertarOrdenado(lista,desencolar(colafte,colafin)); 
	}
	
	while(pila != NULL){
		insertarOrdenado(lista,pop(pila));
	}*/
	
	//Opci�n sin repetidos
	while(colafte != NULL){
		buscaEInsertaOrdenado(lista,desencolar(colafte,colafin),enc); 
	}
	
	while(pila != NULL){
		buscaEInsertaOrdenado(lista,pop(pila),enc);
	}
	
	return lista;
}


void agregarNodo(NodoFinal* &p, int x){
	
	NodoFinal* nuevo = new NodoFinal();
	nuevo->info = x;
	nuevo->sig = NULL;
	
	if(p==NULL){
		p=nuevo;
	} else {
		NodoFinal* aux = p;
	
		while(aux->sig != NULL){
			aux = aux->sig;
		}
	
		aux->sig = nuevo;
	}
	
};

int buscar(int vec[], int len, int v){
	int i = 0;
	int pos;
	
	while(i < len && vec[i] != v) {
		i++;
	}
	
	if(i==len){
	   pos = -1;
	} else {
	   pos = i;
	}
	
	return pos;
}

void interseccionListaYVector(NodoFinal* lista, int vec[], int len, NodoFinal* &listaInter){
	
	NodoFinal* aux = lista;
	int pos;
	
	while(aux != NULL){
		pos = buscar(vec,len,aux->info);
		
		if(pos != -1){
			insertarOrdenado(listaInter,vec[pos]); // o aux->info (es el mismo valor)
		}
		
		aux = aux->sig;
	}
	
}

NodoVentasAnuales* insertarOrdenado(NodoVentasAnuales *&p, ventaAnualMulti v){
    NodoVentasAnuales* nuevo = new NodoVentasAnuales();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoVentasAnuales * aux = p;
	NodoVentasAnuales * ant = NULL;
	
	while(aux != NULL && aux->info.ventas < v.ventas ){
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant == NULL) { // estoy insertando al principio de la lista
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	
	return nuevo;
}
