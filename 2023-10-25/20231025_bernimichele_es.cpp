#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Prodotto {
private:
	string nomeProdotto, codiceProdotto, marchioProdotto;
	float prezzoProdotto;
public:
	Prodotto() : nomeProdotto(""), codiceProdotto(""), marchioProdotto(""), prezzoProdotto(0.0) {} //Default constructor
	Prodotto(string nome, string codice, string marchio, float prezzo) {
		nomeProdotto = nome;
		codiceProdotto = codice;
		marchioProdotto = marchio;
		prezzoProdotto = prezzo;
	}
	float getPrezzo() {
		return prezzoProdotto;
	}
	string getNome() {
		return nomeProdotto;
	}
	string getCodiceProdotto() {
		return codiceProdotto;
	}
};

class Cliente {
private:
	string nome, cognome, indirizzo, email, telefono;
public:
	Cliente() {
		nome = "";
		cognome = "";
		indirizzo = "";
		email = "";
		telefono = "";
	}

	Cliente(string nom, string cogn, string indi, string mail, string tel) {
		nome = nom;
		cognome = cogn;
		indirizzo = indi;
		email = mail;
		telefono = tel;
	}
	string getNomeCompleto() {
		return nome + " " + cognome;
	}
	string getEmail() {
		return email;
	}
	string getTelefono() {
		return telefono;
	}
	string getIndirizzo() {
		return indirizzo;
	}
};

class ProdottoDisponibilita{
private:
	Prodotto prodotto;
	int disponibilita;
public:
	ProdottoDisponibilita(Prodotto prodotto, int disponibilita) : prodotto(prodotto), disponibilita(disponibilita) {};
	Prodotto getProdotto() {
		return prodotto;
	}
	int getDisponibilita() {
		return disponibilita;
	}
	void aggiornaDisponibilita(int quantita) {
		disponibilita = quantita;
	}
};

class Ordine {
private:
	Cliente cliente;
	vector <ProdottoDisponibilita> carrello;
	float spesaTotale;
	bool confermato;
public:
	Ordine(Cliente cliente) {
		this->cliente = cliente;
		spesaTotale = 0.0;
		confermato = false;
	}
	void aggiungiProdotto(ProdottoDisponibilita prodotto, int quantita) {
		if (prodotto.getDisponibilita() <= 0) {
			cout << "Prodotto non disponibile per esaurimento scorte." << endl;
		}
		else {
			for (int i = 0; i < quantita; i++) {
				if (prodotto.getDisponibilita() > 0) {
					carrello.push_back(prodotto);
					prodotto.aggiornaDisponibilita(prodotto.getDisponibilita() - 1);
				}
				else {
					cout << "Impossibile aggiungere tutti i prodotti al carrello, aggiunti solo " << i << endl;
					break;
				}
			}
		}
	}
	void rimuoviProdotto(ProdottoDisponibilita prodotto, int quantita) {
		int contaRimossi = 0;
		vector <ProdottoDisponibilita> ::iterator it = carrello.begin();
		while (it != carrello.end()) {
			if (it->getProdotto().getCodiceProdotto() == prodotto.getProdotto().getCodiceProdotto()) {
				it = carrello.erase(it);
				prodotto.aggiornaDisponibilita(prodotto.getDisponibilita() + 1);
				contaRimossi++;
				if (contaRimossi == quantita) {
					break;
				}
			}
			else {
				++it;
			}
		}
	}
	float calcolaTotale() {
		float totale = 0;
		for (int i = 0; i < carrello.size(); i++) {
			totale += carrello[i].getProdotto().getPrezzo();
		}
		return totale;
	}
	void confermaOrdine() {
		if (confermato) {
			cout << "L'ordine è già stato confermato." << endl;
		}
		else {
			confermato = true;
			cout << "Ordine di " << cliente.getNomeCompleto() << " confermato" << endl;
		}
	}
	Cliente getClienteDiOrdine() {
		return cliente;
	}
	int contaQuantiProdottiRimossi(ProdottoDisponibilita prodotto, int quantita) {
		int contaRimossi = 0;
		vector <ProdottoDisponibilita> ::iterator it = carrello.begin();
		while (it != carrello.end()) {
			if (it->getProdotto().getCodiceProdotto() == prodotto.getProdotto().getCodiceProdotto()) {
				prodotto.aggiornaDisponibilita(prodotto.getDisponibilita() + 1);
				contaRimossi++;
				if (contaRimossi == quantita) {
					break;
				}
			}
			else {
				++it;
			}
		}
		return contaRimossi;
	}
	int contaQuantiProdottiAggiunti(ProdottoDisponibilita prodotto, int quantita) {
		if (prodotto.getDisponibilita() <= 0) {
			return 0;
		}
		else {
			for (int i = 0; i < quantita; i++) {
				if (prodotto.getDisponibilita() > 0) {
					prodotto.aggiornaDisponibilita(prodotto.getDisponibilita() - 1);
				}
				else {
					return i;
				}
			}
			return quantita;
		}
	}

};

