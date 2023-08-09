CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex5-1

all: $(BIN)


Complex.o: Complex.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

ex5-1: ex5-1.cpp Complex.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN)

clean:
	rm -rf $(BIN) *.o