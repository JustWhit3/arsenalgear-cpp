//====================================================
//     Preprocessor settings
//====================================================

// Doctest
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/type.hpp>

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <string>

//====================================================
//     is_pointer_to_const_char
//====================================================
TEST_CASE( "Testing is_pointer_to_const_char function." )
 {
  CHECK( agr::is_pointer_to_const_char( "hey" ) );
  std::string str = "hey";
  CHECK( ! agr::is_pointer_to_const_char( str ) );
 }

//====================================================
//     is_str
//==================================================== 
TEST_CASE( "Testing is_str function." )
 {
  CHECK( agr::is_str( "hey" ) );
  std::string str = "hey";
  CHECK( agr::is_str( str ) );
 }

//====================================================
//     is_streamable
//==================================================== 
TEST_CASE( "Testing is_streamable." )
 {
  CHECK( agr::is_streamable<std::ostream, int>::value );
  CHECK( ! agr::is_streamable<std::ostream, std::ostream>::value );
  CHECK( agr::is_streamable<std::ostream, std::string>::value );
 }

//====================================================
//     is_any
//==================================================== 
TEST_CASE( "Testing is_any." )
 {
  CHECK( agr::is_any<int, int, double, float>() );
  CHECK( ! agr::is_any<int, char, double, float>() );
 }