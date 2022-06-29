//====================================================
//     Preprocessor settings
//====================================================
#ifndef MATH_HPP
#define MATH_HPP

//====================================================
//     Headers
//====================================================

// Extra headers
#if defined( __linux__ ) || defined( __APPLE__ )
#include <exprtk.hpp>
#endif

// STD headers
#include <cmath>

namespace agr
 {
  //====================================================
  //     roundoff
  //====================================================
  /**
   * @brief Function to round a floating point to n-th decimal place after comma.
   * 
   * @tparam T The Type of the variable to be rounded.
   * @param value The variable to be rounded
   * @param prec Precision of the rounding.
   * @return T The rounded variable.
   */
  template <typename T>
  inline T roundoff( const T& value, const unsigned char prec )
   {
    T pow_10 = pow( 10.0f, static_cast<T> ( prec ) );

    return round( value * pow_10 ) / pow_10;
   }

  //====================================================
  //     IsInBounds
  //====================================================
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
  inline bool IsInBounds( const T& value, const T& low, const T& high )
   {
    return !( value < low ) && ( value < high );
   } 

  //====================================================
  //     parsed_f
  //====================================================
  /**
   * @brief Function to parse a mathematical expression f(x,y) (Only for Linux and MacOS).
   * 
   * @tparam T The Type of the expression to be parsed.
   * @param expr The mathematical expression to be parsed.
   * @param x The x variable.
   * @param y The y variable.
   * @return double The parsed expression.
   */
  #if defined( __linux__ ) || defined( __APPLE__ )
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
  #endif
 }

#endif