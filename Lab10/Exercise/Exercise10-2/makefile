CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex10-2
OBJ = Point2D.o Vector.o

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(BIN).cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN)
	
clean:
	rm -rf $(OBJ) $(BIN)