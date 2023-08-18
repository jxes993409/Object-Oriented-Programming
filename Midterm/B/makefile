CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = B-1 B-2

all: $(BIN)


Pair.o: Pair.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

Container.o: Container.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

%: %.cpp Pair.o Container.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./B-1 1.dat 3
	./B-2 2.dat 6

check:
	$(CHECKCC) $(CHECKFLAGS) ./B-1 1.dat 3
	$(CHECKCC) $(CHECKFLAGS) ./B-2 2.dat 6

clean:
	rm -rf $(BIN) *.out *.o