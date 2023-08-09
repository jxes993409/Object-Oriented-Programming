CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex5-2

all: $(BIN)


Score.o: Score.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

ex5-2: ex5-2.cpp Score.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN)

clean:
	rm -rf $(BIN) *.o