//====================================================
//     File data
//====================================================
/**
 * @file containers.hpp
 * @author Gianluca Bianco (biancogianluca9@gmail.com)
 * @date 2022-06-06
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Preprocessor settings
//====================================================
#pragma once
#ifndef ARSENALGEAR_CONTAINERS_HPP
#define ARSENALGEAR_CONTAINERS_HPP

//====================================================
//     Headers
//====================================================

// STD headers
#include <vector>
#include <map>

namespace agr
 {
  //====================================================
  //     Functions
  //====================================================

  // extract_map_keys
  /**
   * @brief Function used to extract a vector of keys from a map.
   * 
   * @tparam TK Template parameter of the map key.
   * @tparam TV Template parameter of the map element.
   * @param input_map The input map.
   * @return std::vector<TK> The vector of keys.
   */
  template <typename TK, typename TV>
  inline std::vector<TK> extract_map_keys( std::map<TK, TV> const& input_map ) 
   {
    std::vector<TK> retval;
    retval.clear();

    for ( auto const& element : input_map ) retval.push_back( element.first );
    
    return retval;
   }

  // extract_map_elem
  /**
   * @brief Function used to extract a vector of elements from a map.
   * 
   * @tparam TK Template parameter of the map key.
   * @tparam TV Template parameter of the map element.
   * @param input_map The input map.
   * @return std::vector<TV> The vector of elements.
   */
  template <typename TK, typename TV>
  inline std::vector<TV> extract_map_elem( std::map<TK, TV> const& input_map ) 
   {
    std::vector<TV> retval;
    retval.clear();

    for ( auto const& element : input_map ) retval.push_back( element.second );

    return retval;
   }
 }

#endif
