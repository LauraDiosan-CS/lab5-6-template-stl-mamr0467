#include "testService.h"
#include <assert.h>
#include <iostream>
using namespace std;



void TestService::test1()
{
	Service r;
	assert(r.getSize() == 0);
	Produs r1("Darius", 20, 30);
	r.addProdus(r1);
	assert(r.getSize() == 1);
	Produs r2("Maria", 32, 10);
	r.addProdus(r2);
	assert(r.getSize() == 2);
	Produs r3("Marcel", 40, 50);
	r.addProdus(r3);
	assert(r.getSize() == 3);
	assert(r.findOne(Produs("Darius", 20, 30)) != -1);
	assert(r.findOne(Produs("Maria", 32, 10)) != -1);
	assert(r.findOne(Produs("Marcel", 40, 50)) != -1);
	char* x = new char[7];
	strcpy_s(x, 7, "Marcel");
	r.update(r2, x, 32, 40);
	assert(r.findOne(Produs(x, 32, 40)) != -1);
	assert(r.findOne(Produs("Maria", 32, 10)) == -1);
	assert(r.getSize() == 3);
	r.delProdus(r1);
	assert(r.getSize() == 2);
	r.addProdus(r1);
	assert(r.getSize() == 3);
	set<Produs> rev;
	rev = r.getAll();
	assert(rev.size() == 3);





	cout << "Testele Service!" << endl;
}

TestService::TestService()
{
}

void TestService::runTests()
{
	test1();
}

TestService::~TestService()
{
}
