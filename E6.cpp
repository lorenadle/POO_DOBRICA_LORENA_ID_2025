#include<iostream>
using namespace std;
class Vanzator {
private:
	const int marca;
	string nume;
	static int nrVanzatori;
	int nrLuniLucrate;
	int* nrZilePeLuna;

	int calculNumarTotalZile()const {
		int suma = 0;
		for (int i = 0; i < this->nrLuniLucrate; i++) {
			suma += this->nrZilePeLuna[i];
		}
		return suma;
	}

public:

	//operator<< - de afisare
	//cout<<vanzator;
	friend ostream& operator<<(ostream& monitor, const Vanzator& v) {
		monitor << v.marca << ". Vanzatorul " << v.nume << " a lucrat " << v.nrLuniLucrate << " luni, cu urmatoarele zile: ";
		for (int i = 0; i < v.nrLuniLucrate; i++) {
			monitor << v.nrZilePeLuna[i] << ", ";
		}
		monitor << endl;
		return monitor;
	}
	//operator>> - de citire
	friend istream& operator>>(istream& tastatura, Vanzator& v) {
		cout << "Numele:";
		tastatura >> v.nume;
		cout << "Numar luni lucrate:";
		tastatura >> v.nrLuniLucrate;
		if (v.nrZilePeLuna != NULL) {
			delete[]v.nrZilePeLuna;
		}
		v.nrZilePeLuna = new int[v.nrLuniLucrate];
		for (int i = 0; i < v.nrLuniLucrate; i++) {
			cout << "Numarul de zile lucrate in luna " << (i + 1) << ":";
			tastatura >> v.nrZilePeLuna[i];
		}
		return tastatura;
	}
	//operator[]
	int& operator[](unsigned int index) {
		if (index < this->nrLuniLucrate) {
			return this->nrZilePeLuna[index];
		}
	}

	//operator+ cu un intreg - numarul de zile dintr-o luna noua
	// 3 luni {20,21,22}
	// obiect1=obiect2+19;
	// obiect2+=19;
	// 4 luni{20,21,22,19}
	Vanzator operator+=(int nrZile) {
		int* temp = new int[this->nrLuniLucrate + 1];
		for (int i = 0; i < this->nrLuniLucrate; i++) {
			temp[i] = this->nrZilePeLuna[i];
		}
		temp[this->nrLuniLucrate] = nrZile;
		this->nrLuniLucrate++;
		if (this->nrZilePeLuna) {
			delete[]this->nrZilePeLuna;
		}
		this->nrZilePeLuna = temp;
		return *this;
	}

	Vanzator operator+(int nrZile) const {
		Vanzator aux = *this;

		int* temp = new int[aux.nrLuniLucrate + 1];
		for (int i = 0; i < aux.nrLuniLucrate; i++) {
			temp[i] = aux.nrZilePeLuna[i];
		}
		temp[aux.nrLuniLucrate] = nrZile;
		aux.nrLuniLucrate++;
		if (aux.nrZilePeLuna) {
			delete[]aux.nrZilePeLuna;
		}
		aux.nrZilePeLuna = temp;
		return aux;
	}

	//operator < (dupa numarul total de zile lucrate)
	bool operator<(const Vanzator& v) {
		return this->calculNumarTotalZile() < v.calculNumarTotalZile();
	}

	int getNrLuniLucrate() {
		return this->nrLuniLucrate;
	}
	int* getNrZilePeLuna() {
		return this->nrZilePeLuna;
	}

	int getNumarZileByLuna(int index) {
		if (index >= 0 && index < this->nrLuniLucrate) {
			return this->nrZilePeLuna[index];
		}
		else {
			return 0;
		}
	}
	void setLuniLucrate(int nrLuni, int* nrZilePeLuna) {
		if (nrLuni > 0 && nrZilePeLuna != NULL) {
			this->nrLuniLucrate = nrLuni;
			if (this->nrZilePeLuna != NULL) {
				delete[]this->nrZilePeLuna;
			}
			this->nrZilePeLuna = new int[nrLuni];
			for (int i = 0; i < nrLuni; i++) {
				this->nrZilePeLuna[i] = nrZilePeLuna[i];
			}
		}
	}

