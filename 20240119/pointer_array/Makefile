CC=gcc
CFLAGS=-std=gnu99

all:  pointer_array

pointer_array: FORCE
	rm -rf *~ pointer_array
	$(CC) -o pointer_array pointer_array.c pointer_array_main.obj $(CFLAGS)

clean:
	rm -rf *~ pointer_array

FORCE: