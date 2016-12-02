# include "factory_shape.hpp"

# include <fstream>
# include <iostream>

# include <dlfcn.h>


# include <assert.h>
# define NDEBUG 1


using namespace std ;


namespace {
 
  /*! 
   * Configuration file for the factory.
   */
  string factory_configuration_file = "./factory_shape.config" ;

 
  /*! 
   * Function name to get from ld.
   */
  string function_name = "create_instance" ;

}


Factory_Shape :: Factory_Shape () { // ---
  ifstream in ( factory_configuration_file.c_str () , std::ifstream::in ) ;
  while ( ! in.eof () ) {
    string shape_name ;
    in >> shape_name ;
    if ( ! shape_name.empty () ) {
      add_shape_dl ( shape_name ) ;
    }
  }
}


Factory_Shape :: ~Factory_Shape () { // ---
  while ( ! list_handler.empty () ) {
    dlclose ( list_handler.front () ) ;
    list_handler.pop_front () ;
  }
}


void Factory_Shape :: add_shape_dl ( string const & s ) { // ---
  string file_name = "./libshape_" + s + ".so" ;
  void *handle_dl = dlopen ( file_name.c_str () , RTLD_NOW ) ;
  if ( NULL == handle_dl ) {
    cerr << "ERROR opening: " << file_name << " -> " << dlerror() << endl;
    return ;
  }
  list_handler.push_front ( handle_dl ) ;

  shape_creator cr_i = ( shape_creator ) ( dlsym ( handle_dl , function_name.c_str () ) ) ;
  if ( NULL == handle_dl ) {
    cerr << "ERROR opening: " << file_name << " -> function" << function_name << " not found" << endl;
    return ;
  }
  clog << "opening: " << file_name << " -> OK" << endl ;
  register_shape ( s , cr_i ) ;
}



void Factory_Shape :: register_shape ( std :: string const & id , 
				       shape_creator s_c ) {
}

Shape * Factory_Shape :: create_shape ( std :: string const & id ,
					U_Sh_d_Stack & c_s ) { 
  // +++ return NULL ;
}
