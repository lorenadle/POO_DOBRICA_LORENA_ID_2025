#include <iostream>
/*librarie pe care o folosim*/

using namespace std;
//folosim std ca sa folosim cout fara std::cout in fata sau endl fara std::endl
// daca este folosit o singura data cout nu mai includem namespace std 

//numele clasei va fi la singular, mai multe clase= generalizare
// la variabile compuse din mai multe cuvinte se foloseste lower camel case
//la clase se foloseste upper lower case

//ctrl+f5 start without debug
//double 8 cu 4
// incapsulare: in cadrul clasei ne protejam atributele, adica private
class Fruct {
//public: //by default e private
private:
	//const int idFruct;
	char* nume;
	string culoare;
	float greutate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;

public:




	//in general un setter e de tip void
	//setter: este metoda
	//setter este  functie in interiorul clasei 
	// prin setter oferim acces controlat
	//toate atributele sunt in zona private si pt toate creem getter si setter
	void setGreutate(float greutate) {
		if (greutate > 0) {
			//this-> pointer la obiectul pe care vrem sa il modificam, adica atributul initial din clasa
			//pointerul retine adresa, ca sa accesam adresa o deferentiem prin (*this)
			//-> inseamna deferentiere si accesare
			this->greutate = greutate;
		}

	}

	//un getter are tipul returnat ca atributul pt care facem getter, 
	// getterul nu primeste parametrii
	float getGreutate() {
		return this->greutate;
	}
	
	char* getNume() {
		return this->nume;
	}

	//char ocupa 1 octet
	//char * ocupa 8 octeti pt sistem de x64 si 4 octeti pt x32
	void setNume(const char* nume) {
		if (strlen(nume) > 0) {
			this->nume = new char[strlen(nume) + 1];
			// +1 este pentru terminatorul de sir de caracter
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}


	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0){
			this->culoare = culoare;
		}
	}

	void setGreutatiSeminte(int nrSeminte, float* greutatiSeminte) {
		if (nrSeminte > 0) {
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != nullptr)
				//memory leak =ramane zona de memorie ocupata si nu mai poate fi accesata
			{
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
		float getGreutateSamanta(int pozitie) {
			if (pozitie >= 0 && pozitie < nrSeminte) {
				return this->greutatiSeminte[pozitie];
			}
			return -1;// aruncam exceptie
		}
		//constructorul metoda din cadrul clasei care are ca scop initializarea atributelor, aloca spatiu
//nu are tip returnat, are acelasi nume ca si clasa
		//constr fara parametrii

		Fruct() {
			this->culoare = "Rosu";
			this->greutate = 0.1;
			this->lunaMaturitate = 6;
			this->nrSeminte = 0;
			this->greutatiSeminte = nullptr;
			this->nume = nullptr;
		}

		//constr cu parametrii
		Fruct(const char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte,
			const float* greutatiSeminte) {

		
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


};


void main() {

	//numele clasei numele variabilei, numele obiectului
	Fruct fruct;

	cout << fruct.getGreutate() << endl << endl;

	fruct.setGreutate(2.5);
	cout << fruct.getGreutate()<<endl ;

	fruct.setNume("Mar");

	int seminte = 3;
	float* vector = new float[3] {0.1, 0.2, 0.3};
	fruct.setGreutatiSeminte(seminte, vector);
	cout << fruct.getGreutatiSeminte()[0] << endl;
	cout << fruct.getGreutatiSeminte()[1] << endl;
	cout << fruct.getGreutatiSeminte()[2] << endl;

	cout << fruct.getGreutateSamanta(0) << endl;
	cout << fruct.getGreutatiSeminte()[1] << endl;
	cout << fruct.getGreutatiSeminte()[2] << endl;

//apelare constructor ciu parametrii
	Fruct mar("Mar", "Galben", 0.4, 8, 3, vector);
	cout << mar.getNume();

}