CC=gcc
CFLAGS=-std=gnu99

all:  nonogram

nonogram: FORCE
	rm -rf *~ nonogram
	$(CC) -o nonogram nonogram.c nonogram_main.obj $(CFLAGS)

clean:
	rm -rf *~ nonogram

FORCE: