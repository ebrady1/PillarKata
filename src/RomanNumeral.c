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


// ----------  Static (Private) object functions --------------

//Decode a single character
static int RomanNumeral_decodeRomanCharacter(char c)
{
   int decodedDigit = 0;
   //Look at the current character and decode
   switch(c)
   {
      //Roman Numeral I = 1
      case 'I':
      {
         decodedDigit = 1;
         break;
      }
      
      //Roman Numeral V = 5
      case 'V':
      {
         decodedDigit = 5;
         break;
      }

      //Roman Numeral X = 10
      case 'X':
      {
         decodedDigit = 10;
         break;
      }

      //Roman Numeral L = 50
      case 'L':
      {
         decodedDigit = 50;
         break;
      }

      //Roman Numeral C = 100
      case 'C':
      {
         decodedDigit = 100;
         break;
      }

      //Roman Numeral D = 500
      case 'D':
      {
         decodedDigit = 500;
         break;
      }

      //Roman Numeral M = 1000
      case 'M':
      {
         decodedDigit = 1000;
         break;
      }
     
     //If we get here, then an invalid digit was
     //encountered.  Mark the deoded digit value as
     //0 
      default:
      {
         decodedDigit = 0;
         break;
      }
   }

   return decodedDigit;
}


// ----------  Public object functions --------------

//Instatiate a new Roman Numeral object and setup private data.
RomanNumeral* RomanNumeral_new(const char* value)
{
  RomanNumeral* returnVal = NULL;

  RomanNumeral* rnObj = (RomanNumeral*) malloc(sizeof(RomanNumeral));
  if (NULL != rnObj)
  {
     rnObj->value = 0;
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

         //Iterate each individual charact.  Decode each character
         //per a standard Roman Numeral decoding paradigm. 
         while((charCount - charIndex ) != 0)
         {
            decodedDigit = 
               RomanNumeral_decodeRomanCharacter(obj->romanValue[charIndex]);

            //If an invalid digit was received, then invalidate the 
            //encoded value by setting it 0 and return. 
            if (0 == decodedDigit )
            { 
               decodedValue = 0;
               break;
            }

            //Look at each digit as it is decode along with the 
            //previously decoded digit to determine how to handle
            //sequences like IV, IX, etc.  
            

            //If a previous digit has not been processed, then move then do 
            //nothing, just store the digit and decide what to do on the next
            //loop iteration. 
            if (lastDecodedDigit == 0)
            {
               lastDecodedDigit = decodedDigit;
            }
            else
            {
               //A previous digit was stored on the last loop iteration, decide
               //what to do. 
          
              //If the last digit is smaller than the current digit, process it
              //by taking the current digit minus the previous digit.       
               if (lastDecodedDigit < decodedDigit)
               {
                  decodedValue += decodedDigit - lastDecodedDigit;
                  // Since both the last digit and current digit where
                  // processed, reset the last digit value.
                  lastDecodedDigit = 0;
                  decodedDigit = 0;
               }
               else
               {
                  //The last digit is equal to or larger than the current one.
                  //Process the last digit and save off the current one for
                  //future processing
                  decodedValue += lastDecodedDigit;
                  lastDecodedDigit = decodedDigit;
               }
            }

            charIndex++;
         }

         //No more Roman Numeral digits to process.   Add in the last one
         decodedValue += decodedDigit;
      }
   }

   //Save off the value
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
