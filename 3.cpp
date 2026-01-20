#include <iostream>
using namespace std;

class SalaEvenimente {
private:
	string numeSala;
	int numarlnvitati;
	float pretBilet;
	int* varstelnvitati;


public:
	//constructor default
	SalaEvenimente() {
		this->numeSala = "";
		this->numarlnvitati = 0;
		this->pretBilet = 0;
		this->varstelnvitati = nullptr;
	}
	// constructor cu un param
	SalaEvenimente(float pretBilet) {
		this->numeSala = "";
		this->numarlnvitati = 0;
		this->pretBilet = pretBilet;
		this->varstelnvitati = nullptr;
	}
	// constructor cu toti param
	SalaEvenimente(string numeSala, int numarInvitati, float pretBilet, const int* varsteInvitati) {
		this->numeSala = numeSala;
		this->numarlnvitati = numarInvitati;
		this->pretBilet = pretBilet;
		if (numarInvitati > 0) {
			this->varstelnvitati = new int[numarInvitati];
			for (int i = 0; i < numarInvitati; i++) {
				this->varstelnvitati[i] = varsteInvitati[i];
			}
		}
		else { varstelnvitati = nullptr; }
	}
	// constructor de copiere
	SalaEvenimente(const SalaEvenimente& copie) {
		this->numeSala = copie.numeSala;
		this->numarlnvitati = copie.numarlnvitati;
		this->pretBilet = copie.pretBilet;

		if (copie.numarlnvitati > 0 && copie.varstelnvitati != nullptr) {
			this->varstelnvitati = new int[copie.numarlnvitati];
			for (int i = 0; i < copie.numarlnvitati; i++) {
				this->varstelnvitati[i] = copie.varstelnvitati[i];
			}

		}
		else { this->varstelnvitati = nullptr; }
	}

	~SalaEvenimente() {
		if (this->varstelnvitati != nullptr)
		{
			delete[] this->varstelnvitati;

		}
		cout << endl << "S-a apelat destructorul!" << endl;
	}


	//operator copiere
	void operator =(SalaEvenimente& c) {
		this->numeSala = c.numeSala;
		this->numarlnvitati = c.numarlnvitati;
		this->pretBilet = c.pretBilet;
		if (c.varstelnvitati != nullptr) {
			this->varstelnvitati = new int[c.numarlnvitati];
			for (int i = 0; i < c.numarlnvitati;i++) {
				this->varstelnvitati[i] = c.varstelnvitati[i];
			}
		}


	}



	// afisare
	void afisare() {
		cout << this->numeSala << " are " << this->numarlnvitati << " invitati";

		if (varstelnvitati != nullptr)
		{

			cout << " cu urmatoarele varste:";
			for (int i = 0; i < numarlnvitati; i++) {
				cout << this->varstelnvitati[i] << " ";
			}
		}
		cout << "Pretul biletului este : " << this->pretBilet << endl;
	}

	//operator index
	int operator [](int index) {
		if (index > 0 && index < numarlnvitati)
		{
			return this->varstelnvitati[index];
		}
	}
	//metoda de calcul
	float calculVarstaMedie() {
		if (varstelnvitati == nullptr && numarlnvitati < 1) {
			return 0;
		}
		else {
			float suma = 0;
			for (int i = 0; i < numarlnvitati; i++) {
				suma = +varstelnvitati[i];
			}
			return suma / numarlnvitati;
		}


	}

	friend ostream& operator<<(ostream& out, SalaEvenimente& c) {
		out << endl << c.numeSala;
		out << endl << c.numarlnvitati;
		out << endl << c.pretBilet;
		if (c.varstelnvitati != nullptr) {
			for (int i = 0; i < c.numarlnvitati; i++) {
				out << endl << c.varstelnvitati[i];
			}
			return out;

		}
	}

	//get 
	int getNumarInvitati() {
		return this->numarlnvitati;
	}

	//set

	void setNumarInvitati(int numarInvitati) {
		this->numarlnvitati = numarInvitati;
	}
};
void main()
{
	SalaEvenimente sl1;
	sl1.afisare();
	SalaEvenimente sl2(59.6);
	sl2.afisare();
	SalaEvenimente sl3("Regal", 5, 85.98, new int[5] {42, 54, 36, 54, 85});
	sl3.afisare();
	SalaEvenimente sl4(sl3);
	sl3.afisare();

	SalaEvenimente sl5;
	sl5 = sl3;
	sl5.afisare();
	cout << endl << sl5[2];

	sl5.calculVarstaMedie();

	cout << sl5;

	cout << endl << "get" << sl5.getNumarInvitati();
	sl2.setNumarInvitati(25);
	cout << endl << "get" << sl2.getNumarInvitati();
}