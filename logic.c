#include <fcntl.h>
#include <stdio.h>
#include "dep.h"
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
