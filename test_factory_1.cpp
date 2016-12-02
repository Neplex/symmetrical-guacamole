/*!
 * \file 
 * \brief 
 * This module provides first tests for the factory.
 *
 * \author PASD
 * \date 2016
 */

# include <iostream>

# include "factory_shape.hpp"

# include <assert.h>
# define NDEBUG 1


using namespace std ;



int main () {
  U_Sh_d_Stack c_s ;

  c_s.push ( Factory_Shape :: ref() . create_shape ( "triangle" , c_s ) ) ;

  Shape * s = c_s . pop_shape () ;
  assert ( NULL != s ) ;

  cout << s -> contains ( 0 , 0 ) << ' '
       << s -> contains ( -1 , 1 )<< ' '
       << s -> contains ( 2 , 2 ) << ' '
       << endl ;
    
  delete s ;
  
  return 0 ;
}


