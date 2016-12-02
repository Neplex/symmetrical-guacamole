#include "shape_circle.hpp"

#include <assert.h>
#define NDEBUG 1

bool Shape_Circle::contains(double const x, double const y) const {
  // The circle equation is  x² + y² ≤ 1
  return (x * x) + (y * y) <= 1;
}

CREATE_INSTANCE(Circle)
