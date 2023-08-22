CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = ex7-2

all: $(BIN)

Shape.o: Shape.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

Circle.o: Circle.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

Rect.o: Rect.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

Square.o: Square.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

Triangle.o: Triangle.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

%: %.cpp Shape.o Circle.o Rect.o Square.o Triangle.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./ex7-2

check:
	$(CHECKCC) $(CHECKFLAGS) ./ex7-2
	
clean:
	rm -rf *.o $(BIN)