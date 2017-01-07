all:    merge

merge: merge.o
	gcc -pthread -o merge  merge.c

merge.o: merge.c
		 gcc -c merge.c -o merge.o


clean:
	rm -f merge  merge.o  core *~



