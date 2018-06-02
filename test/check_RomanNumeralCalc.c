/**
 * @Author: ed
 * @Date:   2018-05-27T17:27:26-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: check_RomanNumeral.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-29T05:13:33-04:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../src/RomanNumeralCalc.h"

//Test creation of RomanNumeral Calculator with Valid Expression
START_TEST (RomanNumeralCalcWithValidExpressions)
{
  char answer[RNCALC_MAX_ANSWER_SIZE];
  RNCALC_STATUS status;

  printf("-- Checking Roman Numeral Calculator with Valid Expressions--\n");
  status = RomanNumeralCalc_processExpression("I + I", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"II",RNCALC_MAX_ANSWER_SIZE) == 0);
  
  status = RomanNumeralCalc_processExpression("i + i", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"II",RNCALC_MAX_ANSWER_SIZE) == 0);
  
  status = RomanNumeralCalc_processExpression("IX + M", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"MIX",RNCALC_MAX_ANSWER_SIZE) == 0);
  
  status = RomanNumeralCalc_processExpression("MMM + LIX", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"MMMLIX",RNCALC_MAX_ANSWER_SIZE) == 0);
  
  status = RomanNumeralCalc_processExpression("mmm + LIX", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"MMMLIX",RNCALC_MAX_ANSWER_SIZE) == 0);

  status = RomanNumeralCalc_processExpression("MMM - I", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"MMCMXCIX",RNCALC_MAX_ANSWER_SIZE) == 0);
  
  status = RomanNumeralCalc_processExpression("MMM - i", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"MMCMXCIX",RNCALC_MAX_ANSWER_SIZE) == 0);
  
  status = RomanNumeralCalc_processExpression("X - VI", answer);
  ck_assert(RNCALC_OK == status);
  ck_assert(strncmp(answer,"IV",RNCALC_MAX_ANSWER_SIZE) == 0);
}
END_TEST

//Test creation of RomanNumeral Calculator with Valid Expression
START_TEST (RomanNumeralCalcWithInvalidExpressions)
{
  char answer[RNCALC_MAX_ANSWER_SIZE];
  RNCALC_STATUS status;

  printf("-- Checking Roman Numeral Calculator with InValid Expressions--\n");

  //Value #1 is out of range
  status = RomanNumeralCalc_processExpression("MMMM + I", answer);
  ck_assert(RNCALC_VAL1_INVALID == status);
  
  //Value #1 is invalid
  status = RomanNumeralCalc_processExpression("AAddfad + I", answer);
  ck_assert(RNCALC_VAL1_INVALID == status);
  
  //Value #2 is out of range
  status = RomanNumeralCalc_processExpression("I + MMMM", answer);
  ck_assert(RNCALC_VAL2_INVALID == status);
  
  //Value #2 is INVALID 
  status = RomanNumeralCalc_processExpression("I + adfbFFFj", answer);
  ck_assert(RNCALC_VAL2_INVALID == status);
  
  //Expression is Invalid
  status = RomanNumeralCalc_processExpression("I / I", answer);
  ck_assert(RNCALC_EXPRESSION_INVALID == status);
  
  //Expression Result is out of range 
  status = RomanNumeralCalc_processExpression("MMM + M", answer);
  ck_assert(RNCALC_NONVALID_RESULT == status);
  
  //Expression Result is out of range 
  status = RomanNumeralCalc_processExpression("I - II", answer);
  ck_assert(RNCALC_NONVALID_RESULT == status);
  
}
END_TEST

Suite* roman_numeral_calc_suite()
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("RomanNumeralCalc");

   /* Core test case */
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, RomanNumeralCalcWithValidExpressions);
   tcase_add_test(tc_core, RomanNumeralCalcWithInvalidExpressions);

   suite_add_tcase(s, tc_core);

   return s;
}
