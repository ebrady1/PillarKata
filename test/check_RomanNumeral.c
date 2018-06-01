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

//Test creation of an empty Roman Numeral object
START_TEST (CreateEmptyRomanNumeral)
{
  printf("-- CreateEmptyRomanNumeral --\n");
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
  printf("-- CreateRomanNumeralWithValidRomanCharacters --\n");
  
  //Initialize a Roman Numeral object with a value of 1
  //Perform this for each valid character type
  RomanNumeral* rn = RomanNumeral_new("");
  ck_assert(rn != NULL);
  if (NULL != rn)
  {
     RomanNumeral_FromRomanString(rn,"I");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 1);

     RomanNumeral_FromRomanString(rn,"II");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 2);

     RomanNumeral_FromRomanString(rn,"III");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 3);

     RomanNumeral_FromRomanString(rn,"IV");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 4);

     RomanNumeral_FromRomanString(rn,"V");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 5);

     RomanNumeral_FromRomanString(rn,"VI");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 6);

     RomanNumeral_FromRomanString(rn,"VII");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 7);

     RomanNumeral_FromRomanString(rn,"VIII");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 8);
     
     RomanNumeral_FromRomanString(rn,"VIV");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 9);

     RomanNumeral_FromRomanString(rn,"IX");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 9);

     RomanNumeral_FromRomanString(rn,"X");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 10);

     RomanNumeral_FromRomanString(rn,"XI");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 11);

     RomanNumeral_FromRomanString(rn,"XII");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 12);

     RomanNumeral_FromRomanString(rn,"XIII");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 13);

     RomanNumeral_FromRomanString(rn,"XIV");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 14);

     RomanNumeral_FromRomanString(rn,"XV");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 15);

     RomanNumeral_FromRomanString(rn,"XVI");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 16);

     RomanNumeral_FromRomanString(rn,"XVII");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 17);

     RomanNumeral_FromRomanString(rn,"XVIV");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 19);

     RomanNumeral_FromRomanString(rn,"XX");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 20);

     RomanNumeral_FromRomanString(rn,"XXX");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 30);

     RomanNumeral_FromRomanString(rn,"XL");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 40);

     RomanNumeral_FromRomanString(rn,"L");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 50);

     RomanNumeral_FromRomanString(rn,"LX");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 60);

     RomanNumeral_FromRomanString(rn,"LXV");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 65);

     RomanNumeral_FromRomanString(rn,"LXVI");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 66);

     RomanNumeral_FromRomanString(rn,"LXL");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 90);

     RomanNumeral_FromRomanString(rn,"C");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 100);

     RomanNumeral_FromRomanString(rn,"VC");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 95);

     RomanNumeral_FromRomanString(rn,"CX");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 110);

     RomanNumeral_FromRomanString(rn,"D");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 500);

     RomanNumeral_FromRomanString(rn,"LD");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 450);

     RomanNumeral_FromRomanString(rn,"M");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 1000);

     RomanNumeral_FromRomanString(rn,"CM");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 900);

     RomanNumeral_FromRomanString(rn,"MV");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 1005);

     RomanNumeral_FromRomanString(rn,"MMMCMXCIX");
     ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 3999);
    RomanNumeral_free(rn);

  }
}
END_TEST

//Test various scenarios of creating INVALID Roman Numeral objects,
START_TEST (CreateRomanNumeralWithInvalidRomanCharacters)
{
  printf("-- CreateRomanNumeralWithInvalidRomanCharacters --\n");
  
  //Initialize a Roman Numeral object with a value of 1
  //Perform this for a number of Invalid Roman Numeral Types
  RomanNumeral* rn = RomanNumeral_new("");
  ck_assert(rn != NULL);
  if (NULL != rn)
  {
    RomanNumeral_FromRomanString(rn,"A");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);
    
    RomanNumeral_FromRomanString(rn,"Z");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);

    RomanNumeral_FromRomanString(rn,"MMMM");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);

    RomanNumeral_FromRomanString(rn,"IIV");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);

    RomanNumeral_FromRomanString(rn,"");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);
    
    RomanNumeral_FromRomanString(rn,"I1");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);
    
    RomanNumeral_FromRomanString(rn,"IVX");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);

    RomanNumeral_FromRomanString(rn,"VV");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);

    RomanNumeral_FromRomanString(rn,"LL");
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);
    
    RomanNumeral_FromRomanString(rn,NULL);
    ck_assert_int_eq(RomanNumeral_ToDecimal(rn), 0);
  
    RomanNumeral_free(rn);
  }
}
END_TEST

