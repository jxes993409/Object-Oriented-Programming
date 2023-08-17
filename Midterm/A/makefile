CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = A-1-1 A-1-2 A-2-1 A-2-2 A-3-1 A-3-2

all: $(BIN)

Matrix.o: Matrix.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

Matrix_.o: Matrix_.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

%: %.cpp Matrix.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./A-1-1
	./A-1-2
	./A-2-1
	./A-2-2
	./A-3-1
	./A-3-2

check:
	$(CHECKCC) $(CHECKFLAGS) ./A-1-1
	$(CHECKCC) $(CHECKFLAGS) ./A-1-2
	$(CHECKCC) $(CHECKFLAGS) ./A-2-1
	$(CHECKCC) $(CHECKFLAGS) ./A-2-2
	$(CHECKCC) $(CHECKFLAGS) ./A-3-1
	$(CHECKCC) $(CHECKFLAGS) ./A-3-2
	
clean:
	rm -rf *.o $(BIN)