#include <iostream>
#include <string>
#include "Zwierze.h"

class Zyrafa : public Zwierze {
private:
	double dlugosc_szyi = 0;
public:
	double getDlugosc() const {
		return dlugosc_szyi;
	}
	void setDlugosc(double dlugosc) {
		dlugosc_szyi = dlugosc;
	}
	std::string getGatunek() const override {
		return "Zyrafa";
	}
	void dajGlos() const override {
		std::cout << "Zyrafa daje glos." << std::endl;
	}
	void wypisz() const override {
		Zwierze::wypisz();
		std::cout << "Dlugosc szyi: " << getDlugosc() << std::endl;
	}
};