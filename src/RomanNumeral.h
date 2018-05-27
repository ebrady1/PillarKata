#ifndef ROMANNUMERAL_H
#define ROMANNUMERAL_H

typedef struct
{
  void* private;
  int (*ToInt)();
  char* (*ToString)();
}RomanNumeral;

extern RomanNumeral* RomanNumeral_new();
extern void RomanNumeral_free(RomanNumeral* obj);

#endif
