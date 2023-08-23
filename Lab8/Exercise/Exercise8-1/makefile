CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex8-1
OBJ = Personnel.o Teacher.o Student.o TA.o Course.o E3.o

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(BIN).cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN) ./input/personals.csv ./input/courses.csv

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN) ./input/personals.csv ./input/courses.csv
	
clean:
	rm -rf $(OBJ) $(BIN)