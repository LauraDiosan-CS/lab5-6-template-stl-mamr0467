#include <iostream>
#include <cstring>
#include <string>
#include "Produs.h"
#include "stdlib.h"
#include "Repo.h"
#include "RepoFile.h"
#include "testProduse.h"
#include "testRepo.h"
#include "testService.h"
#include "testeRepoFile.h"
#include "Service.h"
#include "UI.h"


using namespace std;
int main() {
	testRFile();
	teste2();
	testRepo();
	testRepo2();
	testRepo3();
	TestService ts;
	ts.runTests();
	RepoFile<Produs> r;
	Service serv(r);
	showUI(serv);
	cout << "succes!";
	return 0;

}