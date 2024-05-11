#include <iostream>
#include <concepts>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

///////ZAD 1///////
template<typename T>
concept intNumber = std::is_integral<T>::value;

template<intNumber T>
auto dodaj(T a, T b) {
    return a + b;
}

///////ZAD 2///////
template<typename T>
concept Sortable = requires(T & vector) {
    {std::sort(vector.begin(), vector.end())};
};

template<Sortable v>
void sort(v& vector) {
    std::sort(vector.begin(), vector.end());
}

///////ZAD 3///////
template<typename T>
concept Checkable = requires(T a) {
    {a()} -> std::same_as<bool>;
};

template<Checkable C>
void check(C c) {
    if (c()) {
        std::cout << "Typ Checkable, zwraca true." << std::endl;
    }
    else {
        std::cout << "Typ Checkable, zwraca false." << std::endl;
    }
}

template<typename T>
void check(T t) {
    std::cout << "Typ nie-Checkable." << std::endl;
}

class Zad3 {
public:
    bool operator()() const {
        return true;
    }
};

///////ZAD 4///////
template<typename T>
concept Incrementable = requires(T t) {
    {++t} -> std::same_as<T&>;
};

template<typename T>
concept Container = requires(T t) {
    requires Incrementable<typename T::value_type>;
    {t.begin()} -> std::same_as<typename T::iterator>;
    {t.end()} -> std::same_as<typename T::iterator>;
};

template<typename T>
concept IntType = std::is_integral<T>::value;

template<Container c>
void increment(c& container) {
    for (IntType auto& el : container) {
        ++el;
    }
}

int main()
{
    ///////ZAD 1///////
    double a;
    while (true) {
        std::cout << "Podaj a: ";
        if (std::cin >> a) {
            break; 
        }
        else {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Niepoprawny format danych. Wprowadz liczbe." << std::endl;
        }
    }

    double b;
    while (true) {
        std::cout << "Podaj b: ";
        if (std::cin >> b) {
            break; 
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Niepoprawny format danych. Wprowad? liczb?." << std::endl;
        }
    }

    int aa = a;
    int bb = b;

    if (aa - a == 0 && bb - b == 0) {
        std::cout << "a + b = " << dodaj(aa, bb) << std::endl;
    }
    else {
        std::cout << "\nNiepoprawnie wprowadzone dane." << std::endl;
    }
    std::cout << "\n" << std::endl;
    ///////ZAD 2///////
    std::vector<int> v;
    std::string input;
    std::cout << "Podaj liczby do posortowania. By zakonczyc wpisz 'koniec'." << std::endl;
    while (std::cin >> input && input != "koniec") {
        std::stringstream ss(input);
        int number;
        if (ss >> number) {
            v.push_back(number);
        }
        else {
            std::cout << "Blad: '" << input << "' to niepoprawny format danych. Wprowadz liczbe." << std::endl;
        }
    }
    sort(v);
    for (auto x : v) {
        std::cout << x << std::endl;
    }
    std::cout << "\n" << std::endl;
    ///////ZAD 3///////
    Zad3 object;
    int x = 3;
    check(object);
    check(x);
    std::cout << "\n" << std::endl;
    ///////ZAD 4///////
    std::vector<int> v2 = { 1, 2, 3, 4, 5 };
    std::cout << "Elementy kontenera przed inkrementacja: ";
    for (int el : v2) {
        std::cout << el << " ";
    }
    std::cout << "\n" << std::endl;
    increment(v2);
    std::cout << "Elementy kontenera po inkrementacji: ";
    for (int el : v2) {
        std::cout << el << " ";
    }
}

