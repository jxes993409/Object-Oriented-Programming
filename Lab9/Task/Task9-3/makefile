CC = g++
CFLAGS = -g -Wall
BIN = lab9-3-1 lab9-3-2

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab9-3-1
	./lab9-3-2
	
clean:
	rm -rf *.o $(BIN)