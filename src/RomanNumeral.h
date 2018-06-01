/**
 * @Author: ed
 * @Date:   2018-05-27T11:05:21-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: RomanNumeral.h
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T09:45:50-04:00
 */

#ifndef ROMANNUMERAL_H
#define ROMANNUMERAL_H

#include <stdbool.h>
 
 #define BUFFER_SIZE 16

typedef struct RomanNumeral
{
  unsigned int value;
  char romanValue[BUFFER_SIZE]; 
}RomanNumeral;

//Instantiate a new Roman Numeral object 
//Object can be either empty or initialized from a Roman Numeral Strig
//If a non standard Roman Numeral string is set, then an empty object 
//is created
extern RomanNumeral* RomanNumeral_new(const char* string);

//Free an existing object
extern void RomanNumeral_free(RomanNumeral* obj);

//Return the value of the object as integer
extern int RomanNumeral_ToInt(RomanNumeral* obj);

//Return the Roman Number String
extern char* RomanNumeral_ToString(RomanNumeral* obj);

//Set the value of the object from a RomanNumeral string
extern int RomanNumeral_FromRomanString(RomanNumeral* obj, const char* str);

//Set the value of the object from a Decimal string
extern bool RomanNumeral_FromDecimal(RomanNumeral* obj, unsigned int value);

#endif
