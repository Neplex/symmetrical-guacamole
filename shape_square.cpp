# include "shape_square.hpp"


# include <assert.h>
# define NDEBUG 1

bool Shape_Square :: contains ( double const x ,
				double const y ) const {  // ---
  return ( -1 <= x ) && ( x <= 1 )
    && ( -1 <= y ) && ( y <= 1 );
  // +++ return true ;
}


CREATE_INSTANCE ( Square )
