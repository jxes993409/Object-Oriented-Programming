CC = g++
CFLAGS = -g -Wall
BIN = ex6-2


all: $(BIN)

ex6-2: ex6-2.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./$(BIN) ./1.dat ./1.dat.out
	./$(BIN) ./2.dat ./2.dat.out
	./$(BIN) ./3.dat ./3.dat.out

clean:
	rm -rf $(BIN) *.out *.o