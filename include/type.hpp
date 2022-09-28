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
#include <iostream>
#include <typeinfo>

namespace agr
 {
  //====================================================
  //     Structs
  //====================================================

  // is_streamable
  /**
   * @brief Struct used to check if a type is a streamable or not, i.e. it has operator << overload or not.
   * 
   * @tparam S The type of the stream object which should stream the input object.
   * @tparam T The type of the input object.
   * @tparam typename 
   */
  template<typename S, typename T, typename = void>
  struct is_streamable: std::false_type {};

  // is_streamable specialization
  template<typename S, typename T>
  struct is_streamable <S, T, std::void_t<decltype( std::declval <S&>() <<std::declval<T>() ) > >: std::true_type {};

  //====================================================
  //     Functions
  //====================================================

  // is_pointer_to_const_char (first overload)
  /**
   * @brief Function used to check if an input array is a pointer to const char.
   * 
   * @tparam T The input array to be check.
   * @tparam N The dimension of the array.
   * @return true If the array is a pointer to const char.
   * @return false Otherwise.
   */
  template <typename T, std::size_t N>
  constexpr bool is_pointer_to_const_char( T(&)[N] ) 
   { 
    return std::is_same_v <const char, T>;
   }
  
  // is_pointer_to_const_char (second overload)
  /**
   * @brief Function used to check if an input variable is a pointer to const char.
   * 
   * @tparam T The input variable to be check.
   * @return true If the variable is a pointer to const char.
   * @return false Otherwise.
   */
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

  // is_any
  /**
   * @brief Function used to check if a type is in a list or not.
   * 
   * @tparam Kind The type to be checked.
   * @tparam Kinds The types to which the type is compared.
   * @return true If the type is in a list.
   * @return false Otherwise.
   */
  template <typename Kind, typename... Kinds>
  bool is_any()
   {
    if constexpr ( ( std::is_same_v <Kind, Kinds> || ... ) )
     {
      return true;
     } 
    return false;
   }
 }

#endif