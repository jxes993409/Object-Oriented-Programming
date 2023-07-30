CC = g++
CFLAGS = -g -Wall
BIN = lab2-3-1 lab2-3-2 lab2-3-3

all: $(BIN)

lab2-3-1: lab2-3-1.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab2-3-2: lab2-3-2.cpp
	$(CC) $(CFLAGS) $^ -o $@

lab2-3-3: lab2-3-3.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab2-3-1
	./lab2-3-2
	./lab2-3-3

clean:
	rm -rf *.o $(BIN)