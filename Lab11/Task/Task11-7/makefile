CC = g++
CFLAGS = -g -Wall
BIN = lab11-7

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab11-7
	
clean:
	rm -rf *.o $(BIN)