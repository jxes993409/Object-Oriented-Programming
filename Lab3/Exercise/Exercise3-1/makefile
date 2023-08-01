CC = g++
CFLAGS = -g -Wall
BIN = ex3-1

all: $(BIN)

LineGp.o: LineGp.cpp
	$(CC) $(CFLAGS) -c $< -o $@

ex3-1: ex3-1.cpp LineGp.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

clean:
	rm -rf *.o $(BIN)