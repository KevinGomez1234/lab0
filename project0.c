#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <math.h>

int main(int argc,char* argv [])
{
	if(argc == 1 || *argv[1] == '-'){
	//scanf	
	}
	printf("Hello World");
	return 0;
}

void readBytes()
{
	int fd;
	char charBuffer;
	fd = open("filename.txt", O_RDONLY);	
}

void logic ()
{
	printf("Original\tASCII\tDecimal\tParity");
	printf("\n--------\t--------\t--------\t--------");
	//decide whether reading from file or stdout
	//if reading from stdin then decode that
	//else reading from the file and decode
	//done:
}
void printInformation(int file_descriptor)
{
	int decimal = 0;
	int counter = 0;
	int parityCounter = 0;
	const char t [] = "true";
	const char f [] = "false";
	const char *ptr;
	ptr = f;
	char charBuffer;
	printf("Original\tASCII\tDecimal\tParity\n");
	printf("--------\t--------\t--------\t--------\n");

	while((read(file_descriptor, &charBuffer, 1) > 0)
	{
		if((int)charBuffer == 49 ||(int)charBuffer == 48)
		{
			decimal =  (decimal + pow (2, counter)) * (int)charBuffer;
			counter++;
			printf("%c", (int)charBuffer);
			if(ch == 49)
				parityCounter++;
			if (counter == 7)
			{
				if(parityCounter % 2 == 0)
					ptr = &t;				
				printf("\t%c\t%d\t%s", decimal, decimal,*ptr);
				counter =0;
				decimal = 0;
				parityCounter = 0;
			}			
	}	
	//counter is less than 7
		
		//0 and 1 for loops find binary and parity.
	}
}

