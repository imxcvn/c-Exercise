#ifndef SLON_H
#define SLON_H

#include <iostream>
#include <string>
#include "Zwierze.h"

class Slon : public Zwierze {
private:
	double dlugosc_traby;
public:
	double getDlugosc() const {
		return dlugosc_traby;
	}
	void setDlugosc(double dlugosc) {
		dlugosc_traby = dlugosc;
	}
	std::string getGatunek() const override {
		return "Slon";
	}
	void dajGlos() const override {
		std::cout << "Slon daje glos." << std::endl;
	}
	~Slon() override {
		std::cout << "Destruktor slonia." << std::endl;
	}
	void wypisz() const {
		Zwierze::wypisz();
		std::cout << "Dlugosc traby: " << getDlugosc() << std::endl;
	}
};
#endif 