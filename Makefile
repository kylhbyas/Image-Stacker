#
# @file Makefile
# @author Kyle Byassee
# @date 2022-09-06
# @brief Makefile
# 
# A Makefile for testing
#

# The compiler g++
CC = g++

# The build target
TARGET = test

# Compilation flags - Compiles with all errors and warnings
CFLAGS = -g -c -Wall -Wextra

default: all
all: $(TARGET)

#The executable to be compiled
$(TARGET): main.o stacker.o
	$(CC) main.o -o $(TARGET)

#The binary of the class def
stacker.o: stacker.cpp stacker.h
##	$(CC) $(CFLAGS) Vector.cpp

#The binary of the main file
main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) main.cpp

# Invoked with 'make clean'
clean:
	$(RM) $(TARGET) *.o *~
