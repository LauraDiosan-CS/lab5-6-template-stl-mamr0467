#pragma once
#include "Repo.h"

template<class Elem>
class RepoFile: public Repo<Elem> {
	private:
		char* fileNameIn;
		//char* fileNameOut;
	public:
		RepoFile() :Repo<Elem>() {
			char* fileNameIn = NULL;
			//char* fileNameOut = NULL;
		}
		RepoFile(const char* fileNameIn) :Repo<Elem>() {
			//if (fileNameIn != NULL) {
				this->fileNameIn = new char[strlen(fileNameIn) + 1];
				strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
				this->loadFromFile();
			//}
			
		}
		
		~RepoFile() {
			if (this->fileNameIn != NULL) {
				delete[] this->fileNameIn;
				this->fileNameIn = NULL;
			}
			//if (this->fileNameOut != NULL) {
				//delete[] this->fileNameOut;
				//this->fileNameOut = NULL;
			//}
		}
		
		void loadFromFile() {
			if (this->fileNameIn != NULL) {
				ifstream f(this->fileNameIn);
				Elem e;
				while (f >> e) {
					Repo <Elem>::addElem(e);
				}
				f.close();
				
			}
		}


};