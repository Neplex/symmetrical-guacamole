# ifndef __SHAPE_SCALE_HPP_
# define __SHAPE_SCALE_HPP_

/*!
 * \file 
 * \brief 
 * This module provides a way to scale a shape.
 *
 * \author PASD
 * \date 2016
 */

# include "shape.hpp"

# include <assert.h>
# define NDEBUG 1


/*!
 * This class provide a scaled version of a shape.
 */
class Shape_Scale : public Shape {

  /*! Shape to scale */
  Shape * const sh ;

  /*! Scaling coefficient */
  double const coef ;
  
public : 

  Shape_Scale ( Shape * const _sh ,
		double const _coef ) 
    : sh ( _sh ) 
    , coef ( _coef ) 
  {
    assert ( NULL != _sh ) ;
  } 

  bool contains ( double const x ,
		  double const y ) const ;
 
  ~Shape_Scale () {
    delete sh ;
  }
  
} ;



# endif
