#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <fstream>
#include "Lab5lista.h"
#include "Lab5stack.h"
#include "Lab5lista2.h"
#include "Lab5lista3.h"
//#include "Lab5pointer.h"


void FizzBuzz() {
    try {
        Stack<std::string> result{ 100 };
        for (int i = 100; i >= 1; --i) {
            std::string element;
            if (i % 3 == 0) {
                element = "Fizz";
            }
            if (i % 5 == 0) {
                element += "Buzz";
            }
            if (element.empty()) {
                element = std::to_string(i);
            }
            result.push(element);
        }
        for (std::string el : result) {
            std::cout << el << std::endl;
        }
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

void FizzBuzz2() {
    try {
        List<std::string> result;
        for (int i = 100; i >= 1; --i) {
            std::string element;
            if (i % 3 == 0) {
                element = "Fizz";
            }
            if (i % 5 == 0) {
                element += "Buzz";
            }
            if (element.empty()) {
                element = std::to_string(i);
            }
            result.addElement(element);
        }
        for (std::string el : result) {
            std::cout << el << std::endl;
        }
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

void procentSkladany() {
    try {
        double firstValue;
        std::cout << "Podaj poczatkowa wartosc: " << std::endl;
        std::cin >> firstValue;

        double change;
        std::cout << "Podaj przyrost na jednostke czasu w procentach: " << std::endl;
        std::cin >> change;

        int unitCount;
        std::cout << "Podaj ilosc jednostek czasu: " << std::endl;
        std::cin >> unitCount;

        Stack<double> stack(unitCount + 1);

        double factor = 1 + change / 100;
        double currentValue = firstValue;
        for (int i = 0; i <= unitCount; i++) {
            stack.push(currentValue);
            currentValue = currentValue * factor;
        }

        Stack<double> stack2(unitCount + 1);
        for (double element : stack) {
            stack2.push(element);
        }

        int licznik = 0;
        for (double element : stack2) {
            std::cout << licznik << " -> " << element << std::endl;
            licznik++;
        }
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

void Odbicie() {
    try {
        int number;
        std::cout << "Podaj liczbe: " << std::endl;
        std::cin >> number;

        Stack<int> stack(10);
        do {
            int lastDigit = number % 10;
            stack.push(lastDigit);
            number = number / 10;
        } while (number != 0);

        Stack<int> stack2(10);
        for (int digit : stack) {
            stack2.push(digit);
        }

        for (int digit : stack2) {
            std::cout << digit;
        }
        std::cout << std::endl;
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

void Odbicie2() {
    try {
        int number;
        std::cout << "Podaj liczbe: " << std::endl;
        std::cin >> number;

        List<int> list;
        do {
            int lastDigit = number % 10;
            list.addElement(lastDigit);
            number = number / 10;
        } while (number != 0);

        List<int> list2;
        for (int digit : list) {
            list2.addElement(digit);
        }

        for (int digit : list2) {
            std::cout << digit;
        }
        std::cout << std::endl;
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

void Trojki()
{
    try {
        Stack<int> stack(3);
        std::cout << "Podaj dlugosci bokow trojkata:";
        for (int i = 0; i < 3; i++) {
            int el;
            std::cin >> el;
            stack.push(el);
        }
        std::sort(stack.begin(), stack.end(), std::less<int>{});
        for (int el : stack) {
            std::cout << el << std::endl;
        }
        for (int& el : stack) {
            el = el * el;
        }
        if (*stack.begin() + *(++stack.begin()) == *(++(++stack.begin()))) {
            std::cout << "Trojka pitagorejska." << std::endl;
        }
        else {
            std::cout << "Nie jest trojka pitagorejska." << std::endl;
        }
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}


void Trojki2()
{
    try {
        List<int> list;
        std::cout << "Podaj dlugosci bokow trojkata:";
        for (int i = 0; i < 3; i++) {
            int el;
            std::cin >> el;
            list.addElement(el);
        }
        list.sort();
        for (int el : list) {
            std::cout << el << std::endl;
        }
        for (int& el : list) {
            el = el * el;
        }
        if (list.getElementAt(0) + list.getElementAt(1) == list.getElementAt(2)) {
            std::cout << "Trojka pitagorejska." << std::endl;
        }
        else {
            std::cout << "Nie jest trojka pitagorejska." << std::endl;
        }
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}


struct Skrot {
    std::string short1;
    int number{ -1 };
    std::string long1;
};

void Abbreviations() {
    try {
        std::ifstream file{ "plik.txt" };
        std::ifstream file2{ "plik2.txt" };
        if (!file.is_open() || !file2.is_open()) {
            std::cout << "Pliku nie udalo sie otworzyc." << std::endl;
        }
        else {
            List<Skrot> list;

            std::string short1;
            int number;
            while (file >> short1 >> number) {
                list.addElement({ short1, number });
            }

            int number2;
            std::string long1;

            while (file2 >> number2 >> std::ws && std::getline(file2, long1)) {
                for (auto& f : list) {
                    if (f.number == number2) {
                        f.long1 = long1;
                        break;
                    }
                }
            }

            for (const auto& l : list) {
                std::cout << "Skrot: " << l.short1 << " Rozwiniecie: " << l.long1 << std::endl;
            }

            std::string word;
            std::cout << "Podaj skrot: " << std::endl;
            std::cin >> word;

            for (const auto& s : list) {
                if (s.short1 == word) {
                    std::cout << "Skrot: " << s.short1 << " Rozwiniecie: " << s.long1 << std::endl;
                }
            }
        }
        file.close();
        file2.close();
    }

    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Abbreviations2() {
    try {
        std::ifstream file{ "plik.txt" };
        std::ifstream file2{ "plik2.txt" };
        if (!file.is_open() || !file2.is_open()) {
            std::cout << "Pliku nie udalo sie otworzyc." << std::endl;
        }
        else {
            Stack<Skrot> stack(10);

            std::string short1;
            int number;
            while (file >> short1 >> number) {
                stack.push({ short1, number });
            }

            int number2;
            std::string long1;

            while (file2 >> number2 >> std::ws && std::getline(file2, long1)) {
                for (auto& f : stack) {
                    if (f.number == number2) {
                        f.long1 = long1;
                        break;
                    }
                }
            }

            for (const auto& l : stack) {
                std::cout << "Skrot: " << l.short1 << " Rozwiniecie: " << l.long1 << std::endl;
            }

            std::string word;
            std::cout << "Podaj skrot: " << std::endl;
            std::cin >> word;

            for (const auto& s : stack) {
                if (s.short1 == word) {
                    std::cout << "Skrot: " << s.short1 << " Rozwiniecie: " << s.long1 << std::endl;
                }
            }
        }
        file.close();
        file2.close();
    }

    catch (std::exception& e) {
        std::wcout << e.what() << std::endl;
    }
}

void nGramy() {
    try {
        std::string text;
        std::cout << "Podaj slowo:" << std::endl;
        std::cin >> text;

        int n;
        std::cout << "Podaj n:" << std::endl;
        std::cin >> n;

        Stack<std::string> stack(text.length());
        if (n <= 0 || n > text.length()) {
            std::cerr << "Nieprawidlowa wartosc n.\n";
            return;
        }

        for (int i = 0; i <= text.length() - n; ++i) {
            std::string ngram = text.substr(i, n);
            stack.push(ngram);
        }

        std::cout << "N-gramy:\n";
        while (!stack.empty()) {
            std::cout << stack.top() << "\n";
            stack.pop();
        }
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

void nGramy2() {
    try {
        std::string text;
        std::cout << "Podaj slowo:" << std::endl;
        std::cin >> text;

        int n;
        std::cout << "Podaj n:" << std::endl;
        std::cin >> n;

        List3<std::string>& list =List3<std::string>::getInstance();
        if (n <= 0 || n > text.length()) {
            std::cerr << "Nieprawidlowa wartosc n.\n";
            return;
        }

        for (int i = 0; i <= text.length() - n; ++i) {
            std::string ngram = text.substr(i, n);
            list.addElement(ngram);
        }

        std::cout << "N-gramy:\n";
        for (auto& el : list) {
            std::cout << el << std::endl;
        }
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}


int main()
{
    //FizzBuzz();
    //FizzBuzz2();
    //procentSkladany();
    //Odbicie();
    //Odbicie2();
    //Abbreviations2();
    //Trojki2();
    nGramy2();

    /*List<int> lista;
    lista.addElement(1);
    lista.addElement(2);
    lista.addElement(3);
    try {
        std::cout << lista.getElementAt(4) << std::endl;
    }
    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    */

    /*
    class A
    {
    public:
        int a;
        A(int a) : a{ a } {}
    };
    Pointer<A> p1 = new A{ 10 };
    Pointer<A> p2 = new A{ 20 };
    p2 = std::move(p1);
    std::cout << p2->a << std::endl;
    */
}


