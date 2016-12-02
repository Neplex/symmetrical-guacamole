#include "shape_rotate.hpp"

#include <assert.h>
#define NDEBUG 1

bool Shape_Rotate::contains(double const x, double const y) const {
  return sh->contains(x * cos(c_alpha) - y * (sin(s_alpha)),
                      x * sin(s_alpha) - y * (cos(c_alpha)));
}
