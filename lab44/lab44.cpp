#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include "lab44lista.h"
#include "lab44mapa.h"

struct Data
{
    int day;
    int month;
    int year;

    
    bool operator<(const Data& d) const {
        if (year < d.year) {
            return true;
        } 
        if (year > d.year) {
            return false;
        }
        if (month < d.month) {
            return true;
        }
        if (month > d.month) {
            return false;
        }
        return day < d.day;

    }
    
    bool operator==(const Data& d) const {
        return year == d.year && month == d.month && day == d.day;
    }
};

template <>
struct std::hash<Data> {
    size_t operator()(const Data& d) const {
        return d.year + (d.month << 12) + (d.day << 16);
    }
};

void Zad4()
{
    std::ifstream file("plik3.txt");
    if (!file.is_open()) {
        std::cout << "Nie udalo sie sie otworzyc pliku." << std::endl;
        return;
    }

    std::map<Data, int> entries;

    Data data;
    char dot;
    int temp;
    while (file >> data.day >> dot >> data.month >> dot >> data.year >> temp)
    {
        entries[data] = temp;
    }

    for (auto& p : entries)
    {
        std::cout << "Data: " << p.first.day << '.' << p.first.month << '.' << p.first.year << " temperatura:  " << p.second << "stopni Celsjusza." << std::endl;
    }
    file.close();
}

void Zad4_2()
{
    std::ifstream file("plik3.txt");
    if (!file.is_open()) {
        std::cout << "Nie udalo sie sie otworzyc pliku." << std::endl;
        return;
    }

    std::unordered_map<Data, int> entries;

    Data data;
    char dot;
    int temp;
    while (file >> data.day >> dot >> data.month >> dot >> data.year >> temp)
    {
        entries[data] = temp;
    }

    for (auto& p : entries)
    {
        std::cout << "Data: " << p.first.day << '.' << p.first.month << '.' << p.first.year << " temperatura:  " << p.second << "stopni Celsjusza." << std::endl;
    }
    file.close();
}

struct Entry {
    Data data;
    int temp;
};

void Zad4_3()
{
    std::ifstream file("plik3.txt");
    if (!file.is_open()) {
        std::cout << "Nie udalo sie sie otworzyc pliku." << std::endl;
        return;
    }

    List<Entry> entries;
    Entry entry;
    char dot;
    while (file >> entry.data.day >> dot >> entry.data.month >> dot >> entry.data.year >> entry.temp) {
        entries.addElement(entry);
    }

    for (auto& entry : entries)
    {
        std::cout << "Data: " << entry.data.day << '.' << entry.data.month << '.' << entry.data.year << " temperatura: " << entry.temp  << " stopni Celsjusza." << std::endl;
    }
    file.close();
}


struct Footballer {
    std::string name;
    int number{ -1 };
    int score{ -1 };

    Footballer(const std::string& name, int number) {
        this->name = name;
        this->number = number;
    }
};

void Zad1() {
    std::ifstream file{ "plik1.txt" };
    std::ifstream file2{ "plik2.txt" };
    if (!file.is_open() || !file2.is_open()) {
        std::cout << "Pliku nie udalo sie otworzyc." << std::endl;
    }
    else {
        List<Footballer> list;

        std::string name;
        int number;
        while (file >> name >> number) {
            list.addElement({ name, number });
        }

        int number2, score;
        while (file2 >> number2 >> score) {
            for (auto& f : list) {
                if (f.number == number2) {
                    f.score = score;
                    break;
                }
            }
        }

        for (const auto& l : list) {
            std::cout << "Imie: " << l.name << " numer: " << l.number << " ocena: " << l.score << std::endl;
        }
    }
    file.close();
    file2.close();
}


void Zad1_2()
{
    std::ifstream file("plik1.txt");
    std::ifstream file2("plik2.txt");

    if (!file.is_open() || !file2.is_open()) {
        std::cout << "Nie udalo sie sie otworzyc pliku." << std::endl;
        return;
    }
    else {
        std::map<std::string, int> map1;
        std::map<int, int> map2;

        std::string name;
        int number;
        while (file >> name >> number) {
            map1[name] = number;
        }

        int number2;
        int score;
        while (file2 >> number2 >> score) {
            map2[number2] = score;
        }

        for (auto& p : map1)
        {
            std::cout << "Imie: " << p.first << " numer: " << p.second << " ocena: " << map2[p.second] << std::endl;
        }
    }
    file.close();
    file2.close();
}

void Zad1_3()
{
    std::ifstream file("plik1.txt");
    std::ifstream file2("plik2.txt");

    if (!file.is_open() || !file2.is_open()) {
        std::cout << "Nie udalo sie sie otworzyc pliku." << std::endl;
        return;
    }
    else {
        std::unordered_map<std::string, int> map1;
        std::unordered_map<int, int> map2;

        std::string name;
        int number;
        while (file >> name >> number) {
            map1[name] = number;
        }

        int number2;
        int score;
        while (file2 >> number2 >> score) {
            map2[number2] = score;
        }

        for (const auto& [name, number] : map1) {
            std::cout << "Imie: " << name << " numer: " << number << " ocena: " << map2[number] << std::endl;
        }
    }
    file.close();
    file2.close();
}


int main()
{
    Zad1_3();

    /*
    List<int> lista;
    lista.addElement(2);
    lista.addElement(6);
    lista.addElement(3);
    lista.addElement(5);

    //wypiszListe(lista);


    List<int> lista2{ std::move(lista) };

    //wypiszListe(lista);
    //wypiszListe(lista2);

    List<int> lista3;
    lista3 = std::move(lista2);

    //wypiszListe(lista2);
    //wypiszListe(lista3);

    Map<std::string, std::string> mapa;
    mapa.set("2", "dwa");
    mapa.set("3", "trzy");
    mapa.set("4", "cztery");
    mapa.set("5", "piec");

    mapa.set("3", "TRZY");

    mapa.print();

    Map<std::string, std::string> mapa2{ std::move(mapa) };
    mapa.print();
    mapa2.print();

    Map<std::string, std::string> mapa3;
    mapa3 = std::move(mapa2);

    mapa2.print();
    mapa3.print();

    //Zad1();
    */
}



