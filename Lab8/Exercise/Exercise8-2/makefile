CC = g++
CFLAGS = -g -Wall
GDB = gdb
BIN = ex8-2-1 ex8-2-2

all: $(BIN)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

do:
	./ex8-2-1
	./ex8-2-2

debug:
	$(GDB) ./ex8-2-1
	$(GDB) ./ex8-2-2
	
clean:
	rm -rf $(OBJ) $(BIN)