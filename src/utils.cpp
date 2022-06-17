//====================================================
//     Headers
//====================================================

// My headers
#include "../include/utils.hpp"

// STD headers
#include <string>

namespace agr
 {
  //====================================================
  //     multi
  //====================================================
  /**
   * @brief Function used to multiply a string for n times.
   * @param element The string to be multiplied.
   * @param n_times The times for the string multiplication.
   * @return std::string The multiplied string.
   */
  std::string multi( const std::string& element, const int& n_times )
   {
    std::string container = "";

    for( int i = 0; i < n_times; i++ ) container.append( element );
    return container;
   }
 }