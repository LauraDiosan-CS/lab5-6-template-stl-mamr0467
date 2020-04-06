#pragma once
#include <ostream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iostream>
using namespace std;
#ifndef ZBOR_H
#define ZBOR_H
class Produs {
private:
	// Ceea din ce este constituit examenul (tip sir de caractere ->nume,tip int data si nota*)
	char* nume;
	int pret;
	int nr_exemplare;

public:
	// constructor fara parametrii(explicit se mai numeste daca nu gresesc)
	Produs();
	// constructor cu parametrii
	Produs(const char*, int, int);
	// constructor de copiere
	Produs(const Produs&);
	Produs(string);
	//Rezervare(string);//constructor de conversie
	char* getNume();
	int getPreturi();
	int getNrExemplare();
	// Setteri 
	void setNume(const char*);
	void setPret(int);
	void setNrExemplare(int);
	// Destructorul (Dupa ce te folosesti de ceva si numai ai absolut nevoie de el ->se va sterge ,cam asta e traducerea)
	~Produs();
	// operator de atribuire
	Produs& operator=(const Produs&);
	// Compara 2 examene!(Intr-un fel si asta poate fi ca cei de mai sus!)
	bool operator==(const Produs& e) const;
	// Compara 2 examene!(Intr-un fel si asta poate fi ca cei de mai sus!)
	bool operator!=(const Produs& e) const;
	// Operator folosit doar pentru a specifia ca nota e1 != nota e2
	bool compare(Produs& e) const;
	bool operator<(const Produs&) const;
	char* toString();
	friend ostream& operator<<(ostream&, Produs&);
	friend istream& operator>>(istream&, Produs&);
};

#endif

