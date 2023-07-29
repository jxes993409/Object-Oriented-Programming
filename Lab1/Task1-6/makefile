CC = g++
CFLAGS = -g -Wall
BIN = lab1-6-1 lab1-6-2 lab1-6-3

all: $(BIN)

lab1-6-1: lab1-6-1.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab1-6-2: lab1-6-2.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab1-6-3: lab1-6-3.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab1-6-1
	./lab1-6-2
	./lab1-6-3

clean:
	rm -rf $(BIN)