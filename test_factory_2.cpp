/*!
 * \file 
 * \brief 
 * This module provides more tests for the factory.
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
  Factory_Shape & s_f = Factory_Shape :: ref() ;
  U_Sh_d_Stack c_s ;

  c_s . push ( s_f . create_shape ( "square" , c_s ) ) ;
  c_s . push ( 10 ) ;
  c_s . push ( s_f . create_shape ( "scale" , c_s ) ) ;
  c_s . push ( s_f . create_shape ( "circle" , c_s ) ) ;
  c_s . push ( 20 ) ;
  c_s . push ( s_f . create_shape ( "scale" , c_s ) ) ;
  c_s . push ( s_f . create_shape ( "difference" , c_s ) ) ;

  Shape * s = c_s . pop_shape () ;
  assert ( NULL != s ) ;

  cout << s -> contains ( 0 , 0 ) << ' '
       << s -> contains ( -1 , 1 ) << ' '
       << s -> contains ( 2 , 2 ) << ' '
       << endl ;
    
  delete s ;
  
  return 0 ;
}

