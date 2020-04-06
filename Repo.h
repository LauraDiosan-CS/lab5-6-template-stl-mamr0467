#pragma once

#include <set>
#include <iostream>
#include "Produs.h"
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
using namespace std;

template <class Elem>class Repo
{
private:
	
	set<Elem> elemente;
	

public:
	Repo();
	~Repo();
	void addElem(Elem);
	set<Elem> GetAll();
	size_t getSize();
	int findElem(const Elem&);
	void del(Elem&);
	
	void updateElem(Elem& elementVechi, Elem& elementNou);

};

template <class Elem>
Repo<Elem>::Repo()
{

}

template<class Elem>
Repo<Elem>::~Repo()
{
}

template<class Elem>
void Repo<Elem>::addElem(Elem elem)
{
	typename set<Elem>::iterator it = find(this->elemente.begin(), this->elemente.end(), elem);
	if (it == this->elemente.end())
		elemente.insert(elem);
}

template<class Elem>
set<Elem> Repo<Elem>::GetAll()
{
	return  this->elemente;// this->elemente;
	//for (std::set<MagazinOnline>::iterator it = elemente.begin(); it != elemente.end(); ++it)
		//std::cout << ' ' << *it;
		//return *it;
}

template<class Elem>
size_t Repo<Elem>::getSize()
{
	return  elemente.size();
}


template<class Elem>
int Repo<Elem>::findElem(const Elem& elem)
{
	typename set<Elem>::iterator it = this->elemente.begin();
	for (int i = 0; i < this->elemente.size(); i++)
		if (*next(it, i) == elem)
			return i;
	return -1;
}

template<class Elem>
void Repo<Elem>::updateElem(Elem& elementVechi, Elem& elementNou)
{
	typename set<Elem>::iterator it = find(elemente.begin(), elemente.end(), elementVechi);
	if (!(it == this->elemente.end())) {
		elemente.erase(it);
		elemente.insert(elementNou);
	}
}


template<class Elem>
void Repo<Elem>::del(Elem& elem)
{
	typename set<Elem>::iterator it = find(elemente.begin(), elemente.end(), elem);

	if (!(it == this->elemente.end()))
		elemente.erase(it);
}

