/*!
 * \file
 * \brief
 * This module provides tests for the shapes.
 *
 * \author PASD
 * \date 2016
 */

#include <iostream>

#include "shape.hpp"
#include "shape_binary.hpp"
#include "shape_circle.hpp"
#include "shape_rotate.hpp"
#include "shape_scale.hpp"
#include "shape_square.hpp"
#include "shape_translate.hpp"
#include "shape_triangle.hpp"

#include <assert.h>
#define NDEBUG 1

/*!
 * These should correspond to functions defined in shape_….cpp
 */
bool and_(bool const, bool const);
bool difference_(bool const, bool const);
bool minus_(bool const, bool const);
bool or_(bool const, bool const);

namespace {

/*! Parameters for the picture */
float const min_i = -3;
float const max_i = 3;
float const step_i = 0.1;
float const min_j = -1;
float const max_j = 2;
float const step_j = 0.15;
}

using namespace std;

/*
 * Make an ascii output of a shape.
 */
void test_shape(Shape *sh) {
  assert(NULL != _sh);
  cout << "--------------------------------------------------" << endl;
  for (float j = max_j; min_j <= j; j -= step_j) {
    for (float i = min_i; i <= max_i; i += step_i) {
      cout << (sh->contains(i, j) ? '*' : ' ');
    }
    cout << endl;
  }
  delete sh;
}

/*
 * Test ascii output of various shapes.
 */
int main(void) {

  test_shape(new Shape_Circle());
  test_shape(new Shape_Square());
  test_shape(new Shape_Triangle());

  test_shape(new Shape_Scale(new Shape_Circle(), 2.2));
  test_shape(new Shape_Rotate(new Shape_Square(), 45));

  test_shape(new Shape_Translate(new Shape_Triangle(), 2, 1));

  test_shape(new Shape_Binary<or_>(new Shape_Scale(new Shape_Circle(), 2.2),
                                   new Shape_Rotate(new Shape_Square(), 45)));

  test_shape(new Shape_Binary<and_>(new Shape_Scale(new Shape_Circle(), 2.2),
                                    new Shape_Rotate(new Shape_Square(), 45)));

  test_shape(
      new Shape_Binary<difference_>(new Shape_Scale(new Shape_Circle(), 2.2),
                                    new Shape_Rotate(new Shape_Square(), 45)));

  return 0;
}
