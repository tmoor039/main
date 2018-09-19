bmptool:	bmplib.o imagetool.o
	$(CC) bmplib.o imagetool.o -o $@

bmplib.o:	bmplib.c bmplib.h
	$(CC) -Wall -c $< -o $@

imagetool.o:	imagetool.c bmplib.h 
	$(CC) -Wall -c $< -o $@

clean:
	rm -f bmptool *.o core *~