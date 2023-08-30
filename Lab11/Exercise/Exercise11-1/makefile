CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex11-1
OBJ = Student.o Group.o EEE.o

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