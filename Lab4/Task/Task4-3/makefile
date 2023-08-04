CC = g++
CFLAGS = -g -Wall
BIN = lab4-3-1 lab4-3-2


all: $(BIN)

lab4-3-1: lab4-3-1.cpp
	$(CC) $(CFLAGS) $< -o $@

lab4-3-2: lab4-3-2.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./lab4-3-1
	./lab4-3-2

clean:
	rm -rf $(BIN)