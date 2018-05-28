/**
 * @Author: Ed Brady
 * @Date:   2018-05-27T21:06:49-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: RomanNumeral.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T09:14:00-04:00
 */

#include <stdio.h>
#include <stdlib.h>
#include "RomanNumeral.h"

//Roman Numeral Private Object data
typedef struct
{
  //The Decimal value representation of the object
  int value;
}RomanNumeralPriv;

//Instatiate a new Roman Numeral object and setup private data.
RomanNumeral* RomanNumeral_new()
{
  RomanNumeral* returnVal = NULL;

  RomanNumeralPriv* privateData =
    (RomanNumeralPriv*) malloc(sizeof(RomanNumeralPriv));
    privateData->value = 0;

  RomanNumeral* rnObj = (RomanNumeral*) malloc(sizeof(RomanNumeral));
  if ((NULL != rnObj) && (NULL != privateData))
  {
    rnObj->privateData = privateData;
    returnVal = rnObj;
  }
	return returnVal;
}

//Free an existing Roman Numeral object
void RomanNumeral_free(RomanNumeral* obj)
{
  if (NULL != obj)
  {
    if (NULL != obj->privateData)
    {
      free(obj->privateData);
      obj->privateData = NULL;
    }
    free(obj);
  }
}
