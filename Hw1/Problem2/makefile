CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = hw1-2

all: $(BIN)

Stock.o: Stock.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

hw1-2: hw1-2.cpp Stock.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN)

clean:
	rm -rf *.o $(BIN)