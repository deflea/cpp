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

int main(int argc, char** argv) {
    //Final lista doblemente enlazada
	/*NodoD<Piso>* ascensor = NULL;
	Piso info;
	
	info.nroPiso = -3;
	info.personasQueSuben = 23;
	info.personasQueBajan = 3;
	
	agregarNodoListaDoble<Piso>(ascensor,info);
	
	info.nroPiso = -1;
	info.personasQueSuben = 25;
	info.personasQueBajan = 5;
	
	agregarNodoListaDoble<Piso>(ascensor,info);
	
	info.nroPiso = 0;
	info.personasQueSuben = 7;
	info.personasQueBajan = 10;
	
	agregarNodoListaDoble<Piso>(ascensor,info);
	
	info.nroPiso = 2;
	info.personasQueSuben = 9;
	info.personasQueBajan = 5;
	
	agregarNodoListaDoble<Piso>(ascensor,info);
	
	info.nroPiso = 3;
	info.personasQueSuben = 1;
	info.personasQueBajan = 10;
	
	agregarNodoListaDoble<Piso>(ascensor,info);
	
	info.nroPiso = 4;
	info.personasQueSuben = 1;
	info.personasQueBajan = 15;
	
	agregarNodoListaDoble<Piso>(ascensor,info);

	NodoD<Piso>* unPisoActual = ascensor;
	
	while(unPisoActual != NULL && unPisoActual->info.nroPiso != 0 ){
		unPisoActual = unPisoActual->arriba;
	}
	
	FILE* arch = fopen("pisosEliminados.dat","rb+");
	
    int cantPisosEliminados = EliminarLosPisosPrimosArribaDe<Piso>(unPisoActual, arch);
	
	cout << "La cantidad de pisos eliminados fue " << cantPisosEliminados << endl;
	
	cout << "La lista queda: " << endl;
	
	NodoD<Piso>* auxP = ascensor;
	
	while(auxP != NULL){
		cout << auxP->info.nroPiso << endl;
		auxP = auxP->arriba;
	}
	
	rewind(arch);
	PisoEliminado reg;
	
	cout << "Contenido del archivo" << endl;
	fread(&reg, sizeof(PisoEliminado),1,arch);
	
	while(!feof(arch)){
		cout << reg.nroPiso << endl;
		cout << reg.difSubenYBajan << endl;
		cout << "-----------------" << endl;
		fread(&reg, sizeof(PisoEliminado),1,arch);
	}

	fclose(arch);
	*/
	
	//Final lista y Sublista
/*	Nodo<infoCurso<infoEst<int> > >* cursos = NULL;
	FILE* arch = fopen("novedades.dat","rb");
	procesarNovedades<infoCurso<infoEst<int> >,infoEst<int>, int >(arch,cursos);
	
	Nodo<infoCurso<infoEst<int> > >* auxCur = cursos;
	Nodo<infoEst<int> >* auxEst = NULL;
	Nodo<int>* auxNotas = NULL;
	
	while(auxCur != NULL){
		cout << "Curso nro. " << auxCur->info.id << endl;
		auxEst = auxCur->info.estudiantes;
		while(auxEst != NULL){
			cout << "Estudiante nro. " << auxEst->info.id << endl;
			
			auxNotas = auxEst->info.notas[0];
			cout << "Notas de la 1era Ev. " << endl;
			while(auxNotas != NULL){
				cout << auxNotas->info << endl;
				auxNotas = auxNotas ->sig;
			}
			
			auxNotas = auxEst->info.notas[1];
			cout << "Notas de la 2da Ev. " << endl;
			while(auxNotas != NULL){
				cout << auxNotas->info << endl;
				auxNotas = auxNotas ->sig;
			}
			
			auxNotas = auxEst->info.notas[2];
			cout << "Notas de la 3era Ev. " << endl;
			while(auxNotas != NULL){
				cout << auxNotas->info << endl;
				auxNotas = auxNotas ->sig;
			}
			
			auxNotas = auxEst->info.notas[3];
			cout << "Notas de la 4ta Ev. " << endl;
			while(auxNotas != NULL){
				cout << auxNotas->info << endl;
				auxNotas = auxNotas ->sig;
			}
			
			auxEst = auxEst->sig;
		}
		
		auxCur = auxCur->sig;
	}
	
	calcularEstadisticas<infoCurso<infoEst<int> >, infoEst<int>, int>(cursos);
	
	auxCur = cursos;
	
	while(auxCur != NULL){
		cout << "Nro. de curso: " << auxCur->info.id << endl;
		cout << "Promocionados: " << auxCur->info.promocionados << endl;
		cout << "Regularizados: " << auxCur->info.regularizados << endl;
		cout << "Recursantes: " << auxCur->info.recursantes << endl;
		auxCur = auxCur-> sig;
	}
*/
	
  //Ejercicio Lista y sublista
 /*	NodoCliente* clientes = NULL;
	NodoCliente* cliente;
	NodoArticulo* articulo;		
	bool enc;
	infoCliente ic;
	infoArticulo ia;
	
	FILE * arch = fopen("ventas.dat","rb");
	venta reg;
	
	fread(&reg,sizeof(venta),1,arch);
	
	while(!feof(arch)){
		ic.nroCliente = reg.nroCliente;
		ic.dineroGastado = 0;
		ic.articulos = NULL;
		
		cliente = buscaEInsertaOrdenado(clientes,ic,enc);
		
		cliente->info.dineroGastado += reg.cant * reg.precioUnitario;
		
		strcpy(ia.articulo, reg.articulo);
		ia.cant = 0;
		ia.precioUnitario = reg.precioUnitario;
		
		articulo = buscaEInsertaOrdenado(cliente->info.articulos,ia, enc);
		
		articulo->info.cant += reg.cant;
		
		fread(&reg,sizeof(venta),1,arch);
	}
	
	NodoCliente* auxCli = clientes;
	float dineroTotalRecaudado = 0;
	NodoArticulo* auxArt;
	
	while(auxCli != NULL){
		cout << "Numero de Cliente " << auxCli->info.nroCliente << ": " << auxCli->info.dineroGastado << endl; 
		dineroTotalRecaudado += auxCli->info.dineroGastado;
		cout << "Detalle: " << endl;
		auxArt =  auxCli->info.articulos;
		
		while(auxArt != NULL){
			cout << auxArt->info.articulo << "  " << auxArt->info.cant << "  " << auxArt->info.precioUnitario 
			<< "  " << auxArt->info.cant * auxArt->info.precioUnitario << endl; 
			auxArt = auxArt->sig;
		}
		
		auxCli = auxCli->sig;
	}
	
	cout << "Total Dinero recaudado: " << dineroTotalRecaudado << endl;
	
	fclose(arch);
  */
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
