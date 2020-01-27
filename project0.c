#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc,char* argv [])
{
	if(argc == 1 || *argv[1] == '-'){
	printf("this is it");
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
