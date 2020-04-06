#include "testRepo.h"
#include <set>
#include<cassert>
#include<iostream>
#include<string.h>
#include "Repo.h"
#include "Produs.h"
using namespace std;

void testRepo()
{
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
}

void testRepo2() {
	Repo<Produs> r2;
	char* auxx = new char[6];
	strcpy_s(auxx, 6, "cornx");
	Produs x = Produs(auxx, 11, 25);
	r2.addElem(x);
	assert(r2.getSize() == 1);
	Produs x1 = Produs(auxx, 11, 11);
	r2.addElem(x1);
	assert(r2.getSize() == 2);
	Produs x2 = Produs(auxx, 22, 22);
	r2.addElem(x2);
	assert(r2.getSize() == 3);
	r2.del(x1);
	set<Produs> rezx;
	rezx = r2.GetAll();
	assert(rezx.size() == 2);
	//assert(r2.findElem(x) == 0);
	r2.del(x);
	set<Produs> rezxx;
	rezxx = r2.GetAll();
	assert(rezxx.size() == 1);
	r2.del(x2);
	set<Produs> rexxx;
	rexxx = r2.GetAll();
	assert(rexxx.size() == 0);



	cout << "teste Repo2" << endl;


}

void testRepo3()
{
	Repo<Produs> r3;
	char* auxx = new char[7];
	strcpy_s(auxx, 7, "Darius");
	Produs x = Produs(auxx, 20, 20);
	assert(x.getPreturi() == 20);
	assert(x.getNrExemplare() == 20);
	r3.addElem(x);
	assert(r3.getSize() == 1);
	assert(r3.findElem(x) != -1);
	Produs y = Produs(auxx, 30, 40);
	assert(r3.getSize() == 1);
	assert(r3.findElem(y) == -1);
	assert(r3.findElem(Produs("Darius", 20, 20)) != -1);
	assert(r3.findElem(Produs("Marian", 21, 23)) == -1);
	r3.updateElem(x, y);
	set<Produs> rev;
	rev = r3.GetAll();
	assert(rev.size() == 1);
	cout << "teste Repo3" << endl;
}