//====================================================
//     Headers
//====================================================

//My headers
#include "../include/stream.hpp"

//STD headers
#include <streambuf>
#include <string>

namespace agr
 {
  //====================================================
  //     savebuf::savebuf
  //====================================================
  /**
   * @brief Construct a new savebuf object.
   * 
   * @param sbuf A std::streambuf* object.
   */
  savebuf::savebuf( std::streambuf* sbuf ): 
   sbuf( sbuf ) 
   {}

  //====================================================
  //     savebuf::savebuf
  //====================================================
  /**
   * @brief Method to return the string stored by the output stream.
   * 
   * @return std::string The string stored by the output stream.
   */
  std::string savebuf::str() const 
   { 
    return save; 
   }

  //====================================================
  //     savebuf::overflow
  //====================================================
  /**
   * @brief 
   * 
   * @param c 
   * @return int 
   */
  int savebuf::overflow( int c ) 
   {
    if ( ! traits_type::eq_int_type( c, traits_type::eof() ) ) 
     {
      save.push_back( traits_type::to_char_type( c ) );
      return sbuf -> sputc( c );
     }
    else 
     {
      return traits_type::not_eof( c );
     }
   } 

  //====================================================
  //     savebuf::sync
  //====================================================
  /**
   * @brief 
   * 
   * @return int 
   */
  int savebuf::sync() 
   { 
    return sbuf -> pubsync(); 
   }
 }