CC = g++
CFLAGS = -g -Wall
BIN = lab11-5

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

do:
	./lab11-5
	
clean:
	rm -rf *.o $(BIN)