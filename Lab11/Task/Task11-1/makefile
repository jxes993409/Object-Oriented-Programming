CC = g++
CFLAGS = -g -Wall
BIN = lab11-1

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab11-1
	
clean:
	rm -rf *.o $(BIN)