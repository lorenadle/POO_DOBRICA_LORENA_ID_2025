#include <iostream>
using namespace std;

class Librarie {
private:
	char* numeLibrarie;
	int nrCarti = 0;
	char* numeLibrar;

public:

	char* getNumeLibrarie() {

		return this->numeLibrarie;
	}

	void setNumeLibrarie(const char* numeLibrarie) {
		if (strlen(numeLibrarie)>0)
		{
			this->numeLibrarie = new char[strlen(numeLibrarie) + 1];
			strcpy_s(this->numeLibrarie, strlen(numeLibrarie) + 1, numeLibrarie);

		}

	}

	char* getNumeLibrar() {
		return this->numeLibrar;
	}

	void setNumeLibrar(const char* numeLibrar) {
		if (numeLibrar != nullptr) {
			this->numeLibrar = new char[strlen(numeLibrar) + 1];
			strcpy_s(this->numeLibrar, strlen(numeLibrar) + 1, numeLibrar);


		}
	}

	int getNrCarti() {

		return this->nrCarti;

	}


	void setNrCarti(int nrCarti) {
		if (nrCarti > 0) {
			this->nrCarti = nrCarti;
		}

	}

};
void main() {
	Librarie librarie;
	librarie.setNumeLibrarie("Libraria Casa");
	cout << librarie.getNumeLibrarie() << endl;

	librarie.setNumeLibrar("Ioana popescu");
	cout << "Libraria " << librarie.getNumeLibrarie() << " are ca librar astazi pe " << librarie.getNumeLibrar() << endl;

	librarie.setNrCarti(10);
	cout << "Libraria " << librarie.getNumeLibrarie() << " are ca librar astazi pe " << librarie.getNumeLibrar() << "si are in stoc " << librarie.getNrCarti() << " carti." << endl;

}