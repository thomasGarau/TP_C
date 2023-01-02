CC= gcc
CFLAGS= -Wall -pedantic -g

all: garauThomasExo1

garauThomasListeInt.o: garauThomasListeInt.h garauThomasListeInt.c 
	$(CC) -c garauThomasListeInt.c -o garauThomasListeInt.o

garauThomasExo1: garauThomasExo1.c garauThomasListeInt.o
	$(CC) $(CFLAGS) -o start garauThomasExo1.c garauThomasListeInt.o

clean:
	del *.o start