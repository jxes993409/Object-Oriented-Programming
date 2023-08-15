CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = hw1-1

all: $(BIN)

BST.o: BST.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

hw1-1: hw1-1.cpp BST.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN)

clean:
	rm -rf *.o $(BIN)