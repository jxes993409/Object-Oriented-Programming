CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex7-2
OBJ = Shape.o Circle.o Rect.o Square.o Triangle.o

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(BIN).cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./ex7-2

check:
	$(CHECKCC) $(CHECKFLAGS) ./ex7-2
	
clean:
	rm -rf $(OBJ) $(BIN)