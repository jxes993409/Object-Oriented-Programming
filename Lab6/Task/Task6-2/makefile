CC = g++
CFLAGS = -g -Wall
BIN = lab6-2-1 lab6-2-2


all: $(BIN)

lab6-2-1: lab6-2-1.cpp
	$(CC) $(CFLAGS) $< -o $@

lab6-2-2: lab6-2-2.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./lab6-2-1
	./lab6-2-2

clean:
	rm -rf $(BIN)