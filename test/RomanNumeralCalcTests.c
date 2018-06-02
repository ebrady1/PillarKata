/**
 * @Author: Ed Brady
 * @Date:   2018-05-27T20:21:29-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: RomanNumeralCalcTests.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T08:26:46-04:00
 */

#include <stdlib.h>
#include <check.h>
#include "check_RomanNumeral.h"
#include "check_RomanNumeralCalc.h"

//Main function, generate a test runner for the Calculator tests and
//execute
int main(void)
{
   int number_failed;
   Suite *objSuite;
   Suite *calcSuite;
   SRunner *sr;

   objSuite = roman_numeral_obj_suite();
   sr = srunner_create(objSuite);
   
   calcSuite = roman_numeral_calc_suite();
   srunner_add_suite(sr,calcSuite);

   srunner_set_fork_status (sr, CK_NOFORK);

   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
  
   srunner_free(sr);
   
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
