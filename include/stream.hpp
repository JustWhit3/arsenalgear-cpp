//====================================================
//     Preprocessor settings
//====================================================
#ifndef STREAM_HPP
#define STREAM_HPP

//====================================================
//     Headers
//====================================================

//Extra headers
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/null.hpp>

//STD headers
#include <string>
#include <streambuf>

namespace agr
 {
  //====================================================
  //     Objects
  //====================================================
  extern boost::iostreams::stream<boost::iostreams::null_sink> null_stream 
   {
    boost::iostreams::null_sink{} 
   };

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