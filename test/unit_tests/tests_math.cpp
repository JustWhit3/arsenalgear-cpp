//====================================================
//     Preprocessor settings
//====================================================

// Doctest
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

// OS
#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif

//====================================================
//     Headers
//====================================================

// My headers
#include <include/math.hpp>

//Extra headers
#include <doctest/doctest.h>
#include <cmath>

//====================================================
//     roundoff
//==================================================== 
TEST_CASE_TEMPLATE( "Testing the roundoff function.", T, double )
 {
  T var = 3.34;
  T var_2 = 3.456;
  T var_3 = 345.56;

  CHECK_EQ( agr::roundoff( var, 1 ), 3.3 );
  CHECK_EQ( agr::roundoff( var_2, 2 ), 3.46 );
  CHECK_EQ( agr::roundoff( var_3, 1 ), 345.6 );
  CHECK_EQ( agr::roundoff( 0.0034, 3 ), 0.003 );
 }

//============================================
//     IsInBounds
//============================================
TEST_CASE_TEMPLATE( "Testing the IsInBounds function", T, double )
 {
  T var_1 = 3;
  T var_2 = 0.2;
  
  CHECK( agr::IsInBounds( var_1, 2.9, 3.1 ) );
  CHECK( agr::IsInBounds( var_2, 0.1, 0.21 ) );
 }
 