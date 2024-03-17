#include <iostream>
#include "Zoo.h"
#include "Zwierze.h"
#include "Slon.h"
#include "Zyrafa.h"

int main()
{
    Slon slon;
    Zyrafa zyrafa;
    slon.dajGlos();
    std::cout << slon.getGatunek() << std::endl;

    zyrafa.dajGlos();
    std::cout << zyrafa.getGatunek() << std::endl;

    Zoo zoo;
    Slon* slon1 = new Slon{};
    slon1->setImie("Jan");
    slon1->setWaga(100);

    Zyrafa* zyrafa1 = new Zyrafa{};
    zyrafa1->setImie("Anna");
    zyrafa1->setWaga(90.5);
    zyrafa1->setDlugosc(50.6);

    Slon* slon2 = new Slon{};
    slon2->setImie("Daniel");
    slon2->setWaga(158.2);

    Zyrafa* zyrafa2 = new Zyrafa{};
    zyrafa2->setImie("Oliwier");
    zyrafa2->setWaga(123);
    zyrafa2->setDlugosc(49.5);

    zoo.dodajZwierze(slon1);
    zoo.dodajZwierze(zyrafa1);
    zoo.dodajZwierze(slon2);
    zoo.dodajZwierze(zyrafa2);

    zoo.wypiszZwierzeta();

    std::cout << "/n" << std::endl;
    std::cout << "Liczba sloni: " << zoo.policzSlonie() << std::endl;
}

