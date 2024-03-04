#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

struct Nodo {
	int info;
	Nodo* sig;
};

struct entrada {
	int id_pelicula;
	char nom_pelicula[50];
	int dia;
	int fecha;
	bool ind;
};

struct parte {
	char pais[50];
	int mes;
	int dia;
	int cantidad;
	char tipo;
};


struct jugador{
 unsigned id_jugador;
 char nombres[50 + 1];
 unsigned fecha_nacimiento;
 char pais[50 + 1];
 unsigned cantidad_goles;
};

struct jugo_en {
 unsigned id_jugador;
 char pais[50 + 1];
};

struct NodoListaJugadores
{
  jugador info;
  NodoListaJugadores *sig;
};

struct NodoListaJugoEn
{
  jugo_en info;
  NodoListaJugoEn *sig;
};

NodoListaJugadores* insertarOrdenado(NodoListaJugadores *&p, jugador v);
NodoListaJugoEn* insertarOrdenado(NodoListaJugoEn *&p, jugo_en v);

void cargarDatosEnMemoria(FILE* jugadores, FILE* jugo_en_seleccion, 
NodoListaJugadores* &listaJugadores,NodoListaJugoEn* & listaJugoEn);

int edadDelCandidato(int fechaDeNacimiento);
bool jugoEnOtraSeleccion(int id_jugador, char pais[], NodoListaJugoEn* & listaJugoEn);
bool puedeSerCitado(char pais[], int id_jugador, NodoListaJugadores* listaJugadores, NodoListaJugoEn* listaJugoEn);

struct infoEspec{
	int fecha;
	int dia;
	int cantEspectadores;
};

struct NodoEspectador {
	infoEspec info;
	NodoEspectador* sig;
};

struct infoPeli{
	int id_pelicula;
	char nom_pelicula[50];
	NodoEspectador* espectadores;	
};

struct NodoPelicula{
	infoPeli info;
	NodoPelicula* sig;
};

NodoPelicula* buscaEInsertaOrdenado(NodoPelicula* &p, infoPeli v, bool & enc);
NodoPelicula* buscar(NodoPelicula *p, infoPeli v);
NodoPelicula* insertarOrdenado(NodoPelicula *&p, infoPeli v);

NodoEspectador* buscaEInsertaOrdenado(NodoEspectador* &p, infoEspec v, bool & enc);
NodoEspectador* buscar(NodoEspectador *p, infoEspec v);
NodoEspectador* insertarOrdenado(NodoEspectador *&p, infoEspec v);
void cargarListaDelMes(FILE* arch, NodoPelicula* &peliculas);
int cantidadTotalDeEspectadoresEnElMes(NodoPelicula* &peliculas);
int diaQueMasGenteFueAlCine(NodoPelicula* &peliculas);
void ordenarVector(int vec[], int len);
void peliculaMasVista(NodoPelicula* &peliculas,char nombrePeliMasVista[]);
void push(Nodo* &pila, int v);
int pop(Nodo*& pila);
void encolar(Nodo* & colafte, Nodo* & colafin, int v);
int desencolar(Nodo* & colafte, Nodo* & colafin);

struct infoProceso{
	int id;
	int consumoCPU;
};

struct NodoProceso{
	infoProceso info;
	NodoProceso* sig;
};

struct Servidor {
	int id;
	int sumConsumoCPU;
	NodoProceso* colafte;
	NodoProceso* colafin;
};

void agregarNodo(NodoProceso* &p, infoProceso x);
infoProceso eliminarPrimerNodo(NodoProceso*& p);
void encolar(NodoProceso* & colafte, NodoProceso* & colafin, infoProceso v);
infoProceso desencolar(NodoProceso* & colafte, NodoProceso* & colafin);
void ordenarVector(Servidor vec[], int len);

struct infoFamilia{
	int id;
	int cantIntegrantes;
};

struct NodoFamilia {
	infoFamilia info;
    NodoFamilia* sig;
};

