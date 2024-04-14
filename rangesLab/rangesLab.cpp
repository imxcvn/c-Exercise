#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <string>
#include <random>

void zad1() {
    std::vector<int> VEC{ 1,2,3,4,5,6 };      //jezeli vector bedzie const funkcja nie zadziala, wykonanie wtedy na nim jakichkolwiek operacji modyfikujacych jego zawartosc jest nie mozliwe
    auto VIEW = VEC | std::views::drop(3) | std::views::reverse;
    std::ranges::sort(VIEW);
    for (auto x : VEC) {
        std::cout << x << std::endl;
    }
}

void zad2() {
    std::vector<int> VEC{ 1,2,3,4,5,6 };
    auto VIEW = VEC | std::views::filter([](auto i) {return i % 2 == 0; }) | std::views::transform([](auto i) {return i * i; });
    for (auto x : VIEW) {
        std::cout << x << std::endl;
    }
}

void zad3() {
    std::vector < double > VEC1{ 2,4,6,8 };
    auto KWADRAT = VEC1 | std::views::transform([](auto i) {return i * i / 2; });
    auto KOLO = VEC1 | std::views::transform([](auto i) {return i * i * 3.14; });
    auto TROJKAT = VEC1 | std::views::transform([](auto i) {return i * i * sqrt(3) / 4; });
    auto PROSTOKAT = VEC1 | std::views::transform([](auto i) {return i * 2 * i; });
    std::vector<double> VEC2;
    VEC2.append_range(KWADRAT);
    VEC2.append_range(KOLO);
    VEC2.append_range(TROJKAT);
    VEC2.append_range(PROSTOKAT);
    std::sort(VEC2.begin(), VEC2.end());
    auto duplikaty = std::ranges::unique(VEC2.begin(), VEC2.end());
    VEC2.erase(std::ranges::begin(duplikaty), std::ranges::end(duplikaty));
    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::ranges::shuffle(VEC2, gen);
    for (auto x : VEC2) {
        std::cout << x << std::endl;
    }
}

void zad4() {
    std::vector<std::pair<std::string, int>> VEC{ {"Anna", 40},{"Jakub", 57},{"Karol", 20},{"Oliwia", 69} };
    auto VIEW = VEC | std::views::filter([](auto i) {return i.second < 50; }) | std::views::keys;
    for (auto x : VIEW) {
        std::cout << x << std::endl;
    }
}

int main()
{
    //zad1();
    //zad2();
    zad3();
    //zad4();
}


