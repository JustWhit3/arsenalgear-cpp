//====================================================
//     Headers
//====================================================

//My headers
#include "../include/system.hpp"

//STD headers
#include <stdexcept>
#include <string>
#include <array>
#include <memory>
#include <cstdlib>
#include <cstdio>

namespace agr
 {
  //====================================================
  //     getCommandOut
  //====================================================
  /**
   * @brief Function used to get the output of a shell command.
   * 
   * @param command The command which output is required.
   * @return std::string The output of the command variable.
   */
  extern std::string getCommandOut( const char* command ) 
   {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype( & pclose )> pipe( popen( command, "r" ), pclose );

    if ( ! pipe ) 
     {
      throw std::runtime_error( "popen() failed!" );
     }

    while ( fgets( buffer.data(), buffer.size(), pipe.get() ) != nullptr ) 
     {
      result += buffer.data();
     }

    return result;
   }
 }