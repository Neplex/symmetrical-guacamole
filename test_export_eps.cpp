/*!
 * \file 
 * \brief 
 * This module provides a simple test for exporting eps: it draws a "H" figure into a h.eps file.
 *
 * \author PASD
 * \date 2016
 */

# include "export_eps.hpp"


# include <assert.h>
# define NDEBUG 1


namespace {

  /*! Name of the output file*/
  char const * const file_name = "h.eps" ;
  
  /** picture widht */
  int  x_max = 100 ;
  
  /** picture height */
  int  y_max = 100 ;
}


int main ( void ) {

  Export_Eps eps ( file_name , x_max , y_max ) ;

  // Draw a H 
  for ( int i = 0 ; i <= x_max ; i ++ ) {
    eps.plot ( i, y_max / 2 ) ;
  }
  for ( int j = 0 ; j <= y_max ; j ++ ) {
    eps.plot ( 0, j ) ;
    eps.plot ( y_max, j ) ;
  }

  return 0 ;
}
