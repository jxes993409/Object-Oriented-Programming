CC = g++
CFLAGS = -g -Wall
BIN = lab10-1

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab10-1
	
clean:
	rm -rf *.o $(BIN)