#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

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

int main(int argc, char** argv) {
	
	//Final Seguimiento de Jugadores
	/* 
	FILE* jugadores = fopen("nominaDeJugadores.dat","rb");
	FILE* jugo_en_seleccion = fopen("seleccionDondeJugo.dat","rb");
	
	NodoListaJugadores* listaJugadores = NULL;
	NodoListaJugoEn* listaJugoEn = NULL;
	
	cargarDatosEnMemoria(jugadores,jugo_en_seleccion, listaJugadores,listaJugoEn);

	fclose(jugadores);
	fclose(jugo_en_seleccion);
	
	if(puedeSerCitado("Uruguay",9,listaJugadores,listaJugoEn)){
		cout << "El jugador puede ser citado" << endl;
	} else {
		cout << "El jugador NO puede ser citado" << endl;
	}
	*/
	
	//Final Cine
	/*FILE* arch = fopen("entradasNoviembre.dat","rb");
	NodoPelicula* peliculas = NULL;
	
	cargarListaDelMes(arch,peliculas);
	fclose(arch);
	
	cout << "La cantidad de espectadores en el mes fue " <<
	cantidadTotalDeEspectadoresEnElMes(peliculas) << endl;
	
	int dia = diaQueMasGenteFueAlCine(peliculas);
	
	switch(dia){
		case 0:
			cout << "Domingo"<< endl;
			break;
		case 1:
			cout << "Lunes"<< endl;
			break;
		case 2:
			cout << "Martes"<< endl;
			break;
		case 3:
			cout << "Miercoles"<< endl;
			break;
		case 4:
			cout << "Jueves"<< endl;
			break;
		case 5:
			cout << "Viernes"<< endl;
			break;
		case 6:
			cout << "Sabado" << endl;
			break;			
	}
	
	char nombrePeliMasVista[50];
	peliculaMasVista(peliculas,nombrePeliMasVista);
	
	cout << "La peli mas vista fue " << nombrePeliMasVista << endl;
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
