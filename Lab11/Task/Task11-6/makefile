CC = g++
CFLAGS = -g -Wall
BIN = lab11-6

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab11-6
	
clean:
	rm -rf *.o $(BIN)