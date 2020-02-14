target: main.o printInformation.o logic.o printArgsInformation.o
	gcc main.o printInformation.o logic.o printArgsInformation.o -o zero-one -lm
main.o: main.c logic.o
	gcc -c main.c -Wall -Wextra
printInformation.o: printInformation.c
	gcc -c printInformation.c -Wall -Wextra -lm
logic.o: logic.c printInformation.o
	gcc -c logic.c -Wall -Wextra
printArgsInformation.o: printArgsInformation.c
	gcc -c printArgsInformation.c -Wall -Wextra -lm
REM:
	rm *.o
