//====================================================
//     File data
//====================================================
/**
 * @file system.cpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include <arsenalgear/system.hpp>

// STD headers
#include <array>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>

namespace agr {
    //====================================================
    //     Functions
    //====================================================

    // getCommandOut
    /**
   * @brief Function used to get the output of a shell command.
   * 
   * @param command The command which output is required.
   * @return std::string The output of the command variable.
   */
    std::string getCommandOut( const char* command ) {
        std::array<char, 128> buffer;
        std::string           result;
    #ifdef _WIN32
        std::unique_ptr<FILE, decltype( &_pclose )> pipe( _popen( command, "r" ), _pclose );
    #else
        std::unique_ptr<FILE, decltype( &pclose )> pipe( popen( command, "r" ), pclose );
    #endif

        if ( !pipe ) {
            throw std::runtime_error( "popen() failed!" );
        }

        while ( fgets( buffer.data(), buffer.size(), pipe.get() ) != nullptr ) {
            result += buffer.data();
        }

        return result;
    }
}