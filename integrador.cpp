#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Estructuras
struct t_esc_nombres{
	int anio;
	string nombre;
};// Estructura de archivo_nombres

struct t_esc_ciudades{
	string nombre;
	string ciudad;
};// Estructura de archivo_ciudades

struct t_escritura{
	int anio;
	string nombre;
	string ciudad;
};// Estructura general de escritura de archivo

struct Nodo_ciudades{
	t_esc_ciudades info;
	Nodo_ciudades *nodo_sgt;
};// Estructura nodo ciudades para usar en COLAS

struct Nodo_nombres{
	t_esc_nombres info;
	Nodo_nombres *nodo_sgt;	
};// Estructura nodo nombres para usar en PILAS

//Prototipos de funciones
template <typename TIPOD>
int fileSize(FILE *&,char [],TIPOD); //Calcular el tamanio del archivo leido

void agregarNombresPila(Nodo_nombres *&, t_esc_nombres);
void sacarNombresPila(Nodo_nombres *&,t_esc_nombres &);
void insertarCiudadCola(Nodo_ciudades *&, Nodo_ciudades *&, t_esc_ciudades);
void eliminarCiudadCola(Nodo_ciudades *&, Nodo_ciudades *&, t_esc_ciudades &);
bool esVacia(Nodo_ciudades *);

int main(){
	int t_max = 4;
	t_escritura vector[t_max];
	cout << "\t\t\tCOMIENZO DE CARGA DE DATOS" << endl;
	for(int i = 0; i<t_max; i++){
		cout << "Ingrese el anio: ";
		cin >> vector[i].anio;
		cout << "Ingrese el nombre: ";
		cin >> vector[i].nombre;
		cout << "Ingrese la ciudad: ";
		cin >> vector[i].ciudad;
	}
	cout << "\n\t\t\tPROCESANDO DATOS" << endl;
	//Escritura del archivo
	FILE *archivo = fopen("archivo.dat","wb");
	for(int i = 0; i< t_max;i++){
		fwrite(&vector[i],sizeof(t_escritura),1,archivo);
	}
	fclose(archivo);
	
	//Calcular tamanio archivo
	char filename[] = "archivo.dat";
	int sz_archivo = fileSize(archivo,filename,vector[0]);
	cout << "file size: " << sz_archivo << endl;


	t_escritura vector_lectura[sz_archivo];
	
	//Lectura del archivo
	fopen("archivo.dat","rb");
	int i = 0;
	fread(&vector[i],sizeof(t_escritura),1,archivo);
	while(!feof(archivo)){
		cout << "Anio: " << vector[i].anio << " - Nombre: " << vector[i].nombre << " - Ciudad: " << vector[i].ciudad << endl;
		vector_lectura[i].anio = vector[i].anio;
		vector_lectura[i].nombre = vector[i].nombre;
		vector_lectura[i].ciudad = vector[i].ciudad;
		i++;
		fread(&vector[i],sizeof(t_escritura),1,archivo);
	}
	fclose(archivo);
	
	cout << "Impresion desde vector_lectura" << endl;
	for(int i = 0;i< sz_archivo; i++){
		cout << vector_lectura[i].anio << " - " << vector_lectura[i].nombre << " - " << vector_lectura[i].ciudad << endl;
	}
	
	//Ordenar vector_lectura por anio
	for(int i = 0;i<sz_archivo;i++){
		for(int j = 0;j<sz_archivo;j++){
			if(vector_lectura[j].anio > vector_lectura[i].anio){
				swap(vector_lectura[j],vector_lectura[i]);
			}
		}
	}
	cout << "Ordenado por anio vector_lectura" << endl;
	for(int i = 0;i< sz_archivo; i++){
		cout << vector_lectura[i].anio << " - " << vector_lectura[i].nombre << " - " << vector_lectura[i].ciudad << endl;
	}
	// Creacion de dos archivos uno con el nombre y anio y el otro con nombre y ciudad para luego realizar apareo de archivos
	FILE *archivo_nombres = fopen("nombres.dat","wb");
	FILE *archivo_ciudades = fopen("ciudades.dat","wb");
	
	t_esc_nombres arch_nombres;
	t_esc_ciudades arch_ciudades;
	
	for(int i = 0; i< sz_archivo;i++){
		arch_nombres.anio = vector_lectura[i].anio;
		arch_nombres.nombre = vector_lectura[i].nombre;
		arch_ciudades.ciudad = vector_lectura[i].ciudad;
		arch_ciudades.nombre = vector_lectura[i].nombre;
		fwrite(&arch_nombres,sizeof(t_esc_nombres),1,archivo_nombres);
		fwrite(&arch_ciudades,sizeof(t_esc_ciudades),1,archivo_ciudades);
	}
	fclose(archivo_nombres);
	fclose(archivo_ciudades);
	
	//Calcular tamanio archivo nombres
	char file_nombres[] = "nombres.dat";
	int sz_nombres = fileSize(archivo_nombres,file_nombres,arch_nombres);
	cout << "Sizeof archivo nombres: " << sz_nombres << endl;

	//Calcular tamanio archivo ciudades
	char file_ciudades[] = "ciudades.dat";
	int sz_ciudades = fileSize(archivo_ciudades,file_ciudades,arch_ciudades);
	cout << "Sizeof archivo ciudades: " << sz_ciudades << endl;
	
	//Lectura archivo nombres
	cout << "LECTURA NOMBRES.DAT ------------"<< endl;
	fopen("nombres.dat","rb");
	fread(&arch_nombres,sizeof(t_esc_nombres),1,archivo_nombres);
	while(!feof(archivo_nombres)){
		cout << arch_nombres.anio << " - " << arch_nombres.nombre << endl;
		fread(&arch_nombres,sizeof(t_esc_nombres),1,archivo_nombres);
	}
	fclose(archivo_nombres);
	
	//Lectura archivo ciudades
	cout << "LECTURA CIUDADES.DAT ------------"<< endl;
	fopen("ciudades.dat","rb");
	fread(&arch_ciudades,sizeof(t_esc_ciudades),1,archivo_ciudades);
	while(!feof(archivo_ciudades)){
		cout << arch_ciudades.ciudad << " - " << arch_ciudades.nombre << endl;
		fread(&arch_ciudades,sizeof(t_esc_ciudades),1,archivo_ciudades);
	}
	fclose(archivo_ciudades);
	
	//lectura archivo nombres y agregar a pila
	cout << "Agregando elementos a la pila" << endl;
	Nodo_nombres *pila = NULL;
	t_esc_nombres nombres_pila;
	fopen("nombres.dat","rb");
	fread(&nombres_pila,sizeof(t_esc_nombres),1,archivo_nombres);
	while(!feof(archivo_nombres)){
		agregarNombresPila(pila,nombres_pila);
		fread(&nombres_pila,sizeof(t_esc_nombres),1,archivo_nombres);
	}
	fclose(archivo_nombres);
	
	cout << "Sacando elementos de la pila"<< endl;
	while(pila != NULL){
		sacarNombresPila(pila,nombres_pila);
		cout << "anio: " << nombres_pila.anio << " nombre: " << nombres_pila.nombre << endl;
		/*
		if(pila != NULL){
			cout << "anio: " << nombres_pila.anio << " nombre: " << nombres_pila.nombre << endl;
		}else{
			cout << "anio: " << nombres_pila.anio << " nombre: " << nombres_pila.nombre << endl;
		}
		*/
	}
	
	//lectura archivo ciudades y agregar a pila
	cout << "Agregando elementos a la cola" << endl;
	Nodo_ciudades *inicio = NULL;
	Nodo_ciudades *fin = NULL;
	t_esc_ciudades ciudades_cola;
	fopen("ciudades.dat","rb");
	fread(&ciudades_cola,sizeof(t_esc_ciudades),1,archivo_ciudades);
	while(!feof(archivo_ciudades)){
		insertarCiudadCola(inicio,fin,ciudades_cola);
		fread(&ciudades_cola,sizeof(t_esc_ciudades),1,archivo_ciudades);
	}
	fclose(archivo_ciudades);
	cout << "Sacando elementos de la cola" << endl;
	while(inicio!=NULL){
		eliminarCiudadCola(inicio,fin,ciudades_cola);
		cout << ciudades_cola.ciudad << " - " << ciudades_cola.nombre;
		/*
		if(inicio != NULL){
			cout << ciudades_cola.ciudad << " - " << ciudades_cola.nombre;
		}else{
			cout << dato << " . ";
		}
		*/
	}
	
	
	return 0;
}

