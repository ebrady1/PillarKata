/**
 * @Author: ed
 * @Date:   2018-05-27T11:05:21-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: RomanNumeral.h
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T08:56:42-04:00
 */

#ifndef ROMANNUMERAL_H
#define ROMANNUMERAL_H

typedef struct
{
  void* privateData;
  int (*ToInt)();
  char* (*ToString)();
}RomanNumeral;

extern RomanNumeral* RomanNumeral_new();
extern void RomanNumeral_free(RomanNumeral* obj);

#endif
