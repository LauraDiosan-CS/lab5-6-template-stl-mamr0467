#pragma once
#include "Repo.h"
#include "Produs.h"
#include <vector>
#include <list>
using namespace std;
class Service
{
private:
	Repo<Produs> repo;

public:
	Service();
	Service(const Repo<Produs>&);
	void setRepo(const Repo<Produs>&);
	void addProdus(Produs);
	void delProdus(Produs&);
	set<Produs> getAll();
	void update(Produs&, const char*, int, int);
	int findOne(Produs);
	size_t getSize();
	~Service();
};