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
  RNCALC_OK,
  RNCALC_NONVALID_RESULT,
  RNCALC_VAL2_INVALID,
  RNCALC_VAL1_INVALID,
  RNCALC_EXPRESSION_INVALID
}RNCALC_STATUS;

//Process the user supplied Expression
extern RNCALC_STATUS RomanNumeralCalc_processExpression(char* expression, char* answer);

#endif
