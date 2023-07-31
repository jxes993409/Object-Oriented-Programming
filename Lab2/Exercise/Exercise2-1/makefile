CC = g++
CFLAGS = -g -Wall
BIN = ex2-1

all: $(BIN)

VM.o: VM.cpp
	$(CC) $(CFLAGS) -c $< -o $@

ex2-1: ex2-1.cpp VM.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

clean:
	rm -rf *.o $(BIN)