all:	calc

calc:	main.o getop.o getch.o stack.o
	gcc -o calc main.o getop.o getch.o stack.o

main.o:  main.c calc.h
	gcc -c main.c -o main.o

getop.o:  getop.c calc.h
	gcc -c getop.c -o getop.o

getch.o:  getch.c calc.h
	gcc -c getch.c -o getch.o

stack.o:  stack.c calc.h
	gcc -c stack.c -o stack.o


clean:
	rm -f calc main.o getch.o getop.o stack.o  core *~

