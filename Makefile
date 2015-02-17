CC=gcc
CFLAGS=-I. -std=gnu99 -O3 -Wall
LDFLAGS=
TARGET=k
SRC=*.c

k:
	$(CC) -o $(TARGET) ${SRC} $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o
