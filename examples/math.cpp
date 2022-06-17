//====================================================
//     Preprocessor settings
//====================================================
#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif

//====================================================
//     Headers
//====================================================

// My headers
#include "../include/math.hpp"

// STD headers
#include <iostream>
#include <cmath>

//====================================================
//     math
//====================================================
void math()
 {
  std::cout << "\n" << "======================================================" << "\n"
                    << "     MATH                                             " << "\n"
                    << "======================================================" << "\n"
                    << "\n";

  // Roundoff
  std::cout << "Round " << 3.546 << " until 2-nd precision digits after comma: " 
            << agr::roundoff( 3.546, 2 ) << "." << "\n\n";

  // isInBounds
  std::cout << "Check if 3 is between 2 and 4: " << agr::IsInBounds( 3, 2, 4 ) << " (True)." 
            << "\n\n";

  // parsed_f
  #if defined( __linux__ ) || defined( __APPLE__ )
  std::cout << "\n";
  std::cout << "Parsing cos(x) + sin(y) for x=pi/2 and y=pi/4: " << agr::parsed_f( "cos(x)+sin(y)", M_PI/2, M_PI/4 ) 
            << "." << "\n\n"; 
  #endif
 }

//====================================================
//     main
//====================================================
int main()
 {
  math();
 }