CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex9-2
OBJ = Commodity.o Food.o Healthy.o

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(BIN).cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN) ./input/1.in
	./$(BIN) ./input/2.in

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN) ./input/1.in
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN) ./input/2.in
	
clean:
	rm -rf $(OBJ) $(BIN)