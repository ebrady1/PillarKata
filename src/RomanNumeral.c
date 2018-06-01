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


// ----------  Static (Private) object type definitions --------------
typedef const struct 
{
//  const char* romanString;
  char romanString[BUFFER_SIZE];
  int decValue;
}COMMON_VAL;

typedef struct
{
  size_t size;
  COMMON_VAL* encoder;
}ENCODER_ENTRY_INFO;

// ----------  Static (Private) data tables --------------

//Data tables utilized by decoding algorithm
//NOTE: The algorithm requires each entry hold a specific
//positional placement in the array, do not re-order 
static COMMON_VAL DECODE_ORDER[] = 
{
  { "MMM",  3000  },
  { "MM",   2000  },
  { "M",    1000  },
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
  { "CLC",  150   },
  { "CXC",  190   },
  { "CVC",  195   },
  { "CIC",  199   },
  { "C",    100   },
  { "LC",   50    },
  { "XC",   90    },
  { "VC",   95    },
  { "IC",   99    },
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
  { "XXX",  30    },
  { "XX",   20    },
  { "XIX",  19    },
  { "XIV",  14    },
  { "X",    10    },
  { "IX",   9     },
  { "VIV",  9     },
  { "VIII", 8     },
  { "VII",  7     },
  { "VI",   6     },
  { "V",    5     },
  { "IV",   4     },
  { "III",  3     },
  { "II",   2     },
  { "I",    1     },
};

//The size of the decoding list above
static const 
size_t COMMON_ARRAY_SIZE = (sizeof(DECODE_ORDER) / sizeof(COMMON_VAL));


//Data tables utilized by the encoding algorithm
//NOTE: The algorithm requires each entry hold a specific
//positional placement in the array, do not re-order 
static const COMMON_VAL ENCODE_1000_LIST[] = 
{
  { "MMM",  3000  },
  { "MM",   2000  },
  { "M",    1000  }
};

//Data tables utilized by the encoding algorithm
//NOTE: The algorithm requires each entry hold a specific
//positional placement in the array, do not re-order 
static const COMMON_VAL ENCODE_100_LIST[] = 
{
  { "IM",   999   },
  { "VM",   995   },
  { "XM",   990   },
  { "LM",   950   },
  { "CM",   900   },
  { "DCCC", 800   },
  { "DCC",  700   },
  { "DC",   600   },
  { "D",    500   },
  { "ID",   499   },
  { "VD",   495   },
  { "XD",   490   },
  { "LD",   450   },
  { "CD",   400   },
  { "CCC",  300   },
  { "CC",   200   },
  { "C",    100   },
};

//Data tables utilized by the encoding algorithm
//NOTE: The algorithm requires each entry hold a specific
//positional placement in the array, do not re-order 
static const COMMON_VAL ENCODE_10_LIST[] = 
{
  { "IC",   99    },
  { "VC",   95    },
  { "XC",   90    },
  { "LXL",  90    },
  { "LVL",  95    },
  { "LXXX", 80    },
  { "LXX ", 70    },
  { "LX",   60    },
  { "L",    50    },
  { "IL",   49    },
  { "VL",   45    },
  { "XL",   40    },
  { "XXX",  30    },
  { "XX",   20    },
  { "X",    10    }
};

//Data tables utilized by the encoding algorithm
//NOTE: The algorithm requires each entry hold a specific
//positional placement in the array, do not re-order 
static const COMMON_VAL ENCODE_1_LIST[] = 
{
  { "IX",   9     },
  { "VIII", 8     },
  { "VII",  7     },
  { "VI",   6     },
  { "V",    5     },
  { "IV",   4     },
  { "III",  3     },
  { "II",   2     },
  { "I",    1     },
};

