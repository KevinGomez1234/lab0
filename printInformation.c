//print information
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
	char t [] = "even";
	char f [] = "odd";
	char *ptr = f;
	char ch[1];
	int start = 1;
	//can only use read(fd, buff, how many bits u want read)
	//enter key = \n 
	while(read(file_descriptor, &ch[0], sizeof(ch)) > 0 && ch[0] != terminator)
	{
		if (start == 1)
		{
			printf("Original\tASCII\t\tDecimal\t\tParity");
			printf("\n--------\t--------\t--------\t--------\n");
			start = 0;
		}
		//if 0 or 1 detected
		if(((int)ch[0] == 49 ||(int)ch[0] == 48) && counter != -1 )
		{	
			printf("%d", atoi(&ch[0]));
			if (atoi(&ch[0]) == 1)
				parityChecker++;
			//gets 8 bit number
			decimal = (pow(2, counter) * atoi(&ch[0])) + decimal;
			counter--;
			
		}
		//8 chars print information out 
		if (counter == -1)
		{
			if(parityChecker % 2 == 0)
				ptr = t;
			else 
				ptr = f;
			printf("\t    %c\t\t   %d\t\t  %s\n",decimal,decimal,ptr);

			counter = 7;
			decimal = 0;
			parityChecker = 0;
		}
	}

	//check if there are missing 0's, if there is append them and print out the info.
	if(counter != -1 && counter != 7)
	{
		if(parityChecker % 2 == 0)
			ptr = t;
		else 
			ptr = f;
		for(int i = 0;i < counter + 1;i++)
		{
			printf("0");
		}
		printf("\t    %c\t\t   %d\t\t  %s\n",decimal,decimal,ptr);
	}
}

