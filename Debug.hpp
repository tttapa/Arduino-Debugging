#ifndef DEBUG

#ifdef ARDUINO

// #define DEBUG_OUT Serial // Uncomment this line to override Arduino IDE debug level

#ifndef PRINTSTREAM_FALLBACK
#include <PrintStream.h>
#else
#include <Arduino.h>
typedef Print &manipulator(Print &);
inline Print &endl(Print &printer) {
  printer.println();
  printer.flush();
  return printer;
}
template<class T> inline Print &operator<<(Print &printer, const T printable) {
  printer.print(printable);
  return printer;
}
template<> inline Print &operator<<(Print &printer, manipulator pf) {
  return pf(printer);
}
#endif

#else // No Arduino

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setbase;
using std::setprecision;
using std::dec;
using std::hex;
using std::flush;
using std::boolalpha;
using std::noboolalpha;
using std::uppercase;
using std::nouppercase;
using std::showbase;
using std::noshowbase;
#define F(x) x

#endif

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define FUNC_LOCATION '[' << __PRETTY_FUNCTION__ << F(" @ line " STR(__LINE__) "]:\t")
#define LOCATION "[" __FILE__ ":" STR(__LINE__) "]:\t"

#define NAMEDVALUE(x) F(STR(x)" = ") << x

#ifdef DEBUG_OUT

#pragma message("Debugging enabled on output " STR(DEBUG_OUT))

#define DEBUG(x) do { \
  DEBUG_OUT << x << endl; \
} while (0)

#define DEBUGREF(x) do { \
  DEBUG_OUT << F(LOCATION) << x << endl; \
} while (0)

#define DEBUGFN(x) do { \
  DEBUG_OUT << FUNC_LOCATION << x << endl; \
} while (0)

#ifdef ARDUINO
#define DEBUGTIME(x) do {                                                      \
    unsigned long t = millis();                                                \
    unsigned long h = t / (60UL * 60 * 1000);                                  \
    unsigned long m = (t / (60UL * 1000)) % 60;                                \
    unsigned long s = (t / (1000UL)) % 60;                                     \
    unsigned long ms = t % 1000;                                               \
    const char *ms_zeros = ms > 99 ? "" : (ms > 9 ? "0" : "00");               \
    DEBUG_OUT << '[' << h << ':' << m << ':' << s << '.'                       \
              << ms_zeros << ms << "]:\t" << x << endl;                        \
  } while (0)
#endif

#define DEBUGVAL(...) DEBUGVALN(COUNT(__VA_ARGS__))(__VA_ARGS__)

#define COUNT(...) COUNT_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define COUNT_HELPER(N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N, ...) N

#define DEBUGVALN(N) DEBUGVALN_HELPER(N)
#define DEBUGVALN_HELPER(N) DEBUGVAL##N

#define DEBUGVAL10(x, ...) do {            \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL9(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL9(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL8(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL8(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL7(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL7(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL6(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL6(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL5(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL5(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL4(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL4(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL3(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL3(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL2(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL2(x, ...) do {             \
  DEBUG_OUT << NAMEDVALUE(x) << ", ";      \
  DEBUGVAL1(__VA_ARGS__);                  \
} while (0)
#define DEBUGVAL1(x) do {                  \
  DEBUG_OUT << NAMEDVALUE(x) << endl;      \
} while (0)

#else

#define DEBUG(x)
#define DEBUGREF(x)
#define DEBUGFN(x)
#ifdef ARDUINO
#define DEBUGTIME(x)
#endif
#define DEBUGVAL(...)

#endif

#endif
