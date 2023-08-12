CC = g++
CFLAGS = -g -Wall
BIN = ex6-1


all: $(BIN)

ex6-1: ex6-1.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./$(BIN) ./1.txt ./1.txt.out
	./$(BIN) ./2.txt ./2.txt.out
	./$(BIN) ./3.txt ./3.txt.out

clean:
	rm -rf $(BIN) *.out *.o