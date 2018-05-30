CFLAGS = -I. -g -O0 -std=c11
LINKFLAGS = -g -L$(LIBDIR) `pkg-config --cflags --libs check`
_LINKLIBS = RomanNumeralCalc.a
MAIN = RomanNumeralCalcTests
FILES = check_RomanNumeral RomanNumeralCalcTests
LIB = RomanNumeralCalcTests.a
include ../Makefile.inc
