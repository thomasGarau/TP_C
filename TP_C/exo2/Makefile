CC= gcc
CFLAGS= -Wall -pedantic -g

all: garauThomasExo2

garauThomasListePile.o: garauThomasPile.h garauThomasPile.c 
	$(CC) -c garauThomasPile.c -o garauThomasPile.o

garauThomasExo2: garauThomasExo2.c garauThomasPile.o
	$(CC) $(CFLAGS) -o start garauThomasExo2.c garauThomasPile.o

clean:
	del *.o start