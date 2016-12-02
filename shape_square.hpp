#ifndef __SHAPE_SQUARE_HPP_
#define __SHAPE_SQUARE_HPP_

/*!
 * \file
 * \brief
 * This module provides the basic square shape.
 *
 * \author PASD
 * \date 2016
 */

#include "shape.hpp"

/*!
 * Square [ -1 , 1 ] x [ -1 , 1 ]
 */
class Shape_Square : public Shape {

public:
  bool contains(double const x, double const y) const;
};

#endif
