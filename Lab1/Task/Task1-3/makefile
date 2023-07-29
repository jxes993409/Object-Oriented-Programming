CC = g++
CFLAGS = -g -Wall
BIN = lab1-3-1 lab1-3-2 lab1-3-3

all: $(BIN)

lab1-3-1: lab1-3-1.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab1-3-2: lab1-3-2.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab1-3-3: lab1-3-3.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab1-3-1
	./lab1-3-2
	./lab1-3-3

clean:
	rm -rf $(BIN)