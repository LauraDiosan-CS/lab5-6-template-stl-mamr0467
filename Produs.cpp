#include "Produs.h"
#include <string.h>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdlib.h>
//#include "Rezervare.h"


using namespace std;
Produs::Produs() {
	// initializare,constructor implicit
	this->nume = NULL;
	this->pret = 0;
	this->nr_exemplare = 0;
}
Produs::Produs(const char* nume, int pret, int nr_exemplare) {
	// daca pun const aici ..voi putea creea la teste fara sa copiez totul intr-o variabila!IN caz contrar,nu!
	// contructor cu parametri
	//  new char[strlen(nume)+1 ...Acel new apare din cauza ca dupa cum vedem avem un pointer,strlen(nume)+1 ->lungimea numelui +1 (adica abc -> str(len)+1=4 acel "+1" ->backslash*"
	// Dupa ce scriem prima linie de cod din interior trebuie sa aplicam strcpy_s -> si doar asa reusim sa specificam ca this->nume = nume*
	// strcpy(destinatie,lungime,ceea ce trebuie sa ajunga la destinatie(sa fie aceasta daca e sa o luam asa!)
	// strcpy se aplica aici pentru ca avem un sir de caractere ca parametru 
	//Ca la vectori dinamici ,alocam spatiu care ulterior daca nu gresesc se va dealoca in destructor*
	//Alocarea are loc prin prima linie de cod * ,iar strcpy ->copiem nume in this->nume*
	// la int nu se aplica acelas rationament!
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->pret = pret;
	this->nr_exemplare = nr_exemplare;
}
Produs::Produs(const Produs& e) {
	// Constructorul de copiere , primele 2 linii de cod identice cu cele de la  constructorul cu parametrii
	// doar ca aici avem un Examen e  si this->nume va vrea sa-i ia numele acestuia si de aceea acolo avem e.nume*
	// this->data = e.data (data examenului e *)
	//cout << "copy constructor" << endl;
	this->nume = new char[strlen(e.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(e.nume), e.nume);
	this->pret = e.pret;
	this->nr_exemplare = e.nr_exemplare;
}

Produs::Produs(string linie)
{
	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	nume = new char[tok1.length() + 1];
	strcpy_s(nume, tok1.length() + 1, tok1.c_str());
	pret = stoi(tok2);
	nr_exemplare = stoi(tok3);
}

//Geteri
//   Voi explica la teste importanta lor *!


char* Produs::getNume() {
	return this->nume;
}

int Produs::getPreturi() {
	return this->pret;
}

int Produs::getNrExemplare() {
	return this->nr_exemplare;
}

//Seteri


void Produs::setNume(const char* nume) {
	// Dezalocare(pentru ca s-ar putea sa existe un nume(in general exista)
	if (this->nume != NULL) {
		delete[] this->nume;
	}
	// realocare si copierea noului nume in this->nume
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

}

void Produs::setPret(int pret) {
	this->pret = pret;
}

void Produs::setNrExemplare(int nr_exemplare) {
	this->nr_exemplare = nr_exemplare;
}
char* Produs::toString() {
	if (this->nume != NULL) {
		size_t noChars = strlen(this->nume) + 13;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[5];
		strcpy_s(s, noChars, this->nume);
		strcat_s(s, noChars, " ");
		_itoa_s(this->pret, aux2, 5, 10);
		_itoa_s(this->nr_exemplare, aux, 5, 10);
		strcat_s(s, noChars, aux2);
		strcat_s(s, noChars, " ");
		strcat_s(s, noChars, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		strcat_s(s, noChars, " ");
		return s;
	}
	else
	{
		char* x = new char[1];
		strcpy_s(x, 1, "");
		return x;
	}
}


Produs& Produs::operator=(const Produs& e) {
	// Aici daca nu gresesc totusi nu e vorba de egalitate si de operatorul de atribuire!(lui this ii se atribuie ceva nou(cu ajutorul Seterilor)!
	this->nume = e.nume;
	this->pret = e.pret;
	this->nr_exemplare = e.nr_exemplare;
	// return *this ->valoarea adresei respective
	return *this;
}


Produs::~Produs() {
	//Destructor (Dupa ce folosim Examenul la ce trebuie , facem putin loc in memorie)
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->pret = 0;
	this->nr_exemplare = 0;
}
// Compararea ( verificarea egalitatii dintre Examenul curenta si o a doua Examenul)
bool  Produs::compare(Produs& e) const{
	// verificarea data this->examen este egal cu examenul e 
	return ((this->pret == e.pret) && (strcmp(this->nume, e.nume) == 0) && (this->nr_exemplare == e.nr_exemplare));
}

bool Produs::operator<(const Produs& e) const
{
	//return ((strcmp(this->nume, e.nume) < 0) && (this->pret < e.pret) && (this->nr_exemplare < e.nr_exemplare));
	if (strcmp(this->nume, e.nume) < 0)
		return true;
	else if (strcmp(this->nume, e.nume) > 0)
		return false;
	else {
		if (this->pret < e.pret)
			return true;
		else if (this->pret > e.pret)
			return false;
		else {
			if (this->nr_exemplare < e.nr_exemplare)
				return true;
			else if (this->nr_exemplare > e.nr_exemplare)
				return false;
			else
				return true;
		}
	}
}


bool Produs:: operator==(const Produs& e) const{
	// la fel ca mai sus * (egalitate)
	return strcmp(this->nume, e.nume) == 0 && this->pret == e.pret && this->nr_exemplare == e.nr_exemplare;
}

bool Produs:: operator!=(const Produs& e) const{

	return strcmp(this->nume, e.nume) == 0 && this->pret == e.pret && this->nr_exemplare != e.nr_exemplare;

}

ostream& operator<<(ostream& os, Produs& e) {
	os << e.nume << " " << e.pret << " " << e.nr_exemplare << '\n';

	return os;
}

istream& operator>>(istream& is, Produs& e)
{
	cout << "Dati numele: ";
	char* nume = new char[20];
	//char nume[20];
	//is.get(nume,20);
	//cin.get(nume,19);
	cin >> nume;
	cout << "Dati pret: ";
	int pret;
	cin >> pret;
	cout << "Dati nr_exemplare:";
	int nr_exemplare;
	cin >> nr_exemplare;
	e.setNume(nume);
	e.setPret(pret);
	e.setNrExemplare(nr_exemplare);
	delete[] nume;
	return is;
}
