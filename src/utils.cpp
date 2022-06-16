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
  std::string multi( const std::string& element, const int& n_times )
   {
    std::string container = "";

    for( int i = 0; i < n_times; i++ ) container.append( element );
    return container;
   }
 }