all: sender receiver udpheader

sender: sender.o udpheader.o
	gcc -Wall -o sender sender.o udpheader.o

receiver: receiver.o udpheader.o
	gcc -Wall -o receiver receiver.o udpheader.o

udpheader: udpheader.c udpheader.h
	gcc -Wall -c udpheader.c

clean:
	rm -f  sender receiver udpheader *.o *~ core













