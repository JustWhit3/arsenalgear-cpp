//====================================================
//     File data
//====================================================
/**
 * @file stream.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef ARSENALGEAR_STREAM_HPP
#define ARSENALGEAR_STREAM_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <iostream>
#include <string>

namespace agr
 {
  //====================================================
  //     Classes
  //====================================================

  // savebuf
  /**
   * @brief Class used to store the output sent to an output stream.
   * 
   */
  class savebuf: public std::streambuf 
   {
    public:

    //====================================================
    //     Public methods declaration
    //====================================================
    savebuf( std::streambuf* sbuf );
    std::string str() const;

    private:

    //====================================================
    //     Private methods declaration
    //====================================================
    int overflow( int c );
    int sync();

    //====================================================
    //     Private attributes
    //====================================================
    std::streambuf* sbuf;
    std::string     save;
   };

  //====================================================
  //     Structs
  //====================================================
  
  // select_cout
  /**
   * @brief Struct used to define a way to template the choice of the "std::cout" object in order to be "std::cout" for "char" type or "std::wcout" for "wchar_t" type.
   * 
   * @tparam T The template type of the "std::cout" object (char, wchar_t, ...).
   */  
  template <class T> 
  struct select_cout
   {
    static std::basic_ostream<T> &cout;
   };

  // select_cout specializations
  template <> inline std::ostream &select_cout <char>::cout = std::cout;
  template <> inline std::wostream &select_cout <wchar_t>::cout = std::wcout;

  // select_cin
  /**
   * @brief Struct used to define a way to template the choice of the "std::cin" object in order to be "std::cin" for "char" type or "std::wcin" for "wchar_t" type.
   * 
   * @tparam T The template type of the "std::cin" object (char, wchar_t, ...).
   */  
  template <class T> 
  struct select_cin
   {
    static std::basic_istream<T> &cin;
   };

  // select_cin specializations
  template <> inline std::istream &select_cin <char>::cin = std::cin;
  template <> inline std::wistream &select_cin <wchar_t>::cin = std::wcin;
 }

#endif