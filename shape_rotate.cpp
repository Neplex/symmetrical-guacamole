#include "shape_rotate.hpp"

#include <assert.h>
#define NDEBUG 1

bool Shape_Rotate::contains(double const x, double const y) const {
  return sh->contains(x * s_alpha - y * c_alpha, x * c_alpha + y * s_alpha);
}
