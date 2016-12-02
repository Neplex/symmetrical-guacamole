#ifndef __SHAPE_TRANSLATE_HPP_
#define __SHAPE_TRANSLATE_HPP_

/*!
 * \file
 * \brief
 * This module provides a way to translate shapes.
 *
 * \author PASD
 * \date 2016
 */

#include "shape.hpp"

#include <assert.h>
#define NDEBUG 1

/*!
 * This module provides a translated version of a shape.
 */
class Shape_Translate : public Shape {

  /** Translated shape */
  Shape *const sh;

  /** Translation on x */
  double const tx;

  /** Translation on y */
  double const ty;

public:
  bool contains(double const x, double const y) const;
};

#endif
