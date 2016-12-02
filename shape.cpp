#include <iostream>

#include "factory_shape.hpp"
#include "shape.hpp"

#include <assert.h>
#define NDEBUG 1

using namespace std;

istream &operator>>(istream &in, Shape *&sh) {
  assert(NULL != sh);
  U_Sh_d_Stack c_s;

  for (;;) {
    in >> std::ws;
    if (in.eof()) {
      break;
    }
    double d;
    in >> d;
    if (!(in.fail())) {
      clog << "double: " << d << endl;
      c_s.push(d);
    } else {
      in.clear();
      string shape_name;
      in >> shape_name;
      clog << "string: " << shape_name << endl;
      c_s.push(Factory_Shape::ref().create_shape(shape_name, c_s));
    }
  }

  assert(1 == c_s.size());
  sh = c_s.pop_shape();

  return in;
}
