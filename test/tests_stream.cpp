//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include "../include/stream.hpp"

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <iostream>
#include <streambuf>

//============================================
//     null_stream
//============================================
TEST_CASE( "Testing the null_stream." )
 {
  auto v = []( std::ostream& os = agr::null_stream )
   {
    if( &os != &agr::null_stream ) return 10;
    return 5;
   };

  CHECK_EQ( v(), 5 );
  CHECK_EQ( v( std::cout ), 10 );
 }

//============================================
//     savebuf class
//============================================
TEST_CASE( "Testing the savebuf class." )
 {
  std::streambuf* coutbuf = std::cout.rdbuf();
  agr::savebuf sbuf( coutbuf );
  std::cout.rdbuf( &sbuf );
  std::cout << "Test";
  std::cout.rdbuf( coutbuf );
  CHECK_EQ( sbuf.str(), "Test" );
 }