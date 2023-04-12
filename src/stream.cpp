//====================================================
//     File data
//====================================================
/**
 * @file stream.cpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

//My headers
#include <arsenalgear/stream.hpp>

//STD headers
#include <string>

namespace agr {
    //====================================================
    //     savebuf class methods
    //====================================================

    // Parametric constructor
    /**
   * @brief Construct a new savebuf object.
   * 
   * @param sbuf A std::streambuf* object.
   */
    savebuf::savebuf( std::streambuf* sbuf ):
        sbuf( sbuf ) { }

    // str
    /**
   * @brief Method to return the string stored by the output stream.
   * 
   * @return std::string The string stored by the output stream.
   */
    std::string savebuf::str() const {
        return save;
    }

    // overflow
    /**
   * @brief 
   * 
   * @param c 
   * @return int 
   */
    int savebuf::overflow( int c ) {
        if ( !traits_type::eq_int_type( c, traits_type::eof() ) ) {
            save.push_back( traits_type::to_char_type( c ) );
            return sbuf->sputc( c );
        } else {
            return traits_type::not_eof( c );
        }
    }

    // sync
    /**
   * @brief 
   * 
   * @return int 
   */
    int savebuf::sync() {
        return sbuf->pubsync();
    }
}