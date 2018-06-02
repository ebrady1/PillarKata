# Roman Numeral Calculator

This is my submission for the Embedded Application Kata - Roman Numeral Calculator
This exercise is based on the Roman Numeral Calculator Kata at http://bit.ly/1VfHqlj.

## Getting Started
These will get you a copy of the project up and running on your local machine for review and testing purposes. 

## Prerequisites
```
OS:  Ubuntu Linux 14.04.05 LTS
Compiler: gcc version 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04.4)
```

## Building 
To build the program an all test suites:
```
cd RomanNumeralCalc
make            - Makes all 
make src        - Makes the Roman Numeral Calculator executable
make tests      - Makes a standalone executable for the tests
make run        - Makes the Roman Numeral Calculator and starts it
make run_test   - Makes the test executable and executes it
make clean      - Cleans the build directoy
```

##Build output
```
objs - Directory of compiled objects
src - Source files for main executable
tests - Source files for test suite libraries and main test runner
bin - Compiled executable files for Calculator and Test runner
```

## Files
```
Roman_Numeral_Calc
bin
\- RomanNumeralCalc         - Standalone Calculator 
 - RomanNumeralCalcTests    - Standalone Calculator test runner
docs
lib
\- RomanNumeralCalc.a       - Roman Numeral Calculator statically linked library
 - RomanNumeralCalcTests.a  - Roman Numeral Calculator statically linked test cases
src
\- Makefile             - The Makefile, required ../Makefile.inc
 - main.c               - Provides a main() for the standalone Calculator exe
 - RomanNumeralCalc.h   - The header for the Calculator executable
 - RomanNumeralCalc.c   - The main code for the Calculator executable
 - RomanNumeral.h       - Header code for the RomanNumeral "object"
 - RomanNumeral.c       - Implementation code for the RomanNumeral "object"
\- test
 - check_RomanNumeralCalc.h - Header for the main Calculator tests
 - check_RomanNumeralCalc.c - Calculator test cases
 - check_RomanNumeral.h     - Header for the RomanNumeral "object" test cases
 - check_RomanNumeral.c     - Implementation for the RomanNumeral "object" test cases.
 ``` 

