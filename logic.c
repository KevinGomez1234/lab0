#include <fcntl.h>
#include <stdio.h>
#include "dep.h"
void logic (int argc,char* argv [])
{

	if(argc == 1 || *argv[1] == '-')
	{
		//file_desriptor is 0 for reading from stdin.
		printInformation(0, (int)'\n');	
	}
	else
	{
		int fd = open(argv[1], O_RDONLY);
		printInformation(fd, -1);
	}
}
