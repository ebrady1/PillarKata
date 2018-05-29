/**
 * @Author: ed
 * @Date:   2018-05-27T17:27:26-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: check_RomanNumeral.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T10:00:37-04:00
 */

#include <check.h>
#include "../src/RomanNumeral.h"

//Test creation of an empty Roman Numeral object
START_TEST (CreateEmptyRomanNumeral)
{
  //Instantiate a Roman Numeral object and check if a pointer to the object
  //was returned
  RomanNumeral* rn =  RomanNumeral_new(NULL);
  ck_assert(NULL != rn);
  if (NULL != rn)
  {
    RomanNumeral_free(rn);
  }

  rn =  RomanNumeral_new("");
  ck_assert(rn != NULL);
  if (NULL != rn)
  {
    RomanNumeral_free(rn);
  }

}
END_TEST

START_TEST (CreateRomanNumeralWithValidRomanCharacters)
{
   //Initialize a Roman Numeral object with a value of 1
   //Perform this for each valid character type
  RomanNumeral* rn = RomanNumeral_new("");
  ck_assert(rn != NULL);
  if (NULL != rn)
  {
     RomanNumeral_FromRomanString(rn,"I");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 1);
     
     RomanNumeral_FromRomanString(rn,"II");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 2);
     
     RomanNumeral_FromRomanString(rn,"III");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 3);

     RomanNumeral_FromRomanString(rn,"IV");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 4);
     
     RomanNumeral_FromRomanString(rn,"V");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 5);
     
     RomanNumeral_FromRomanString(rn,"VI");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 6);
     
     RomanNumeral_FromRomanString(rn,"VII");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 7);
     
     RomanNumeral_FromRomanString(rn,"VIII");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 8);
     
     RomanNumeral_FromRomanString(rn,"IX");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 9);
     
     RomanNumeral_FromRomanString(rn,"X");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 10);
     
     RomanNumeral_FromRomanString(rn,"XI");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 11);
     
     RomanNumeral_FromRomanString(rn,"XII");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 12);
     
     RomanNumeral_FromRomanString(rn,"XIII");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 13);
     
     RomanNumeral_FromRomanString(rn,"XIV");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 14);
     
     RomanNumeral_FromRomanString(rn,"XV");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 15);
     
     RomanNumeral_FromRomanString(rn,"XVI");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 16);
     
     RomanNumeral_FromRomanString(rn,"XVII");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 17);
    
     RomanNumeral_FromRomanString(rn,"XVIV");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 19);
     
     RomanNumeral_FromRomanString(rn,"XX");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 20);
     
     RomanNumeral_FromRomanString(rn,"XXX");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 30);
     
     RomanNumeral_FromRomanString(rn,"XL");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 40);
     
     RomanNumeral_FromRomanString(rn,"L");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 50);
     
     RomanNumeral_FromRomanString(rn,"LX");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 60);
     
     RomanNumeral_FromRomanString(rn,"LXV");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 65);
     
     RomanNumeral_FromRomanString(rn,"LXVI");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 66);
     
     RomanNumeral_FromRomanString(rn,"LXL");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 90);
     
     RomanNumeral_FromRomanString(rn,"C");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 100);
     
     RomanNumeral_FromRomanString(rn,"VC");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 95);
     
     RomanNumeral_FromRomanString(rn,"CX");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 110);
     
     RomanNumeral_FromRomanString(rn,"D");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 500);

     RomanNumeral_FromRomanString(rn,"LD");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 450);
     
     RomanNumeral_FromRomanString(rn,"M");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 1000);

     RomanNumeral_FromRomanString(rn,"CM");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 900);
     
     RomanNumeral_FromRomanString(rn,"MV");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 1005);

     RomanNumeral_FromRomanString(rn,"MMMCMXCIX");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 3999);
    RomanNumeral_free(rn);
  
  }
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
   tcase_add_test(tc_core, CreateRomanNumeralWithValidRomanCharacters);
   tcase_add_test(tc_core, CreateRomanNumeralWithInvalidRomanCharacters);
   tcase_add_test(tc_core, CreateRomanNumeralWithDecimalValue);
   tcase_add_test(tc_core, CreateOutofBoundsRomanNumeral);
   tcase_add_test(tc_core, CreateOutofBoundsRomanNumeralWithDecimal);
   suite_add_tcase(s, tc_core);
   


   return s;
}