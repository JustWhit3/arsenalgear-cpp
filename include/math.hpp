//====================================================
//     Preprocessor settings
//====================================================
#ifndef MATH_HPP
#define MATH_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <cmath>

namespace agr
 {
  //====================================================
  //     roundoff
  //====================================================
  // Function to round a floating point to n-th decimal place after comma.
  template <typename T>
  inline T roundoff( const T& value, const unsigned char prec )
   {
    T pow_10 = pow( 10.0f, static_cast<T> ( prec ) );

    return round( value * pow_10 ) / pow_10;
   }

  //====================================================
  //     IsInBounds
  //====================================================
  // Function to check if a number lies in a certain bound or not.
  template <typename T>
  inline bool IsInBounds( const T& value, const T& low, const T& high )
   {
    return !( value < low ) && ( value < high );
   } 

 }

#endif