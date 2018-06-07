# Desktop example

This is an example of a desktop C++ file using the Arduino-Debugging library.  
Think of it as a file containing your unit tests, for example.

```cpp
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

The expected output is:
```
This is the result of `DEBUG`
[Desktop-Example.cpp:7]:	This is the result of `DEBUGREF`
[int main() @ line 8]:	This is the result of `DEBUGFN`
[int someFunction(int) @ line 14]:	The answer is 42
```
