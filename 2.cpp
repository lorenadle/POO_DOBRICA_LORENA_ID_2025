#include <iostream>
using namespace std;

class Biblioteca {
private:
	string adresa;
	int nrAbonati;
	float pretAbonament;
	int* ultimaVizita;
public:
	//constructor fara parametrii
	Biblioteca() {
		adresa = "Necunoscuta";
		nrAbonati = 50;
		pretAbonament = 72.5;
		ultimaVizita = nullptr;
	}

	// constructor cu parametrii
	Biblioteca(string adresa, int nrAbonati, float pretAbonament, const int* ultimaVizita) {
		this->adresa = adresa;
		this->nrAbonati = nrAbonati;
		this->pretAbonament = pretAbonament;
		if (this->ultimaVizita != nullptr) {
			delete[] this->ultimaVizita;
		}
		this->ultimaVizita = new int[nrAbonati];
		for (int i = 0; i < nrAbonati; i++) {
			this->ultimaVizita[i] = ultimaVizita[i];
		}

	}
	// constructor cu 1 param
	Biblioteca(float pretAbonament) {
		this->adresa = "victoriei";
		this->nrAbonati = 2;
		this->pretAbonament = pretAbonament;
		this->ultimaVizita = new int[2] {7, 8};
	}
	// set
	void setNrabonati(int nrAbonati) {
		this->nrAbonati = nrAbonati;
	}
	// get
	int getNrAbonati() {
		return this->nrAbonati;
	}

	// destructor
	~Biblioteca() {
		if (this->ultimaVizita != nullptr) {
			delete[] this->ultimaVizita;
		}
		cout << endl << "destructor";

	}

	//constructor de copiere
	Biblioteca(const Biblioteca& copie) {
		this->adresa = copie.adresa;
		this->nrAbonati = copie.nrAbonati;
		this->pretAbonament = copie.pretAbonament;
		if (this->ultimaVizita != nullptr) {
			delete[] this->ultimaVizita;
		}
		if (copie.ultimaVizita != nullptr)
		{
			this->ultimaVizita = new int[copie.nrAbonati];
			for (int i = 0; i < copie.nrAbonati; i++) {

				this->ultimaVizita[i] = copie.ultimaVizita[i];
			}

		}
	}

	// operator egal 
	void operator=(const Biblioteca& copie) {
		this->adresa = copie.adresa;
		this->nrAbonati = copie.nrAbonati;
		this->pretAbonament = copie.pretAbonament;
		if (this->ultimaVizita != nullptr)
		{
			delete[]this->ultimaVizita;
		}
		if (copie.ultimaVizita != nullptr)
		{
			this->ultimaVizita = new int[copie.nrAbonati];
			for (int i = 0; i < copie.nrAbonati; i++) {
				this->ultimaVizita[i] = copie.ultimaVizita[i];
			}

		}
	}

	friend ostream& operator<<(ostream& out, Biblioteca& c) {
		out << c.adresa << endl;
		out << c.nrAbonati << endl;
		out << c.pretAbonament << endl;
		if (c.ultimaVizita != nullptr)
		{

			for (int i = 0;i < c.nrAbonati; i++) {
				out << c.ultimaVizita[i];
			}
		}
		return out;
	}

	// operator ==
	bool operator==(const Biblioteca& c) {
		return this->nrAbonati == c.nrAbonati;

	}

	//metoda de afisare
	void afisare() {
		cout << endl << "Adresa: " << this->adresa << " Are  " << this->nrAbonati << " abonati. Pretul ab este " << this->pretAbonament;
		if (this->ultimaVizita != nullptr)
		{
			cout << " si ultima vizita a abonatilor a fost in luna: ";
			for (int i = 0; i < nrAbonati; i++) {
				cout << this->ultimaVizita[i] << " ";
			}

		}
		else { cout << "."; }
	}

	// operator index
	int& operator[](int index) {
		if (index >= 0 && index < nrAbonati) {
			return this->ultimaVizita[index];
		}
		else {
			throw "Indexul nu se afla in interval!";
		}
	}

	// calcul 
	float ultimavizita() {
		if (ultimaVizita != nullptr && nrAbonati < 1) {
			return 0;
		}
		float suma = 0;
		for (int i = 0; i < nrAbonati; i++) {
			suma += 1;

		}
		return suma;
	}
};
void main() {
	Biblioteca bibl1;
	bibl1.afisare();

	Biblioteca bibl2("unirii", 2, 85.5, new int[2] {5, 7});
	bibl2.afisare();

	Biblioteca bibl3(125.5);
	bibl3.afisare();
	bibl3.setNrabonati(6);
	cout << endl << bibl3.getNrAbonati();

	Biblioteca bibl4 = bibl2;
	bibl4.afisare();

	Biblioteca bibl5;
	bibl5 = bibl1;
	bibl5.afisare();

	cout << bibl2 << endl;
	if (bibl1 == bibl2)
	{
		cout << "egale";
	}
	else { cout << "nu sunt egale"; }
	cout << bibl2[0] << endl;

	try {
		cout << bibl2[0] << endl;
		cout << bibl2[1] << endl;
	}
	catch (exception& e) {
		cout << "Eroare: " << e.what();
	}
	cout << "nr vizitelor este" << bibl2.ultimavizita();
}