//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/type.hpp>

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

  // is_str
  std::string str = "Is this string an std::string? ";
  std::cout << str << agr::is_str( str ) << "\n";

  // is_streamable
  std::cout << "Is a string streamable? " << agr::is_streamable <std::ostream, std::string>::value << "\n";

  // is_any
  std::cout << "Check if int is in the list (int, double, float): " << agr::is_any<int, double, float>() << "\n";
 }

//====================================================
//     main
//====================================================
int main()
 {
  type();
 }