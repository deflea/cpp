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

int main(int argc, char** argv) {
	/* Ejercicio Lista con Sublista
	ingreso reg;
	NodoSucursal* listaSucursales = NULL;
	NodoSucursal* sucBuscada;
	NodoSocio* socBuscado;
	bool enc;
	infoSuc isuc;
	infoSoc isoc;
	
	FILE* arch = fopen("ingreso.dat","rb");
	
	fread(&reg,sizeof(ingreso),1,arch);
	
	while(!feof(arch)){
		isuc.nroSuc = reg.nroSucursal;
		isuc.cantTotalDeVisitas = 0;
		isuc.cantDeVisitasDistintas = 0;
		isuc.socios = NULL;
		
		sucBuscada = buscaEInsertaOrdenado(listaSucursales,isuc,enc);

		sucBuscada->info.cantTotalDeVisitas++;
		
		isoc.nroSoc = reg.nroSocio;
		isoc.estadiaTotal = 0;
		isoc.visitasTotales = 0;
		
		socBuscado = buscaEInsertaOrdenado(sucBuscada->info.socios,isoc,enc);

		if(!enc){
			sucBuscada->info.cantDeVisitasDistintas++;
		}
		
		socBuscado->info.estadiaTotal += reg.estadia;
		socBuscado->info.visitasTotales++;		

		fread(&reg,sizeof(ingreso),1,arch);	
	}
		
	fclose(arch);
	
	cout << "Septiembre" << endl;
	
	NodoSucursal* auxSuc = listaSucursales;
	NodoSocio* auxSoc;
	int maxEstadia;
	int socMaxEstadia;
	
	while(auxSuc != NULL){
		cout << "Nro. de Sucursal: " << auxSuc->info.nroSuc << "  Cantidad de Visitas Totales: " 
		<< auxSuc->info.cantTotalDeVisitas << "  Cantidad de Personas Distintas: "
		<< auxSuc->info.cantDeVisitasDistintas << endl;
		
		auxSoc = auxSuc->info.socios;
		maxEstadia = 0;
		
		while(auxSoc != NULL){
			if(auxSoc->info.estadiaTotal > maxEstadia){
			 	socMaxEstadia = auxSoc->info.nroSoc;
			 	maxEstadia = auxSoc->info.estadiaTotal;
			}	
			auxSoc = auxSoc ->sig;
		}
		
		cout << "El socio " << socMaxEstadia << " tuvo mayor estadia en la suc " << auxSuc->info.nroSuc
		<< " con " << maxEstadia << " minutos" << endl;
				
		auxSuc = auxSuc->sig;
	}
	*/
	
	/* Ejercicio Vector lista con Sublista
	FILE * arch = fopen("ventas2018.dat","rb");
	ventaAnual reg;
	NodoTicket* vecMeses[12];
	infoTicket iTicket;
	infoItem iItem;
	NodoTicket* ticketBuscado;
	bool enc;

	
	for(int i =0; i < 12; i++){
		vecMeses[i] = NULL;
	}
	
	fread(&reg,sizeof(ventaAnual),1,arch);
	
	while(!feof(arch)){
		iTicket.idTicket = reg.idTicket;
		iTicket.montoTotal = 0;
		iTicket.items = NULL;
		
		ticketBuscado = buscaEInsertaOrdenado(vecMeses[reg.idMes-1],iTicket,enc);
		
		ticketBuscado->info.montoTotal += reg.precioUnitario * reg.cantVendida;
		
		strcpy(iItem.descProducto, reg.descProducto);
		iItem.cantVendida = reg.cantVendida;
		iItem.precioUnitario = reg.precioUnitario;
		
		insertarOrdenado(ticketBuscado->info.items,iItem);

		fread(&reg,sizeof(ventaAnual),1,arch);
	}
	
	fclose(arch);
	
	NodoTicket* auxTicket;
	NodoItem* auxItem;
	int ticketMaxMonto;
	int ticketMinMonto;
	float montoMaxTicket;
	float montoMinTicket;
	int cantTickets;
	float sumaMontoTickets;
	
	int ticketMaxMontoAnio;
	int ticketMinMontoAnio;
	int mesTicketMaxMonto;
	int mesTicketMinMonto;
	float montoMaxTicketAnio = 0;
	float montoMinTicketAnio = 999999999;
	int cantTicketsAnio = 0;
	float sumaMontoTicketsAnio = 0;
	
	int maxCompras = 0;
	int mesMaxCompras;
	
	for(int i =0; i < 12; i++){
		cout << "Mes: " << i+1 << endl;
		
		auxTicket = vecMeses[i];
	    montoMaxTicket = 0;
	    montoMinTicket = 9999999999;
	    cantTickets = 0;
	    sumaMontoTickets = 0;
	    
		while(auxTicket != NULL){
			cout << "Ticket: " << auxTicket->info.idTicket << endl;
			
			auxItem = auxTicket->info.items;
			
			while(auxItem != NULL){
				cout << auxItem->info.descProducto << "  " << auxItem->info.cantVendida
				<< " unidades  $" << auxItem->info.precioUnitario << " pu  $"
				<<  auxItem->info.cantVendida * auxItem->info.precioUnitario << " total" << endl;
				
				auxItem = auxItem->sig;
			}
			
			cout << "Monto Total del Ticket $" << auxTicket->info.montoTotal << endl;
			
			if(auxTicket->info.montoTotal > montoMaxTicket){
				montoMaxTicket = auxTicket->info.montoTotal;
				ticketMaxMonto = auxTicket->info.idTicket;
			}
			
			if(auxTicket->info.montoTotal < montoMinTicket){
				montoMinTicket = auxTicket->info.montoTotal;
				ticketMinMonto = auxTicket->info.idTicket;
			}
			
			if(auxTicket->info.montoTotal > montoMaxTicketAnio){
				montoMaxTicketAnio = auxTicket->info.montoTotal;
				ticketMaxMontoAnio = auxTicket->info.idTicket;
				mesTicketMaxMonto = i+1;
			}
			
			if(auxTicket->info.montoTotal < montoMinTicketAnio){
				montoMinTicketAnio = auxTicket->info.montoTotal;
				ticketMinMontoAnio = auxTicket->info.idTicket;
				mesTicketMinMonto = i+1;
			}
			
			cantTickets++;
			sumaMontoTickets += auxTicket->info.montoTotal;
			
			cantTicketsAnio++;
			sumaMontoTicketsAnio += auxTicket->info.montoTotal;
			
			auxTicket = auxTicket->sig;
		}
		
		if(cantTickets > maxCompras){
			maxCompras = cantTickets;
			mesMaxCompras = i+1;
		}
		
		cout << "El menor ticket fue " << ticketMinMonto << " con $" << montoMinTicket << endl;
		cout << "El mayor ticket fue " << ticketMaxMonto << " con $" << montoMaxTicket << endl;
		cout << "El ticket promedio del mes fue " << sumaMontoTickets/cantTickets << endl;
		
		cout << "------------------------------------------------" << endl;
		
	}
	
	cout << "El ticket mas alto fue " << ticketMaxMontoAnio << " con $" << montoMaxTicketAnio << " en el mes " << mesTicketMaxMonto << endl;
	cout << "El ticket mas bajo fue " << ticketMinMontoAnio << " con $" << montoMinTicketAnio << " en el mes " << mesTicketMinMonto << endl;
	cout << "El ticket promedio del anio fue " << sumaMontoTicketsAnio/cantTicketsAnio << endl;
	cout << "El mes con mas compras fue " << mesMaxCompras << endl;
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
