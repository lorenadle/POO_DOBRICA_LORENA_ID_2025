#include <iostream>
using namespace std;

class TelefonMobil
{
public:
    TelefonMobil()
    {
        producator = "";
        model = "";
        nivelBaterie = 0;
    }

    TelefonMobil(string _producator, string _model) : producator(_producator), model(_model), nivelBaterie(0)
    {
    }

    TelefonMobil(int nivelBaterie) : TelefonMobil()
    {
        this->nivelBaterie = nivelBaterie;
    }

    TelefonMobil(const TelefonMobil& t)
    {
        this->producator = t.producator;
        (*this).model = t.model;
        nivelBaterie = t.nivelBaterie - 1;
    }

    ~TelefonMobil()
    {
        cout << "apel destructor" << endl;
    }

    string getProducator()
    {
        return producator;
    }

    int getNivelBaterie()
    {
        return nivelBaterie;
    }

    void setNivelBaterie(int _nivelBaterie)
    {
        if (_nivelBaterie >= 0 && _nivelBaterie <= 100)
        {
            nivelBaterie = _nivelBaterie;
        }
    }

    void incarca(int nivelIncarcare)
    {
        nivelBaterie += nivelIncarcare;
    }

    void descarca(int);

protected:
    string producator;
private:
    string model;
    int nivelBaterie;
};

void TelefonMobil::descarca(int nivelDescarcare)
{
    nivelBaterie -= nivelDescarcare;
}

TelefonMobil incrementeazaNivelBaterie(TelefonMobil t)
{
    t.setNivelBaterie(t.getNivelBaterie() + 1);
    return t;
}

int main()
{
    TelefonMobil telefonPersonal;
    TelefonMobil* pTelefon = new TelefonMobil();
   
    delete pTelefon;
    pTelefon = nullptr;

    TelefonMobil telefonDeServiciu("Samsung", "S20");
    pTelefon = new TelefonMobil("Apple", "Iphone 14");
   
    delete pTelefon;
    pTelefon = nullptr;

    TelefonMobil telefon3(70);
    TelefonMobil telefon4 = 70;

    TelefonMobil telefon5(telefon4);
    TelefonMobil telefon6 = telefon5;

  

    cout << telefonDeServiciu.getProducator() << endl;

    cout << telefon3.getNivelBaterie() << endl;
    telefon3.setNivelBaterie(90);
    cout << telefon3.getNivelBaterie() << endl;
    telefon3.setNivelBaterie(120);
    cout << telefon3.getNivelBaterie() << endl;
    telefon3.descarca(30);
    cout << telefon3.getNivelBaterie() << endl;
}