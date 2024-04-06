#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

void zad1() {
    std::filesystem::path path = "data.txt";
    if (std::filesystem::exists(path)) {
        std::cout << "Plik istnieje." << std::endl;
    }
    else
        std::cout << "Plik nie istnieje." << std::endl;
}

void zad2() {
    std::filesystem::path path = "output.txt";
    std::ofstream file(path);
    if (file.is_open()) {
        file << "Witaj, swiecie!";
        file.close();
        std::cout << "Stworzono plik i zapisano dane." << std::endl;
    }
    else
        std::cout << "Blad otwierania pliku." << std::endl;
}

void zad3() {
    std::filesystem::path file1("data.txt");
    if (!std::filesystem::exists(file1)) {
        std::cout << "Plik nie jest dostepny." << std::endl;
        return;
    }
    std::filesystem::path file2("copy.txt");
    if (std::filesystem::exists(file2)) {
        std::cout << "Czy nadpisac plik?" << std::endl;
        std::string decision;
        std::cin >> decision;
        if (decision == "nie") {
            return;
        }
    }
    try {
        std::filesystem::copy_file(file1, file2);
        std::cout << "Plik zostal skopiowany." << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cout << "Blad w kopiowaniu pliku: " << e.what() << std::endl;
    }
}

void zad4(const std::filesystem::path& path) {
    for (auto const& dir_entry : std::filesystem::directory_iterator{ path }) {
        if (std::filesystem::is_directory(dir_entry)) {
            std::cout << dir_entry.path() << std::endl;
            zad4(dir_entry.path());
        }
        else {
            std::cout << dir_entry.path() << std::endl;
        }
    }
}

int main()
{
    //zad1();
    zad2();
    //zad3();
    //std::string path;
    //std::cout << "Podaj sciezke: ";
    //std::getline(std::cin, path);
    //zad4(path);
}