void encolar(NodoFamilia* & colafte, NodoFamilia* & colafin, infoFamilia v);
infoFamilia desencolar(NodoFamilia* & colafte, NodoFamilia* & colafin);

struct infoProducto{
	int id;
	int fecha; //AAAAMMDD
};

struct NodoProducto{
	infoProducto info;
	NodoProducto* sig;
};

void push(NodoProducto* &pila, infoProducto v);
infoProducto pop(NodoProducto*& pila);
NodoProducto* insertarOrdenado(NodoProducto *&p, infoProducto v);
infoProducto eliminarPrimerNodo(NodoProducto*& p);

struct infoProductoDeposito {
	int id;
	string nombre;
};

struct NodoProductoDeposito {
	infoProductoDeposito info;
	NodoProductoDeposito* sig;
};

void agregarNodo(NodoProductoDeposito* &p, infoProductoDeposito x);
infoProductoDeposito pop(NodoProductoDeposito*& pila);
void push(NodoProductoDeposito* &pila, infoProductoDeposito v);
NodoProductoDeposito* buscar(NodoProductoDeposito *p, infoProductoDeposito v);

int main(int argc, char** argv) {

	//Ejercicio 1 Colas
	/*Servidor vec[5];
	int len = 5;
	
	for(int i =0; i < len; i++){
		vec[i].id = i+1;
		vec[i].sumConsumoCPU = 0;
		vec[i].colafte = NULL;
		vec[i].colafin = NULL;
	}
	
	NodoProceso* listaDeProcesos = NULL;
	
	infoProceso info;
	info.id = 1;
	info.consumoCPU = 56;
	
	agregarNodo(listaDeProcesos,info);
	
	info.id = 2;
	info.consumoCPU = 46;
	
	agregarNodo(listaDeProcesos,info);
	
	info.id = 3;
	info.consumoCPU = 38;
	
	agregarNodo(listaDeProcesos,info);
	
	info.id = 4;
	info.consumoCPU = 78;
	
	agregarNodo(listaDeProcesos,info);
	
	info.id = 5;
	info.consumoCPU = 100;
	
	agregarNodo(listaDeProcesos,info);
	
	info.id = 6;
	info.consumoCPU = 10;
	
	agregarNodo(listaDeProcesos,info);
	
	info.id = 7;
	info.consumoCPU = 30;
	
	agregarNodo(listaDeProcesos,info);

		
	while(listaDeProcesos != NULL){
		info = eliminarPrimerNodo(listaDeProcesos);
		ordenarVector(vec,len);
		vec[0].sumConsumoCPU += info.consumoCPU;
		encolar(vec[0].colafte,vec[0].colafin,info);
	}
	cout << listaDeProcesos << endl;
	
	for(int i = 0; i <len; i++){
		 cout << "Servidor " << vec[i].id << endl;
		 cout << vec[i].sumConsumoCPU << endl;
		 while(vec[i].colafte != NULL){
		 	info = desencolar(vec[i].colafte, vec[i].colafin);
		 	cout << info.id << endl;
		 	cout << info.consumoCPU << endl;
		 }
	}
	*/
	
	//Ejercicio 2 Colas
	/*NodoFamilia* colaFteVIP = NULL;
	NodoFamilia* colaFinVIP = NULL;
	
	NodoFamilia* colaFteES = NULL;
	NodoFamilia* colaFinES = NULL;
	
	infoFamilia info;
	info.id = 1;
	info.cantIntegrantes = 5;
	
	encolar(colaFteVIP,colaFinVIP,info);
	
	info.id = 2;
	info.cantIntegrantes = 4;
	
	encolar(colaFteVIP,colaFinVIP,info);
	
	info.id = 3;
	info.cantIntegrantes = 3;
	
	encolar(colaFteVIP,colaFinVIP,info);
	
	info.id = 4;
	info.cantIntegrantes = 5;
	
	encolar(colaFteVIP,colaFinVIP,info);
	
	info.id = 5;
	info.cantIntegrantes = 4;
	
	encolar(colaFteVIP,colaFinVIP,info);
	
	info.id = 6;
	info.cantIntegrantes = 5;
	
	encolar(colaFteVIP,colaFinVIP,info);

	info.id = 10;
	info.cantIntegrantes = 6;
	
	encolar(colaFteES,colaFinES,info);
	
	info.id = 12;
	info.cantIntegrantes = 2;
	
	encolar(colaFteES,colaFinES,info);

	info.id = 13;
	info.cantIntegrantes = 5;
	
	encolar(colaFteES,colaFinES,info);
	
	info.id = 14;
	info.cantIntegrantes = 4;
	
	encolar(colaFteES,colaFinES,info);
	
	info.id = 15;
	info.cantIntegrantes = 3;
	
	encolar(colaFteES,colaFinES,info);
	
	int capacidad = 30;
	int mitadDeLaCapacidad = capacidad/2;
	int contador = 0;
	int cantidadDeJuegos = 1;
	
	cout << "Juego " << cantidadDeJuegos << endl; 
	
	while(colaFteES != NULL && colaFteVIP != NULL){
		
		if(contador <= mitadDeLaCapacidad){
			info = desencolar(colaFteVIP, colaFinVIP);
		    contador += info.cantIntegrantes;
		    cout << info.id << " " << info.cantIntegrantes << " - Cola VIP" << endl;
		} else if(contador == capacidad) {
		     contador = 0;
		     cantidadDeJuegos++;
		     cout << "Juego " << cantidadDeJuegos << endl; 
		} else {
			if(colaFteES->info.cantIntegrantes + contador <= capacidad){
				info = desencolar(colaFteES, colaFinES);
			    contador += info.cantIntegrantes;
			    cout << info.id << " " << info.cantIntegrantes << " - Cola Estandar" << endl;
			} else {
				contador = 0;
				cantidadDeJuegos++;
				cout << "Juego " << cantidadDeJuegos << endl; 
			}
		}

	}
	
	while(colaFteES != NULL){
		if(contador == capacidad) {
		     contador = 0;
		     cantidadDeJuegos++;
		     cout << "Juego " << cantidadDeJuegos << endl; 
		}else{
		  if(colaFteES->info.cantIntegrantes + contador <= capacidad){
				info = desencolar(colaFteES, colaFinES);
			    contador += info.cantIntegrantes;
			    cout << info.id << " " << info.cantIntegrantes << " - Cola Estandar" << endl;
			} else {
				contador = 0;
				cantidadDeJuegos++;
				cout << "Juego " << cantidadDeJuegos << endl; 
			}
	    }
	}
	
	while(colaFteVIP != NULL){
	   if(contador == capacidad) {
		     contador = 0;
		     cantidadDeJuegos++;
		     cout << "Juego " << cantidadDeJuegos << endl; 
		}else{
		  if(colaFteVIP->info.cantIntegrantes + contador <= capacidad){
				info = desencolar(colaFteVIP, colaFinVIP);
			    contador += info.cantIntegrantes;
			    cout << info.id << " " << info.cantIntegrantes << " - Cola VIP" << endl;
			} else {
				contador = 0;
				cantidadDeJuegos++;
				cout << "Juego " << cantidadDeJuegos << endl; 
			}
	    }
	}
	*/
	
	//Ejercicio 1 Pilas
	/*NodoProducto* pila = NULL;
	
	infoProducto info;
	info.id = 4632;
	info.fecha = 20211124;
	
	push(pila,info);
	
	info.id = 7482;
	info.fecha = 20211130;
	
	push(pila,info);
	
	info.id = 2562;
	info.fecha = 20211107;
	
	push(pila,info);
	
	info.id = 1829;
	info.fecha = 20211111;
	
	push(pila,info);
	
	info.id = 8573;
	info.fecha = 20211110;
	
	push(pila,info);
	
	info.id = 1456;
	info.fecha = 20211117;
	
	push(pila,info);
	
    
	NodoProducto* listaParaOrdenar = NULL;
	
	while(pila != NULL){
	   insertarOrdenado(listaParaOrdenar,pop(pila));
	
    }
    
    while(listaParaOrdenar != NULL){
    	push(pila,eliminarPrimerNodo(listaParaOrdenar));
	}
    
    while(pila != NULL){
    	info = pop(pila);
    	cout << info.fecha << endl;
	}
	*/
	//Ejercicio 2 Pilas
	
	/*NodoProductoDeposito* listaPedido = NULL;
	infoProductoDeposito info;
	
	info.id = 1;
	info.nombre = "alfajor";
	
	agregarNodo(listaPedido, info);
	
	info.id = 7;
	info.nombre = "galletitas";
	
	agregarNodo(listaPedido, info);
	
	info.id = 10;
	info.nombre = "gaseosas";
	
	agregarNodo(listaPedido, info);
	
	NodoProductoDeposito* pilaEstanteria = NULL;
	
	info.id = 7;
	info.nombre = "galletitas";
	
	push(pilaEstanteria, info);
	
	info.id = 12;
	info.nombre = "gomitas";
	
	push(pilaEstanteria, info);
	
	info.id = 1;
	info.nombre = "alfajor";
	
	push(pilaEstanteria, info);
	
	info.id = 24;
	info.nombre = "cereal";
	
	push(pilaEstanteria, info);
	
	info.id = 60;
	info.nombre = "papas fritas";
	
	push(pilaEstanteria, info);
	
	info.id = 10;
	info.nombre = "gaseosas";
	
	push(pilaEstanteria, info);
	
	NodoProductoDeposito* pilaAux = NULL;
	NodoProductoDeposito* nodoBuscado;
	
	while(pilaEstanteria != NULL){
		info = pop(pilaEstanteria);
		nodoBuscado = buscar(listaPedido,info); // busco por id
		if(nodoBuscado == NULL){ // no est� en la lista del pedido
			push(pilaAux,info);
		}
	}
	
	while(pilaAux != NULL){
		push(pilaEstanteria, pop(pilaAux));
	}
	
	while(pilaEstanteria != NULL){
		info = pop(pilaEstanteria);
		cout << info.nombre << endl;
	}
	*/
		
}