	int getMarca() {
		return this->marca;
	}
	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 2) {
			this->nume = nume;
		}
	}

	static int getNrVanzatori() {
		return nrVanzatori;
	}


	Vanzator() :marca(nrVanzatori++) {
		this->nume = "Vanzator incepator";
		this->nrLuniLucrate = 0;
		this->nrZilePeLuna = NULL;
	}

	Vanzator(string nume) :marca(nrVanzatori++) {
		this->nume = nume;
		this->nrLuniLucrate = 0;
		this->nrZilePeLuna = NULL;
	}

	Vanzator(string nume, int nrLuniLucrate, int* nrZilePeLuna) :marca(nrVanzatori++) {
		this->nume = nume;
		this->nrLuniLucrate = nrLuniLucrate;
		this->nrZilePeLuna = new int[nrLuniLucrate];
		for (int i = 0; i < nrLuniLucrate; i++) {
			this->nrZilePeLuna[i] = nrZilePeLuna[i];
		}
	}

	Vanzator(const Vanzator& v) :marca(nrVanzatori++) {
		this->nume = v.nume;
		this->nrLuniLucrate = v.nrLuniLucrate;
		this->nrZilePeLuna = new int[v.nrLuniLucrate];
		for (int i = 0; i < v.nrLuniLucrate; i++) {
			this->nrZilePeLuna[i] = v.nrZilePeLuna[i];
		}
	}

	Vanzator operator=(const Vanzator& v) {
		if (this != &v) { //verificare de autoasignare
			this->nume = v.nume;
			this->nrLuniLucrate = v.nrLuniLucrate;
			if (this->nrZilePeLuna != NULL) {
				delete[]this->nrZilePeLuna;
			}
			this->nrZilePeLuna = new int[v.nrLuniLucrate];
			for (int i = 0; i < v.nrLuniLucrate; i++) {
				this->nrZilePeLuna[i] = v.nrZilePeLuna[i];
			}
		}
		return *this;
	}

	void afisare() {
		cout << this->marca << ". Vanzatorul " << this->nume << " a lucrat " << this->nrLuniLucrate << " luni, cu urmatoarele zile: ";
		for (int i = 0; i < this->nrLuniLucrate; i++) {
			cout << this->nrZilePeLuna[i] << ", ";
		}
		cout << endl;
	}

	~Vanzator() {
		if (this->nrZilePeLuna != NULL) {
			delete[]this->nrZilePeLuna;
		}
	}

};
int Vanzator::nrVanzatori = 0;


void main() {

	//Vanzator* v = new Vanzator[100];
	//cout<<Vanzator::getNrVanzatori();

	Vanzator vanzator1;
	Vanzator vanzator2("Ionescu");
	int* vectorZile = new int[4] {22, 20, 21, 18};
	Vanzator vanzator3("Vasilescu", 4, vectorZile);
	Vanzator vanzator4 = vanzator3;
	vanzator1 = vanzator4;
	vanzator1.setNume("Georgescu");
	int* vector2 = new int[3] {15, 18, 22};
	vanzator1.setLuniLucrate(3, vector2);

	cout << vanzator1.getMarca() << "." << vanzator1.getNume() << " a lucrat "
		<< vanzator1.getNrLuniLucrate() << " luni.";
	for (int i = 0; i < vanzator1.getNrLuniLucrate(); i++)
	{
		cout << vanzator1.getNumarZileByLuna(i) << ", ";
	}
	cout << endl;

	cout << vanzator4.getMarca() << "." << vanzator4.getNume() << " a lucrat "
		<< vanzator4.getNrLuniLucrate() << " luni.";
	for (int i = 0; i < vanzator4.getNrLuniLucrate(); i++)
	{
		cout << vanzator4[i] << ", ";
	}
	cout << endl;
	vanzator1.afisare();
	vanzator2.afisare();
	vanzator3.afisare();
	vanzator1 = vanzator3 + 67;
	vanzator1.setNume("Georgescu");
	cout << "vanzator1:" << vanzator1 << endl;
	cout << "vanzator3:" << vanzator3 << endl;

	if (vanzator3 < vanzator1) {
		cout << "Vanzatorul " + vanzator3.getNume() << " are mai putine zile lucrate";
	}
	else {
		cout << "Vanzatorul " + vanzator1.getNume() << " are mai putine zile lucrate";
	}

	cin >> vanzator3;
	cout << vanzator3;


}