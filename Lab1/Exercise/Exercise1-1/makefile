CC = g++
CFLAGS = -g -Wall
BIN = ex1-1

all: $(BIN)

Double.o: Double.cpp
	$(CC) $(CFLAGS) -c $< -o $@

ex1-1: ex1-1.cpp Double.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

clean:
	rm -rf *.o $(BIN)