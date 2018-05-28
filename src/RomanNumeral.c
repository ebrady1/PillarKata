/**
 * @Author: Ed Brady
 * @Date:   2018-05-27T21:06:49-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: RomanNumeral.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T10:02:38-04:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RomanNumeral.h"

//Instatiate a new Roman Numeral object and setup private data.
RomanNumeral* RomanNumeral_new(const char* value)
{
  RomanNumeral* returnVal = NULL;

  RomanNumeral* rnObj = (RomanNumeral*) malloc(sizeof(RomanNumeral));
  if (NULL != rnObj)
  {
     rnObj->value = 0;
     rnObj->ToInt = RomanNumeral_ToInt;
     rnObj->ToString = RomanNumeral_ToString;
     rnObj->FromRomanString = RomanNumeral_FromRomanString;
     rnObj->FromDecimalString = RomanNumeral_FromDecimalString;
     returnVal = rnObj;
  }

  if (NULL != value)
  {
     rnObj->romanValue = value;
  }
  else
  {
    rnObj->romanValue = "";
  }

  return returnVal;
}

//Free an existing Roman Numeral object
void RomanNumeral_free(RomanNumeral* obj)
{
  if (NULL != obj)
  {
    free(obj);
  }
}

//Return the value of the object as integer
int RomanNumeral_ToInt(RomanNumeral* obj)
{
   int decodedValue = 0;
   int charCount = 0;
   int charIndex = 0;
   int lastDecodedDigit = 0;
   int decodedDigit = 0;

  //Verify an object was passed in 
   if (NULL != obj)
   {
      //If our stored decimal value is not 0, return the
      //existing value, if not reparse the string 
      if (0 != obj->value)
      {
         decodedValue = obj->value;
      }
      else if ((obj->romanValue == NULL) || (strcmp(obj->romanValue,"") != 0))
      {
         charCount = strlen(obj->romanValue);
         while((charCount - charIndex ) != 0)
         {
            char current = obj->romanValue[charIndex];

            switch(current)
            {
               case 'I':
               {
                  decodedDigit = 1;
                  break;
               }
               
               case 'V':
               {
                  decodedDigit = 5;
                  break;
               }

               case 'X':
               {
                  decodedDigit = 10;
                  break;
               }

               case 'L':
               {
                  decodedDigit = 50;
                  break;
               }

               case 'C':
               {
                  decodedDigit = 100;
                  break;
               }

               case 'D':
               {
                  decodedDigit = 500;
                  break;
               }

               case 'M':
               {
                  decodedDigit = 1000;
                  break;
               }
               
               default:
               {
                  decodedDigit = 0;
                  break;
               }
            }

            if (0 == decodedDigit )
            { 
               decodedValue = 0;
               break;
            }

            if (lastDecodedDigit == 0)
            {
               lastDecodedDigit = decodedDigit;
            }
            else
            {
               if (lastDecodedDigit < decodedDigit)
               {
                  decodedValue += decodedDigit - lastDecodedDigit;
                  lastDecodedDigit = 0;
                  decodedDigit = 0;
               }
               else
               {
                  decodedValue += lastDecodedDigit;
                  lastDecodedDigit = decodedDigit;
               }
            }

            charIndex++;
         }

         decodedValue += decodedDigit;
      }
   }
   obj->value = decodedValue;
   return decodedValue;
}

//Return the Roman Number String
char* RomanNumeral_ToString(RomanNumeral* obj)
{
   return "";
}

//Set the value of the object from a RomanNumeral string
int RomanNumeral_FromRomanString(RomanNumeral* obj, const char* str)
{
   int decodedValue = 0;
   if (NULL != obj)
   {
      obj->romanValue = str;
      obj->value = 0;
      decodedValue = RomanNumeral_ToInt(obj);
   }
   return decodedValue;
}

//Set the value of the object from a Decimal string
int RomanNumeral_FromDecimalString(RomanNumeral* obj, const char* str)
{
   return 0;
}
