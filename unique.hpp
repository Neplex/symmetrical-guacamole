# ifndef __SHAPE_INIQUE_HPP_
# define __SHAPE_INIQUE_HPP_

/*!
 * \file 
 * \brief This module provide an implantation of the unique pattern.
 */


# include <assert.h>
# define NDEBUG 1


/*! Curious recurring template to implement singleton pattern.
 *
 * Use \verbatim
 * class A
 *   : public Unique < A > {
 *   friend class Unique < A > ;
 *   // [...]
 *  }
 * \endverbatim
 * As presented in last lecture.
 */

/*!
 * \param T Class to endow with unique instance by inheritance.
 */
template < class T >
class Unique {
  
  Unique ( Unique const & ) ;
  
  Unique & operator = ( Unique const & ) ;
  
protected :
  
  Unique () {} ;
  
  virtual ~Unique () {} ;
  
public :
  
  static T & ref () {
    static T the_instance ;
    return the_instance ;
  }
  
} ;

# endif
