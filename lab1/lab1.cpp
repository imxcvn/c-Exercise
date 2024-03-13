#include "Student.h"
#include <iostream>


int main()
{
    Student student{ "Wolska", "Kasia", 2 };
    std::cout << student.getImie() << std::endl;
}

