//====================================================
//     Headers
//====================================================

// STD headers
#include <iostream>
#include <streambuf>

// My headers
#include "../include/stream.hpp"

//====================================================
//     stream
//====================================================
void stream()
 {
  std::cout << "\n" << "======================================================" << "\n"
                      << "     STREAM                                           " << "\n"
                      << "======================================================" << "\n"

                      << "\n";

  //Store the output of a stream using the savebuf class
  std::streambuf* coutbuf = std::cout.rdbuf();
  agr::savebuf sbuf( coutbuf );
  std::cout.rdbuf( &sbuf );
  std::cout << "This string";
  std::cout.rdbuf( coutbuf ); // restore the original stream buffer
  std::cout << "\nI have saved: " << sbuf.str() << "\n\n";
 }

//====================================================
//     main
//====================================================
int main()
 {
  stream();
 }