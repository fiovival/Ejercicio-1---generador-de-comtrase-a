#pragma once
#include<iostream>
using namespace std;
class Contraseña{
public:
	Contraseña();
	Contraseña(int longi);
	~Contraseña();
	//metodos de acceso  get    set
	int getlongitud();
	void setlongitud(int dato);
	void generar();
	bool esseguro();
	char* getcontra();
private:
	char* contra;
	int longitud;
};
Contraseña::Contraseña() {//constructor -> se encarga de crear un objeto
	contra = nullptr;
	longitud = 8;
}
Contraseña::Contraseña(int longi) {
	longitud = longi;
	contra = nullptr;
}
Contraseña::~Contraseña(){//destrructor->elimina el objeti-> delete auotllamado
	if (contra != nullptr)delete[] contra;
}
int Contraseña::getlongitud() { return longitud; } //get->  nos informa del dato
void Contraseña::setlongitud(int dato) { longitud = dato; }// set cambia el dato
void Contraseña::generar() {
	if (contra != nullptr)delete[]contra;
	contra = new char[longitud];
	for (int i = 0; i < longitud; i++){
		//rand()%+(max - min +1) + min;
		contra[i] = rand() % (250-5+1) + 5;
		//contra[i] = rand() % ('Z' - 'A' + 1) + 'A';
	}
}
bool Contraseña::esseguro() { //2 mayusculas, mas de 1 minuscula y mas de 5 numeros
	int cont1 = 0, cont2 = 0, cont3 = 0;
	for (int i = 0; i < longitud; i++){
		if (contra[i] <= 'Z' && contra[i] >= 'A')cont1++;
		if (contra[i] <= 'z' && contra[i] >= 'a')cont2++;
		if (contra[i] <= '9' && contra[i] >= '0')cont3++;
	}
	return cont1 > 2 && cont2 > 1 && cont3 > 5;
}

char* Contraseña::getcontra() {
	return contra;
}