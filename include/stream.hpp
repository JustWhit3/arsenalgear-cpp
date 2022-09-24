//====================================================
//     Preprocessor settings
//====================================================
#ifndef STREAM_HPP
#define STREAM_HPP

//====================================================
//     Headers
//====================================================

//STD headers
#include <string>
#include <streambuf>

namespace agr
 {
  //====================================================
  //     savebuf class
  //====================================================
  /**
   * @brief Class used to store the output sent to an output stream.
   * 
   */
  class savebuf: public std::streambuf 
   {
    public:

    //====================================================
    //     Public methods
    //====================================================
    savebuf( std::streambuf* sbuf );
    std::string str() const;

    private:

    //====================================================
    //     Private methods
    //====================================================
    int overflow( int c );
    int sync();

    //====================================================
    //     Private attributes
    //====================================================
    std::streambuf* sbuf;
    std::string     save;
   };
 }

#endif