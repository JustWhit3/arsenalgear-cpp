//====================================================
//     File data
//====================================================
/**
 * @file operators.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-09
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef ARSENALGEAR_OPERATORS_HPP
#define ARSENALGEAR_OPERATORS_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <string>

//====================================================
//     String operators
//====================================================

// std::string * int
/**
 * @brief Function to multiply a string by an integer.
 * 
 * @param str The string to be multiplied.
 * @param n The integer to be multiplied.
 * @return std::string The multiplied string.
 */
template <typename T>
inline std::string operator *( const T& generic_string, unsigned int integer ) 
 {
  std::string output;
  output.reserve( integer * generic_string.size() );

  while( integer -- ) 
   {
    output += generic_string;
   }
   
  return output;
 }

// int * std::string
/**
 * @brief Function to multiply an integer by a string.
 * 
 * @param str The string to be multiplied.
 * @param n The integer to be multiplied.
 * @return std::string The multiplied string.
 */
template <typename T>
inline std::string operator *( unsigned int integer, const T& generic_string ) 
 {
  std::string result = generic_string * integer;
  return result;
 }

#endif
