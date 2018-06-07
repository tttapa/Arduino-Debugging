#include "../Debug.hpp"

int someFunction(int answer);

int main() {
  DEBUG( "This is the result of `DEBUG`" );
  DEBUGREF( "This is the result of `DEBUGREF`" );
  DEBUGFN( "This is the result of `DEBUGFN`" );
  someFunction(42);
  return 0;
}

int someFunction(int answer) {
  DEBUGFN( "The answer is " << answer);
  return answer;
}
