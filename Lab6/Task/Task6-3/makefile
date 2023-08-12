CC = g++
CFLAGS = -g -Wall
BIN = lab6-3-1 lab6-3-2


all: $(BIN)

lab6-3-1: lab6-3-1.cpp
	$(CC) $(CFLAGS) $< -o $@

lab6-3-2: lab6-3-2.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./lab6-3-1
	./lab6-3-2

clean:
	rm -rf $(BIN)