//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/system.hpp>
#include <arsenalgear/utils.hpp>

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <string>
#include <vector>

//============================================
//     getCommandOut
//============================================
TEST_CASE( "Testing the getCommandOut function." )
 {
  CHECK_EQ( agr::getCommandOut( "echo ciao" ), "ciao\n" );
  
  std::string my_command = "echo \"asd erd ftr\"";
  std::string output = agr::getCommandOut( my_command.c_str() );
  std::vector <std::string> splitted_output = agr::split_string( output, " " );
  CHECK_EQ( splitted_output.back(), "ftr\n" );
 }