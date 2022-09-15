#
# @file Makefile
# @author Kyle Byassee
# @date 2022-09-13
# @brief Makefile
# 
# A Makefile for testing
#

# The build target
TARGET = test

# The compiler g++
CC = g++

# General compilation flags - Compiles with all errors and warnings
CFLAGS = -g -Wall -Wextra

# Compiles and Assembles without Linking
CFLAGSC = $(CFLAGS) -c

# Compiles and Links
CFLAGSO = $(CFLAGS) -o $(TARGET)

default: all
all: $(TARGET)

#The executable to be compiled
$(TARGET): stacker.o main.o
	$(CC) $(CFLAGSO) stacker.o main.o

#The binary of the class def
stacker.o: stacker.cpp stacker.h
	$(CC) $(CFLAGSC) stacker.cpp

#The binary of the main file
main.o: main.cpp stacker.h
	$(CC) $(CFLAGSC) main.cpp

# Invoked with 'make clean'
clean:
	$(RM) $(TARGET) *.o *~
