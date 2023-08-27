CC = g++
CFLAGS = -g -Wall
BIN = lab9-1

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab9-1
	
clean:
	rm -rf *.o $(BIN)