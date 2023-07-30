CC = g++
CFLAGS = -g -Wall
BIN = ex1-2

all: $(BIN)

Array.o: Array.cpp
	$(CC) $(CFLAGS) -c $< -o $@

ex1-2: ex1-2.cpp Array.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

clean:
	rm -rf *.o $(BIN)