#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct t_lectura{
	string tipo;
	int monto;
};

int main(){
	
	FILE *archivo = fopen("facturas.dat","wb");
	t_lectura escritura;
	
	for(int i = 0; i<4; i++){
		cout << "Ingrese tipo: ";
		cin >> escritura.tipo;
		cout << "Ingrese monto: ";
		cin >> escritura.monto;
		fwrite(&escritura,sizeof(t_lectura),1,archivo);
	}
	fclose(archivo);

	
	fopen("facturas.dat","rb");
	t_lectura lectura;
	int imp_total = 0;
	int imp_factura = 0;
	string anterior = lectura.tipo;
	fread(&lectura,sizeof(t_lectura),1,archivo);
	while(!feof(archivo)){
		imp_total += lectura.monto;
		while(anterior == lectura.tipo){
			imp_factura += lectura.monto;
			anterior = lectura.tipo;
		}
		
		cout << "Anterior " << anterior << " lectura.tipo " << lectura.tipo << endl;
		cout << "Importe de la factura: " << lectura.tipo << " - Monto: " << lectura.monto<< endl;
		fread(&lectura,sizeof(t_lectura),1,archivo);
	}
	cout << "Importe total: " << imp_total << endl;
	fclose(archivo);
	
	
	return 0;
}
