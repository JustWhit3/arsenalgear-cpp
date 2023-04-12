//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/constants.hpp>
#include <arsenalgear/operators.hpp>

// STD headers
#include <iostream>
#include <string>

//====================================================
//     operators
//====================================================
void operators() {
    std::cout << "\n"
              << "======================================================"
              << "\n"
              << "     OPERATORS                                        "
              << "\n"
              << "======================================================"
              << "\n"
              << "\n";

    // * strings by an integer:
    std::string a { "a" };
    std::cout << "Multiplying \"a\" for 5 times: " << a * 5 << agr::empty_space<std::string_view> * 5
              << "adding spaces."
              << "\n\n";
}

//====================================================
//     main
//====================================================
int main() {
    operators();
}