//Data tables utilized by the encoding algorithm
//NOTE: The algorithm requires each entry hold a specific
//positional placement in the array, do not re-order 
static const ENCODER_ENTRY_INFO VAL_ENCODERS[] = 
{
  { sizeof(ENCODE_1000_LIST) / sizeof(COMMON_VAL),  ENCODE_1000_LIST },
  { sizeof(ENCODE_100_LIST) / sizeof(COMMON_VAL),  ENCODE_100_LIST },
  { sizeof(ENCODE_10_LIST) / sizeof(COMMON_VAL),   ENCODE_10_LIST },
  { sizeof(ENCODE_1_LIST) / sizeof(COMMON_VAL),    ENCODE_1_LIST },
};


// ----------  Static (Private) object functions --------------


/**
 * Member: RomanNumeral_startsWith
 * Description: Test to see if a target string begins with a user supplied
 *              search string;
 * Arg1: The RomanNumeral object to which this function is associated with
 * Arg2: The search string to check to use while testing the target string
 * Arg3: The target string  to search
 */
static bool RomanNumeral_startsWith(RomanNumeral* obj, const char* searchStr, const char* targetStr)
{
  size_t lenSearch = strlen(searchStr);
  size_t lenTarget = strlen(targetStr);
  bool retVal = 
    (lenTarget < lenSearch) ? 
      false : 
      (strncmp(targetStr, searchStr, lenSearch) == 0);

  return retVal;
}

// ----------  Public object functions --------------

/**
 * Member: RomanNumeral_new
 * Description: Instantiates a new RomanNumeral object
 * Arg1: Optional string value to initialize RomanNumreal object with
 */
RomanNumeral* RomanNumeral_new(const char* value)
{
  RomanNumeral* returnVal = NULL;

  RomanNumeral* rnObj = (RomanNumeral*) malloc(sizeof(RomanNumeral));
  if (NULL != rnObj)
  {
    memset(rnObj,0,sizeof(RomanNumeral));
     returnVal = rnObj;
  }

  if (NULL != value)
  {
     strncpy(rnObj->romanValue, value, BUFFER_SIZE);
  }
  return returnVal;
}

/**
 * Member: RomanNumeral_free
 * Description: Frees a previously instantiated RomanNumeral object
 * Arg1: The RomanNumeral object to free
 */
void RomanNumeral_free(RomanNumeral* obj)
{
  if (NULL != obj)
  {
    free(obj);
  }
}

/**
 * Member: RomanNumeral_ToInt
 * Description: Returns the integer value of the RomanNumeral object 
 * Arg1: The RomanNumeral object to perform the operation on 
 * Returns: Integer value of the RomanNumeral object, returns 0 if 
 *          the object's value could not be decoded
 */
int RomanNumeral_ToInt(RomanNumeral* obj)
{
  int curIndex = 0;
  int retVal = 0;

  //Test of the user supplied value is valid
  if (NULL != obj)
  {
    size_t lenTarget = strlen(obj->romanValue);

    //Process the Roman Numeral string and decode each character units using
    //the data decoding tables with common RomanNumeral definitions
    for (int j = 0; j < COMMON_ARRAY_SIZE; j++)
    {
      COMMON_VAL* commonVal = DECODE_ORDER + j;
      if (RomanNumeral_startsWith(obj, commonVal->romanString, obj->romanValue + curIndex))
      {
        retVal += commonVal->decValue;
        int searchLen = strlen(commonVal->romanString);
        curIndex += searchLen;
        if (curIndex >= lenTarget)
        {
          break;
        }
      }
    }

    if ((curIndex != lenTarget) || (retVal < 1) || (retVal > 3999))
    {
      retVal = 0;
    }
  }

  return retVal;
}

/**
 * Member: RomanNumeral_ToString
 * Description: Returns the string value of the RomanNumeral object 
 * Arg1: The RomanNumeral object to perform the operation on 
 * Returns: The string representation of the Numeral object
 */
char* RomanNumeral_ToString(RomanNumeral* obj)
{
  char* retVal = "";
  if ((NULL != obj) && 
      (0 != obj->romanValue[0]) && 
      (strcmp(obj->romanValue,"") == 0))
  {
    retVal = obj->romanValue;
  }
  
  return retVal;
}

