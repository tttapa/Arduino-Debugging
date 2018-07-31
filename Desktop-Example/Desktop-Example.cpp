#include "../Debug.hpp"
#include "math.h"

int someFunction(int answer);

int main() {
  DEBUG( "This is the result of `DEBUG`" );
  DEBUGREF( "This is the result of `DEBUGREF`" );
  DEBUGFN( "This is the result of `DEBUGFN`" );
  int a = 1, b = 2, c = 3;
  DEBUGVAL( a, b, c );
  DEBUGVAL( log10(1000) - 2 );
  someFunction(42);
  return 0;
}

int someFunction(int parameter) {
  DEBUGFN( NAMEDVALUE(parameter) );
  return parameter;
}