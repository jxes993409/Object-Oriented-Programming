CC = g++
CFLAGS = -g -Wall
BIN = lab10-2

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab10-2
	
clean:
	rm -rf *.o $(BIN)