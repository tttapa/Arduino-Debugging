#define PRINTSTREAM_FALLBACK
#define DEBUG_OUT Serial
#include "Debug.hpp"

void setup() {
  Serial.begin(115200);
  while (!Serial);
}

void loop() {
  DEBUG( "This is the result of `DEBUG`" );
  DEBUGREF( "This is the result of `DEBUGREF`" );
  DEBUGFN( "This is the result of `DEBUGFN`" );
  DEBUGTIME( "This is the result of `DEBUGTIME`" );
  int a = 1, b = 2, c = 3;
  DEBUGVAL( a, b, c );
  DEBUGVAL( log10(1000) - 2 );
  DEBUGVAL( millis() );
  DEBUGVAL( Serial.read() );
  someFunction(42);
  DEBUG("");
  delay(5000);
}

int someFunction(int parameter) {
  DEBUGFN( NAMEDVALUE(parameter) );
  return parameter;
}
