CC = g++
CFLAGS = -g -Wall
BIN = lab4-2-1 lab4-2-2


all: $(BIN)

lab4-2-1: lab4-2-1.cpp
	$(CC) $(CFLAGS) $< -o $@

lab4-2-2: lab4-2-2.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./lab4-2-1
	./lab4-2-2

clean:
	rm -rf $(BIN)