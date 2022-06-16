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

namespace agr
 {
  //====================================================
  //     Objects
  //====================================================
  extern boost::iostreams::stream<boost::iostreams::null_sink> null_stream;
 }

#endif