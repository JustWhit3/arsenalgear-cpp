//====================================================
//     Headers
//====================================================

//My headers
#include "../include/stream.hpp"

//Extra headers
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/null.hpp>

namespace agr
 {
  //====================================================
  //     null_stream
  //====================================================
  boost::iostreams::stream<boost::iostreams::null_sink> null_stream 
   {
    boost::iostreams::null_sink{} 
   };
 }