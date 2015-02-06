CC=gcc
CFLAGS=-I. -O3
LDFLAGS=
TARGET=k
SRC=*.c

k:
	$(CC) -o $(TARGET) ${SRC} $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o
