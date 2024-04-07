#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>

int counter = 0;
std::mutex m;

void test1() {
    for (int i = 0; i < 1000000; i++) {
        //m.lock();
        std::lock_guard<std::mutex> guard{ m };
        counter++;
        //m.unlock();
    }
}

class Bufor {
private:
    int capacity;
    std::list<int> list;
public:
    Bufor(int size) {
        capacity = size;
    }
    void addElement(int element) {
        if (list.size() == capacity) {
            throw std::runtime_error("Bufor jest pelny.");
        }
        list.push_back(element);
    }
    int takeElement() {
        if (list.size() == 0) {
            throw std::runtime_error("Bufor jest pusty.");
        }
        int element = list.front();
        list.pop_front();
        return element;
    }
    int getSize() {
        return list.size();
    }
    int getCapacity() {
        return capacity;
    }
};

Bufor bufor{5};
int liczbaProducentow;

void producent() {
    int counter = 0;
    while (counter < 100) {
        int ms = 100 + rand() % 401;
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        std::lock_guard<std::mutex> guard{ m };
        if (bufor.getSize() != bufor.getCapacity()) {
            bufor.addElement(counter);
            counter++;
        }
    }
    liczbaProducentow--;
}

void konsument() {
    while (true) {
        int ms = 10 + rand() % 41;
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        std::lock_guard<std::mutex> guard{ m };
        if (bufor.getSize() != 0) {
            std::cout << bufor.takeElement() << std::endl;
        }
        else if (liczbaProducentow == 0) {
            break;
        }
    }
}

int main()
{
    liczbaProducentow = 2;
    std::thread producent1{ producent };
    std::thread producent2{ producent };

    std::thread konsument1{ konsument };
    std::thread konsument2{ konsument };

    producent1.join();
    producent2.join();

    konsument1.join();
    konsument2.join();
    

    /*
    std::vector<std::thread> t;
    for (int i = 0; i < 10; i++) {
        t.emplace_back(test1);
        //t[i].join();
    }
    for (int j = 0; j < t.size(); j++) {
        t[j].join();
    }
    std::cout << counter << std::endl;
    */
}


