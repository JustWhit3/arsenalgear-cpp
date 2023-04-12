//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/containers.hpp>

// STD headers
#include <iostream>
#include <string>
#include <map>

//====================================================
//     containers
//====================================================
void containers()
 {
  std::cout << "\n" << "======================================================" << "\n"
                    << "     CONTAINERS                                       " << "\n"
                    << "======================================================" << "\n"
                    << "\n";

  // extract_map_keys and extract_map_elem
  std::map <std::string, int> test_map = { { "first", 1 }, { "second", 2 }, { "third", 3 } };
  std::string str_map = "{ { \"first\", 1 }, { \"second\", 2 }, { \"third\", 3 } }:";
  std::cout << "Extracting keys and elements of " + str_map + "\n";

  std::cout << "Keys: ";
  for ( auto& key: agr::extract_map_keys( test_map ) ) std::cout << key << " ";
  std::cout << "\n";

  std::cout << "Elements: ";
  for ( auto& elem: agr::extract_map_elem( test_map ) ) std::cout << elem << " ";
  std::cout << "\n";
 }

//====================================================
//     main
//====================================================
int main()
 {
  containers();
 }