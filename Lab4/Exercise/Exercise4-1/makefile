CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex4-1

all: $(BIN)

Grid.o: Grid.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

MineSweeper.o: MineSweeper.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

ex4-1: ex4-1.cpp Grid.o MineSweeper.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN)

clean:
	rm -rf $(BIN) *.o