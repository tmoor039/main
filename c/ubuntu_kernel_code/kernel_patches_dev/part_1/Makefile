all:	threading threadingSync

threading: threading.o
	gcc -lpthread -o threading threading.c

threading.o: threading.c
	gcc -c threading.c -o threading.o


threadingSync:
	gcc -lpthread -D PTHREAD_SYNC threading.c -o threadingSync


clean:
	rm -f threading threadingSync threading.o core *~
