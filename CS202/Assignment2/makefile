# Make file for Ast2- craps game program.

OBJS	= main.o crapsTypeImp.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= crapsType.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o main $(OBJS)

main.o:	main.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c main.cpp

crapsTypeImp.o: crapsTypeImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c crapsTypeImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS) main
