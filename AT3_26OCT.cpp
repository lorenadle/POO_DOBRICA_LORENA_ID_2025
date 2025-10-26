#include<iostream>

using namespace std;

class Fruct {
private:
	const int idFruct;// definire constanta 
	static int numarFructe; // atribut static,
	char* nume;
	string culoare;
	float greutate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;

public:
	void setGreutate(float greutate) {
		if (greutate > 0) {
			(*this).greutate = greutate;//-> inseamna dereferentiere+accesare
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(const char* nume) {
		if (strlen(nume) > 0) {
			if (this->nume != nullptr) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void setGreutatiSeminte(int nrSeminte, float* greutatiSeminte) {
		if (nrSeminte > 0) {
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != nullptr) {
				delete[] this->greutatiSeminte;
			}
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++) {
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
	}

	float* getGreutatiSeminte() {
		return this->greutatiSeminte;
	}

	int getIdFruct() {
		return this->idFruct;
	}

	string getCuloare() {
		return this->culoare;
	}

	int getLunaMaturitate() {
		return this->lunaMaturitate;
	}

	int getNrSeminte() {
		return this->nrSeminte;
	}

	static int getNumarFructe() {
		return numarFructe;// doar nr veriabilei, nu are acces la this
	}


	void setNumarFructe(int nrFructe) {
		numarFructe = nrFructe;
	}

	float getGreutateSamanta(int pozitie) {
		if (pozitie >= 0 && pozitie < nrSeminte) {
			return this->greutatiSeminte[pozitie];
		}
		//aruncam exceptie...atunci cand le invatam
		//  metode de throw

		throw exception();
		//throw 404;
		//throw "Pozitie in afara intervalului vectorului";
	}


	// constanta se initializeaza :idFruct(1) la inceputul constructorului default adica doua puncte numele parametrului si intre paranteze valoarea
	// ca sa incrementam id-ul atunci :idFruct(numarFructe++) pt post incrementare si :idFruct(++numarFructe), unde numarFructe este atribut static
	Fruct() :idFruct(++numarFructe) {
		//this->idFruct = 1; nu asa se initializeaza o constanta 
		this->culoare = "Rosu";
		this->greutate = 0.6;
		this->lunaMaturitate = 6;
		this->nrSeminte = 0;
		this->greutatiSeminte = nullptr;
		this->nume = nullptr;
	}
	//constructor cu parametrii
	//initializare constanta :idFruct(2) pt al doilea constructor
	Fruct(const char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte, const float* greutatiSeminte) :idFruct(++numarFructe) {
		this->culoare = culoare;
		this->greutate = greutate;
		this->lunaMaturitate = lunaMaturitate;
		this->nrSeminte = nrSeminte;

		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < nrSeminte; i++) {
			this->greutatiSeminte[i] = greutatiSeminte[i];
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	//constructor de copiere, transmitem prin referinta &
	//cuvantul copie este sugestiv pt a intelege ca copiem un constructor existent in acesta
	//  in cazul pointerilor trebuie pusa o validare pt a verifica daca pointerii din constructorul cu parametrii nu sunt nuli, daca sunt nuli trebuie ca in constructorul copie sa fie tot  null

	Fruct(const Fruct& copie) :idFruct(++numarFructe) {

		this->culoare = copie.culoare;
		this->greutate = copie.greutate;
		this->lunaMaturitate = copie.lunaMaturitate;
		this->nrSeminte = copie.nrSeminte;


		//validare daca pointerul din constructorul initial este diferit de null 
		if (copie.greutatiSeminte != nullptr) {
			this->greutatiSeminte = new float[copie.nrSeminte];
			for (int i = 0; i < copie.nrSeminte; i++) {
				this->greutatiSeminte[i] = copie.greutatiSeminte[i];
			}
		}
		else { this->greutatiSeminte = nullptr; }

		//validare daca pointerul din constructorul initial este diferit de null 
		if (copie.nume != nullptr) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}
		else {
			this->nume = nullptr;
		}

	}


	// operatorul =
	//un operator atribuim o valoare existent, pentru operator egal avem nevoie de un obiect existent doar ca actualizam valorile unui obiect din nou existent
	// 2obiecte existente, iau valorile de la primul si le actualizez pe cel de-al doilea obiect existent
	//operatorii definesc conceptul de polimorfism = folosirea unei metode in mai multe scenarii
	//cuvant cheie operator, daca definesc ca fiind void nu mai trebuie return 
	// in stanga operatorului vom avea acces la pointerul this
	// la operator= nu initializam constante, nu se pot modifica constantele
	// nu incrementam numarFructe fiindca nu creez obiect nou si nu modificam atributele statice

	void operator=(const Fruct& copie) {

		this->culoare = copie.culoare;
		this->greutate = copie.greutate;
		this->lunaMaturitate = copie.lunaMaturitate;
		this->nrSeminte = copie.nrSeminte;


		// dezalocare de memorie daca este deja completat pointerul
		if (this->greutatiSeminte != nullptr) {

			delete[] this->greutatiSeminte;
			this->greutatiSeminte = nullptr;

		}

		//validare daca pointerul din constructorul initial este diferit de null 
		if (copie.greutatiSeminte != nullptr) {
			this->greutatiSeminte = new float[copie.nrSeminte];
			for (int i = 0; i < copie.nrSeminte; i++) {
				this->greutatiSeminte[i] = copie.greutatiSeminte[i];
			}
		}
		else { this->greutatiSeminte = nullptr; }


		// dezalocare de memorie daca este deja completat pointerul
		if (this->greutatiSeminte != nullptr) {

			delete[] this->greutatiSeminte;
			this->greutatiSeminte = nullptr;

		}

		//validare daca pointerul din constructorul initial este diferit de null 
		if (copie.nume != nullptr) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}
		else {
			this->nume = nullptr;
		}

	}


	void afisareFruct() {
		//const int idFruct;// definire constanta 
		//
		//char* nume;
		//string culoare;
		//float greutate;
		//int lunaMaturitate;
		//int nrSeminte;
		//float* greutatiSeminte;
		cout << endl << this->getIdFruct() << " . Fructul ";

		if (this->getNume() != nullptr) {
			cout << this->getNume();
		}

		cout << " are culoarea " << this->getCuloare() << ", greutatea este de  " << this->getGreutate() << "kg, a fost copt in luna a " << this->getLunaMaturitate() << "-a. Contine " << this->getNrSeminte() - 1 << " seminte";
		if (this->getNrSeminte() > 0) {

			cout << " cu urmatoarele greutati: ";
			for (int i = 0; i < this->getNrSeminte(); i++) {
				cout << this->getGreutateSamanta(i) << ",";
			}
			cout << this->getGreutateSamanta(this->getNrSeminte() - 1) << ".";

		}

	}


	//destructor
	~Fruct() {
		if (this->greutatiSeminte != nullptr) {
			delete[]this->greutatiSeminte;

		}
		if (this->nume != nullptr) {
			delete[]this->nume;

		}

	}
	//cand in stanga operatorului este obiect se retine cu this-> 
	void operator+=(float valoareDeAdaugatLaGreutate) {
		this->greutate += valoareDeAdaugatLaGreutate;

	}








	//comparatie intre 2 obiecte dupa un atribut => return bool
	bool operator<(const Fruct f) {
		return this->greutate < f.greutate;


	}

	// operator negatie !
	bool operator !() {

		return this->lunaMaturitate != 0;

	}
	//operator functie 
	float operator()(int pozitie) {
		return this->getGreutateSamanta(pozitie);


	}
};
//functie de afisare in afara clasei, adica primeste obiect
//daca e in afara clasei nu avem acces la parametrii ca sunt in zona private






//initializare atribut static, in afara clasei
int Fruct::numarFructe = 0;// ajuta atunci cand apelam (construim) constructori in mail
//contor care numara nr de obiecte din functia main


void main() {

	float* vector = new float[3] {0.1, 0.2, 0.3};

	Fruct fruct("Mar", "Galben", 0.4, 8, 3, vector);
	try {
		cout << endl << fruct.getGreutateSamanta(3);
	}
	//metode de catch, ordine de catch prestabilite 

	catch (int cod) {
		cout << endl << cod;


	}

	catch (const char* mesaj) {
		cout << endl << mesaj;


	}

	//catch(...) se prinde orice fel de exceptie 
	catch (...) {
		cout << endl << "Positia este in fara intervalului";
	}

	cout << endl << fruct.getIdFruct();

	cout << endl << "Am initializat  " << fruct.getNumarFructe() << " obiect/e";
	cout << endl << "Am initializat  " << Fruct::getNumarFructe() << " obiect/e";// numele clasei:: numele metodei daca este in zona public

	cout << endl << "Id fruct bazat pe contructorul cu toti parametrii:" << fruct.getIdFruct();

	Fruct fruct2 = fruct;// apel constructor de copiere
	//Fruct fruct2(fruct);// apel constructor de copiere 

	cout << endl << "Id fruct bazat pe contructorul de copiere" << fruct2.getIdFruct();

	//apel operator egal
	Fruct fructDefault;

	fructDefault = fruct;
	// toate operatiile efectuate in operatorul egal se vor efectua in fructDefault
	cout << endl << "Id fruct bazat pe operatorul egal:" << fructDefault.getIdFruct();


	fruct.afisareFruct();// dam parametru fiindca e in afara clasei
	fruct2.afisareFruct();
	fructDefault.afisareFruct();

	cout << endl << "Am initializat  " << fruct.getNumarFructe() << " obiect/e";
	cout << endl << "Am initializat  " << Fruct::getNumarFructe() << " obiect/e";// numele clasei:: numele metodei daca este in zona public
	fruct += 0.1;
	fruct.afisareFruct();
	if (fruct < fruct2) {
		cout << endl << "Primul fruct are greutatea mai mica decat al doilea fruct";
	}
	else {
		cout << endl << "Al doilea fruct are greutatea mai mica decat primul fruct";
	}
	if (!fruct) {
		cout << endl << "nu";
	}
	else {

		cout << endl << "da";
	}
	;

	cout << endl << fruct(2);


}

//atribute constante nu pot fi modificate si se initializeaza o singura data la creare obiectului
// pt constant se poate face get dar nu si set fiindca nu se poate modifica

//atribute statice nu apartin obiectelor, ele apartin claselor
//constructor de copiere ia atributele unui obiect existent si le pune altui obiect nou creat, nu modificam obiectul existent folosim atributele constant
//transmitere prin referinta in lista de parametrii
//dereferentiere inseamna extragere valori de la adresa

// dieferente intre constr de copiere si operator egal : la constr creem obiect nou folosind un obiect existent iar pt operator avem 2 obiecte existente si actualizam valorile dintr-un obiect existent in cel de-al doilea obiect existent

//discutie despre atribute constante
	//atribute statice
	//constructor de copiere
	// destructor
	//operator =(de atribuire)
	//alti operatori
	//try catch 

//teme -=, /=, ., ==, functie, >
// // de cautat operator index