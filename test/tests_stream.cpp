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