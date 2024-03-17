#include <vector>
#include "Zwierze.h"
#include "Slon.h"

class Zoo {
private:
	std::vector<Zwierze*> zwierzeta;
public:
	void dodajZwierze(Zwierze* zwierze) {
		zwierzeta.push_back(zwierze);
	}
	void wypiszZwierzeta() {
		for (int i = 0; i < zwierzeta.size(); i++) {
			std::cout << "Numer zwierzecia: " << i << std::endl;
			zwierzeta[i]->wypisz();
		}
	}
	~Zoo() {
		for (int i = 0; i < zwierzeta.size(); i++) {
			delete zwierzeta[i];
		}
	}
	int policzSlonie() const {
		int suma = 0;
		for (int i = 0; i < zwierzeta.size(); i++) {
			Slon* slon = dynamic_cast<Slon*>(zwierzeta[i]);
			if (slon != nullptr) {
				suma++;
			}
		}
		return suma;
	}
};