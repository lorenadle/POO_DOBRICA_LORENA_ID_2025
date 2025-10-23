#include <iostream>
using namespace std;

class Librarie {
private:
	char* numeLibrarie;
	int nrCarti = 0;
	char numeLibrar;

public:

	char* getNumeLibrarie() {

		return this->numeLibrarie;
	};

	void setNumeLibrarie(const char* numeLibrarie) {
		if (strlen(numeLibrarie)>0)
		{
			this->numeLibrarie = new char[strlen(numeLibrarie) + 1];
			strcpy_s(this->numeLibrarie, strlen(numeLibrarie) + 1, numeLibrarie);

		}

	}




};
void main() {
	Librarie librarie;
	librarie.setNumeLibrarie("Libraria Casa");
	cout << librarie.getNumeLibrarie() << endl;

}