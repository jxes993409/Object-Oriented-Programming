CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = hw2-1
OBJ = Spotify.o User.o Playlist.o Song.o

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(BIN).cpp $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BIN) ./input/music.in

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BIN) ./input/music.in

clean:
	rm -rf *.o $(BIN)