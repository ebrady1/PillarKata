/**
 * @file	main. 
 * @author: Ed Brady <ed>
 * @date:   2018-05-27T10:29:39-04:00
 * @email:  ed@ebrady.net
 * @brief:	main executable fr Pillar Technologies Roman Numeral Kata
 * @see:	https://github.com/PillarTechnology/kata-roman-numeral-calculator
 */

#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include "RomanNumeralCalc.h"

#define BUFFSIZE 64
static char buffer[BUFFSIZE];
static char answer[RNCALC_MAX_ANSWER_SIZE];

/**
 * @brief Read a calculator expression from the keyboard
 */
static bool readExpression(char* buff, int size)
{
	bool retVal = false;
	if (NULL != buff)
	{
		memset(buff,0,size);
	}
	if (fgets (buff, size, stdin) != NULL)
	{
		retVal = true;
		//Flush any remaining outpu
		if(!strchr(buff, '\n'))
		{
 		   while(fgetc(stdin)!='\n'); //discard extra input 
		}
	}
	return retVal;
}

/**
 * @brief Compile to run Calculator as a standalone executable.
 */

int main(int argc, char* argv[])
{
	RNCALC_STATUS status;
	printf("Roman Numeral Kata:  By Ed Brady\n");
	while (true)
	{
		printf("Enter Expression to add/subtract Roman Numerals (Ctrl-C to break):");
		if (readExpression(buffer,BUFFSIZE))
		{
			status = RomanNumeralCalc_processExpression(buffer,answer);
			switch (status)
			{
  				case RNCALC_OK:
				{
					printf("Answer: %s\n", answer);
					break;
				}

				case RNCALC_NONVALID_RESULT:
				{
					printf("Answer results in a non valid value!\n");
					break;
				}

				case RNCALC_VAL1_INVALID: 
				case RNCALC_VAL2_INVALID: 
				{
					printf("One or more of the Roman Numeral values in invalid!\n");
					break;
				}
				case RNCALC_EXPRESSION_INVALID:
				{
					printf("Invalid Expression!\n");
					break;
				}
			}
		}
	}
}
