#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

void printInformation();
void logic();
int main(int argc,char* argv [])
{
	logic(argc,argv);
	return 0;
}


void logic (int argc,char* argv [])
{
	printf("Original\tASCII\tDecimal\tParity");
	printf("\n--------\t--------\t--------\t--------\n");
	if(argc == 1 || *argv[1] == '-')
	{
		printInformation(0);	
	}
	else
	{
		int fd = open(argv[1], O_RDONLY);
		printInformation(fd);
	}
	//decide whether reading from file or stdout
	//if reading from stdin then decode that
	//else reading from the file and decode
	//done:
}
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
	//counter is less than 7
		//0 and 1 for loops find binary and parity.
