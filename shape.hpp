# ifndef __SHAPE_HPP_
# define __SHAPE_HPP_

/*!
 * \file 
 * \brief 
 * This module provides the base class for representing geometrical shapes.
 *
 * \author PASD
 * \date 2016
 */


# include <istream>

# include "u_sh_d_stack.hpp"

# include <assert.h>
# define NDEBUG 1


/*!
 * Abstract class used to represent a geometric shape.
 */
class Shape {

public : 

  /*! 
   * Tell whether a point is in the shape.
   * It has to be defined for each shape.
   * \param x X coordinate of the queried point.
   * \param y Y coordinate of the queried point.
   * \return true if the point (x,y) is in the shape. 
   */
  virtual bool contains ( double const x ,
			  double const y ) const = 0 ;

  /*! Destructor. **/
  virtual ~Shape () {} ;

} ;


/*!
 * Read a shape from a stream.
 * The read shape is stored in the indicated pointer.
 *
 * \par in stream to read from
 * \pas sh where to store the shape
 * \return the input stream \c in
 */
std :: istream & operator >> ( std :: istream & in ,
			       Shape * & sh ) ;



/*!
 * To use when there is no need to read any argument on the stack.
 *
 * Otherwise a special version has to be made that reads the arguments on the stack.
 */
# define CREATE_INSTANCE( sh )			\
  extern "C"					\
  Shape * create_instance ( U_Sh_d_Stack & ) {	\
    return new Shape_ ## sh () ;		\
  }


// TODO REMOVE WHEN ALL CREATE_INSTANCE ARE OK
// i.e. all ...._DUMMY should be replaced !
# define CREATE_INSTANCE_DUMMY( sh )		\
  extern "C"					\
  Shape * create_instance ( U_Sh_d_Stack & ) {	\
    return NULL ;				\
  }


# endif
