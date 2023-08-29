CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex10-1

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./ex10-1

check:
	$(CHECKCC) $(CHECKFLAGS) ./ex10-1

clean:
	rm -rf *.o $(BIN)