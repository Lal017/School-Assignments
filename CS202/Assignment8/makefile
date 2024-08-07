# Make file for operator overloading assignment

OBJS	=   main.o dataProcessing.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= dataProcessing.h

all: main

main: $(OBJS)
	@echo "Linking Objects..."
	$(CC) $(CCFLAGS) -o processing $(OBJS)
	@echo "Done! Finished building processing program"

main.o:	main.cpp $(MAIN_DEPS)
	@echo "Compiling Main..."
	$(CC) $(CCFLAGS) -c main.cpp
dataProcessing.o : dataProcessing.cpp $(COMPLEX_DEPS)
	@echo "Compiling dataProcessing..."
	$(CC) $(CCFLAGS) -c dataProcessing.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS) processing
