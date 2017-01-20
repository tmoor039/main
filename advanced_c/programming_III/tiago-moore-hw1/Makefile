all:    replace

replace: main.o
	gcc -o replace main.c

main.o: main.c
		 gcc -c main.c -o main.o


clean:
	rm -f replace main.o  core *~
