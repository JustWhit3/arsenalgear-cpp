//====================================================
//     File data
//====================================================
/**
 * @file utils.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <stdexcept>
#include <functional>
#include <type_traits>
#include <vector>
#include <string>
#include <stdexcept>
#include <codecvt>
#include <locale>

//====================================================
//     Namespaces
//====================================================
using namespace std::literals::string_literals;

namespace agr
 {
  //====================================================
  //     Enum classes
  //====================================================
  enum class ANSI { first, generic };

  //====================================================
  //     Functions
  //====================================================
  extern std::string multi( const std::string& element, unsigned int n_times );
  extern std::vector <std::string> split_string( const std::string& input, const std::string& regex );
  
  //====================================================
  //     maxptr
  //====================================================
  /**
   * @brief Function used to find the maximum value of a generic pointer containing listed values.
   * @tparam T The type of the pointer.
   * @param ptr The given pointer.
   * @param dim The pointer dimension.
   * @return T The maximum value of the pointer elements.
   */
  template <typename T>
  inline T maxptr ( T *ptr, int ptr_dim )
   {
    if( ptr_dim == 1 ) return *ptr;
    return *ptr > ( ptr_dim = maxptr( ptr + 1, ptr_dim - 1 ) ) ? *ptr : ptr_dim;
   }

  //====================================================
  //     except_error_func
  //====================================================
  // Function used to throw customized runtime error.
  /**
   * @brief Function used to throw customized stdexception error.
   * @tparam T_err The type of the exception error.
   * @param beg The first part of the error message.
   * @param variable The variable to be inserted in the error message.
   * @param end The last part of the error message.
   * @return T_err The modified exception error.
   */
  template <typename T_err = std::runtime_error, typename T>
  inline T_err except_error_func( const std::string& beg = "", T variable = NULL, const std::string& end = "" )
   {
    static std::string error = "\033[31m" +
                               beg + " \""s + 
                               "\033[1m" +
                               static_cast <std::string>( variable ) +
                               "\033[22m" + "\" "s + 
                               end +
                               "\033[39m";

    return T_err( error ); 
   }

  //====================================================
  //     isFloatingPoint
  //====================================================
  /**
   * @brief Function to check if an expression is a floating point or not.
   * @tparam T The type of the expression.
   * @return bool True if the expression is a floating point, false otherwise.
   */
  template <typename T>
  inline bool isFloatingPoint( const T& )
   {
    return std::is_floating_point <T>::value;
   }

  //====================================================
  //     one
  //====================================================
  // Function to find the incremented unit of a loop.
  /**
   * @brief Function to find the incremented unit of a loop.
   * @tparam T The type of the iterating variable of the loop.
   * @param iterating_var The iterating variable of the loop.
   * @return T The incremented unit of the loop.
   */
  template <typename T>
  inline T one( const T& iterating_var )
   {
    static std::vector<T> counter_( 2 );

    if( isFloatingPoint( iterating_var ) )
     {
      if( counter_.size() < 2 ) counter_.push_back( iterating_var );
      if( counter_.size() == 2 ) return abs( abs( counter_.front() ) - abs( counter_.back() ) );
      return static_cast <T> ( NULL );
     }
    return 1;
   }

  // StringConverter
  /**
   * @brief Function used to convert an std::string into other string types (std::wstring etc...). If the argument is an std::string it will be returned without any modification.
   * 
   * @tparam CharT The char type (char, wchar_t...) to which the string is converted..
   * @param input_str The input std::string object.
   * @return std::conditional_t<std::is_same_v<CharT, char>, const std::basic_string<CharT>&, std::basic_string<CharT>> The converted string object.
   */
  template <class CharT>
  std::conditional_t<std::is_same_v<CharT, char>, const std::basic_string<CharT>&, std::basic_string<CharT>>
  StringConverter( const std::string& input_str )
   {
    if constexpr( std::is_same_v <CharT, char> ) 
     {
      return input_str;
     }
    else if constexpr( std::is_same_v <CharT, wchar_t> )
     {
      static std::wstring_convert <std::codecvt_utf8_utf16 <wchar_t>> converter_wchar_t;
      return converter_wchar_t.from_bytes( input_str );
     }
    #ifndef __APPLE__
    #if ( __cplusplus >= 202002L )
    else if constexpr( std::is_same_v <CharT, char8_t> )
     {
      return reinterpret_cast <const char8_t*>( input_str.c_str() );
     }
    #endif
    else if constexpr( std::is_same_v <CharT, char16_t> )
     {
      static std::wstring_convert <std::codecvt_utf8_utf16 <char16_t>, char16_t> converter_16_t;
      return converter_16_t.from_bytes( input_str );
     } 
    else if constexpr( std::is_same_v <CharT, char32_t> )
     {
      static std::wstring_convert <std::codecvt_utf8_utf16 <char32_t>, char32_t> converter_32_t;
      return converter_32_t.from_bytes( input_str );
     }
    #endif
    else 
     {
      return StringConverter<CharT>( "" );
     }
   }

  // is_escape
  /**
   * @brief This method is used to check if an input variable is an ANSI escape sequency or not.
   * 
   * @tparam T Template type of the input variable.
   * @param str The input variable.
   * @param flag A flag which let to return different things with respect to its value. If flag = ANSI::first the ANSI is searched as the first substring of the str argument, otherwise, if flag = ANSI::generic the ANSI is searched as a substring inside the str argument.
   * @return true If the input variable is an ANSI escape sequency.
   * @return false Otherwise.
   */
  template <typename T>
  bool is_escape( const T& str, const ANSI& flag )
   {
    if constexpr( std::is_convertible_v <T, std::string_view> && ! std::is_same_v<T, std::nullptr_t> )
     {
      switch( flag )
       {
        case( ANSI::first ): 
         {
          return ( std::string_view( str ).length() < 7 ) && ( str[0] == '\033' );
         }
        case( ANSI::generic ):
         {
          return ( std::string_view( str ).find( '\033' ) != std::string_view::npos );
         }
       }
     }
    return false;
   }
 }

#endif