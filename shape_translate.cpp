#include "shape_translate.hpp"

#include <assert.h>
#define NDEBUG 1

bool Shape_Translate::contains(double const x, double const y) const {
  return sh->contains(x - tx, y - ty);
}
