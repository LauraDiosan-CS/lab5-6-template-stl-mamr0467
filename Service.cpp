#include "Service.h"
#include <algorithm> 

Service::Service()
{
}

Service::Service(const Repo<Produs>& r)
{
	repo = r;
}

void Service::setRepo(const Repo<Produs>& r)
{
	repo = r;
}

void Service::addProdus(Produs r)
{
	repo.addElem(r);
}

void Service::delProdus(Produs& r)
{
	repo.del(r);
}

set<Produs> Service::getAll()
{
	return repo.GetAll();
}


void Service::update(Produs& p, const char* nume, int pret, int nr_exemplare)
{
	Produs pNou(nume, pret, nr_exemplare);
	repo.updateElem(p, pNou);
}

int Service::findOne(Produs r)
{
	return repo.findElem(r);
}

size_t Service::getSize()
{
	return this->repo.getSize();
}

Service::~Service()
{
}