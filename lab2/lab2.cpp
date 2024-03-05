#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <vector>
#include "lab2list.h"

//ZAD1

void fillConteiner() {
	std::vector<size_t> v(10);
	std::iota(v.begin(), v.end(), 1);
	//wypelnienie kontenera

	std::for_each(v.begin(), v.end(), [](auto x) { std::cout << x << " "; });
	std::cout << std::endl;
	//wypisanie elementow kontenera
}

//ZAD2

void stars() {
	std::ifstream file{ "pliklab2.txt" };
	if (!file.is_open()) {
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
	}
	else {
		std::vector<std::string> v;

		std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(v));
		//wczytywanie do kontenera
		file.close();
		std::cout << "Wczytane dane z pliku:" << std::endl;
		std::for_each(v.begin(), v.end(), [](auto x) {std::cout << x << " "; });
		std::cout << std::endl;

		size_t condition = 0;
		size_t count = std::count_if(v.begin(), v.end(), [condition](auto star) {return star.length() > condition; });
		std::cout << "Liczba gwiazdek: " << count << std::endl;
		//zliczenie gwiazdek

		std::ofstream file2{ "pliklab2wyj.txt" };
		if (!file2.is_open()) {
			std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		}
		else {
			file2 << count;
			file2.close();
		}
		//wypisanie liczby gwiazdek do pliku
	}
	

}


int main()
{
	//Zad1
	fillConteiner();
	//zad2
	stars();
}


	