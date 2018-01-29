CFLAGS = -Wall -g

all:	udpclient udpserver tcpclient tcpserver

udpclient:	udpclient.o
	$(CC) $(CFLAGS) $< -o $@

udpserver:	udpserver.o
	$(CC) $(CFLAGS) $< -o $@

tcpclient:	tcpclient.o
	$(CC) $(CFLAGS) $< -o $@

tcpserver:	tcpserver.o
	$(CC) $(CFLAGS) $< -o $@

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) udpclient udpserver tcpclient tcpserver
	$(RM) *.o

