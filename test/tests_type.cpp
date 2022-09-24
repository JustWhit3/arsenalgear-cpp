//====================================================
//     Preprocessor settings
//====================================================

// Doctest
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include "../include/type.hpp"

// Extra headers
#include <doctest/doctest.h>

// STD headers

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