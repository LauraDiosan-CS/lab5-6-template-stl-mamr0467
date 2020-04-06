#include "testeRepoFile.h"
#include <set>
#include<cassert>
#include<iostream>
#include<string.h>
#include "RepoFile.h"
#include "Produs.h"
using namespace std;

void testRFile()
{
	RepoFile<Produs> r;
	char* aux = new char[5];
	strcpy_s(aux, 5, "corn");
	Produs p = Produs(aux, 11, 25);
	r.addElem(p);
	/*
	Repo<Produs> r;
	set<Produs> rez;
	rez = r.GetAll();
	assert(rez.size() == 0);
	char* aux = new char[5];
	strcpy_s(aux, 5, "corn");
	Produs p = Produs(aux, 11, 25);
	r.addElem(p);
	rez.insert(p);
	Produs p1 = Produs(aux, 11, 11);
	r.addElem(p1);
	rez.insert(p1);
	Produs p2 = Produs(aux, 22, 22);
	r.addElem(p2);
	rez.insert(p2);
	assert(r.findElem(p1) == 0);
	assert(r.getSize() == 3);
	assert(rez.size() == 3);
	// se pastreaza elementele adaugate in lista
	cout << "teste Repo" << endl;
	*/
}

