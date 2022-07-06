//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include "../include/utils.hpp"
#include "../include/constants.hpp"

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <string>
#include <vector>
#include <stdexcept>
#include <map>

//====================================================
//     Namespaces
//====================================================
using namespace std::string_literals;

//====================================================
//     maxptr
//====================================================
TEST_CASE( "Testing the maxptr function." )
 {
  int *p = new int[5];
  double *t = new double[2];

  for( int i = 0; i < 5; i++ ) p[i] = i;
  for( int i = 0; i < 2; i++ ) t[i] = ( i + 50 ) / 10;

  CHECK_EQ( agr::maxptr( p, 5 ), 4 );
  CHECK_EQ( agr::maxptr( t, 2 ), 5 );
 }

//====================================================
//     isFloatingPoint
//====================================================
TEST_CASE_TEMPLATE( "Testing the isFLoatingPoint function.", T, double, float, long double )
 {
  T type = 0.;
  const int integer = 2;
  
  CHECK( ! agr::isFloatingPoint( integer ) );
  CHECK( agr::isFloatingPoint( type ) );
 }

//====================================================
//     except_error_func
//==================================================== 
TEST_CASE( "Testing the except_error_func function." )
 {
  std::string var = "this";
  const std::string test_string = "\033[31mfirst" + " \""s +
                                  "\033[1m" + static_cast <std::string>( var ) + 
                                  "\033[22m" + "\" "s +
                                  "second\033[39m" +
                                  "\n";
                       
  CHECK_THROWS_AS( throw( agr::except_error_func( "first", var, "second" ) ), std::runtime_error );
  CHECK_THROWS_AS( throw( agr::except_error_func<std::out_of_range>( "first", var, "second" ) ), std::out_of_range );
  CHECK_THROWS_MESSAGE( throw( agr::except_error_func( "first", var, "second" ) ), test_string );
 }

//====================================================
//     one
//==================================================== 
TEST_CASE( "Testing the one function." )
 {
  std::vector <int> v { 1, 2, 3, 4 };
  std::vector <int> counter_ {};

  for( const auto & element: v )
   {
    if( counter_.size() == 2 )
     {
      CHECK_EQ( agr::one( element ), abs( abs( counter_.front() ) - abs( counter_.back() ) ) );
     }
    counter_.push_back( element );
   }
 }

//====================================================
//     multi
//==================================================== 
TEST_CASE( "Testing the multi function." )
 {
  CHECK_EQ( agr::multi( "this", 2 ), "thisthis" );
  CHECK_EQ( agr::multi( "a ", 5 ), "a a a a a " );
 }

//====================================================
//     split_string
//==================================================== 
TEST_CASE( "Testing the split_string function." )
 {
  CHECK_EQ( agr::split_string( "aa bb cc", " " )[1], "bb" );
  CHECK_EQ( agr::split_string( "aaqfq dddd ff", " " ).back(), "ff" );
 }

//====================================================
//     extract_map_keys and extract_map_elem
//==================================================== 
TEST_CASE( "Testing the extract_map_keys and extract_map_elem functions." )
 {
  std::map <std::string, int> test_map = { { "first", 1 }, { "second", 2 }, { "third", 3 } };

  CHECK_EQ( agr::extract_map_keys( test_map )[0], "first" );
  CHECK_EQ( agr::extract_map_keys( test_map )[1], "second" );
  CHECK_EQ( agr::extract_map_keys( test_map )[2], "third" );

  CHECK_EQ( agr::extract_map_elem( test_map )[0], 1 );
  CHECK_EQ( agr::extract_map_elem( test_map )[1], 2 );
  CHECK_EQ( agr::extract_map_elem( test_map )[2], 3 );
 }