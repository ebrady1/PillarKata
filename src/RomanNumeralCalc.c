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

#define BUFFSIZE 64

static char buffer[BUFFSIZE];

static bool readExpression(char* buff, int size)
{
	bool retVal = false;
	if (NULL != buff)
	{
		memset(buff,0,BUFFSIZE);
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

//Compile to run Calculator as a standalone executable.
int main(int argc, char* argv[])
{
	bool add = false;
	bool subtract = false;
	bool success = false;

	int retVal = -1;	
	char* currentChar = NULL;

	RomanNumeral* val1 = NULL;
	RomanNumeral* val2 = NULL;
	RomanNumeral* answer = RomanNumeral_new(NULL);
	
	printf("Roman Numeral Kata:  By Ed Brady\n");
	while (true)
	{
		printf("Enter Expression to add/subtract Roman Numerals:");
		if (readExpression(buffer,BUFFER_SIZE))
		{
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
									printf("Answer: %s\n", RomanNumeral_ToString(answer));
								}
								else
								{
									printf("Answer results in a non valid value!\n");
								}
							}
							else
							{
								printf("%s is not Valid!\n",currentChar);
							}
						}
					}
					else
					{
						printf("%s is not Valid!\n",currentChar);
					}
				}

			}
			else
			{
				printf("Invalid Expression!\n");
			}
		}
	}
}
