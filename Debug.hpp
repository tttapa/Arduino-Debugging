#ifndef DEBUG
#include <PrintStream.h>

// #define DEBUG_OUT Serial // Uncomment this line to override Arduino IDE debug level

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#ifdef DEBUG_OUT
#ifndef ARDUINO
#undef DEBUG_OUT
#define DEBUG_OUT std::cout
#endif
#pragma message("Debugging enabled on output " STR(DEBUG_OUT))
#endif

#define FUNC_LOCATION '[' << __PRETTY_FUNCTION__ << F(" @ line " STR(__LINE__) "]:\t")
#define LOCATION "[" __FILE__ ":" STR(__LINE__) "]:\t"

#ifdef DEBUG_OUT

#define DEBUG(x) do { \
  DEBUG_OUT << x << endl; \
} while (0)
#define DEBUGREF(x) do { \
  DEBUG_OUT << F(LOCATION) << x << endl; \
} while (0)
#define DEBUGFN(x) do { \
  DEBUG_OUT << FUNC_LOCATION << x << endl; \
} while (0)

#else

#define DEBUG(x)
#define DEBUGREF(x)
#define DEBUGFN(x)

#endif

#endif
