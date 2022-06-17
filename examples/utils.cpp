//====================================================
//     Headers
//====================================================

// My headers
#include "../include/utils.hpp"
#include "../include/constants.hpp"

// STD headers
#include <iostream>
#include <string>

//====================================================
//     utils
//====================================================
void utils()
 {
  std::cout << "\n" << "======================================================" << "\n"
                    << "     UTILS                                            " << "\n"
                    << "======================================================" << "\n"
                    << "\n";

  // maxptr
  int *ptr = new int[5];
  std::cout << "Finding max value of this pointer: { ";
  for( int i = 0; i < 5; i++ ) 
   {
    ptr[i] = i;
    std::cout << ptr[i] << agr::empty_space<std::string>;
   }
  std::cout << "} -> " << agr::maxptr( ptr, 5 ) << "." << "\n\n";

  // runtime_error_func
  // commented since it quit the program. Uncomment to try it:
  // std::cout << "Runtime error function example: ";
  // throw agr::runtime_error_func( "Inserted command", "<command>", "is not supported!" );

  // isFLoatingPoint
  std::cout << "Check if 0.00034 is a floating point: " << agr::isFloatingPoint( 0.00034 ) 
            << " (True)." << "\n\n";

  // one
  std::cout << "Check incremented value of for( const auto & element: v ) with v vector of dim = 2: ";
  static std::vector <int> v { 1, 2 };

  for( const auto & element: v )
   {
    if( element == 2 ) std::cout << agr::one( element ) << "." << "\n\n";
   }

  // multi
  std::cout << "Repeating \"this\" for 3 times_ " << agr::multi( "this", 3 ) << "\n\n";
 }

//====================================================
//     main
//====================================================
int main()
 {
  utils();
 }