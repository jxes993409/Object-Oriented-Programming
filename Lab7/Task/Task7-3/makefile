CC = g++
CFLAGS = -g -Wall
BIN = lab7-3

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab7-3
	
clean:
	rm -rf *.o $(BIN)