NodoListaJugoEn* insertarOrdenado(NodoListaJugoEn *&p, jugo_en v){
	
	NodoListaJugoEn* nuevo = new NodoListaJugoEn();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoListaJugoEn * aux = p;
	NodoListaJugoEn * ant = NULL;
	
	while(aux != NULL && aux->info.id_jugador <= v.id_jugador){
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



NodoListaJugadores* insertarOrdenado(NodoListaJugadores *&p, jugador v){
	
	NodoListaJugadores* nuevo = new NodoListaJugadores();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoListaJugadores * aux = p;
	NodoListaJugadores * ant = NULL;
	
	while(aux != NULL && aux->info.id_jugador <= v.id_jugador){
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

void cargarDatosEnMemoria(FILE* jugadores, FILE* jugo_en_seleccion, 
NodoListaJugadores* &listaJugadores,NodoListaJugoEn* & listaJugoEn){
	jugador regJugador;
	jugo_en regJugoEn;
	
	fread(&regJugador,sizeof(jugador),1,jugadores);
	
	while(!feof(jugadores)){
		insertarOrdenado(listaJugadores,regJugador);
		fread(&regJugador,sizeof(jugador),1,jugadores);
	}
	
	
	fread(&regJugoEn,sizeof(jugo_en),1,jugo_en_seleccion);
	
	while(!feof(jugo_en_seleccion)){
		insertarOrdenado(listaJugoEn,regJugoEn);
		fread(&regJugoEn,sizeof(jugo_en),1,jugo_en_seleccion);
	}
	
}

//aaaammdd
int edadDelCandidato(int fechaDeNacimiento){ 
 	time_t t = time(0);  
 	tm* now = localtime(&t); 
	 
	int anioActual = now->tm_year + 1900;
 	int mesActual = now->tm_mon +1;
 	int diaActual = now->tm_mday;
 		
	int fechaActual = anioActual* 10000 + mesActual*100 + diaActual;
	int edad = (fechaActual - fechaDeNacimiento) /10000;
	
	return edad;
}


NodoListaJugoEn* buscar(NodoListaJugoEn *p, int id_jugador){
	NodoListaJugoEn* aux = p;
	
	while(aux != NULL && aux->info.id_jugador != id_jugador) {
		aux= aux->sig;
	}
	
	return aux;
}


bool jugoEnOtraSeleccion(int id_jugador, char pais[], NodoListaJugoEn* & listaJugoEn){
	
	bool jugoEnOtra = true;
	NodoListaJugoEn* nodoBuscado = buscar(listaJugoEn,id_jugador);
	
	if(strcmp(nodoBuscado->info.pais,pais) == 0 || nodoBuscado == NULL) {
		jugoEnOtra = false;
	}
	
	return jugoEnOtra;
}

NodoListaJugadores* buscar(NodoListaJugadores *p, int id_jugador){
	NodoListaJugadores* aux = p;
	
	while(aux != NULL && aux->info.id_jugador != id_jugador) {
		aux= aux->sig;
	}
	
	return aux;
}

bool puedeSerCitado(char pais[], int id_jugador, NodoListaJugadores* listaJugadores, NodoListaJugoEn* listaJugoEn){
	bool puedeSerCitadoAJugar = false;
	NodoListaJugadores* jugadorBuscado = buscar(listaJugadores,id_jugador);
	
	int edadCandidato = edadDelCandidato(jugadorBuscado->info.fecha_nacimiento);
	bool jugoEnOtra = jugoEnOtraSeleccion(id_jugador, pais, listaJugoEn);
	
	if(edadCandidato < 30 && !jugoEnOtra){
		puedeSerCitadoAJugar = true;
	}
	
	return puedeSerCitadoAJugar;
}

NodoPelicula* insertarOrdenado(NodoPelicula *&p, infoPeli v){
	
	NodoPelicula* nuevo = new NodoPelicula();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoPelicula * aux = p;
	NodoPelicula * ant = NULL;
	
	while(aux != NULL && aux->info.id_pelicula <= v.id_pelicula){
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

NodoPelicula* buscar(NodoPelicula *p, infoPeli v){
	NodoPelicula* aux = p;
	
	while(aux != NULL && aux->info.id_pelicula != v.id_pelicula) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoPelicula* buscaEInsertaOrdenado(NodoPelicula* &p, infoPeli v, bool & enc){
	
	NodoPelicula * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}



NodoEspectador* insertarOrdenado(NodoEspectador *&p, infoEspec v){
	
	NodoEspectador* nuevo = new NodoEspectador();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoEspectador * aux = p;
	NodoEspectador * ant = NULL;
	
	while(aux != NULL && aux->info.fecha <= v.fecha){
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

NodoEspectador* buscar(NodoEspectador *p, infoEspec v){
	NodoEspectador* aux = p;
	
	while(aux != NULL && aux->info.fecha != v.fecha) {
		aux= aux->sig;
	}
	
	return aux;
}


NodoEspectador* buscaEInsertaOrdenado(NodoEspectador* &p, infoEspec v, bool & enc){
	
	NodoEspectador * nodoBuscado = buscar(p,v);
	if(nodoBuscado== NULL) {
		enc = false;
		nodoBuscado = insertarOrdenado(p,v);
	} else {
		enc = true;
	}
	
	//enc = nodoBuscado == NULL ? false : true;
	
	return nodoBuscado;
}


void cargarListaDelMes(FILE* arch, NodoPelicula* &peliculas){
	entrada reg;
	bool enc;
	infoPeli ipeli;
	infoEspec iespec;
	
	fread(&reg,sizeof(entrada),1,arch);
	
	while(!feof(arch)){
		if(!reg.ind){  // chequear que no sea independiente
			ipeli.id_pelicula = reg.id_pelicula;
			strcpy(ipeli.nom_pelicula,reg.nom_pelicula);
			ipeli.espectadores = NULL;
			
			NodoPelicula* peliculaBuscada = buscaEInsertaOrdenado(peliculas,ipeli,enc);
			
			iespec.fecha = reg.fecha;
			iespec.dia = reg.dia;
			iespec.cantEspectadores = 0;
			
			NodoEspectador* fechaBuscada = buscaEInsertaOrdenado(peliculaBuscada->info.espectadores, iespec, enc);		
			
			fechaBuscada->info.cantEspectadores++;
		}
		
		fread(&reg,sizeof(entrada),1,arch);
	}
	
}

int cantidadTotalDeEspectadoresEnElMes(NodoPelicula* &peliculas){
	NodoEspectador* auxEspec;
	NodoPelicula* auxPeliculas = peliculas;
	int cant = 0;
	
	while(auxPeliculas != NULL){
		auxEspec = auxPeliculas->info.espectadores;
		while(auxEspec != NULL){
			cant += auxEspec->info.cantEspectadores;	
			auxEspec = auxEspec->sig;
		}
		auxPeliculas = auxPeliculas->sig;
	}
	
	return cant;
}

void ordenarVector(int vec[], int len){
	int temp; 
	
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len-1; j++){
			if(vec[j] < vec[j+1]){
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}
		}
		
	}
}


int diaQueMasGenteFueAlCine(NodoPelicula* &peliculas){
	int vec[7];
	int n = 7;
	int len = 7;
	
	for(int i=0; i < n; i++){
		vec[i] = 0;
	}
	
	NodoEspectador* auxEspec;
	NodoPelicula* auxPeliculas = peliculas;

	
	while(auxPeliculas != NULL){
		auxEspec = auxPeliculas->info.espectadores;
		while(auxEspec != NULL){
			vec[auxEspec->info.dia] += auxEspec->info.cantEspectadores;
			auxEspec = auxEspec->sig;
		}
		auxPeliculas = auxPeliculas->sig;
	}
	
	ordenarVector(vec,len);
	
	
	return vec[0];
}

void peliculaMasVista(NodoPelicula* &peliculas,char nombrePeliMasVista[]){
	NodoEspectador* auxEspec;
	NodoPelicula* auxPeliculas = peliculas;
	int cantEspecPeli;
	int maxCantEspec = 0;

	
	while(auxPeliculas != NULL){
		auxEspec = auxPeliculas->info.espectadores;
		cantEspecPeli = 0;
		while(auxEspec != NULL){
			cantEspecPeli += auxEspec->info.cantEspectadores;
			auxEspec = auxEspec->sig;
		}
		if(cantEspecPeli > maxCantEspec){
			maxCantEspec = cantEspecPeli;
			strcpy(nombrePeliMasVista,auxPeliculas->info.nom_pelicula);
		}
		auxPeliculas = auxPeliculas->sig;
	}
	
}

void push(Nodo* &pila, int v){
	
	Nodo * nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
	
}

int pop(Nodo*& pila){
	int resultado = pila->info;
	
	Nodo * aux = pila;
	pila = pila->sig;
	delete aux;
	
	return resultado;
}


void encolar(Nodo* & colafte, Nodo* & colafin, int v){
	Nodo * nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL) {
		colafte = nuevo;
	} else{
		colafin->sig = nuevo;
	}
	
	colafin = nuevo;
}

int desencolar(Nodo* &colafte, Nodo* &colafin){
	int resultado = colafte->info;
	
	Nodo* aux = colafte;
	colafte = colafte->sig;
	
	if(colafte == NULL){
		colafin = NULL;
	}
	
	delete aux;
	return resultado;
}

void agregarNodo(NodoProceso* &p, infoProceso x){
	
	NodoProceso* nuevo = new NodoProceso();
	nuevo->info = x;
	nuevo->sig = NULL;
	
	if(p==NULL){
		p=nuevo;
	} else {
		NodoProceso* aux = p;
	
		while(aux->sig != NULL){
			aux = aux->sig;
		}
	
		aux->sig = nuevo;
	}
	
};

infoProceso eliminarPrimerNodo(NodoProceso*& p){
	infoProceso resultado = p->info;
	
	NodoProceso* aux = p;
	p = p->sig;
	delete aux;
	
	return resultado;
}

void encolar(NodoProceso* & colafte, NodoProceso* & colafin, infoProceso v){
	NodoProceso * nuevo = new NodoProceso();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL) {
		colafte = nuevo;
	} else{
		colafin->sig = nuevo;
	}
	
	colafin = nuevo;
}

infoProceso desencolar(NodoProceso* & colafte, NodoProceso* & colafin){
	infoProceso resultado = colafte->info;
	
	NodoProceso* aux = colafte;
	colafte = colafte->sig;
	
	if(colafte == NULL){
		colafin = NULL;
	}
	
	delete aux;
	return resultado;
}

void ordenarVector(Servidor vec[], int len){
	Servidor temp; 
	
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len-1; j++){
			if(vec[j].sumConsumoCPU > vec[j+1].sumConsumoCPU){
				temp = vec[j+1];
				vec[j+1] = vec[j];
				vec[j] = temp;
			}
		}
		
	}
}

void encolar(NodoFamilia* & colafte, NodoFamilia* & colafin, infoFamilia v){
	NodoFamilia * nuevo = new NodoFamilia();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	if(colafte == NULL) {
		colafte = nuevo;
	} else{
		colafin->sig = nuevo;
	}
	
	colafin = nuevo;
}

infoFamilia desencolar(NodoFamilia* & colafte, NodoFamilia* & colafin){
	infoFamilia resultado = colafte->info;
	
	NodoFamilia* aux = colafte;
	colafte = colafte->sig;
	
	if(colafte == NULL){
		colafin = NULL;
	}
	
	delete aux;
	return resultado;
}

void push(NodoProducto* &pila, infoProducto v){	
	NodoProducto * nuevo = new NodoProducto();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
}
infoProducto pop(NodoProducto*& pila){
	infoProducto resultado = pila->info;
	
	NodoProducto * aux = pila;
	pila = pila->sig;
	delete aux;
	
	return resultado;
}

NodoProducto* insertarOrdenado(NodoProducto *&p, infoProducto v){
	NodoProducto* nuevo = new NodoProducto();
	nuevo->info = v;
	nuevo->sig = NULL;
	
	NodoProducto * aux = p;
	NodoProducto * ant = NULL;
	
	while(aux != NULL && aux->info.fecha >= v.fecha){
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

infoProducto eliminarPrimerNodo(NodoProducto*& p){
	infoProducto resultado = p->info;
	
	NodoProducto* aux = p;
	p = p->sig;
	delete aux;
	
	return resultado;
}

void agregarNodo(NodoProductoDeposito* &p, infoProductoDeposito x){
	NodoProductoDeposito* nuevo = new NodoProductoDeposito();
	nuevo->info = x;
	nuevo->sig = NULL;
	
	if(p==NULL){
		p=nuevo;
	} else {
		NodoProductoDeposito* aux = p;
	
		while(aux->sig != NULL){
			aux = aux->sig;
		}
	
		aux->sig = nuevo;
	}
}
infoProductoDeposito pop(NodoProductoDeposito*& pila){
    infoProductoDeposito resultado = pila->info;
	
	NodoProductoDeposito * aux = pila;
	pila = pila->sig;
	delete aux;
	
	return resultado;
}
void push(NodoProductoDeposito* &pila, infoProductoDeposito v){
	NodoProductoDeposito * nuevo = new NodoProductoDeposito();
	nuevo->info = v;
	nuevo->sig = pila;
	pila = nuevo;
}

NodoProductoDeposito* buscar(NodoProductoDeposito *p, infoProductoDeposito v){
	NodoProductoDeposito* aux = p;
	
	while(aux != NULL && aux->info.id != v.id) {
		aux= aux->sig;
	}
	
	return aux;
}
