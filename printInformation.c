#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "dep.h"
void printInformation(int file_descriptor, int terminator)
{
	int decimal = 0;
	int counter = 7;
	int parityChecker = 0;
	char ch[1];
	const char** ptr;
	printf("Original\t   ASCII\t\t Decimal\tParity\n");
	printf("-------\t          -------\t\t-------\t       -------\n");

	//use read(fd, buff, how many bits u want read)
	while(read(file_descriptor, &ch[0], sizeof(ch)) > 0 && ch[0] != terminator)
	{
		//if a 0 or 1 is read then do something
		if(((int)ch[0] == 49 ||(int)ch[0] == 48) && counter != -1 )
		{	
			printf("%d", atoi(&ch[0]));
			if (atoi(&ch[0]) == 1)
				parityChecker++;
			if(counter!=7)
				decimal = (pow(2, counter) * atoi(&ch[0])) + decimal;
			counter--;
		}//endwhile
		
		//we've read 8 chars therefore print the missing information out
		if (counter == -1)
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

	//if counter has not ended, but we reached end of the loop, then we have extra 0's to pad.
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