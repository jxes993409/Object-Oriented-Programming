CC = g++
CFLAGS = -g -Wall
BIN = lab11-3

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab11-3
	
clean:
	rm -rf *.o $(BIN)