CC = g++
CFLAGS = -g -Wall
BIN = lab7-2

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab7-2
	
clean:
	rm -rf *.o $(BIN)