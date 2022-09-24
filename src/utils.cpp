//====================================================
//     File data
//====================================================
/**
 * @file utils.cpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include "../include/utils.hpp"

// STD headers
#include <string>
#include <vector>
#include <regex>

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
  std::string multi( const std::string& element, unsigned int n_times )
   {
    std::string container = "";

    for( unsigned int i = 0; i < n_times; i++ ) container.append( element );
    return container;
   }
  
  //====================================================
  //     split_string
  //====================================================
  /**
   * @brief Function used to split a string based on a certain reges.
   * 
   * @param input The input string.
   * @param regex The regex.
   * @return std::vector<std::string> The collection of string elements splitted by the regex.
   */
  std::vector<std::string> split_string( const std::string& input, const std::string& regex )
   {
    std::regex re( regex );
    std::sregex_token_iterator first{ input.begin(), input.end(), re, -1 }, last;
    return { first, last };
   }
 }