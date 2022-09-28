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
#include <sstream>
#include <array>

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
  //     Functions definition
  //====================================================

  // except_error_func
  /**
   * @brief Function used to throw customized stdexception error. This function is extremely specific to my purposes and you can find examples usages in other my projects lik "osmanip" or "SAFD-algorithm".
   * @tparam T_err The type of the exception error.
   * @param beg The first part of the error message.
   * @param var The variable to be inserted in the error message.
   * @param end The last part of the error message.
   * @return T_err The modified exception error.
   */
  template <typename T_err = std::runtime_error>
  inline T_err except_error_func( const std::string& beg = "", std::string var = nullptr, const std::string& end = "" )
   {
    using namespace std::literals::string_literals;

    static std::ostringstream oss;
    oss.str( "" );
    oss.clear();
    oss << "\033[31m" << beg << " \""s << "\033[1m" << var << "\033[22m" << "\" "s << end << "\033[39m";

    return T_err( oss.str() ); 
   }

  // isFloatingPoint
  /**
   * @brief Function to check if an expression (not a type) is a floating point or not. I know this function is almost useless, but it has been created for lazy purposes and since it is used in other projects it cannot be eliminated now in order to not break backward compatibility.
   * @tparam T The type of the expression.
   * @return bool True if the expression is a floating point, false otherwise.
   */
  template <typename T>
  inline bool isFloatingPoint( const T& )
   {
    return std::is_floating_point <T>::value;
   }

  // one
  /**
   * @brief Function to find the incremented unit of a loop. Not easy to understand its purpose without context, but it is used to get the loop incremented unit in case of loops with floating-point indexes. See example usage in "osmanip" in progress bars "update" method.
   * @tparam T The type of the iterating variable of the loop.
   * @param iterating_var The iterating variable of the loop.
   * @return T The incremented unit of the loop.
   */
  template <typename T>
  inline T one( const T& iterating_var )
   {
    std::vector<T> counter_;

    if( isFloatingPoint( iterating_var ) )
     {
      if( counter_.size() < 2 ) counter_.push_back( iterating_var );
      if( counter_.size() == 2 ) return abs( abs( counter_.front() ) - abs( counter_.back() ) );
      return static_cast <T> ( NULL );
     }

    counter_.clear();
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