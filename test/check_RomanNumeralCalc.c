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
#include "../src/RomanNumeral.h"

//Test creation of RomanNumeral Calculator with Valid Expression
START_TEST (RomanNumeralCalcWithValidExpressions)
{
  printf("-- Checking Roman Numeral Calculator with Valid Expressions--\n");
  ck_assert(false);
}
END_TEST

//Test creation of RomanNumeral Calculator with Valid Expression
START_TEST (RomanNumeralCalcWithInvalidExpressions)
{
  printf("-- Checking Roman Numeral Calculator with InValid Expressions--\n");
  ck_assert(false);
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
