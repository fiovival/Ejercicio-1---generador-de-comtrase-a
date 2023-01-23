#include"Contraseña.h"
#include <conio.h>
#include<time.h>
void main() {
	srand(time(0));//
	Contraseña* objcontra = new Contraseña(100);
	//objcontra->setlongitud(20);
	bool *arreglo = new bool[5];
	for (int i = 0; i < 5; i++){
		objcontra->generar();
		cout << objcontra->getcontra() << endl;
		if (objcontra->esseguro())arreglo[i] = 1;
		else arreglo[i] = 0;
		cout << objcontra->esseguro() << endl;
	}
	delete[] arreglo;
	delete objcontra;
	_getch();
}