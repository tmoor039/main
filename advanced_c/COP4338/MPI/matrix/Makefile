all:	seqmm thmm genmat prtmat

CFLAGS = -O3 -Wall -pthread

seqmm:	seqmm.c
	$(CC) $(CFLAGS) $< -lm -o $@

thmm:	thmm.c
	$(CC) $(CFLAGS) $< -lm -o $@

genmat:	genmat.c
	$(CC) $(CFLAGS) $< -lm -o $@

prtmat:	prtmat.c
	$(CC) $(CFLAGS) $< -lm -o $@

clean:
	$(RM) seqmm thmm genmat prtmat *~
