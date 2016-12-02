#ifndef __U_SH_D_HPP_
#define __U_SH_D_HPP_

/*!
 * \file
 * \brief
 * This module provides a simple test for exporting eps: it draws a "H" figure
 * into a h.eps file.
 *
 * The module is not in charge of creating (thus not deleting) any Shape.
 *
 * \author PASD
 * \date 2016
 */

#include <stack>

#include <assert.h>
#define NDEBUG 1

// Pre-definition of \c Shape since only pointer are asked for AND shape.hpp
// include this file.
class Shape;

/*!
 * Used to store both double and Shape *.
 */
class U_Sh_d {

  /*! The type of value held */
  enum { SHAPE, DOUBLE } const type;

  /*! The held value. */
  union {
    Shape *sh;
    double d;
  } val;

public:
  /* To record a double.
   * \param _d double to store.
   */
  U_Sh_d(double const _d) : type(DOUBLE) { val.d = _d; }

  /* To record a shape.
   * \pre The shape should be defined.
   * \param _sh pointer to the \c Shape to store.
   */
  U_Sh_d(Shape *const _sh) : type(SHAPE) {
    assert(NULL != _sh);
    val.sh = _sh;
  }

  /*!
   * To retrieve the shape value.
   * \pre must record a shape.
   * \return pointer to the shape recorded.
   */
  Shape *get_shape() {
    assert(SHAPE == type);
    return val.sh;
  }

  /*!
   * To retrieve the double value.
   * \pre must record a double.
   * \return the double recorded.
   */
  double get_double() {
    assert(DOUBLE == type);
    return val.d;
  }
};

/*!
 * Used as a stack of u_sh_ded shapes and doubles
 */
class U_Sh_d_Stack {

  /*! Delegation stack to hold \c U_Sh_d * */
  std::stack<U_Sh_d *> stack;

public:
  /*
   * To push a shape on top of the stack.
   * \pre The shape should be defined.
   * \param _sh pointer to the \c Shape to store.
   */
  void push(Shape *const _sh) {
    assert(NULL != _sh);
    stack.push(new U_Sh_d(_sh));
  };

  /*
   * To push a double on top of the stack.
   * \param _d \c double to store.
   */
  void push(double _d) { stack.push(new U_Sh_d(_d)); };

  /*
   * To get the shape on top of the stack.
   * \pre It should be a shape.
   * \return pointer to the popped shape.
   */
  Shape *pop_shape() {
    U_Sh_d *c = stack.top();
    stack.pop();
    Shape *sh = c->get_shape();
    delete c;
    return sh;
  }

  /*
   * To get the double on top of the stack.
   * \pre It should be a double.
   * \return value of the popped double.
   */
  double pop_double() {
    U_Sh_d *c = stack.top();
    stack.pop();
    double d = c->get_double();
    delete c;
    return d;
  }

  /*
   * To get the size of the stack.
   * \return number of elements in the stack.
   */
  unsigned int size() { return stack.size(); }
};

#endif
