#include "Produs.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <cstring>
#include "testProduse.h"

using namespace std;

void teste2() {


	Produs e1 = Produs();
	// Aici se folosesc acele geturi care ne ajuta sa determinam ceea ce ne intereseaza(data examenului de exemplu)!
	// Examenului e1 ii se atribuie constructorul fara parametrii deci e1.getNume este egal cu NUll si int-urile cu 0!
	assert(e1.getNume() == NULL);
	assert(e1.getPreturi() == 0);
	assert(e1.getNrExemplare() == 0);


	char* x = new char[10];
	//alocare dinamica ,aici vom cuprinde numele Darius
	// il vom copia in x
	strcpy_s(x, 7, "Darius");
	Produs e2 = Produs(x, 30, 8);
	// Examen e2 primeste Examen(x , 30 ,8) , x= numele =Darius, 30 = data,8 -nota
	assert(strcmp(e2.getNume(), x) == 0);
	// in loc de x aici se poate pune si "Darius"
	// strcmp(e2.getNume(),x) == 0 -> asta inseamna ca numele este chiar Darius!
	// Nu se pune assert(e2.getNume() == Darius! gresit total,acesta fiind retinut intr-un this care este x...si asta este forma,nu stiu sa explic corect si nu ma bag,doar sa stii ca unde ai sir de caractere asa faci!)
	assert(e2.getPreturi() == 30);
	//  Data ne asteptam sa fie 30 
	assert(e2.getNrExemplare() == 8);
	// Nota ne asteptam sa fie 8 
	assert(strcmp(e2.toString(), "Darius 30 8 ") == 0);
	Produs e3 = Produs(e2);
	// Examenul e3 primeste  Examen(e2)
	assert(strcmp(e3.getNume(), "Darius") == 0);
	// Se poate pune si x in loc de "Darius"
	// Ne asteptam ca numele de la examenul al studentului sa fie chiar Darius
	assert(e3.getPreturi() == 30);
	assert(e3.getNrExemplare() == 8);
	assert(strcmp(e3.toString(), "Darius 30 8 ") == 0);
	// Observam ca e2 are aceleasi valori ca e3 ,deci sunt egale!
	assert(e2.compare(e3) == true);
	assert(e2 == e3);
	assert(strcmp(e3.getNume(), e2.getNume()) == 0);

	e3.setPret(25);
	// Setam o noua data la examenul 3,astfel e3.getData() == va deveni 25
	assert(e3.getPreturi() == 25);
	// Din cauza schimbarii datii  ,e2 != e3
	assert(e2.compare(e3) == false);
	assert(strcmp(e3.toString(), "Darius 25 8 ") == 0);

	cout << "teste" << endl;
}
