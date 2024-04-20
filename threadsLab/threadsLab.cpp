#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <vector>

void zad1(const std::string& komunikat, int liczba) {
    std::cout << komunikat << std::endl;
    int liczba1 = liczba;
    for (int i = 1; i <= 5; i++) {
        std::cout << liczba << " do " << i << " potegi rowna sie " << liczba1 << std::endl;
        liczba1 *= liczba;
    }
}

void natezenie(std::promise<double>& promise, double Q, double t) {
    double natezenie = Q / t;
    promise.set_value(natezenie);
}

void rezystancja(std::promise<double>& promise, double R1, double R2) {
    double R = R1 * R2 / (R1 + R2);
    promise.set_value(R);
}

int add(int a, int b) {
    return a + b;
}

void zad4(std::packaged_task<int(int, int)>& zadanie, int a, int b, std::promise<void>& promise) {
    zadanie(a, b);
    promise.set_value();
}

int main()
{
    ///////ZAD1///////

    /*
    std::thread thread1(zad1, "komunikat1", 2);
    thread1.join();
    std::thread thread2(zad1, "komunikat2", 3);
    thread2.join();
    */

    ///////ZAD2///////
    
    /*
    std::future<int> dlaInt = std::async(std::launch::async, [](int a, int b) {return a + b; }, 30, 39);
    std::future<double> dlaDouble = std::async(std::launch::async, [](double a, double b) {return a + b; }, 45.33, 87.65);
    std::cout << "Wynik dla int: " << dlaInt.get() << std::endl;
    std::cout << "Wynik dla double: " << dlaDouble.get() << std::endl;
    */
    
    ///////ZAD3///////

    /*
    std::promise<double> promise1;
    std::promise<double> promise2;
    std::future<double> future1 = promise1.get_future();
    std::future<double> future2 = promise2.get_future();
    std::thread thread1(natezenie, std::ref(promise1), 4.3, 5);
    thread1.join();
    std::thread thread2(rezystancja, std::ref(promise2), 2, 3.2);
    thread2.join();
    double U = future1.get() * future2.get();
    std::cout << "U = " << U << " V." << std::endl;
    */

    ////////ZAD4///////
    std::vector<std::packaged_task<int(int, int)>> tasks;
    std::vector<std::future<int>> results;

    for (int i = 0; i < 5; ++i) {
        std::packaged_task<int(int, int)> task(add);
        std::future<int> result = task.get_future();
        tasks.push_back(std::move(task));
        results.push_back(std::move(result));
    }

    std::vector<std::thread> threads;
    std::vector<std::promise<void>> promises(5);

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(zad4, std::ref(tasks[i]), i + 1, i + 2, std::ref(promises[i]));
    }

    for (int i = 0; i < 5; ++i) {
        promises[i].get_future().wait();
        threads[i].join();
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << "Wynik " << i + 1 << ": " << results[i].get() << std::endl;
    }

}

