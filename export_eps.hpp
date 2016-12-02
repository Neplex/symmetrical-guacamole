# ifndef __EXPORT_EPS_HPP_
# define __EXPORT_EPS_HPP_

/*!
 * \file 
 * \brief 
 * This module provides a way to create a simple picture in postscript.
 *
 * \author PASD
 * \date 2016
 */


# include <fstream>

# include "shape.hpp"


# include <assert.h>
# define NDEBUG 1

using namespace std ;

namespace {

  /*! Size of pixels. */
  unsigned int const res_defaut = 3 ;

}


class Export_Eps {

  /**  0 <=  x <= x_max */ 
  unsigned int const x_max ;
  /**  0 <=  y <= y_max */ 
  unsigned int const y_max ;

  /** Pixel is a square of length size res. */
  unsigned int const res ;

  /** Stream to the generated output eps file */
  ofstream output ;

public :

  /** Plot a pixel */
  void plot ( unsigned int const x ,
	      unsigned int const y ) ;

  /** Open file file_name for writing and send the prologue into it.  */ 
  Export_Eps ( char const * const _file_name ,
	       unsigned int const _x_max ,
	       unsigned int const _y_max ,
	       unsigned int const _res = res_defaut
	       ) ;

  /** Plot a shape */
  void plot ( Shape const * const sh ) ;
  
  /** Destroys the  export and close the stream */
  ~Export_Eps () ;

} ;


# endif
