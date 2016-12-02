/*!
 * \file 
 * \brief 
 * This module provides tests for the shapes.
 *
 * \author PASD
 * \date 2016
 */

# include <cstdlib>
# include <iostream>
# include <fstream>
# include <string>
# include <list>

# include <stdio.h>

# include <assert.h>
# define NDEBUG 1

# include "export_eps.hpp"


using namespace std ;



namespace {

  /** picture widht */
  int  x_max = 100 ;

  /** picture height */
  int  y_max = 100 ;

}



int main ( int argc ,
	   char ** argv ) {
  assert ( 1 < argc ) ;

  string file_name = "fig" + string ( argv[1] ) + ".shape" ;
  ifstream in ( file_name.c_str () , std::ifstream::in ) ;

  Shape * s ;
  in >> s ;
  
  assert ( NULL != s ) ;
  
  string eps_file_name = "fig" + string ( argv[1] ) + ".eps" ;
  Export_Eps eps ( eps_file_name.c_str () , x_max , y_max ) ;
  
  assert ( NULL != eps ) ;

  eps.plot ( s );
    
  delete s ;
  
  return 0 ;
}

