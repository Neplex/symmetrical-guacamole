#include "shape_intersect.hpp"

#include "shape_binary.hpp"

#include <assert.h>
#define NDEBUG 1

bool and_(bool const b1, bool const b2) { return b1 && b2; }

CREATE_INSTANCE_BINARY(and_)
