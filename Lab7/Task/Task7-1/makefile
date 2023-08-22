CC = g++
CFLAGS = -g -Wall
BIN = lab7-1-1 lab7-1-2 lab7-1-3

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab7-1-1
	./lab7-1-2
	./lab7-1-3
	
clean:
	rm -rf *.o $(BIN)