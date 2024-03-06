#include <iostream>
#include <algorithm>
#include <array>
#include <exception>
#include "lab3.h"

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
        std::for_each(result.begin(), result.end(), [](std::string el) {std::cout << el << std::endl; });
    }

    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
}

void Trojki()
{
    std::array<int, 3> elements;
    std::cout << "Podaj dlugosci bokow trojkata:";
    std::for_each(elements.begin(), elements.end(), [](auto& el) { std::cin >> el; });
    std::sort(elements.begin(), elements.end());
    std::transform(elements.begin(), elements.end(), elements.begin(), [](auto el) { return el * el; });
    if (elements[0] + elements[1] == elements[2]) {
        std::cout << "Trojka pitagorejska." << std::endl;
    }
    else {
        std::cout << "Nie jest trojka pitagorejska." << std::endl;
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

void Odbicie() {
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

void procentSkladany() {
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

void Anagramy() {
    std::string word;
    std::cout << "Podaj slowo: " << std::endl;
    std::cin >> word;

    int number;
    std::cout << "Podaj liczbe anagramow do wylosowania: " << std::endl;
    std::cin >> number;

    Stack<std::string> stack(number);
    for (int i = 0; i < number; i++) {
        int indeksA;
        int indeksB;
        indeksA = rand() % word.length();
        indeksB = rand() % word.length();

        char C = word[indeksA];
        word[indeksA] = word[indeksB];
        word[indeksB] = C;

        stack.push(word);
    }

    for (const std::string& s : stack) {
        std::cout << s << std::endl;
    }
}

int main()
{
    //FizzBuzz();
    //Trojki();
    //nGramy();
    //Odbicie();
    //procentSkladany();
    Anagramy();
    Stack<int> stos(10);
    stos.push(1);
    stos.push(7);
    stos.push(5);

    //std::cout << *stos.begin() << " " << *stos.end() << std::endl;
}