//Test various scenarios of creating Roman Numeral objects,
//In this test we will exercise all different digit types, along with
//Variations of smaller digits occuring before larger digits.
START_TEST (CreateRomanNumeralWithDecimalValue)
{
  printf("-- CreateRomanNumeralWithDecimalValue --\n");
  int decodeVal = 0;
  bool success = false;
  
  RomanNumeral* obj = RomanNumeral_new("");
  ck_assert(NULL != obj);

  if (NULL != obj)
  {
    for (int j = 1; j <= 3999; j++)
    {
      success = RomanNumeral_FromDecimal(obj,j);
      ck_assert(true == success);

      decodeVal = RomanNumeral_ToDecimal(obj);
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

    RomanNumeral_free(obj);
  }
}

END_TEST

START_TEST (RomanNumeralAdditionOps)
{
  printf("-- RomanNumeralAdditionOps --\n");
  bool success = false;
  bool success1 = false;
  bool success2 = false;

  unsigned int randDec1;
  unsigned int randDec2; 
  RomanNumeral* obj1 = RomanNumeral_new("");
  RomanNumeral* obj2 = RomanNumeral_new("");
  RomanNumeral* answer = RomanNumeral_new("");
  ck_assert((NULL != obj1) && (NULL != obj2) && (NULL != answer));

  if ((NULL != obj1) && (NULL != obj2))
  {

    //Seed the test with 10000 random numbers
    for (unsigned int j = 1; j < 10000; j++)
    {
      randDec1 = (unsigned int)rand() % 2000;
      randDec2 = (unsigned int)rand() % 2000;

      randDec1 = (randDec1 == 0) ? 1 : randDec1;
      randDec2 = (randDec2 == 0) ? 1 : randDec2;
      
      success1 = RomanNumeral_FromDecimal(obj1, randDec1);
      success2 = RomanNumeral_FromDecimal(obj2, randDec2);

      ck_assert(success1 && success2);
      if (success1 && success2)
      {
        success = RomanNumeral_Add(obj1, obj2, answer);
        ck_assert(success);
        if (success)
        {
          success = RomanNumeral_Equals(answer, randDec1 + randDec2);
          ck_assert(success);
        }
      }
    }
    RomanNumeral_free(obj1);
    RomanNumeral_free(obj2);
    RomanNumeral_free(answer);
  }
}
END_TEST

START_TEST (RomanNumeralSubtractionOps)
{
  printf("-- RomanNumeralSubtractionOps --\n");
  bool success = false;
  bool success1 = false;
  bool success2 = false;

  unsigned int randDec1;
  unsigned int randDec2; 
  unsigned int randScratch; 
  RomanNumeral* obj1 = RomanNumeral_new("");
  RomanNumeral* obj2 = RomanNumeral_new("");
  RomanNumeral* answer = RomanNumeral_new("");
  ck_assert((NULL != obj1) && (NULL != obj2) && (NULL != answer));

  if ((NULL != obj1) && (NULL != obj2))
  {

    //Seed the test with 10000 random numbers 
    for (unsigned int j = 1; j < 10000; j++)
    {
      randDec1 = (unsigned int)rand() % 4000;
      randDec2 = (unsigned int)rand() % 4000;

      randDec1 = (randDec1 == 0) ? 1 : randDec1;
      randDec2 = (randDec2 == 0) ? 1 : randDec2;

      if (randDec1 < randDec2)
      {
        randScratch = randDec2;
        randDec2 = randDec1;
        randDec1 = randScratch;
      }
       
      success1 = RomanNumeral_FromDecimal(obj1, randDec1);
      success2 = RomanNumeral_FromDecimal(obj2, randDec2);

      ck_assert(success1 && success2);
      if (success1 && success2)
      {
        success = RomanNumeral_Subtract(obj1, obj2, answer);
        if (success)
        {
          success = RomanNumeral_Equals(answer, randDec1 - randDec2);
          ck_assert(success);
        }
        else
        {
          ck_assert(randDec1 == randDec2);
        }
      }
    }

    RomanNumeral_free(obj1);
    RomanNumeral_free(obj2);
    RomanNumeral_free(answer);
  }
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
   tcase_add_test(tc_core, RomanNumeralAdditionOps);
   tcase_add_test(tc_core, RomanNumeralSubtractionOps);

   suite_add_tcase(s, tc_core);

   return s;
}
