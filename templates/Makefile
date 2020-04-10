# C++ Makefile using g++ and gdb
# Roberto Nicolás Savinelli <rsavinelli@est.frba.utn.edu.ar>

CC = g++
CFLAGS = -std=c++17 -Wall -pedantic-errors
INCLUDES = -I ./inc/
SOURCES = ./src/*.cpp

OUTPUT = a.out

.PHONY: compile debug clean

compile:
	$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES) -o $(OUTPUT)

debug:
	$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES) -g3 -o $(OUTPUT) && gdb -se $(OUTPUT)

clean:
	$(RM) ./$(OUTPUT)
