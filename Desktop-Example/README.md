# Desktop example

This is an example of a desktop C++ file using the Arduino-Debugging library.  
Think of it as a file containing your unit tests, for example.

```cpp
#include "../Debug.hpp"
#include "math.h" // log10

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
```

## Compiling

To compile a version without debugging, open a terminal in this folder, and run:
```sh
make
```

To compile a version with debugging, run:
```sh
make debug
```

To execute the result, just run:
```sh
./Desktop-Example
```

The expected output of the version with debugging enabled is:
```
This is the result of `DEBUG`
[Desktop-Example.cpp:8]:        This is the result of `DEBUGREF`
[int main() @ line 9]:  This is the result of `DEBUGFN`
a = 1, b = 2, c = 3
log10(1000) - 2 = 1
[int someFunction(int) @ line 18]:      parameter = 42
```

Running the executable without debugging enabled will print nothing.