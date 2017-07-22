CC=g++
CFLAGS=-c -Wall -std=c++0x

all: main

main: main.o grid.o csv.o
	$(CC) build/main.o build/grid.o -o bin/main

main.o: src/grid.cpp
	$(CC) $(CFLAGS) src/main.cpp -o build/main.o

grid.o: src/grid.cpp
	$(CC) $(CFLAGS) src/grid.cpp -o build/grid.o

csv.o: src/csv.h
	$(CC) $(CFLAGS) src/csv.h -o build/csv.o

clean:
	rm build/* bin/*
