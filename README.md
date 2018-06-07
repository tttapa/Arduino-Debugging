# Arduino Debugging

When working on an Arduino sketch or library, you often find yourself writing an awful lot of `Serial.print(...)` statements for debugging. It can be quite hard to keep track of where all of this data comes from, and it's a pain to remove or comment out all of it when preparing for a release.

This library aims at facilitating the debugging process by providing simple macros that add no overhead whatsoever when debugging is disabled. It can also automatically print out information about the context, like function name, filename and line number.

On top of that, it can be used for the Arduino, as well as desktop C++. This makes it easier to develop on your computer, run unit tests on your computer, and then compile for the Arduino using the exact same code.

## Dependencies

All that's needed is the [Arduino PrintStream library](https://github.com/tttapa/Arduino-PrintStream), that adds `std::cout`-like support for the Arduino (using the `<<`-operator).

## API

The library provides three macros:

1. `DEBUG(x)`  
This is the easiest one: it just prints out `x` to the debug output if debugging is enabled. It also terminates the line.
2. `DEBUGREF(x)`  
This one behaves similar to `DEBUG`, but it also prints out a reference to the filename and line number where it was called.
3. `DEBUGFN(x)`  
Rather than printing the entire filename, this one prints out just the function name and the line number where it was called.

## Example

```cpp
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
```
When debugging is enabled the code above produces the following output:
```
This is the result of `DEBUG`
[/home/pieter/Arduino/debug_macro_ref/debug_macro_ref.ino:10]:	This is the result of `DEBUGREF`
[void loop() @ line 11]:	This is the result of `DEBUGFN`
[int someFunction(int) @ line 17]:	The answer is 42

```

