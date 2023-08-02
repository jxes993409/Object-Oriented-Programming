CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex3-2

all: $(BIN)

Class.o: Class.cpp
	$(CC) $(CFLAGS) -c $< -o $@

ex3-2: ex3-2.cpp Class.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN)

clean:
	rm -rf *.o $(BIN)