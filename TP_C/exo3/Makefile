CC= gcc
CFLAGS= -Wall -pedantic -g

all: garauThomasExo2

garauThomasListePile.o: garauThomasVoyage.h garauThomasVoyage.c 
	$(CC) -c garauThomasVoyage.c -o garauThomasVoyage.o

garauThomasExo2: garauThomasExo3.c garauThomasVoyage.o
	$(CC) $(CFLAGS) -o start garauThomasExo3.c garauThomasVoyage.o

clean:
	del *.o start
