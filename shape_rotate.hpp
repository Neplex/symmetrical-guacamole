#ifndef __SHAPE_ROTATE_HPP_
#define __SHAPE_ROTATE_HPP_

/*!
 * \file
 * \brief
 * This module provides a way to rotate shapes.
 *
 * \author PASD
 * \date 2016
 */

#include <cmath> // math.h for sin and cos

#include "shape.hpp"

#include <assert.h>
#define NDEBUG 1

/*!
 * This module provides a rotate version of a shape.
 */
class Shape_Rotate : public Shape {

  /*!  Shape to rotate. */
  Shape *const sh;

  /*! cos and sin of the angle to avoid re-computation */
  double const c_alpha, s_alpha;

public:
  Shape_Rotate(Shape *sh, int angle)
      : sh(sh), c_alpha(cos(angle)), s_alpha(sin(angle)) {}
  bool contains(double const x, double const y) const;
};

#endif
