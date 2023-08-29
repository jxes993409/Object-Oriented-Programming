CC = g++
CFLAGS = -g -Wall
BIN = lab10-4

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab10-4
	
clean:
	rm -rf *.o $(BIN)