#include <iostream>
using namespace std;

class Cafenea {
private:
	int nrTipuriCafea;
	float* preturiCafea;
	char* numeCafenea;

public:

	//constructor fara parametrii
	Cafenea() {
		this->nrTipuriCafea = 2;
		this->preturiCafea = nullptr;
		//this->numeCafenea=nullptr;
		this->numeCafenea = new char[strlen("necunoscuta") + 1];
		strcpy_s(this->numeCafenea, strlen("necunoscuta") + 1, "necunoscuta");
	}

	//constructor cu 1 param
	Cafenea(int nrTipuriCafea) {
		this->nrTipuriCafea = nrTipuriCafea;
		this->numeCafenea = new char[strlen("Starbucks") + 1];
		strcpy_s(this->numeCafenea, strlen("Starbucks") + 1, "Starbucks");
		this->preturiCafea = nullptr;
	}
	// contructor cu toti parametrii
	Cafenea(int nrTipuriCafea, const float* preturiCafea, const char* numeCafenea) {
		this->nrTipuriCafea = nrTipuriCafea;
		this->numeCafenea = new char[strlen(numeCafenea) + 1];
		strcpy_s(this->numeCafenea, strlen(numeCafenea) + 1, numeCafenea);
		this->preturiCafea = new float[nrTipuriCafea];
		for (int i = 0; i < nrTipuriCafea; i++) {
			this->preturiCafea[i] = preturiCafea[i];
		}

	}

	// get
	int getNrTipuriCafea() {
		return this->nrTipuriCafea;

	}

	char* getNumeCafenea() {
		return this->numeCafenea;
	}

	// set 
	void setNrTipuriCafea(int nrTipuriCafea) {
		this->nrTipuriCafea = nrTipuriCafea;
	}

	void setNumeCafenea(const char* numeCafenea) {
		if (this->numeCafenea != nullptr) {
			delete[] this->numeCafenea;
		}
		this->numeCafenea = new char[strlen(numeCafenea) + 1];
		strcpy_s(this->numeCafenea, strlen(numeCafenea) + 1, numeCafenea);

	}


	//constructor de copiere
	Cafenea(const Cafenea& copie) {
		this->nrTipuriCafea = copie.nrTipuriCafea;

		if (copie.numeCafenea != nullptr) {
			this->numeCafenea = new char[strlen(copie.numeCafenea) + 1];
			strcpy_s(numeCafenea, strlen(copie.numeCafenea) + 1, copie.numeCafenea);
		}
		else {
			this->numeCafenea = nullptr;
		}
		if (copie.preturiCafea != nullptr) {
			this->preturiCafea = new float[copie.nrTipuriCafea];

			for (int i = 0; i < copie.nrTipuriCafea; i++) {
				this->preturiCafea[i] = copie.preturiCafea[i];
			}
		}
		else { this->preturiCafea = nullptr; }
	}

	// destructor
	~Cafenea() {
		if (this->numeCafenea != nullptr)
		{
			delete[] this->numeCafenea;

		}
		if (this->preturiCafea != nullptr) {
			delete[] this->preturiCafea;
		}
		cout << "S-a apelat destructorul" << endl;
	}

	void afisare() {
		cout << endl << this->numeCafenea << " are " << this->nrTipuriCafea << " nr tipuri de cafea";
		if (preturiCafea != nullptr)
		{
			cout << ", cu urmatoarele preturi : ";
			for (int i = 0; i < nrTipuriCafea;i++) {
				cout << this->preturiCafea[i] << endl;
			}
		}

	}

	// operator =
	void operator =(const Cafenea& copie) {
		if (numeCafenea != nullptr) {
			delete[] numeCafenea;
		}
		if (preturiCafea != nullptr) {
			delete[] preturiCafea;
		}

		this->nrTipuriCafea = copie.nrTipuriCafea;
		if (copie.numeCafenea != nullptr) {
			this->numeCafenea = new char[strlen(copie.numeCafenea) + 1];
			strcpy_s(this->numeCafenea, strlen(copie.numeCafenea) + 1, copie.numeCafenea);
		}
		else {
			this->numeCafenea = nullptr;
		}
		if (copie.preturiCafea != nullptr) {
			this->preturiCafea = new float[copie.nrTipuriCafea];
			for (int i = 0; i < copie.nrTipuriCafea; i++) {
				this->preturiCafea[i] = copie.preturiCafea[i];
			}
		}
		else
		{
			this->preturiCafea = nullptr;
		}
	}

	// operator +=
	void operator +=(int valoareAdaugare) {
		this->nrTipuriCafea += valoareAdaugare;

	}
	// operator <
	bool operator<(const Cafenea c) {
		return this->nrTipuriCafea < c.nrTipuriCafea;
	}
	// operator ! negatie
	bool operator!() {
		return this->nrTipuriCafea != 0;
	}



	//operator postincrementare
	Cafenea operator++(int) {
		Cafenea copie = *this;
		this->nrTipuriCafea++;
		return copie;
	}

	//operator preincrementare
	Cafenea operator++() {
		this->nrTipuriCafea++;
		return *this;
	}

	//operator functie 


	float operator()() {
		return *this->getNumeCafenea();
	}



	//
	friend ostream& operator<<(ostream& out, const Cafenea& c) {
		out << c.nrTipuriCafea << endl;
		out << c.numeCafenea << endl;
		for (int i = 0; i < c.nrTipuriCafea; i++) {
			out << c.preturiCafea[i] << endl;
		}
		return out;

	}

	// operator index 
	int operator[](int index) {
		if (index >= 0 && preturiCafea != nullptr) {
			return this->preturiCafea[index];
		}
		else {
			throw "index nu e interval";
		}

	}
};
void main() {
	Cafenea cafenea1;
	cafenea1.afisare();

	Cafenea cafenea2(2);
	cafenea2.afisare();
	float* vector = new float[2] {12.5, 15.0};
	int tipuri = 2;
	Cafenea cafenea3(2, vector, "TED");
	cafenea3.afisare();

	cafenea1.setNrTipuriCafea(20);
	cafenea1.afisare();

	Cafenea cafeneacopie = cafenea3;
	cafeneacopie.afisare();
	cout << cafenea1.getNrTipuriCafea();
	Cafenea cafenea4;
	cafenea4 = cafenea3;
	cafenea4.afisare();
	cafenea4 < cafenea2;
	if (cafenea4 < cafenea2) {
		cout << "cafenea 4 are mai putine" << endl;
	}
	{ cout << "cafenea 2 are mai putine" << endl; }
	if (!cafenea4) {
		cout << "mai multe tipuri" << endl;
	}
	else { cout << " 0tipuri" << endl; }

	cafenea4.setNumeCafenea("5TG");
	cafenea4.getNumeCafenea();

	cafenea4 += 2;
	cout << cafenea4.getNrTipuriCafea() << endl;
	delete[] vector;
	Cafenea cafenea5 = cafenea1++;
	cafenea5.afisare();
	Cafenea cafenea6 = ++cafenea1;
	cafenea6.afisare();
	cout << endl << cafenea6() << endl;
	cout << cafenea1;

	try {
		cout << endl << cafenea3[1];
	}
	catch (exception& e) {
		cout << "Eroare: " << e.what();
	}

}