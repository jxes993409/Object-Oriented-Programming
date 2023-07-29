CC = g++
CFLAGS = -g -Wall
BIN = lab1-5-1 lab1-5-2

all: $(BIN)

lab1-5-1: lab1-5-1.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab1-5-2: lab1-5-2.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab1-5-1
	./lab1-5-2

clean:
	rm -rf $(BIN)