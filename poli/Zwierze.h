#ifndef ZWIERZE_H
#define ZWIERZE_H

#include <iostream>
#include <string>

class Zwierze {
private:
	std::string imie;
	double waga = 0;
public:
	Zwierze() {

	}
	const std::string& getImie() const {
		return imie;
	}
	double getWaga() const {
		return waga;
	}
	void setImie(const std::string& imie) {
		this->imie = imie;
	}
	void setWaga(double waga) {
		this->waga = waga;
	}
	virtual std::string getGatunek() const = 0;
	virtual void dajGlos() const {
		std::cout << "Metoda nie zaimplementowana." << std::endl;
	}
	virtual ~Zwierze() {

	}
	virtual void wypisz() const {
		std::cout << "Imie: " << getImie() << std::endl;
		std::cout << "Waga: " << getWaga() << std::endl;
		std::cout << "Gatunek: " << getGatunek() << std::endl;
	}
};
#endif