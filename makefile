CC=g++
CFLAGS=-g -Wall --debug --warn-unused-variable

targets= interpreter
files=interpreter.cpp Tree.cpp Tree.hpp

all:$(targets)

interpreter: $(files)
	$(CC) $(CFLAGS) Tree.cpp $@.cpp -o $@

clean:
	rm -rf $(targets) *.o
