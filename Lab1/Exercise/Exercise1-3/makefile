CC = g++
CFLAGS = -g -Wall
BIN = ex1-3

all: $(BIN)

Array.o: Array.cpp
	$(CC) $(CFLAGS) -c $< -o $@

ex1-3: ex1-3.cpp Array.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

clean:
	rm -rf *.o $(BIN)