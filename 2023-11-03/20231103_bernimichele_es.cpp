#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
	string nome;
	string dataDiNascita;
	int contapassi;
public:
	Persona(string nome, string dataDiNascita) : nome(nome), dataDiNascita(dataDiNascita), contapassi(0) {}
	void cammina(int passi) {
		if (passi < 0) {
			throw invalid_argument("Impossibile camminare passi negativi");
		}
		contapassi += passi;
	}
	void piangi() {
		cout << ";_;" << endl;
	}
	void ridi(){
		cout << "Hahahahaha!" << endl;
	}
	string getNome() {
		return nome;
	}
	string getDataDiNascita() {
		return dataDiNascita;
	}
	int getContapassi() {
		return contapassi;
	}
};

int main()
{
	Persona p1("Franks", "25 Dicembre anno 0");
	try
	{
		p1.cammina(-5);
	}
	catch(const invalid_argument& e)
	{
		cerr << e.what() << endl;
	}
	p1.cammina(25);
	cout << "passi: " << p1.getContapassi() << endl;

	return 0;
}