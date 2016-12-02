#include "shape_scale.hpp"

#include <assert.h>
#define NDEBUG 1

bool Shape_Scale::contains(double const x, double const y) const {
  return sh->contains(x / coef, y / coef);
}

extern "C" Shape *create_instance(U_Sh_d_Stack &c_s) {
  double coef = c_s.pop_double();
  Shape *sh = c_s.pop_shape();
  assert(NULL != sh);
  sh = new Shape_Scale(sh, coef);
  assert(NULL != sh);
  return sh;
}
