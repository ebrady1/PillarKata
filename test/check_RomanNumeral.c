/**
 * @Author: ed
 * @Date:   2018-05-27T17:27:26-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: check_RomanNumeral.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-29T05:13:33-04:00
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

//Test various scenarios of creating Roman Numeral objects,
//In this test we will exercise all different digit types, along with
//Variations of smaller digits occuring before larger digits.
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
     
     RomanNumeral_FromRomanString(rn,"VIV");
     ck_assert_int_eq(RomanNumeral_ToInt(rn), 9);

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

//Test various scenarios of creating INVALID Roman Numeral objects,
START_TEST (CreateRomanNumeralWithInvalidRomanCharacters)
{
  //Initialize a Roman Numeral object with a value of 1
  //Perform this for a number of Invalid Roman Numeral Types
  RomanNumeral* rn = RomanNumeral_new("");
  ck_assert(rn != NULL);
  if (NULL != rn)
  {
    RomanNumeral_FromRomanString(rn,"A");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);
    
    RomanNumeral_FromRomanString(rn,"Z");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);

    RomanNumeral_FromRomanString(rn,"MMMM");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);

    RomanNumeral_FromRomanString(rn,"IIV");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);

    RomanNumeral_FromRomanString(rn,"");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);
    
    RomanNumeral_FromRomanString(rn,"I1");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);
    
    RomanNumeral_FromRomanString(rn,"IVX");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);

    RomanNumeral_FromRomanString(rn,"VV");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);

    RomanNumeral_FromRomanString(rn,"LL");
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);
    
    RomanNumeral_FromRomanString(rn,NULL);
    ck_assert_int_eq(RomanNumeral_ToInt(rn), 0);

  }
}
END_TEST
//Test various scenarios of creating Roman Numeral objects,
//In this test we will exercise all different digit types, along with
//Variations of smaller digits occuring before larger digits.
START_TEST (CreateRomanNumeralWithDecimalValue)
{
  RomanNumeral* obj = RomanNumeral_new("");
  int decodeVal = 0;
  bool success = false;

  for (int j = 1; j <= 3999; j++)
  {
    success = RomanNumeral_FromDecimal(obj,j);
    ck_assert(true == success);

    decodeVal = RomanNumeral_ToInt(obj);
    ck_assert_int_eq(j,decodeVal);
  }

  success = RomanNumeral_FromDecimal(obj,0);
  ck_assert(!success);
  
  success = RomanNumeral_FromDecimal(obj,4000);
  ck_assert(!success);
  
  success = RomanNumeral_FromDecimal(obj,9999);
  ck_assert(!success);
  
  success = RomanNumeral_FromDecimal(obj,99999);
  ck_assert(!success);
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
   suite_add_tcase(s, tc_core);

   return s;
}
