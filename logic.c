#include <fcntl.h>
#include <stdio.h>
#include "dep.h"
#include <unistd.h>
void logic (int argc,char* argv [])
{
	if(argc == 1)
		printf("Invalid input program will now exit.\n");
	else if(argc >= 2)
	{
		//assume input is a file
		int fd = open(argv[1], O_RDONLY);
		//if not valid file, then check if it's a stream of 1's and 0's
		if(fd == -1)
		{
			close(fd);
			if( (argv[1][0] == '1' || argv[1][0] == '0'  || *argv[1] == '-') )
				printArgsInformation(argc, argv);
			//not any then it's invalid input
			else 
				printf("Invalid input, program will now exit\n");
		}

		//if fd != -1 then it's a proper file descriptor and read file
		else
		{
			int fd = open(argv[1], O_RDONLY);
			printInformation(fd, -1);
		}
	}
}


