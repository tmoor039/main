all: tracker peer p2pheader 

peer: peer.o p2pheader.o
	gcc -Wall -o peer peer.o -lpthread

tracker: tracker.o p2pheader.o
	gcc -Wall -o tracker tracker.o p2pheader.o -lpthread

p2pheader: p2pheader.c p2pheader.h
	gcc -Wall -c p2pheader.c -lpthread

clean:
	rm -f  peer tracker p2pheader *.o *~ core


