#include "shape_difference.hpp"

#include "shape_binary.hpp"

#include <assert.h>
#define NDEBUG 1

bool difference_(bool const b1, bool const b2) { return b1 != b2; }

CREATE_INSTANCE_BINARY(difference_)
