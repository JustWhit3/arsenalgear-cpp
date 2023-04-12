//====================================================
//     File data
//====================================================
/**
 * @file math.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-09
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef ARSENALGEAR_MATH_HPP
#define ARSENALGEAR_MATH_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <cmath>

namespace agr
 {
  //====================================================
  //     Functions
  //====================================================

  // roundoff
  /**
   * @brief Function to round a floating point to n-th decimal place after comma.
   * 
   * @tparam T The Type of the variable to be rounded.
   * @param value The variable to be rounded
   * @param prec Precision of the rounding.
   * @return T The rounded variable.
   */
  template <typename T>
  inline T roundoff( T value, unsigned char prec )
   {
    T pow_10 = pow( 10.0f, static_cast<T> ( prec ) );

    return round( value * pow_10 ) / pow_10;
   }

  // IsInBounds
  /**
   * @brief Function to check if a number lies in a certain bound or not.
   * 
   * @tparam T The Type of the variable to be checked.
   * @param value The variable to be checked.
   * @param low The lower bound.
   * @param high The upper bound.
   * @return bool True if the variable lies in the bound, false otherwise.
   */
  template <typename T>
  inline bool IsInBounds( T value, T low, T high )
   {
    return !( value < low ) && ( value < high );
   } 
 }

#endif