/**
 * Member: RomanNumeral_FromRomanString
 * Description: Sets the RomanNumeral to the specified string value 
 *              and decode it's corresponding decimal value
 * Arg1: The RomanNumeral object to perform the operation on 
 * Arg2: The string to process
 * Returns: The decoded integer value, returns 0 if the decoding failed
 */
int RomanNumeral_FromRomanString(RomanNumeral* obj, const char* str)
{
   int decodedValue = 0;
   if ((NULL != obj) && (NULL != str))
   {
      strncpy(obj->romanValue,str, BUFFER_SIZE);
      obj->value = 0;
      decodedValue = RomanNumeral_ToInt(obj);
   }
   return decodedValue;
}

/**
 * Member: RomanNumeral_FromDecimal
 * Description: Sets the RomanNumeral to the specified decimal value 
 *              and decode it's corresponding RomanNumeral string value
 * Arg1: The RomanNumeral object to perform the operation on 
 * Arg2: The decimal value
 * Returns: true if the decimal value was succesfully converter to a 
 *          valid Roman Numeral string value. 
 */
bool RomanNumeral_FromDecimal(RomanNumeral* obj, unsigned int dec)
{

  bool found = false;
  bool retVal = false;
  int bufferIndex = 0;
  int encoderEntryLen = 0;
  char buffer[BUFFER_SIZE];
  unsigned int decodeValue = 0;
  unsigned int workVal = dec;
  COMMON_VAL* commonVal = NULL;

  int numEncoders = sizeof(VAL_ENCODERS) / sizeof(ENCODER_ENTRY_INFO);

  //Process the user supplied decimal value, digit by digit, and encode
  //to a valid roman String.
  if ((NULL != obj) && (dec > 0) && (dec < 4000))
  {
    memset(buffer,0,BUFFER_SIZE);
    for (int encoderIndex = 0; encoderIndex < numEncoders; encoderIndex++)
    {
      found = false;
      encoderEntryLen = VAL_ENCODERS[encoderIndex].size;
      for (int encoderEntry = 0; encoderEntry < encoderEntryLen; encoderEntry++)
      {
        commonVal = (VAL_ENCODERS[encoderIndex].encoder) + encoderEntry;
        if ((workVal / commonVal->decValue) >= 1)
        {
          strncpy(buffer + bufferIndex,commonVal->romanString,strlen(commonVal->romanString));
          bufferIndex += strlen(commonVal->romanString);
          workVal = workVal - commonVal->decValue;
          found = true;
          break;
        }
      }
    }
    if (0 == workVal)
    {

      strncpy(obj->romanValue, buffer, BUFFER_SIZE);
      retVal = true;
    }
  }

  return retVal;
}

/**
 * Member: RomanNumeral_Add
 * Description: Adds two Numeral objects
 * Arg1: Numeral #1 to add 
 * Arg2: Numeral #2 to add
 * Arg3: Answer
 * Returns: true if the operation can be performed succesfully. 
 *          false if the operation could not be completed succesfully
 */
bool RomanNumeral_Add(RomanNumeral* val1, RomanNumeral* val2, RomanNumeral* answer)
{
  return false;
}

/**
 * Member: RomanNumeral_Add
 * Description: Adds two Numeral objects
 * Arg1: Numeral #1 to add 
 * Arg2: Numeral #2 to add
 * Arg3: Answer
 * Returns: true if the operation can be performed succesfully. 
 *          false if the operation could not be completed succesfully
 */
bool RomanNumeral_Subtract(RomanNumeral* val1, RomanNumeral* val2, RomanNumeral* answer)
{
  return false;
}


/**
 * Member: RomanNumeral_Add
 * Description: Check if the Roman Numeral is equal to the user supplied decimal value. 
 * Arg1: Object to check 
 * Arg2: Decimal value to check against 
 * Returns: true if the object's value is equal to the user supplied number
 *          false if not equal, or an invalid object/decimal value was passed 
 */
bool RomanNumeral_Equals(RomanNumeral* obj, unsigned int value)
{
  return false;
}