//====================================================
//     File data
//====================================================
/**
 * @file constants.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-09
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */
//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef ARSENALGEAR_CONSTANTS_HPP
#define ARSENALGEAR_CONSTANTS_HPP

namespace agr
 {
  //==================================================== 
  //     String constants
  //====================================================

  // null_str
  /**
   * @brief The string used to represent the null value.
   * 
   */
  template <typename T>
  inline const T null_str = "";

  // empty_space
  /**
   * @brief The string used to represent the empty space.
   * 
   */
  template <typename T>
  inline const T empty_space = " ";
 }

#endif