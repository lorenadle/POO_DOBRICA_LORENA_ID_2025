#include<iostream>

using namespace std;

class Produs {
private:
	const int cod;
	static int contorCoduri;
	string denumire;
	float pret;
	float greutateReala;
	int cantitate;
	char* taraOrigine;
public:

	 operator++ pentru cantitate
	Produs operator++() {forma prefixata
		this->cantitate++;
		return *this;
	}

	Produs operator++(int) {forma postfixata
		Produs aux = *this;
		this->cantitate++;
		return aux;
	}

	operator== pentru denumire, pret si cantitate
	bool operator==(const Produs& p)const {
		return this->cantitate == p.cantitate
			&& this->pret == p.pret
			&& this->denumire == p.denumire;
	}
	operator+ adaugare de sufix la nume;
	Produs operator+(string sufix)const {
		Produs p = *this;
		p.denumire = p.denumire + sufix;
		return p;
	}

	int getCod() {
		return this->cod;
	}

	string getDenumire() {
		return this->denumire;
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}

	float getGreutate() {
		return this->greutateReala;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutateReala = greutate;
		}
	}

	int getCantitate() {
		return this->cantitate;
	}

	void setCantitate(int cantitate) {
		if (cantitate > 0) {
			this->cantitate = cantitate;
		}
	}

	char* getTaraOrigine() {
		return this->taraOrigine;
	}

	void setDenumire(string denumire) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
	}

	void setTaraOrigine(const char* tara) {
		if (strlen(tara) > 2) {
			if (this->taraOrigine != NULL) {
				delete[]this->taraOrigine;
			}
			this->taraOrigine = new char[strlen(tara) + 1];
			strcpy_s(this->taraOrigine, strlen(tara) + 1, tara);
		}
	}

	Produs() :cod(contorCoduri++) {
		this->denumire = "";
		this->pret = 0;
		this->greutateReala = 0;
		this->cantitate = 0;
		this->taraOrigine = NULL;
	}

	Produs(string denumire, float pret, int cantitate) :cod(contorCoduri++) {
		this->denumire = denumire;
		this->pret = pret;
		this->cantitate = cantitate;
		this->greutateReala = 0;
		this->taraOrigine = new char[strlen("Romania") + 1];
		strcpy_s(this->taraOrigine, strlen("Romania") + 1, "Romania");
	}

	Produs(string denumire, float pret, float greutateReala, int cantitate, const char* taraOrigine) :cod(contorCoduri++) {
		this->denumire = denumire;
		this->pret = pret;
		this->greutateReala = greutateReala;
		this->cantitate = cantitate;
		this->taraOrigine = new char[strlen(taraOrigine) + 1];
		strcpy_s(this->taraOrigine, strlen(taraOrigine) + 1, taraOrigine);
	}

	Produs(const Produs& p) :cod(contorCoduri++) {
		this->denumire = p.denumire;
		this->pret = p.pret;
		this->greutateReala = p.greutateReala;
		this->cantitate = p.cantitate;
		if (p.taraOrigine != NULL) {
			this->taraOrigine = new char[strlen(p.taraOrigine) + 1];
			strcpy_s(this->taraOrigine, strlen(p.taraOrigine) + 1, p.taraOrigine);
		}
		else {
			this->taraOrigine = NULL;
		}
	}

	Produs operator=(const Produs& p) {
		if (this != &p) {verificare de autoasignare
			this->denumire = p.denumire;
			this->pret = p.pret;
			this->greutateReala = p.greutateReala;
			this->cantitate = p.cantitate;
			if (this->taraOrigine != NULL) {
				delete[]this->taraOrigine;
			}
			if (p.taraOrigine != NULL) {
				this->taraOrigine = new char[strlen(p.taraOrigine) + 1];
				strcpy_s(this->taraOrigine, strlen(p.taraOrigine) + 1, p.taraOrigine);
			}
			else {
				this->taraOrigine = NULL;
			}
		}
		return *this;
	}

	~Produs() {
		if (this->taraOrigine) {
			delete[]this->taraOrigine;
		}
	}

	void afisare() {
		cout << "Cod: " << this->cod << ". ";
		cout << "Denumire: " << this->denumire << ". ";
		cout << "Pret: " << this->pret << ". ";
		cout << "Greutate: " << this->greutateReala << ". ";
		cout << "Cantitate: " << this->cantitate << ". ";
		if (this->taraOrigine != NULL) {
			cout << "Tara: " << this->taraOrigine << endl;
		}
		else {
			cout << endl;
		}
	}
};
int Produs::contorCoduri = 1000;
void main() {


	Produs produs1;
	Produs produs2("Lapte", 12, 5);
	Produs produs3("Carne", 34, 1000, 3, "Turcia");
	Produs produs4 = produs3;
	produs1 = produs3;
	produs1.setDenumire("Paine");
	cout << produs1.getDenumire() << " " << produs1.getGreutate() << " " << produs1.getTaraOrigine() << endl;
	cout << produs4.getDenumire() << " " << produs4.getGreutate() << " " << produs4.getTaraOrigine() << endl;

	cout << "Produse:" << endl;
	produs1.afisare();
	produs2.afisare();
	produs3.afisare();

	produs3++;
	produs2 = produs3;
	produs3.afisare();

	if (produs3 == produs2) {
		cout << "Sunt egale";
	}
	else {
		cout << "Sunt diferite";
	}
	cout << endl;

	produs2 = produs3 + " - China";
	produs2.afisare();
	produs3.afisare();}