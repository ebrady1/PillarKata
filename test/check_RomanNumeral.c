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
     rn->FromRomanString(rn,"I");
     ck_assert_int_eq(rn->ToInt(rn), 1);
     
     rn->FromRomanString(rn,"II");
     ck_assert_int_eq(rn->ToInt(rn), 2);
     
     rn->FromRomanString(rn,"III");
     ck_assert_int_eq(rn->ToInt(rn), 3);

     rn->FromRomanString(rn,"IV");
     ck_assert_int_eq(rn->ToInt(rn), 4);
     
     rn->FromRomanString(rn,"V");
     ck_assert_int_eq(rn->ToInt(rn), 5);
     
     rn->FromRomanString(rn,"VI");
     ck_assert_int_eq(rn->ToInt(rn), 6);
     
     rn->FromRomanString(rn,"VII");
     ck_assert_int_eq(rn->ToInt(rn), 7);
     
     rn->FromRomanString(rn,"VIII");
     ck_assert_int_eq(rn->ToInt(rn), 8);
     
     rn->FromRomanString(rn,"IX");
     ck_assert_int_eq(rn->ToInt(rn), 9);
     
     rn->FromRomanString(rn,"X");
     ck_assert_int_eq(rn->ToInt(rn), 10);
     
     rn->FromRomanString(rn,"XI");
     ck_assert_int_eq(rn->ToInt(rn), 11);
     
     rn->FromRomanString(rn,"XII");
     ck_assert_int_eq(rn->ToInt(rn), 12);
     
     rn->FromRomanString(rn,"XIII");
     ck_assert_int_eq(rn->ToInt(rn), 13);
     
     rn->FromRomanString(rn,"XIV");
     ck_assert_int_eq(rn->ToInt(rn), 14);
     
     rn->FromRomanString(rn,"XV");
     ck_assert_int_eq(rn->ToInt(rn), 15);
     
     rn->FromRomanString(rn,"XVI");
     ck_assert_int_eq(rn->ToInt(rn), 16);
     
     rn->FromRomanString(rn,"XVII");
     ck_assert_int_eq(rn->ToInt(rn), 17);
    
     rn->FromRomanString(rn,"XVIV");
     ck_assert_int_eq(rn->ToInt(rn), 19);
     
     rn->FromRomanString(rn,"XX");
     ck_assert_int_eq(rn->ToInt(rn), 20);
     
     rn->FromRomanString(rn,"XXX");
     ck_assert_int_eq(rn->ToInt(rn), 30);
     
     rn->FromRomanString(rn,"XL");
     ck_assert_int_eq(rn->ToInt(rn), 40);
     
     rn->FromRomanString(rn,"L");
     ck_assert_int_eq(rn->ToInt(rn), 50);
     
     rn->FromRomanString(rn,"LX");
     ck_assert_int_eq(rn->ToInt(rn), 60);
     
     rn->FromRomanString(rn,"LXV");
     ck_assert_int_eq(rn->ToInt(rn), 65);
     
     rn->FromRomanString(rn,"LXVI");
     ck_assert_int_eq(rn->ToInt(rn), 66);
     
     rn->FromRomanString(rn,"LXL");
     ck_assert_int_eq(rn->ToInt(rn), 90);
     
     rn->FromRomanString(rn,"C");
     ck_assert_int_eq(rn->ToInt(rn), 100);
     
     rn->FromRomanString(rn,"VC");
     ck_assert_int_eq(rn->ToInt(rn), 95);
     
     rn->FromRomanString(rn,"CX");
     ck_assert_int_eq(rn->ToInt(rn), 110);
     
     rn->FromRomanString(rn,"D");
     ck_assert_int_eq(rn->ToInt(rn), 500);

     rn->FromRomanString(rn,"LD");
     ck_assert_int_eq(rn->ToInt(rn), 450);
     
     rn->FromRomanString(rn,"M");
     ck_assert_int_eq(rn->ToInt(rn), 1000);

     rn->FromRomanString(rn,"CM");
     ck_assert_int_eq(rn->ToInt(rn), 900);
     
     rn->FromRomanString(rn,"MV");
     ck_assert_int_eq(rn->ToInt(rn), 1005);

     rn->FromRomanString(rn,"MMMCMXCIX");
     ck_assert_int_eq(rn->ToInt(rn), 3999);
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
