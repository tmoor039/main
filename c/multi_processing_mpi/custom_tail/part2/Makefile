all:    tail

tail: tail.o
	gcc -o tail tail.c

tail.o: tail.c
		 gcc -c tail.c -o tail.o


clean:
	rm -f problem2 tail.o  core *~
