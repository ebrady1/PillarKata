CFLAGS = -I. -g -O0 -std=c11
LINKFLAGS = -g -L$(LIBDIR) `pkg-config --cflags --libs check`
_LINKLIBS = RomanNumeralCalc.a
MAIN = RomanNumeralCalcTests
FILES = RomanNumeralCalcTests check_RomanNumeral check_RomanNumeralCalc 
LIB = RomanNumeralCalcTests.a
include ../Makefile.inc
