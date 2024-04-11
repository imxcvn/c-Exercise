#include <iostream>
#include <regex>

int main()
{
    std::string s = "aBc 12.06 -42 +8.801 aaabCC";
    std::regex r1("(\\+|-)?([0-9]+)(([.,])([0-9]+))?");
    if (std::regex_search(s, r1)) {
        std::cout << "Dopasowane." << std::endl;
    }
    else
        std::cout << "Nie dopasowane." << std::endl;
    if (std::regex_match(s, r1)) {
        std::cout << "Caly string dopasowany." << std::endl;
    }
    else
        std::cout << "Caly string nie dopasowany." << std::endl;

    std::regex r2("^[a-zA-Z]");
    std::cout << "r2 search: " << std::regex_search(s, r2) << std::endl;
    std::regex r3("^[0-9]");
    std::cout << "r3 search: " << std::regex_search(s, r3) << std::endl;

    std::sregex_iterator numberIterator(s.begin(), s.end(), r1);
    std::sregex_iterator numberEnd;

    while (numberIterator != numberEnd) {
        std::smatch match = *numberIterator;
        std::string match_str = match.str();
        std::cout << "  " << match_str << '\n';
        for (size_t i = 0; i < match.size(); i++) {
            std::cout << "    " << match[i].str() << std::endl;
        }
        ++numberIterator;
    }
}


