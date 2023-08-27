CC = g++
CFLAGS = -g -Wall
BIN = lab9-2

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab9-2
	
clean:
	rm -rf *.o $(BIN)