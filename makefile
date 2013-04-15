CC=g++
CFLAGS=-pthread -Wall -I.
PROG_NAME=client

all: build clean

build: proj2.h
	$(CC) $(CFLAGS) proj2.c client.c -o $(PROG_NAME)

clean:
	rm -rf client
