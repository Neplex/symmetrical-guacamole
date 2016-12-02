#ifndef __SHAPE_BINARY_HPP_
#define __SHAPE_BINARY_HPP_

/*!
 * \file
 * \brief
 * This module provides a way to create a simple binary shape operators.
 *
 * \author PASD
 * \date 2016
 */

#include "shape.hpp"

#include <assert.h>
#define NDEBUG 1

/*!
 * this template provides a generic ways to generate operators between shapes
 * such that:
 * \li the operator is binary, i.e. depends only on two shapes (an no other
 * parameter)
 * \li the return value of contains only depends on the values returned by the
 * contains (on the same point) in the two shapes.
 */

template <bool (*op)(bool const, bool const)>
class Shape_Binary : public Shape {
public:
  Shape_Binary(Shape *const shape_1, Shape *const shape_2) {
    this->shape_1 = shape_1;
    this->shape_2 = shape_2;
  }

  bool contains(double const x, double const y) const {
    return op(shape_1->contains(x, y), shape_2->contains(x, y));
  }

protected:
  Shape *shape_1;
  Shape *shape_2;
};

/*!
 * Provide the create_instante function for the given op by instanciating the
 * pattern.
 */
#define CREATE_INSTANCE_BINARY(op)                                             \
  extern "C" Shape *create_instance(U_Sh_d_Stack &c_s) {                       \
    Shape *sh2 = c_s.pop_shape();                                              \
    Shape *sh1 = c_s.pop_shape();                                              \
    return new Shape_Binary<op>(sh1, sh2);                                     \
  }

#endif
