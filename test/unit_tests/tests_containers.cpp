//====================================================
//     Preprocessor settings
//====================================================
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/containers.hpp>

// Extra headers
#include <doctest/doctest.h>

// STD headers
#include <map>
#include <string>

//====================================================
//     extract_map_keys and extract_map_elem
//====================================================
TEST_CASE( "Testing the extract_map_keys and extract_map_elem functions." ) {
    std::map<std::string, int> test_map { { { "first", 1 }, { "second", 2 }, { "third", 3 } } };

    CHECK_EQ( agr::extract_map_keys( test_map )[0], "first" );
    CHECK_EQ( agr::extract_map_keys( test_map )[1], "second" );
    CHECK_EQ( agr::extract_map_keys( test_map )[2], "third" );

    CHECK_EQ( agr::extract_map_elem( test_map )[0], 1 );
    CHECK_EQ( agr::extract_map_elem( test_map )[1], 2 );
    CHECK_EQ( agr::extract_map_elem( test_map )[2], 3 );
}