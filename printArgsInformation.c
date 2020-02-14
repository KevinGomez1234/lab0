#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "dep.h"
#include <string.h>
void printArgsInformation(int argc, char* argv[])
{
	int arraySize;
	int decimal = 0;
	int counter = 7;
	int parityChecker = 0;
	const char** ptr;
	static const char* EVEN = "EVEN";
	static const char* ODD = "ODD";
	char ch[1];
	printf("Original\t   ASCII\t\t Decimal\tParity\n");
	printf("-------\t          -------\t\t-------\t       -------\n");

	for(int i = 1; i<argc;i++)
	{
		arraySize = strlen(argv[i]); 
		for(int j = 0; j<arraySize;j++)
		{
			if(argv[i][j] == (int)'1' || argv[i][j] == (int)'0')
			{
				ch[0] = argv[i][j];
				printf("%d", atoi(&ch[0]));
				if(atoi(&ch[0]) == 1)
					parityChecker++;
				if(counter != 7)
					decimal = (pow(2, counter) * atoi(&ch[0])) + decimal;
				counter--;
			}

			if(counter == -1)
			{
				if(parityChecker % 2 == 0)
					ptr = &EVEN;
				else
					ptr = &ODD;

				//edge cases
				if(decimal>=0 && decimal<=32)
					printf("\t    %s\t\t   %d\t\t  %s\n", nonPrintables[decimal],decimal, *ptr);
				else if(decimal == 127)
					printf("\t    %s\t\t   %d\t\t  %s\n", nonPrintables[33],decimal, *ptr);
				else	
					printf("\t      %c\t\t\t   %d\t\t  %s\n",decimal,decimal,*ptr);
				counter = 7;
				decimal = 0;
				parityChecker = 0;
			}
		}
	}

	if(counter != -1 && counter != 7)
	{
			if(parityChecker % 2 == 0)
				ptr = &EVEN;
			else
				ptr = &ODD;
			for(int i = 0;i < counter + 1;i++)
			{
				printf("0");
			}
			//edge cases
			if(decimal>=0 && decimal<=32)
				printf("\t    %s\t\t   %d\t\t  %s\n", nonPrintables[decimal],decimal, *ptr);
			else if(decimal == 127)
				printf("\t    %s\t\t   %d\t\t  %s\n", nonPrintables[33],decimal, *ptr);
			else	
				printf("\t      %c\t\t\t   %d\t\t  %s\n",decimal,decimal,*ptr);
			counter = 7;
			decimal = 0;
			parityChecker = 0;
	}
}