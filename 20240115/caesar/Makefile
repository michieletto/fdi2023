CC=gcc
CFLAGS=-std=gnu99

all:  caesar

caesar: FORCE
	rm -rf *~ caesar
	$(CC) -o caesar caesar.c caesar_main.obj $(CFLAGS)

clean:
	rm -rf *~ caesar

FORCE: