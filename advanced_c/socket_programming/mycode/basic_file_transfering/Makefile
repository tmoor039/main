all: tcpheader tcpclient tcpserver

tcpclient: tcpclient.o tcpheader.o
	gcc -Wall -o tcpclient tcpclient.o 

tcpserver: tcpserver.o tcpheader.o
	gcc -Wall -o tcpserver tcpserver.o tcpheader.o

tcpheader: tcpheader.c tcpheader.h
	gcc -Wall -c tcpheader.c

clean:
	rm -f  tcpclient tcpserver tcpheader *.o *~ core













