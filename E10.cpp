#include<iostream>
#include<string>

using namespace std;

class Masina {
private:
	const int id;
	static int nrMasini;
	string marca;
	int nrComponente;
	float* preturi;
public:


	Masina() :id(++nrMasini) {
		this->marca = "Necunoscuta";
		this->nrComponente = 0;
		this->preturi = nullptr;
	}

	Masina(string _marca, int nrComponente, const float* preturi) :id(++nrMasini) {
		marca = _marca;
		this->nrComponente = nrComponente;
		//shallow copy
		//this->preturi = preturi;

		//deep copy
		this->preturi = new float[nrComponente];
		for (int i = 0; i < nrComponente; i++) {
			this->preturi[i] = preturi[i];
		}
	}

	Masina(const Masina& m) :id(++nrMasini) {
		this->marca = m.marca;
		this->nrComponente = m.nrComponente;
		this->preturi = new float[m.nrComponente];
		for (int i = 0; i < m.nrComponente; i++) {
			this->preturi[i] = m.preturi[i];
		}
	}

	const Masina& operator=(const Masina& m) {
		if (this == &m) {
			return *this;
		}
		this->marca = m.marca;
		this->nrComponente = m.nrComponente;
		if (this->preturi != nullptr) {
			delete[]this->preturi;
		}
		this->preturi = new float[m.nrComponente];
		for (int i = 0; i < m.nrComponente; i++) {
			this->preturi[i] = m.preturi[i];
		}
		return *this;
	}

	//masina3 += 1000;
	Masina operator+=(float pret) {
		this->nrComponente++;
		float* aux = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente - 1; i++) {
			aux[i] = this->preturi[i];
		}
		aux[this->nrComponente - 1] = pret;
		if (this->preturi != nullptr) {
			delete[]this->preturi;
		}
		this->preturi = aux;
		return *this;
	}

	Masina operator+(float pret) const {
		Masina temp = *this;//generare eroare in cascada
		float* aux = new float[temp.nrComponente + 1];
		for (int i = 0; i < temp.nrComponente; i++) {
			aux[i] = this->preturi[i];
		}
		aux[temp.nrComponente] = pret;
		if (temp.preturi != nullptr) {
			delete[]temp.preturi;
		}
		temp.preturi = aux;
		temp.nrComponente++;
		return temp;
	}
	//masina2 = 3000.0f + masina3;
	//masina2=masina1+masina3;



	int getNrComponente() {
		return this->nrComponente;
	}

	string getProducator() {
		return this->marca;
	}



	void setNrComponente(int nrComponente) {
		if (nrComponente > 0) {
			this->nrComponente = nrComponente;
		}
		else {
			//throw "Valoare negativa!";
			//throw 400;
			throw new exception();
		}
	}

	//get si set pentru vectorul de preturi
	float* getPreturi() const {
		//return this->preturi;
		float* vectorPreturi = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			vectorPreturi[i] = this->preturi[i];
		}
		return vectorPreturi;
	}

	void setPreturi(float* noulVectorPreturi, int nouaDimensiune) {
		setNrComponente(nouaDimensiune);
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
		this->preturi = new float[nouaDimensiune];
		for (int i = 0; i < nouaDimensiune; i++) {
			this->preturi[i] = noulVectorPreturi[i];
		}
		delete[] noulVectorPreturi;
	}

	const int getId()const {
		return this->id;
	}
	friend Masina operator+(float pret, Masina m);

	~Masina() {
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}

	virtual void afisare() {
		cout << "Masina cu marca " << this->marca << " este cu ardere interna." << endl;
	}

	void afisareMasina() {
		cout << this->id << ". Masina cu marca " << this->marca;
		if (this->nrComponente > 0) {
			cout << " are " << this->nrComponente << " componente cu urmatoarele preturi:";
			if (this->preturi != nullptr) {
				for (int i = 0; i < this->nrComponente; i++) {
					cout << " " << this->preturi[i];
				}
			}
		}
		cout << endl;
	}

	static int getNrMasini() {
		return nrMasini;
	}
	static void setNrMasini(int _nrMasini) {
		nrMasini = _nrMasini;
	}

	friend istream& operator>>(istream& input, Masina& m) {
		cout << "Marca:";
		input >> m.marca;
		cout << "Numar componente:";
		input >> m.nrComponente;
		if (m.preturi != nullptr) {
			delete[]m.preturi;
		}
		if (m.nrComponente > 0) {
			m.preturi = new float[m.nrComponente];
			for (int i = 0; i < m.nrComponente; i++) {
				cout << "Pretul componentei " << (i + 1) << ":";
				input >> m.preturi[i];
			}
		}
		else {
			m.preturi = nullptr;
		}
		return input;
	}

	friend ostream& operator<<(ostream& consola, const Masina& m) {
		consola << m.id << ". Masina cu marca " << m.marca;
		if (m.nrComponente > 0) {
			consola << " are " << m.nrComponente << " componente cu urmatoarele preturi:";
			if (m.preturi != nullptr) {
				for (int i = 0; i < m.nrComponente; i++) {
					consola << " " << m.preturi[i];
				}
			}
		}
		//consola << endl;
		return consola;
	}

};
int Masina::nrMasini = 0;


