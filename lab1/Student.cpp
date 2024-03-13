#include "Student.h"

Student::Student() {
	this->nazwisko = "Nowak";
	this->imie = "Jan";
	this->numer_legitymacji = 0;
	std::cout << "Konstruktor 1 wywolany" << std::endl;
}

Student::Student(const std::string& nazwisko, const std::string& imie, int numer_legitymacji) {
	this->nazwisko = nazwisko;
	this->imie = imie;
	this->numer_legitymacji = numer_legitymacji;
	std::cout << "Konstruktor 2 wywolany" << std::endl;
}

void Student::setNazwisko(const std::string& nazwisko) {
	this->nazwisko = nazwisko;
}

const std::string& Student::getNazwisko() const {
	return this->nazwisko;
}

void Student::setImie(const std::string& imie) {
	this->imie = imie;
}

const std::string& Student::getImie() const {
	return this->imie;
}

void Student::setNumer_legitymacji(int numer_legitymacji) {
	this->numer_legitymacji = numer_legitymacji;
}

int Student::getNumer_legitymacji() {
	return this->numer_legitymacji;
}

void Student::setSemestr(int semestr) {
	this->semestr = semestr;
}

int Student::getSemestr() {
	return this->semestr;
}

Student::~Student() {
	std::cout << "Destruktor wywolany" << std::endl;
}