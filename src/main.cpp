// Copyright 2021 by me
#include <iostream>
#include <string>

#include "../include/postfix.h"

int main() {
    std::string s1("2 + 2");
    std::string s2 = infix2postfix(s1);  // I want to calculate a simple example
    std::cout << s2 << "\n";  // the right answer: 2 2 +
    s1 = "1 + 3.5 * (2 - 5 / ( 10 + 9) + 4) - 1.5";  // a harder example
    s2 = infix2postfix(s1);
    std::cout << s2;  // the right answer: 1 3.5 2 5 10 9 + / - 4 + * + 1.5 -
    return 0;
}
