CC = g++
CFLAGS = -g -Wall
BIN = lab10-3

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab10-3
	
clean:
	rm -rf *.o $(BIN)