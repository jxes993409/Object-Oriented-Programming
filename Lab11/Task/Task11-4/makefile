CC = g++
CFLAGS = -g -Wall
BIN = lab11-4

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab11-4
	
clean:
	rm -rf *.o $(BIN)