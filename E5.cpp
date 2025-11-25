#include <iostream>
using namespace std;

class Cafenea {
private:
	int nrTipuriCafea;
	float* preturiCafea;
public:


	Cafenea() {
		this->nrTipuriCafea = 2;
		this->preturiCafea = new float[2] {25.1, 22.5};
		this->preturiCafea = new float[nrTipuriCafea];
		for (int i = 0; i < nrTipuriCafea; i++) {
			this->preturiCafea[i] = preturiCafea[i];
		}

	}

	void afisare() {
		cout << "nr tipuri cafea " << this->nrTipuriCafea << "cu urmatoarele preturi: " << this->preturiCafea << endl;

	}

};
void main{
	Cafenea cafenea1;
cafenea1.afisare();


}



