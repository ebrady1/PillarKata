/**
 * @Author: ed
 * @Date:   2018-05-27T17:27:26-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: check_RomanNumeral.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T09:12:17-04:00
 */

#include <check.h>
#include "../src/RomanNumeral.h"

//Test creation of an empty Roman Numeral object
START_TEST (CreateEmptyRomanNumeral)
{
  //Instantiate a Roman Numeral object and check if a pointer to the object
  //was returned
  RomanNumeral* rn =  RomanNumeral_new();
  ck_assert(rn != NULL);
}
END_TEST

START_TEST (CreateRomanNumeralWithValidRomanCharacters)
{
}
END_TEST

START_TEST (CreateRomanNumeralWithInvalidRomanCharacters)
{
}
END_TEST

START_TEST (CreateRomanNumeralWithDecimalValue)
{
}
END_TEST

START_TEST (CreateOutofBoundsRomanNumeral)
{
}
END_TEST

START_TEST (CreateOutofBoundsRomanNumeralWithDecimal)
{
}
END_TEST

Suite* roman_numeral_obj_suite()
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("RomanNumeralObject");

   /* Core test case */
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, CreateEmptyRomanNumeral);
   suite_add_tcase(s, tc_core);

   return s;
}