Masina operator+(float pret, Masina m) {
	Masina temp = m + pret;
	return temp;
}

class Vehicul {
private:
	string producator;
public:
	string getProducator() {
		return this->producator;
	}
};


class MasinaElectrica :public Masina {
private:
	int autonomie;
	char* producatorBaterie;
public:

	void afisare() {
		cout << "Masina electrica de la producatorul "
			<< this->getProducator() << " functioneaza pe baterie." << endl;
	}

	MasinaElectrica() :Masina() {
		this->autonomie = 400;
		this->producatorBaterie = new char[strlen("Rombat") + 1];
		strcpy_s(this->producatorBaterie, strlen("Rombat") + 1, "Rombat");
	}

	MasinaElectrica(string marca,
		int nrComponente,
		float* preturi,
		int autonomie,
		const char* producatorBaterie) :Masina(marca, nrComponente, preturi)
	{
		this->autonomie = autonomie;
		this->producatorBaterie = new char[strlen(producatorBaterie) + 1];
		strcpy_s(this->producatorBaterie, strlen(producatorBaterie) + 1, producatorBaterie);
	}

	MasinaElectrica(const MasinaElectrica& me) : Masina(me) {
		this->autonomie = me.autonomie;
		this->producatorBaterie = new char[strlen(me.producatorBaterie) + 1];
		strcpy_s(this->producatorBaterie, strlen(me.producatorBaterie) + 1, me.producatorBaterie);
	}

	~MasinaElectrica() {
		if (this->producatorBaterie != nullptr) {
			delete[]this->producatorBaterie;
		}
	}

	MasinaElectrica operator=(const MasinaElectrica& me) {
		if (&me != this) {
			(Masina)*this = (Masina)me;
			this->autonomie = me.autonomie;
			if (this->producatorBaterie != nullptr) {
				delete[]this->producatorBaterie;
			}
			this->producatorBaterie = new char[strlen(me.producatorBaterie) + 1];
			strcpy_s(this->producatorBaterie, strlen(me.producatorBaterie) + 1, me.producatorBaterie);
		}
		return *this;
	}

	MasinaElectrica(const Masina& m) :Masina(m) {
		this->autonomie = 0;
		this->producatorBaterie = nullptr;
	}
	friend ostream& operator<<(ostream& out, const MasinaElectrica& me) {
		out << (Masina)me;
		out << " are o autonomie de " << me.autonomie
			<< " km iar bateria este produsa de catre "
			<< me.producatorBaterie << endl;
		return out;
	}

	char* getProducatorBaterie() {
		return this->producatorBaterie;
	}
};

int main() {

	//Masina masina1("Dacia", 3, new float[3] {3, 5, 7});

	//Masina masina2 = masina1;
	//Masina masina3("BMW", 3, new float[3] {664, 645, 32});
	//cout << masina2;
	////cin >> masina2;
	////cout << masina2;

	//MasinaElectrica me;
	//cout << me.Masina::getProducator();
	//
	//MasinaElectrica me2 = me;
	//me = me2;
	//Masina m;
	//cout << m.getNrComponente();
	//cout << endl << "de aici:" << endl;
	//cout << me;
	////masina2.afisareMasina();

	////Masina m;
	float* param = new float[2] {45, 67};
	Masina m1("Audi", 2, param);//nu este recomandata initializarea inline

	m1.afisare();

	Masina* pMasina1 = new Masina("Toyota", 2, param);
	pMasina1->afisare();



	delete pMasina1;
	pMasina1 = new MasinaElectrica("Tesla", 2, param, 500, "Varta");


	pMasina1->afisare();

	delete pMasina1;
	Masina** vector = new Masina * [10];
	vector[0] = new Masina();
	vector[1] = new Masina();
	vector[2] = new MasinaElectrica();
	vector[3] = new Masina();
	vector[4] = new Masina();
	vector[5] = new MasinaElectrica();
	vector[6] = new Masina();
	vector[7] = new Masina();
	vector[8] = new Masina();
	vector[9] = new MasinaElectrica();

	for (int i = 0; i < 10; i++) {
		vector[i]->afisare();
	}


	delete[]param;


}