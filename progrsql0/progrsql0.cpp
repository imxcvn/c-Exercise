#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Autor {
	string imie;
	string nazwisko;
	Autor() {

	}
	Autor(const string& imie, const string& nazwisko) {
		this->imie = imie;
		this->nazwisko = nazwisko;
	}

};

std::string PobObecnaDate() {
	std::time_t now = std::time(nullptr);
	char buf[sizeof "YYYY-MM-DD"];
	std::strftime(buf, sizeof buf, "%Y-%m-%d", std::localtime(&now));

	return std::string(buf);
};

class Notatka {
private:
	string tresc;
protected:
	Autor autor;
	string data;
public:
	Notatka() {
		tresc = " ";
		data = PobObecnaDate();
		cout << "Konstruktor bezargumentowy wywolany" << endl;
	}
	Notatka(const Autor& autor, const string& data) {
		this->autor = autor;
		this->data = data;
		cout << "\nKonstruktor dwuargumentowy wywolany" << endl;
	}
	const Autor& getAutor() const {
		return autor;
	}

	void setAutor(const Autor& autor) {
		this->autor = autor;
	}

	const string& getTresc() const {
		return tresc;
	}

	void setTresc(const string& tresc) {
		this->tresc = tresc;
	}

	const string& getData() const {
		return data;
	}

	void setData(const string& data) {
		this->data = data;
	}
};

std::ostream& operator<<(std::ostream& o, const Notatka& notatka) {
	o << "Autor: " << notatka.getAutor().imie << " " << notatka.getAutor().nazwisko << endl;
	o << "Data utworzenia: " << notatka.getData() << endl;
	o << "Tresc notatki: " << notatka.getTresc() << endl;
	o << "\nOperator wywolany" << endl;
	return o;
}



class Rekopis : Notatka {
private:
	string tytul_roboczy;
	string recenzja;
protected:
	string tekst;
	vector<string> spis_tresci;
public:
	Rekopis() {
		this->tytul_roboczy = "tytul";
		this->recenzja = "recenzja";
		cout << "\nKonstruktor bezargumentowy wywolany." << endl;
	}
	Rekopis(string tytul_roboczy) {
		this->tytul_roboczy = tytul_roboczy;
		cout << "\nKonstruktor jednoargumentowy wywolany." << endl;
	}
	Rekopis(const string& tytul_roboczy, const string& nazwisko, const string& imie) 
	{
		this->autor = Autor{ imie, nazwisko };
		this->tytul_roboczy = tytul_roboczy;
		cout << "\nKonstruktor trzyargumentowy wywolany." << endl;
	}

	Rekopis(const Autor& autor, const string& data, const string& tresc, const string& tytul_roboczy, const string& recenzja, const string& tekst, const vector<string>& spis_tresci) 
	:Notatka(autor, data){
		this->setTresc(tresc);
		this->setData(data);
		this->setAutor(autor);
		this->tytul_roboczy = tytul_roboczy;
		this->spis_tresci = spis_tresci;
		this->recenzja = recenzja;
		this->tekst = tekst;
		cout << "\nKonstruktor wieloargumentowy wywolany." << endl;
	}

	~Rekopis() {
		cout << "\Destruktor wywolany." << endl;
	};

	void setTytulRoboczy(const string& tytul) {
		this->tytul_roboczy = tytul;
	}

	const string& getTytulRoboczy() const {
		return tytul_roboczy;
	}

	void setTekst(const string& tekst) {
		this->tekst = tekst;
	}

	const string& getTekst() const {
		return tekst;
	}

	void setSpisTresci(const vector<string>& spis_tresci) {
		this->spis_tresci = spis_tresci;
	}

	const vector<string>& getSpisTresci() const {
		return spis_tresci;
	}

	void setTekstRecenzji(const string& recenzja) {
		this->recenzja = recenzja;
	}

	const string& getTekstRecenzji() const {
		return recenzja;
	}
};

std::ostream& operator<<(ostream& o, const Rekopis& rekopis) {
	o << (const Notatka&)rekopis;  
	o << "Tytul roboczy: " << rekopis.getTytulRoboczy() << endl;
	o << "Tekst: " << rekopis.getTekst() << endl;
	const vector<string>& spis_tresci = rekopis.getSpisTresci();
	cout << "Spis tresci: " << endl;
	for (int i = 0; i < spis_tresci.size(); i++) {
		cout << i + 1 << ". " << spis_tresci[i] << endl;
	}
	o << "Recenzja: " << rekopis.getTekstRecenzji() << endl;
	cout << "\nOperator wywolany." << endl;
	return o;
}

class Ksiazka : Rekopis {
private:
	string wydawnictwo;
	int numer_wydania;
	int rok_wydania;
	string numer_isbn;
public:
	Ksiazka() {
		this->wydawnictwo = "wydawnictwo";
		this->numer_wydania = 0;
		this->rok_wydania = 2003;
		this->numer_isbn = "nr_isbn";
		cout << "\nKonstruktor bezargumentowy wywolany." << endl;
	}

	Ksiazka(const Autor& autor, const string& data, const string& tresc, const string& tytul_roboczy, const string& recenzja, const string& tekst, const vector<string>& spis_tresci, const string& wydawnictwo, int numer_wydania, int rok_wydania, const string& numer_isbn)
		:Rekopis(autor, data, tresc, recenzja, tytul_roboczy, tekst, spis_tresci) {
		this->wydawnictwo = wydawnictwo;
		this->numer_wydania = numer_wydania;
		this->rok_wydania = rok_wydania;
		this->numer_isbn = numer_isbn;
		cout << "\nKostruktor wieloargumentowy wywolany." << endl;
	}

	const string& getWydawnictwo() const {
		return wydawnictwo;
	}

	int getNumerWydania() const {
		return numer_wydania;
	}

	int getRokWydania() const {
		return rok_wydania;
	}

	const string& getNumerIsbn() const {
		return numer_isbn;
	}
};

std::ostream& operator<<(ostream& o, const Ksiazka& ksiazka) {
	o << (const Rekopis&)ksiazka;
	o << "Wydawnictwo: " << ksiazka.getWydawnictwo() << endl;
	o << "Numer wydania: " << ksiazka.getNumerWydania() << endl;
	o << "Rok wydania: " << ksiazka.getRokWydania() << endl;
	o << "Numer isbn: " << ksiazka.getNumerIsbn() << endl;
	cout << "\nOperator wywolany." << endl;
	return o;
}

int main()
{
	Ksiazka k{ Autor {"imie", "nazwisko"}, "12.03.2005", "tresc", "recenzja", "tytul roboczy", "tekst", {"rozdzial 1", "rozdzial 2"}, "wydawnictwo", 2, 2003, "isbn"};
	cout << k << endl;
	
}

