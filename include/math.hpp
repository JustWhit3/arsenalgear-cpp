//====================================================
//     Preprocessor settings
//====================================================
#ifndef MATH_HPP
#define MATH_HPP

//====================================================
//     Headers
//====================================================

// Extra headers
#include <exprtk.hpp>

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

  //====================================================
  //     parsed_f
  //====================================================
  // Function used to parse a mathematical function f(x,y).
  template <typename T>
  inline double parsed_f( const T& expr, double x, double y )
   {
    exprtk::rtl::io::file::package<double> fileio_package;

    static exprtk::symbol_table<double> symbol_table;
    symbol_table.add_variable( "x", x );
    symbol_table.add_variable( "y", y );

    static exprtk::expression<double> expression;
    expression.register_symbol_table( symbol_table );
  
    static exprtk::parser<double> parser;
    if ( ! parser.compile( expr, expression ) )
     {
      throw std::runtime_error( "Error in the inserted expression!" );
     }
    
    return expression.value();
   }
 }

#endif