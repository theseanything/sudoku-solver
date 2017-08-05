SRCDIR=src
BUILDDIR=build
TARGETDIR=bin
CC=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=-I /usr/local/include -I /usr/local/lib
TESTLIBS=/usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a
SOURCES=main.cpp grid.cpp
OBJECTS=$(SOURCES:%.cpp=$(BUILDDIR)/%.o)

EXECUTABLE=main

all: $(BUILDDIR) $(TARGETDIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGETDIR)/$@

$(OBJECTS): $(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

test:
	$(CC) -std=c++0x $(LDFLAGS) $(TESTLIBS) test/grid_unittests.cpp src/grid.cpp -o test/test
	test/test
.PHONY: test

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

clean:
	rm $(TARGETDIR)/$(EXECUTABLE) $(OBJECTS)
.PHONY: clean

print-%:
	@echo '$*=$($*)'
