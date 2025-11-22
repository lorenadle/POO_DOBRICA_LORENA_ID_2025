#include <iostream>
using namespace std;


class Carte {
private:
	const int idCarte;
	static int nrCarti;
	char* numeAutor;
	string  numeCarte;
	int anulPublicarii;
	int lunaPublicarii;
	float pret;

public:
	int getIdCarte() const {
		return this->idCarte;
	}

	static int getNrCarti() {
		return nrCarti;
	}



	void setNrCarti(int _nrCarti) {
		nrCarti = _nrCarti;
	}


	void setNumeCarte(string numeCarte) {
		if (numeCarte.length() > 0) {
			this->numeCarte = numeCarte;
		}
	}

	int getLunaPublicarii() {
		return lunaPublicarii;
	}
	
	void setLunaPublicarii(int lunaPublicarii) {
		lunaPublicarii = lunaPublicarii;

	}

	void setPret(float pret) {
		if (pret > 0) {
			(*this).pret = pret;//-> inseamna dereferentiere+accesare
		}
	}

	float getPret() {
		return this->pret;
	}

	//destructor
	~Carte() {
		if (this->numeAutor != NULL) {
			delete[]this->numeAutor;
		}
	}
	//constructor fara parametrii
	Carte() :idCarte(++nrCarti) {
		this->numeAutor = new char[strlen("Necunoscut") + 1];
		strcpy_s(this->numeAutor, strlen("Necunoscut") + 1, "Necunoscut");
		this->numeCarte = "Colivia";
		this->anulPublicarii = 2025;
		this->lunaPublicarii = 7;
		this->pret = 2.05;
	}

	//constructor cu parametrii
	Carte(string numeCarte) :idCarte(++nrCarti) {
		this->numeCarte = numeCarte;
		this->anulPublicarii = 2014;
		this->lunaPublicarii = 5;
		this->pret = 25.74;
		this->numeAutor = new char[strlen("Necunoscut") + 1];
		strcpy_s(this->numeAutor, strlen("Necunoscut") + 1, "Necunoscut");
	}

	// constructor cu parametrii

	Carte(const char* numeAutor,
	string  numeCarte,
	int anulPublicarii,
	int lunaPublicarii,
	float pret) :idCarte(++nrCarti) {
		this->numeCarte = numeCarte;
		this->anulPublicarii = anulPublicarii;
		this->lunaPublicarii = lunaPublicarii;
		this->pret = pret;
		this->numeAutor = new char[strlen(numeAutor) + 1];
		strcpy_s(this->numeAutor, strlen(numeAutor) + 1, numeAutor);
	}

	//contructor de copiere
	Carte(const Carte& copie) :idCarte(++nrCarti) {

		this->numeCarte = copie.numeCarte;
		this->anulPublicarii = copie.anulPublicarii;
		this->lunaPublicarii = copie.lunaPublicarii;
		this->pret = copie.pret;


		//validare daca pointerul din constructorul initial este diferit de null 
		
		if (copie.numeAutor != nullptr) {
			this->numeAutor = new char[strlen(copie.numeAutor) + 1];
			strcpy_s(this->numeAutor, strlen(copie.numeAutor) + 1, copie.numeAutor);
		}
		else {
			this->numeAutor = nullptr;
		}

	}




	char* getNumeAutor() {
		return this->numeAutor;
	}

	void setNume(const char* numeAutor) {
		if (strlen(numeAutor) > 0) {
			if (this->numeAutor != nullptr) {
				delete[]this->numeAutor;
			}
			this->numeAutor = new char[strlen(numeAutor) + 1];
			strcpy_s(this->numeAutor, strlen(numeAutor) + 1, numeAutor);
		}
	}



	void operator=(const Carte& copie) {

		this->numeCarte = copie.numeCarte;
		this->anulPublicarii = copie.anulPublicarii;
		this->lunaPublicarii = copie.lunaPublicarii;
		this->pret = copie.pret;
		if (this->numeAutor != nullptr) {

			delete[] this->numeAutor;

		}	
			this->numeAutor = new char[strlen(copie.numeAutor) + 1];
			strcpy_s(this->numeAutor, strlen(copie.numeAutor) + 1, copie.numeAutor);
		

	}


	void operator+=(float valoareDeAdaugatLaPret) {
		this->pret += valoareDeAdaugatLaPret;

	}








	//comparatie intre 2 obiecte dupa un atribut => return bool
	bool operator<(const Carte f) {
		return this->anulPublicarii < f.anulPublicarii;


	}

	// operator negatie !
	bool operator !() {

		return this->lunaPublicarii != 0;

	}





	void afisare() { 
		cout << "Nume carte:" << this->numeCarte << endl;
		cout << "Nume autor:" << this->numeAutor << endl;
		cout << "Anul publicarii:" << this->anulPublicarii << endl;
		cout << "Luna publicarii:" << this->lunaPublicarii << endl;
		cout << "Pret: " <<this->pret << endl;
	}


};
//initializare atribut static, in afara clasei
int Carte::nrCarti = 0;
void main() {

	Carte carte ;
	carte.afisare();
	Carte  carte1("Amintiri din copilarie");
	carte1.afisare();

	Carte carte2("Eliade", "Nunta in cer", 1970, 10, 20.98);
	carte2.afisare();

	cout << endl << carte1.getIdCarte();

	Carte carte3 = carte2;
	carte3.afisare();
	// set si get
	carte.setPret(2.5);
	cout << carte.getPret() << endl;
	
	Carte carteCopiere;	

	carteCopiere = carte1;
	carteCopiere.afisare();

	carte2 += 50.98;
	carte2.afisare();

	carte2 < carte1;

	if (carte2 < carte1) {
		cout << endl << "anul publicarii 2 mai mic decat anul publicarii 1";
	}
	else {
		cout << endl << "anul publicarii 1 mai mic decat anul publicarii 2";
	}

	if (!carte3) {
		cout << endl << "nu";
	}
	else {

		cout << endl << "da";
	}
	;



};