all: mycipher cipherHeader

mycipher: mycipher.o cipherHeader.o
	gcc -o mycipher mycipher.o cipherHeader.o

cipherHeader: cipherHeader.c cipherHeader.h
	gcc  -c cipherHeader.c
clean:
	rm -f mycipher cipherHeader *.o *~ core