class Negozio {
private:
	vector <ProdottoDisponibilita> catalogo;
	vector <Cliente> clientiRegistrati;
	vector <Ordine> vettoreOrdini;

	
	int findIndexOfObject(vector <ProdottoDisponibilita> vettoreProdottiDisponibilita, Prodotto prodotto) {
		for (int i = 0; i < vettoreProdottiDisponibilita.size(); i++) {
			if (vettoreProdottiDisponibilita[i].getProdotto().getCodiceProdotto() == prodotto.getCodiceProdotto()) {
				return i;
			}
		}
		return -1;
	}
	int findIndexOfObject(vector <Cliente> vettoreClienti, Cliente cliente) {
		for (int i = 0; i < vettoreClienti.size(); i++) {
			if (vettoreClienti[i].getTelefono() == cliente.getTelefono()) {
				return i;
			}
		}
		return -1;
	}
	int findIndexOfObject(vector <Ordine> vettoreOrdini, Cliente cliente) {
		for (int i = 0; i < vettoreOrdini.size(); i++) {
			if (vettoreOrdini[i].getClienteDiOrdine().getTelefono() == cliente.getTelefono()) {
				return i;
			}
		}
		return -1;
	}
	bool objectIsInVector(vector <ProdottoDisponibilita> vettoreProdotti, Prodotto prodotto) {
		for (int i = 0; i < vettoreProdotti.size(); i++) {
			if (vettoreProdotti[i].getProdotto().getCodiceProdotto() == prodotto.getCodiceProdotto()) {
				return true;
			}
		}
		return false;
	}

