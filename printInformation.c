//print information
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "dep.h"


void printInformation(int file_descriptor)
{
	int decimal = 0;
	int counter = 7;
	int parityChecker = 0;
	char t [] = "even";
	char f [] = "odd";
	char *ptr = f;
	char ch;
	while(read(file_descriptor, &ch, sizeof(ch)) > 0 && ch != '\n')
	{
		if((int)ch == 49 ||(int)ch == 48)
		{
			if (atoi(&ch) == 1)
				parityChecker++;
			//gets 8 bit number
			decimal = (pow(2, counter) * atoi(&ch)) + decimal;
			counter--;
			printf("%d", atoi(&ch));
		}
		if (counter == -1)
		{
			if(parityChecker % 2 == 0)
				ptr = t;
			else 
				ptr = f;
			printf("\t%c\t%d\t%s\n",decimal,decimal,ptr);
			counter = 7;
			decimal = 0;
		}
	}
	//check if there are missing 0's
	if(counter != -1 && counter != 7)
	{
		for(int i = 0;i<counter+1;i++)
			printf("0");
		printf("\t%c\t%d\t%s\n",decimal,decimal,ptr);
	}
}

