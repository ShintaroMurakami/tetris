CC=g++
OBJS=field.cpp game.cpp util.cpp keys.cpp mino.cpp main.cpp

all:
	$(CC) -g $(OBJS)

clean:
	rm a.out