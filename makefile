CFLAGS = -Wall -std=c99 -g

CC = gcc

# arquivos-objeto
	objects = beale.o lista.o chaves.o codifica.o decodifica.o
     
all: beale.o lista.o chaves.o codifica.o decodifica.o
	$(CC) -o beale beale.o lista.o chaves.o codifica.o decodifica.o

codifica.o: codifica.c
	$(CC) -c $(CFLAGS) codifica.c

decodifica.o: decodifica.c
	$(CC) -c $(CFLAGS) decodifica.c

chaves.o: chaves.c
	$(CC) -c $(CFLAGS) chaves.c

lista.o: lista.c
	$(CC) -c $(CFLAGS) lista.c

beale.o: beale.c
	$(CC) -c $(CFLAGS) beale.c

clean:
	-rm -f $(objects)

purge: clean
	-rm -f beale


