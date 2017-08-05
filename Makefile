SRCDIR=src
BUILDDIR=build
TARGETDIR=bin
CC=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=-I /usr/local/include -I /usr/local/lib
SOURCES=main.cpp grid.cpp
OBJECTS=$(SOURCES:%.cpp=$(BUILDDIR)/%.o)

EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGETDIR)/$@

$(OBJECTS): $(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(TARGETDIR)/$(EXECUTABLE) $(OBJECTS)
.PHONY: clean

print-%:
	@echo '$*=$($*)'
