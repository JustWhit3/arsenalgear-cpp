//====================================================
//     File data
//====================================================
/**
 * @file type.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-09-24
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef TYPE_HPP
#define TYPE_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <type_traits>
#include <string>
#include <string_view>

namespace agr
 {
  //====================================================
  //     Functions
  //====================================================

  // is_pointer_to_const_char
  /**
   * @brief Function used to check if a pointer is a pointer to const char.
   * 
   * @tparam T The input pointer to be check.
   * @tparam N The dimension of the pointer.
   * @return true If the pointer is a pointer to const char.
   * @return false Otherwise.
   */
  template <typename T, std::size_t N>
  constexpr bool is_pointer_to_const_char( T(&)[N] ) 
   { 
    return std::is_same_v <const char, T>;
   }
  
  // is_pointer_to_const_char specialization
  template<typename T>
  constexpr bool is_pointer_to_const_char( T&& ) 
   { 
    return std::is_same_v <const char *, T>;
   }
  
  // is_str
  /**
   * @brief Function used to check if a variable is a string object (std::string, const char*, etc...).
   * 
   * @tparam T The type of the input variable.
   * @param obj The input variable.
   * @return true If the variable is a string object.
   * @return false Otherwise.
   */
  template <class T>
  constexpr bool is_str( const T& obj )
   {
    return is_pointer_to_const_char( obj ) || std::is_same_v<T, std::string> || std::is_same_v<T, std::string_view>;
   }
 }

#endif