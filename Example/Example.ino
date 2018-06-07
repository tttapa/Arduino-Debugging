#include "Debug.h"

void setup() {
  Serial.begin(115200);
  while (!Serial);
}

void loop() {
  DEBUG( "This is the result of `DEBUG`" );
  DEBUGREF( "This is the result of `DEBUGREF`" );
  DEBUGFN( "This is the result of `DEBUGFN`" );
  someFunction(42);
  delay(5000);
}

int someFunction(int answer) {
  DEBUGFN( "The answer is " << answer);
  return answer;
}