	bool objectIsInVector(vector <Cliente> vettoreClienti, Cliente cliente) {
		for (int i = 0; i < vettoreClienti.size(); i++) {
			if (vettoreClienti[i].getTelefono() == cliente.getTelefono()) {
				return true;
			}
		}
		return false;
	}
	bool clienteHaGiaOrdineInCorso(Cliente cliente) {
		for (int i = 0; i < vettoreOrdini.size(); i++) {
			if (vettoreOrdini[i].getClienteDiOrdine().getTelefono() == cliente.getTelefono()) {
				return true;
			}
		}
		return false;
	}
public:
	void aggiungiProdottoAlCatalogo(Prodotto prodotto, int disponibilitaIniziale) {
		if (objectIsInVector(catalogo, prodotto)) {
			cout << "Il prodotto e' gia presente nel catalogo, riforniscilo usando rifornisciProdotto" << endl;
		}
		else {
			
			catalogo.push_back(ProdottoDisponibilita(prodotto, disponibilitaIniziale));
		}

	}
	void rifornisciProdotto(Prodotto prodotto, int quantita) {
		if (objectIsInVector(catalogo, prodotto)) {
			catalogo[findIndexOfObject(catalogo, prodotto)].aggiornaDisponibilita(catalogo[findIndexOfObject(catalogo, prodotto)].getDisponibilita() + quantita);
		}
		else {
			cout << "Il prodotto non e' presente nel catalogo, prima aggiungilo usando aggiungiProdottoAlCatalogo" << endl;
		}
	}
	void rimuoviProdotto(Prodotto prodotto) {
		if (objectIsInVector(catalogo, prodotto)) {
			catalogo.erase(catalogo.begin() + findIndexOfObject(catalogo, prodotto));
		}
		else {
			cout << "Il prodotto non e' presente nel catalogo, impossibile rimuoverlo" << endl;
		}
	}
	int getDisponibilitaProdotto(Prodotto prodotto) {
		if (objectIsInVector(catalogo, prodotto)) {
			return catalogo[findIndexOfObject(catalogo, prodotto)].getDisponibilita();
		}
		else {
			return 15;
		}
	}
	void aggiungiProdottoAOrdine(Cliente cliente, Prodotto prodotto, int quantita) {
		if (clienteHaGiaOrdineInCorso(cliente)) {
			if (objectIsInVector(catalogo, prodotto)) {
				int modificatoreDisponibilita = -vettoreOrdini[findIndexOfObject(vettoreOrdini, cliente)].contaQuantiProdottiAggiunti(catalogo[findIndexOfObject(catalogo, prodotto)], quantita);
				vettoreOrdini[findIndexOfObject(vettoreOrdini, cliente)].aggiungiProdotto(catalogo[findIndexOfObject(catalogo, prodotto)], quantita);
				catalogo[findIndexOfObject(catalogo, prodotto)].aggiornaDisponibilita(catalogo[findIndexOfObject(catalogo, prodotto)].getDisponibilita() + modificatoreDisponibilita);
			}
			else {
				cout << "Il prodotto non e' disponibile nella lista dei prodotti" << endl;
			}
		}
		else {
			cout << "Il cliente non ha un ordine in corso" << endl;
		}
	}
	void rimuoviProdottoAOrdine(Cliente cliente, Prodotto prodotto, int quantita) {
		if (clienteHaGiaOrdineInCorso(cliente)) {
			int modificatoreDisponibilita = vettoreOrdini[findIndexOfObject(vettoreOrdini, cliente)].contaQuantiProdottiAggiunti(catalogo[findIndexOfObject(catalogo, prodotto)], quantita);
			vettoreOrdini[findIndexOfObject(vettoreOrdini, cliente)].rimuoviProdotto(catalogo[findIndexOfObject(catalogo, prodotto)], quantita);
			catalogo[findIndexOfObject(catalogo, prodotto)].aggiornaDisponibilita(catalogo[findIndexOfObject(catalogo, prodotto)].getDisponibilita() + modificatoreDisponibilita);
		}
		else {
			cout << "Il cliente non ha un ordine in corso" << endl;
		}
	}
	void registraCliente(Cliente cliente) {
		if (objectIsInVector(clientiRegistrati, cliente)) {
			cout << "Il cliente e' gia presente nella lista dei clienti registrati" << endl;
		}
		else {
			clientiRegistrati.push_back(cliente);
		}
	}
	void creaOrdine(Cliente cliente) {
		if (clienteHaGiaOrdineInCorso(cliente)) {
			cout << "Il cliente ha gia un ordine in corso, prima termini il vecchio" << endl;
		}
		else {
			vettoreOrdini.push_back(Ordine(cliente));
		}
	}
	void visualizzaOrdini() {
		cout << "Ordini in attesa di conferma: " << endl;
		for (int i = 0; i < vettoreOrdini.size(); i++) {
			cout << vettoreOrdini[i].getClienteDiOrdine().getNomeCompleto() << " per un totale di " << vettoreOrdini[i].calcolaTotale() << " Euro" << endl;
		}
	}
	void confermaOrdine(Cliente clienteDelOrdine) {
		int i = findIndexOfObject(vettoreOrdini, clienteDelOrdine);
		vettoreOrdini[i].confermaOrdine();
		vettoreOrdini.erase(vettoreOrdini.begin() + i);
	}
};

int main() {
	Cliente c1("Cliente", "Test", "Via test 123", "cliente.test@gmail.com", "1234567890");
	Prodotto p1("Prodotto", "codiceProdotto12345", "MarchioTest", 1.50);
	Negozio n1;
	n1.registraCliente(c1);
	n1.aggiungiProdottoAlCatalogo(p1, 0);
	cout << "Disponibilita' del prodtto p1: " << n1.getDisponibilitaProdotto(p1) << endl;
	n1.aggiungiProdottoAlCatalogo(p1, 10);
	cout << "Disponibilita' del prodtto p1: " << n1.getDisponibilitaProdotto(p1) << endl;
	n1.rifornisciProdotto(p1, 100);
	cout << "Disponibilita' del prodtto p1: " << n1.getDisponibilitaProdotto(p1) << endl;
	n1.creaOrdine(c1);
	n1.aggiungiProdottoAOrdine(c1, p1, 25);
	cout << "Disponibilita' del prodtto p1: " << n1.getDisponibilitaProdotto(p1) << endl;
	n1.rimuoviProdottoAOrdine(c1, p1, 10);
	cout << "Disponibilita' del prodtto p1: " << n1.getDisponibilitaProdotto(p1) << endl;
	n1.visualizzaOrdini();
	n1.confermaOrdine(c1);
	n1.visualizzaOrdini();

	return 0;
}