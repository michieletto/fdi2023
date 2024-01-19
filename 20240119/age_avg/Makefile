CC=gcc
CFLAGS=-std=gnu99

all:  age_avg

age_avg: FORCE
	rm -rf *~ age_avg
	$(CC) -o age_avg age_avg.c age_avg_main.obj $(CFLAGS)

clean:
	rm -rf *~ age_avg

FORCE: