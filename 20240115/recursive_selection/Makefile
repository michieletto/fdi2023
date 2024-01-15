CC=gcc
CFLAGS=-std=gnu99

all:  recursive_selection

recursive_selection: FORCE
	rm -rf *~ recursive_selection
	$(CC) -o recursive_selection recursive_selection.c recursive_selection_main.obj $(CFLAGS)

clean:
	rm -rf *~ recursive_selection

FORCE: