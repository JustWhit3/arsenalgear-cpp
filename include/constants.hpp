//====================================================
//     Preprocessor settings
//====================================================
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace agr
 {
  //==================================================== 
  //     null_str
  //====================================================
  /**
   * @brief The string used to represent the null value.
   * 
   */
  template <typename T>
  inline const T null_str = "";

  //==================================================== 
  //     empty_space
  //====================================================
  /**
   * @brief The string used to represent the empty space.
   * 
   */
  template <typename T>
  inline const T empty_space = " ";
 }

#endif