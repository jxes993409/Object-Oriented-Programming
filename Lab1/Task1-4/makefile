CC = g++
CFLAGS = -g -Wall
BIN = lab1-4-1 lab1-4-2

all: $(BIN)

lab1-4-1: lab1-4-1.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab1-4-2: lab1-4-2.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab1-4-1
	./lab1-4-2

clean:
	rm -rf $(BIN)