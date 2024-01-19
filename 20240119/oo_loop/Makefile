CC=gcc
CFLAGS=-std=gnu99

all:  oo_loop

oo_loop: FORCE
	rm -rf *~ oo_loop
	$(CC) -o oo_loop oo_loop.c oo_loop_main.obj $(CFLAGS)

clean:
	rm -rf *~ oo_loop

FORCE: