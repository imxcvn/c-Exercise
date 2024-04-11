#include <iostream>
#include <regex>
#include <string>
#include <fstream>

void zad1(const std::string& word) {
    if (word.size() >= 8) {
        std::regex two_numbers(R"(\d{2})");
        std::regex big_letter("[A-Z]");
        std::regex small_letter("[a-z]");
        std::regex digit("[^0-9a-zA-z]{1}");
        if (std::regex_search(word, two_numbers) && std::regex_search(word, big_letter) && std::regex_search(word, small_letter), std::regex_search(word, digit)) {
            std::cout << "Prawidlowe haslo." << std::endl;
        }
        else {
            std::cout << "Nieprawidlowe haslo." << std::endl;
        }
        return;
    }
}

void zad2(const std::string& email) {
    std::regex pattern("^[a-z0-9._+-]+@[a-z.]+\\.[a-z]{2,3}$");
    if (std::regex_match(email, pattern)) {
        std::cout << "Poprawny email." << std::endl;
    }
    else {
        std::cout << "Niepoprawny email." << std::endl;
    }
    return;
}

void zad3() {
    std::ifstream file("LOREM-IPSUM.txt");
    if (!file.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku (LOREM-IPSUM.txt)." << std::endl;
    }
    else {
        std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        std::regex wordRegex(R"(\b[aA]\w{3,}[mtrb]\b)"); 

        std::sregex_iterator it(text.begin(), text.end(), wordRegex);
        std::sregex_iterator end;

        std::cout << "Pasujace slowa:" << std::endl;
        while (it != end) {
            std::cout << it->str() << std::endl;
            ++it;
        }
 
    }
    file.close();
}

void zad4() {
    std::ifstream file("PAN-TADEUSZ.txt");
    if (!file.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku (PAN-TADEUSZ.txt)." << std::endl;
    }
    else {
        std::vector<std::string> soplicaLines;
        std::string line;
        std::regex soplicaRegex("Soplica\\b");
        while (std::getline(file, line)) {
            if (std::regex_search(line, soplicaRegex)) {
                soplicaLines.push_back(line);
                if (soplicaLines.size() == 20)
                    break;
            }
        }

        std::cout << "Pierwsze 20 linii zawierajacych slowo 'Soplica':" << std::endl;
        for (const auto& soplicaLine : soplicaLines) {
            std::cout << soplicaLine << std::endl;
        }

        file.clear();
        file.seekg(0, std::ios::beg);

        int zosiaCount = 0;
        int currentLine = 1;

        std::cout << "\n" << std::endl;

        while (std::getline(file, line)) {
            std::regex zosiaRegex("\\bZosia\\b");
            std::sregex_iterator it(line.begin(), line.end(), zosiaRegex);
            while (it != std::sregex_iterator()) {
                ++zosiaCount;
                if (zosiaCount == 23) {
                    std::cout << "Linia, w ktorej wystepuje 23-cie wystapienie slowa 'Zosia': " << currentLine << std::endl;
                    std::cout << line << std::endl;
                    break;
                }
                ++it;
            }
            if (zosiaCount == 23)
                break;
            ++currentLine;
        }

    }
    file.close();
}

int main()
{
    ///ZAD1///
    std::string password;
    std::cout << "Podaj haslo: ";
    std::cin >> password;
    zad1(password);

    ///ZAD2///
    //std::string email{ "anna.m.nowak@gmail.com" };
    std::string email;
    std::cout << "Podaj email: ";
    std::cin >> email;
    zad2(email);

    ///ZAD3///
    zad3();

    ///ZAD4///
    zad4();
}


