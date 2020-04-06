#include "UI.h"
#include "Service.h"
#include <iostream>
using namespace std;

void addProd(Service& s) {
	Produs pr;
	cout << "Dati Produsul:";
	cin >> pr;
	s.addProdus(pr);
	cout << "Produsul a fost adaugat cu succes!" << endl;
}

void findProd(Service& serv) {
	Produs pr;
	cout << "Dati produsul:";
	cin >> pr;
	int rez = serv.findOne(pr);
	if (rez != -1)
		cout << "Pozitia produsului este:" << rez;
	else
		cout << "Produsul nu se afla in lista.";
}



void delProd(Service& serv) {
	Produs re;
	cout << "Dati produsului:" << endl;
	cin >> re;
	serv.delProdus(re);
	cout << "Produsul sters" << endl;
}

void showAll(Service& serv) {
	set<Produs> re = serv.getAll();
	for (Produs r : re)
		cout << r;
	
	
}

void updateProdus(Service& serv) {
	Produs pr;
	cout << "Dati Produsul de modificat:" << endl;
	cin >> pr;
	char* newnume = new char[25];
	cout << "Noul nume:" << endl;
	cin >> newnume;
	int newPret;
	cout << "Noul pret:" << endl;
	cin >> newPret;
	int newNr_exemplare;
	cout << "Noul numar de exemplare:" << endl;
	cin >> newNr_exemplare;
	serv.update(pr, newnume, newPret, newNr_exemplare);
}



void cumparare(Service& s){
	char** mat = new char* [100];
	int sir[100];
	int n = 0; 
	for (int i = 0; i < 99; i++) {
		mat[i] = new char[20];
	}
	cout << "Introduceti exit pt a iesi" << '\n';
	while (true) {
		cout << "Nume: " << '\n';
		
		cin >> mat[n];
		if (strcmp(mat[n], "exit") == 0)
			break;
		cout << "Cantitate:" << '\n';
		cin >> sir[n];
		n++;
	}
	set<Produs> lst = s.getAll();
	for (int i = 0; i < n; i++) {
		bool ok = 0;
		set<Produs>::iterator it = lst.begin();
		for (it = lst.begin(); it != lst.end(); it++) {
			Produs p = *it;
			if (strcmp(p.getNume(), mat[i]) == 0) {
				if (p.getNrExemplare() >= sir[i]) {
					ok = 1;
					s.update(p, p.getNume(), p.getPreturi(), p.getNrExemplare() - sir[i]);
				}
				else {
					ok = 1;
					cout << "Nu exista suficiente exemplare pentru " << p.getNume() << '\n';
				}
			}
		}
			if (ok == 0)
				cout << "Nu exista produsul  " << mat[i] << '\n';
			
		 
		

	}

		for (int i=0; i<99; i++)
		{
			delete[] mat[i];
		}
	delete[] mat;
}


void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga produs " << endl;
		cout << "	2. Cauta produs " << endl;
		cout << "	3. Sterge produs " << endl;
		cout << "	4. Afiseaza toate produsele " << endl;
		cout << "	5. Modifica produs " << endl;
		cout << " 6. cCumpara produse" << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addProd(serv); break; }
		case 2: {findProd(serv); break; }
		case 3: {delProd(serv); break; }
		case 4: {showAll(serv); break; }
		case 5: {updateProdus(serv); break; }
		case 6: {cumparare(serv); break; }
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		}
	}
}