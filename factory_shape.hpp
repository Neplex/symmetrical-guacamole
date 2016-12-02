#ifndef __FACTORY_SHAPE_HPP_
#define __FACTORY_SHAPE_HPP_

/*!
 * \file
 * \brief
 * This module provides a factory to generate shape.
 *
 * \author PASD
 * \date 2016
 */

#include <exception>
#include <list>
#include <map>
#include <string>

#include "shape.hpp"
#include "u_sh_d_stack.hpp"
#include "unique.hpp"

#include <assert.h>
#define NDEBUG 1

namespace {

/*! Beginning of exception message in case of creation problem. */
std::string const defaut_creation_error_message_start("Cannot create: ");
}

/*!
 * Exception used when the factory cannot deliver the requested shape.
 */
class Bad_Shape_Creation_Exception : public std::exception {

  /*! Recorded message */
  std::string const reason;

public:
  Bad_Shape_Creation_Exception(std::string const &type_name)
      : reason(defaut_creation_error_message_start + type_name) {}

  char const *what() { return reason.c_str(); }

  ~Bad_Shape_Creation_Exception() throw() {}
};

/*!
 * Type used to define (pointers to) functions to generate each kind of shape.
 *
 * \param the c_s U_Sh_d_Stack is here to provide the arguments to build the
 * shape.
 */
typedef Shape *(*shape_creator)(U_Sh_d_Stack &c_s);

/*!
 * Implements the factory pattern on shape_creator (with \c string indexin).
 *
 * Singleton is used to guaranty unique load of shared libraries.
 */
class Factory_Shape : public Unique<Factory_Shape> {

  /*! record the shape creators associated to string. */
  std::map<std::string const, shape_creator> creators;

  /*!
   * Used to record all handlers from dlopen.
   * They are needed to dlclose them before leaving.
   */
  std::list<void *> list_handler;

  /*!
   * Load all the dynamic library corresponding to the names in
   * factory_shape.config.
   */
  Factory_Shape();

  // Allow creation only to unique as part of the unique pattern.
  friend class Unique<Factory_Shape>;

public:
  /*!
   * Unload all the loaded dynamic library.
   */
  ~Factory_Shape();

  /*!
   * Dynamically load \c shape_ \c name \c .so, get the function name
   * create_instance in it and add the entry \c (name,create_instance)
   * \param name String name of the library to be loaded.
   */
  void add_shape_dl(std::string const &name);

  /*
   * To add a shape creator to the factory.
   * \param id Id associated to the creator.
   * \param s_c shape creator registered.
   */
  void register_shape(std::string const &id, shape_creator s_c);

  /*! Create a shape according to an id and a stack.
   * \param id Id the shape constructor to be used.
   * \param c_s Stack to get any needed argument.
   * \return the newly created shape.
   */
  Shape *create_shape(std::string const &id, U_Sh_d_Stack &c_s);
};

#endif
