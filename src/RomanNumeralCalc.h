/**
 * @Author: ed
 * @Date:   2018-05-27T11:05:21-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: RomanNumeralCalc.h
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T09:45:50-04:00
 */

#ifndef ROMANNUMERALCALC_H
#define ROMANNUMERALCALC_H

#define RNCALC_MAX_ANSWER_SIZE  16

typedef enum
{
  RNCALC_OK,                //Expression processed OK
  RNCALC_NONVALID_RESULT,   //Expression processed, but returned an invalid result
  RNCALC_VAL2_INVALID,      //Value #2 of the expression was invalid
  RNCALC_VAL1_INVALID,      //Value #1 of the expression was invalid
  RNCALC_EXPRESSION_INVALID //The expression was invalid
}RNCALC_STATUS;

//Process the user supplied Expression
extern RNCALC_STATUS RomanNumeralCalc_processExpression(char* expression, char* answer);

#endif
