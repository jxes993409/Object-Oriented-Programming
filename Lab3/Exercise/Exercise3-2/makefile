CC = g++
CFLAGS = -g -Wall
BIN = ex3-2

all: $(BIN)

Class.o: Class.cpp
	$(CC) $(CFLAGS) -c $< -o $@

ex3-2: ex3-2.cpp Class.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

clean:
	rm -rf *.o $(BIN)