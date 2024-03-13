#include <iostream>
#include <string>

class Student {
private:
	std::string nazwisko;
	std::string imie;
	int numer_legitymacji;
	int semestr;
	int* srednia;
public:
	Student();
	Student(const std::string& nazwisko, const std::string& imie, int numer_legitymacji);
	~Student();
	void setNazwisko(const std::string& nazwisko);
	const std::string& getNazwisko() const;
	void setImie(const std::string& imie);
	const std::string& getImie() const;
	void setNumer_legitymacji(int numer_legitymacji);
	int getNumer_legitymacji();
	void setSemestr(int semestr);
	int getSemestr();

};