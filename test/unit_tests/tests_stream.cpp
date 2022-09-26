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

//============================================
//     select_cout
//============================================
TEST_CASE( "Testing select_cout" )
 {
  CHECK_EQ( &agr::select_cout<char>::cout, &std::cout );
  CHECK_EQ( &agr::select_cout<wchar_t>::cout, &std::wcout );
 }

//============================================
//     select_cin
//============================================
TEST_CASE( "Testing select_cin" )
 {
  CHECK_EQ( &agr::select_cin<char>::cin, &std::cin );
  CHECK_EQ( &agr::select_cin<wchar_t>::cin, &std::wcin );
 }