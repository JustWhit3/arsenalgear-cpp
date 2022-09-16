//====================================================
//     Preprocessor settings
//====================================================
#ifndef OPERATORS_HPP
#define OPERATORS_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <string>

//====================================================
//     std::string * int
//====================================================
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
  std::string output = "";

  while( integer -- ) 
   {
    output += generic_string;
   }
   
  return output;
 }

//====================================================
//     int * std::string
//====================================================
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
  return generic_string * integer;
 }

#endif