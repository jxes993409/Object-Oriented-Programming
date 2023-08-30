CC = g++
CFLAGS = -g -Wall
BIN = lab11-2

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab11-2
	
clean:
	rm -rf *.o $(BIN)