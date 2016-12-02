/*!
 * \file 
 * \brief
 * This module provides tests for the dynamic library use.
 *
 * \author PASD
 * \date 2016
 */

# include <cstdlib>
# include <iostream>
# include <string>

# include <stdio.h>
# include <dlfcn.h>


# include <assert.h>
# define NDEBUG 1

using namespace std ;


int main () {
  void * handle_dl = dlopen ( "./libok.so" , RTLD_NOW ) ;
  assert ( NULL != handle_dl ) ;

  void ( * mkr ) () = ( void (*) () ) ( dlsym ( handle_dl , "call_ok" ) ) ;
  assert ( NULL != mkr ) ;

  ( * mkr ) () ;

  dlclose ( handle_dl ) ;

  return 0 ;
}

