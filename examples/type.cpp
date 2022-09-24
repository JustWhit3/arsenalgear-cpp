//====================================================
//     Headers
//====================================================

// My headers
#include "../include/type.hpp"

// STD headers
#include <iostream>
#include <string>

//====================================================
//     type
//====================================================
void type()
 {
  std::cout << "\n" << "======================================================" << "\n"
                      << "     TYPE                                           " << "\n"
                      << "======================================================" << "\n"

                      << "\n";

  //is_pointer_to_const_char
  const char * c_str = "Is this string a pointer to const char? ";
  std::cout << c_str << agr::is_pointer_to_const_char( c_str ) << "\n";

  //is_pointer_to_const_char
  std::string str = "Is this string an std::string? ";
  std::cout << str << agr::is_pointer_to_const_char( str ) << "\n";
 }

//====================================================
//     main
//====================================================
int main()
 {
  type();
 }