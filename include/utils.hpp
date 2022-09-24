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

//====================================================
//     Namespaces
//====================================================
using namespace std::literals::string_literals;

namespace agr
 {
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
 }

#endif