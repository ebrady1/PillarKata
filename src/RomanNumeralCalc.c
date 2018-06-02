/**
 * @Author: Ed Brady <ed>
 * @Date:   2018-05-27T10:29:39-04:00
 * @Email:  ed@ebrady.net
 * @Project: Pillar Technologies Roman Numeral Kata
 * @Filename: RomanNumeralCalc.c
 * @Last modified by:   ed
 * @Last modified time: 2018-05-28T08:26:03-04:00
 */

#include <stdio.h>
#include <memory.h>

#define PLUS_OP				"+"
#define MINUS_OP			"-"
#define ALLOWED_OPERATIONS "+-"

#include "RomanNumeral.h"
#include "RomanNumeralCalc.h"

#define BUFFSIZE 64

static char buffer[BUFFSIZE];
/**
 * Member: RomanNumeralCalc_processExpression
 * Description: Processes a simple, user supplied expression and returns the result
 * 				expression must be in the form of X + Y  or X - Y
 * Arg1: The expression to process
 * Arg2: The string to process
 * Returns: The decoded integer value, returns 0 if the decoding failed
 */

RNCALC_STATUS RomanNumeralCalc_processExpression(char* expression, char* answerBuffer)
{
	bool add = false;
	bool subtract = false;
	bool success = false;

	int retVal = -1;	
	char* currentChar = NULL;
	
	RomanNumeral* val1 = NULL;
	RomanNumeral* val2 = NULL;
	RomanNumeral* answer = RomanNumeral_new(NULL);

	if ((NULL != expression) && (NULL != answerBuffer))
	{
		strncpy(buffer, expression, BUFFER_SIZE);
		
		add = (strstr(buffer,PLUS_OP) != NULL);
		subtract = (strstr(buffer,MINUS_OP) != NULL);
		if ((add && !subtract) || (!add && subtract))
		{
			currentChar = strtok(buffer, ALLOWED_OPERATIONS);
			if (NULL != currentChar)
			{
				val1 = RomanNumeral_new(currentChar);
				if ((NULL != val1) && (RomanNumeral_IsValid(val1)))
				{
					currentChar = strtok(NULL,ALLOWED_OPERATIONS); 
					if (NULL != currentChar)
					{
						val2 = RomanNumeral_new(currentChar);
						if ((NULL != val2) && (RomanNumeral_IsValid(val2)))
						{
							if (add)
							{
								success = RomanNumeral_Add(val1,val2,answer);
							}
							else
							{
								success = RomanNumeral_Subtract(val1, val2, answer);
							}

							if (success)
							{
								retVal = RNCALC_OK;
							}
							else
							{
								retVal = RNCALC_NONVALID_RESULT;
							}
						}
						else
						{
							retVal = RNCALC_VAL2_INVALID;
						}
					}
				}
				else
				{
					retVal = RNCALC_VAL1_INVALID;
				}
			}
		}
		else
		{
			retVal = RNCALC_EXPRESSION_INVALID;	
		}
	}

	if (RNCALC_OK == retVal)
	{
		strncpy(answerBuffer,RomanNumeral_ToString(answer),RNCALC_MAX_ANSWER_SIZE);
	}

	RomanNumeral_free(answer);
	return retVal;
}
