# include "shape_triangle.hpp"


# include <assert.h>
# define NDEBUG 1

bool Shape_Triangle :: contains ( double const x ,
				  double const y ) const { // ---
  return ( x <= 1 )
    && ( -1 <= y )
    && ( 0 <= x - y ) ;
  // +++ return true ;
}


CREATE_INSTANCE ( Triangle )
