#include <stdio.h>

// Magic ;-)
#define elsif else if
#define my int  // this really is cheating quite a bit.
#define sub int
#define main main()
void say_char(char* n) { printf("%s", n); }
void say_int(int n) { printf("%d", n); }
#define print(_1, ...) _Generic((_1), int: say_int, char *: say_char)(_1)
// End of Magic.

#include "fizzbuzz.cpl"

