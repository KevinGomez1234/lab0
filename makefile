target: main.o printInformation.o logic.o
	gcc main.o printInformation.o logic.o -o main -lm
main.o: main.c logic.o
	gcc -c main.c
printInformation.o: printInformation.c
	gcc -c printInformation.c -Wall -Wextra -lm
logic.o: logic.c printInformation.o
	gcc -c logic.c -Wall -Wextra
clean:
	rm *.o
	rm main
