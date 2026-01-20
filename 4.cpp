#include <iostream>
using namespace std;

class CameraHotel {
private:
	string numarCamera;
	int numarFacilitati;
	float pretPeNoapte;
	string* facilitatiCamera;


public:
	//constructor

	CameraHotel() {
		this->numarCamera = "default";
		this->numarFacilitati = 3;
		this->pretPeNoapte = 0;
		this->facilitatiCamera = new string[numarFacilitati];
		facilitatiCamera[0] = "WIFI";
		facilitatiCamera[1] = "balcon";
		facilitatiCamera[2] = "minibar";
		facilitatiCamera[2] = "parcare";

	}

	void afisare() {
		cout << endl << "Camera: " << this->numarCamera << " are " << this->numarFacilitati << " facilitati, iar pretul pe noapte este :" << this->pretPeNoapte;
		if (this->facilitatiCamera != nullptr) {
			cout << "si are urmatoarea facilitati ";
			for (int i = 0; i < numarFacilitati; i++) {
				cout << this->facilitatiCamera[i] << endl;
			}
		}
	}
	//set
	void setNumarFacilitati(int numarFacilitati) {
		this->numarFacilitati = numarFacilitati;
	}

	// get 

	int getNumarFacilitati() {
		return this->numarFacilitati;
	}
	// constructor cu 3 parametri
	CameraHotel(string numarCamera, int numarFacilitati, float pretPeNoapte) {
		this->numarCamera = numarCamera;
		this->numarFacilitati = numarFacilitati;
		this->pretPeNoapte = pretPeNoapte;
		if (numarFacilitati > 0) {
			this->facilitatiCamera = new string[numarFacilitati];
			for (int i = 0; i < numarFacilitati; i++) {
				this->facilitatiCamera[i] = "ALL";
			}
		}
		else {
			this->facilitatiCamera = nullptr;
		}
	}

	//constructor de copiere
	CameraHotel(const CameraHotel& copie) {
		this->numarCamera = copie.numarCamera;
		this->numarFacilitati = copie.numarFacilitati;
		this->pretPeNoapte = copie.pretPeNoapte;
		if (copie.numarFacilitati > 0 && copie.facilitatiCamera != nullptr) {
			this->facilitatiCamera = new string[copie.numarFacilitati];
			for (int i = 0; i < copie.numarFacilitati; i++) {
				this->facilitatiCamera[i] = copie.facilitatiCamera[i];
			}
		}



	}
	// operator egal 
	void operator =(const CameraHotel& c) {
		this->numarCamera = c.numarCamera;
		this->numarFacilitati = c.numarFacilitati;
		this->pretPeNoapte = c.pretPeNoapte;


		if (c.numarFacilitati > 0 && c.facilitatiCamera != nullptr) {
			this->facilitatiCamera = new string[c.numarFacilitati];
			for (int i = 0; i < c.numarFacilitati; i++) {
				this->facilitatiCamera[i] = c.facilitatiCamera[i];
			}
		}
	}

	//destructor
	~CameraHotel() {
		if (facilitatiCamera != nullptr)
		{
			delete[] this->facilitatiCamera;
		}cout << endl << "Destructor apelat";
	}

	//operator index
	string operator[](int index) {
		if (index > 0 && index << numarFacilitati)
		{
			return this->facilitatiCamera[index];
		}
	}

	//ostream
	friend ostream& operator <<(ostream& out, CameraHotel& c) {
		out << endl << c.numarCamera;
		out << endl << c.numarFacilitati;
		out << endl << c.pretPeNoapte;
		if (c.numarFacilitati > 0 && c.facilitatiCamera != nullptr) {

			for (int i = 0; i < c.numarFacilitati; i++) {
				out << endl << c.facilitatiCamera[i];
			}
		}return out;

	}
	// metoda calcul
	float costPerFacilitate() {

		if (numarFacilitati > 0) {
			return pretPeNoapte / numarFacilitati;
		}
		else { return 0; }

	}
};


void main() {
	CameraHotel camera1;
	camera1.afisare();

	camera1.setNumarFacilitati(5);
	cout << endl << camera1.getNumarFacilitati();

	CameraHotel camera2("A1", 5, 600);
	camera2.afisare();

	CameraHotel camera3 = camera2;
	camera3.afisare();

	CameraHotel camera4;
	camera4 = camera2;
	camera4.afisare();
	cout << endl << camera1[2];

	cout << endl << camera4;
	cout << endl << camera3.costPerFacilitate();


}