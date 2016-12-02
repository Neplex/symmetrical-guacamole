# include "export_eps.hpp"


# include <assert.h>
# define NDEBUG 1

using namespace std ;


Export_Eps :: Export_Eps ( char const * const _file_name ,
			   unsigned int const _x_max ,
			   unsigned int const _y_max ,
			   unsigned int const _res
			   )  
  : x_max ( _x_max ) ,
    y_max ( _y_max) ,
    res ( _res ) ,
    output ( _file_name , std :: ofstream :: out )  
{
  output << "%!PS-Adobe-2.0 EPSF-2.0" << endl ;
  output << "%%BoundingBox: 0.0 0.0 " << ( ( x_max + 1 ) * res ) << " " << ( ( y_max + 1 ) * res ) << endl ;
  output << "%%Pages: 1" << endl << "%%EndComments" << endl << "%%EndProlog"  << endl;
  output << "/res { " << res << " } def"  << endl ;
  output << "/p { gsave newpath moveto 0 res rlineto res 0 rlineto 0 res neg rlineto closepath fill grestore } def" << endl ;
}


Export_Eps :: ~Export_Eps () {
  output << "%%EOF" << endl ;
  // file will be destroyed and thus the stream closed
}


void Export_Eps :: plot ( unsigned int const x,
			  unsigned int const y ) {
  output << ( res * x ) << " " << (res * y ) << " p" << endl ;
}


void Export_Eps :: plot ( Shape const * const sh ) {
  assert ( NULL != sh ) ;
  for ( unsigned int i = 0 ; i <= x_max ; i ++ ) {
    for (unsigned int j = 0 ; j <= y_max ; j ++ ) {
      if ( sh -> contains ( i , j ) ) {
	plot ( i , j ) ;
      }
    }
  }
}
