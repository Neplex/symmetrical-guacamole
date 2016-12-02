#ifndef __SHAPE_TRIANGLE_HPP_
#define __SHAPE_TRIANGLE_HPP_

/*!
 * \file
 * \brief
 * This module provides the basic triangle shape.
 *
 * \author PASD
 * \date 2016
 */

#include "shape.hpp"

#include <assert.h>
#define NDEBUG 1

/*!
 * Triangle of extremities ( -1 , -1 ) - ( 1 , 1 ) - ( 1 , -1 )
 */
class Shape_Triangle : public Shape {

public:
  bool contains(double const x, double const y) const;
};

#endif
