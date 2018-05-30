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
#include <stdbool.h>
#include "RomanNumeral.h"


// ----------  Static (Private) object functions --------------
typedef struct 
{
  const char* romanString;
  int decValue;
}COMMON_VAL;

static COMMON_VAL COMMON_VALUES[] = 
{
  { "M",    1000  },
  { "MM",   2000  },
  { "MMM",  3000  },
  { "IM",   999   },
  { "VM",   995   },
  { "XM",   990   },
  { "LM",   950   },
  { "CM",   900   },
  { "DM",   500   },
  { "DCCC", 800   },
  { "DCC",  700   },
  { "DC",   600   },
  { "ID",   499   },
  { "VD",   495   },
  { "CD",   400   },
  { "LD",   450   },
  { "XD",   490   },
  { "VD",   495   },
  { "ID",   499   },
  { "D",    500   },
  { "XC",   90    },
  { "VC",   95    },
  { "IC",   99    },
  { "CCC",  300   },
  { "CC",   200   },
  { "C",    100   },
  { "LXL",  90    },
  { "LVL",  95    },
  { "LIL",  99    },
  { "LXXX", 80    },
  { "LXX ", 70    },
  { "LX",   60    },
  { "IL",   49    },
  { "VL",   45    },
  { "XL",   40    },
  { "L",    50    },
  { "IX",   9     },
  { "XXX",  30    },
  { "XX",   20    },
  { "X",    10    },
  { "VIII", 8     },
  { "VII",  7     },
  { "IV",   4     },
  { "V",    5     },
  { "IV",   4     },
  { "VI",   6     },
  { "III",  3     },
  { "II",   2     },
  { "I",    1     },
};

static const 
size_t COMMON_ARRAY_SIZE = (sizeof(COMMON_VALUES) / sizeof(COMMON_VAL));

static bool RomanNumeral_startsWith(const char* searchStr, const char* targetStr)
{
  size_t lenSearch = strlen(searchStr);
  size_t lenTarget = strlen(targetStr);
  bool retVal = 
    (lenTarget < lenSearch) ? 
      false : 
      (strncmp(targetStr, searchStr, lenSearch) == 0);

  return retVal;
}

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
  int curIndex = 0;
  int retVal = 0;

  size_t lenTarget = strlen(obj->romanValue);
  const char* romanStrPtr = obj->romanValue; 
  
  for (int j = 0; j < COMMON_ARRAY_SIZE; j++)
  {
    COMMON_VAL* commonVal = &(COMMON_VALUES[j]);
    if (RomanNumeral_startsWith(commonVal->romanString, (obj->romanValue + curIndex)))
    {
      retVal += commonVal->decValue;
      int searchLen = strlen(commonVal->romanString);
      if ((curIndex + searchLen) <= lenTarget)
      {
        curIndex += searchLen;
      }
      else
      {
        break;
      }
    }
  }

  if (curIndex != lenTarget)
  {
    retVal = 0;
  }

  return retVal;
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
