//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/utils.hpp>
#include <arsenalgear/constants.hpp>

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <string>
#include <vector>
#include <stdexcept>

//====================================================
//     Namespaces
//====================================================
using namespace std::string_literals;

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
//     StringConverter
//==================================================== 
TEST_CASE( "Testing StringConverter function." )
 {
  // char
  CHECK_EQ( agr::StringConverter<char>( "Hello" ), "Hello" );
  CHECK_EQ( agr::StringConverter<char>( "Test a long string" ), "Test a long string" );
  CHECK_EQ( agr::StringConverter<char>( "" ), "" ); 

  // wchar_t
  CHECK_EQ( agr::StringConverter<wchar_t>( "Hello" ), L"Hello" );
  CHECK_EQ( agr::StringConverter<wchar_t>( "Test a long string" ), L"Test a long string" );
  CHECK_EQ( agr::StringConverter<wchar_t>( "" ), L"" ); 
  // char16_t

  CHECK_EQ( agr::StringConverter<char16_t>( "Hello" ), u"Hello" );
  CHECK_EQ( agr::StringConverter<char16_t>( "Test a long string" ), u"Test a long string" );
  CHECK_EQ( agr::StringConverter<char16_t>( "" ), u"" ); 

  // char32_t
  CHECK_EQ( agr::StringConverter<char32_t>( "Hello" ), U"Hello" );
  CHECK_EQ( agr::StringConverter<char32_t>( "Test a long string" ), U"Test a long string" );
  CHECK_EQ( agr::StringConverter<char32_t>( "" ), U"" ); 

  // char8_t
  #if ( __cplusplus >= 202002L )
    CHECK_EQ( agr::StringConverter<char8_t>( "Hello" ), u8"Hello" );
    CHECK_EQ( agr::StringConverter<char8_t>( "Test a long string" ), u8"Test a long string" );
    CHECK_EQ( agr::StringConverter<char8_t>( "" ), u8"" );
  #endif
 }

//====================================================
//     is_escape
//==================================================== 
TEST_CASE( "Testing is_escape function." )
 {
  CHECK( ! agr::is_escape( "aaa", agr::ANSI::first ) );
  CHECK( agr::is_escape( "\033[30m", agr::ANSI::first ) );
  CHECK( agr::is_escape( "aaa\033[30m", agr::ANSI::generic ) );
 }