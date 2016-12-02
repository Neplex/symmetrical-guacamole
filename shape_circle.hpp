#ifndef __SHAPE_CIRCLE_HPP_
#define __SHAPE_CIRCLE_HPP_

/*!
 * \file
 * \brief
 * This module provides basic circle shape.
 *
 * \author PASD
 * \date 2016
 */

#include "shape.hpp"

/*!
 * Circle of center (0,0) and radius 1.
 */

class Shape_Circle : public Shape {

public:
  bool contains(double const x, double const y) const;
};

#endif
