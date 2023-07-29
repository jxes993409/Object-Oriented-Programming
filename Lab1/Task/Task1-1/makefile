CC = g++
CFLAGS = -g -Wall
BIN = main1 main2

all: $(BIN)

lab1-1.o: lab1-1.cpp
	$(CC) $(CFLAGS) -c $< -o $@

main1: lab1-1-main1.cpp lab1-1.o
	$(CC) $(CFLAGS) $^ -o $@

main2: lab1-1-main2.cpp lab1-1.o
	$(CC) $(CFLAGS) $^ -o $@

do:
	./main1
	./main2

clean:
	rm -rf *.o main1 main2