CC=g++
OBJS=draw.cpp field.cpp game.cpp util.cpp main.cpp

all:
	$(CC) -g $(OBJS)

clean:
	rm a.out