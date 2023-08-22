CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex7-1

all: $(BIN)

Stocks.o: Stocks.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

Fruits.o: Fruits.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

%: %.cpp Stocks.o Fruits.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./ex7-1

check:
	$(CHECKCC) $(CHECKFLAGS) ./ex7-1
	
clean:
	rm -rf *.o $(BIN)