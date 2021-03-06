//====================================================
//     Headers
//====================================================

//My headers
#include "../include/operators.hpp"

//Extra headers
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>

//====================================================
//     Macros
//====================================================
#define ARGS( ... ) BOOST_PP_TUPLE_TO_SEQ( ( __VA_ARGS__ ) )

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
std::string operator *( const T& generic_string, unsigned int integer ) 
 {
  std::string output = "";

  while( integer -- ) 
   {
    output += generic_string;
   }
   
  return output;
 }

#define PROD_1( r, data, T ) template \
std::string operator * <T> ( const T& generic_string, unsigned int integer );

BOOST_PP_SEQ_FOR_EACH( PROD_1, _, ARGS( std::string, std::string_view ) );

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
std::string operator *( unsigned int integer, const T& generic_string ) 
 {
  return generic_string * integer;
 }

#define PROD_2( r, data, T ) template \
std::string operator * <T> ( unsigned int integer, const T& generic_string );

BOOST_PP_SEQ_FOR_EACH( PROD_2, _, ARGS( std::string, std::string_view ) );