template <typename TIPOD>
int fileSize(FILE *&archivo,char filename[], TIPOD t_struct){
	int p_ini, p_fin, t_arch; 					//Defino 3 variables de tipo int
	cout << "filename: " << filename << endl;   //Imprimo el nombre del archivo
	archivo = fopen(filename,"rb");				//Abro el archivo en modo lectura binario
	p_ini = ftell(archivo);						//Guardo la posicion inicial del puntero
	fseek(archivo,0,SEEK_END);					//Posiciono el puntero al final del archivo
	p_fin = ftell(archivo);						//Guardo la posicion final del puntero
	fseek(archivo,p_ini,SEEK_SET);				//Posiciono el puntero al inicio del archivo nuevamente
	t_arch = p_fin/sizeof(t_struct);			//Calculo el tamanio del archivo
	fclose(archivo);							//Cierro el archivo
	return t_arch;								//Devuelvo el tamanio del archivo
}

void agregarNombresPila(Nodo_nombres *&pila, t_esc_nombres dato){
	Nodo_nombres *nuevo_nodo = new Nodo_nombres();
	nuevo_nodo->info = dato;
	nuevo_nodo->nodo_sgt = pila;
	pila = nuevo_nodo;
	cout << "Elemento " << dato.anio << " - " << dato.nombre << " agregado correctamente" << endl;
}

void sacarNombresPila(Nodo_nombres *&pila, t_esc_nombres &dato){
	Nodo_nombres *nuevo_nodo = pila;
	dato = nuevo_nodo->info;
	pila = nuevo_nodo->nodo_sgt;
	delete nuevo_nodo;
	
}

void insertarCiudadCola(Nodo_ciudades *&inicio, Nodo_ciudades *&fin, t_esc_ciudades dato){
		
	Nodo_ciudades *nuevo_nodo = new Nodo_ciudades();
	
	nuevo_nodo->info = dato;
	nuevo_nodo->nodo_sgt = NULL;
	
	if(esVacia(inicio)){
		inicio = nuevo_nodo;
	}else{
		fin->nodo_sgt = nuevo_nodo;
	}
	fin = nuevo_nodo;

	cout << "Elemento " << dato.ciudad << " - " << dato.nombre << " ingresado correctamente" << endl;
}
void eliminarCiudadCola(Nodo_ciudades *&inicio, Nodo_ciudades *&fin, t_esc_ciudades &dato){

	dato = inicio->info;
	Nodo_ciudades *aux_nodo = inicio;
	
	if(inicio == fin){
		inicio = NULL;
		fin = NULL;
	}else{
		inicio = inicio->nodo_sgt;
	}
	delete aux_nodo;
}

bool esVacia(Nodo_ciudades *inicio){
	return (inicio==NULL) ? true : false;
}
