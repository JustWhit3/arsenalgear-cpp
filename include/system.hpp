//====================================================
//     File data
//====================================================
/**
 * @file system.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef ARSENALGEAR_SYSTEM_HPP
#define ARSENALGEAR_SYSTEM_HPP

//====================================================
//     Headers
//====================================================

//STD headers
#include <string>

namespace agr
 {
  //====================================================
  //     Functions declaration
  //====================================================
  extern std::string getCommandOut( const char* command );
 }

#endif