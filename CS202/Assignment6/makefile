# Make file for operator overloading assignment

OBJS	=   Main.o TreasureMap.o ComplexNumber.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
MAIN_DEPS	= TreasureMap.h List.h ComplexNumber.h
COMPLEX_DEPS = ComplexNumber.h
TREASURE_DEPS = TreasureMap.h List.h

all: main

main: $(OBJS)
	@echo "Linking Objects..."
	$(CC) $(CCFLAGS) -o treasure $(OBJS)
	@echo "Done! Finished building treasure program"

Main.o:	Main.cpp $(MAIN_DEPS)
	@echo "Compiling Main..."
	$(CC) $(CCFLAGS) -c Main.cpp
ComplexNumber.o: ComplexNumber.cpp $(COMPLEX_DEPS)
	@echo "Compiling ComplexNumber..."
	$(CC) $(CCFLAGS) -c ComplexNumber.cpp
TreasureMap.o: TreasureMap.cpp $(TREASURE_DEPS)
	@echo "Compiling TreasureMap..."
	$(CC) $(CCFLAGS) -c TreasureMap.cpp


# -----
# clean by removing object files.

clean:
	rm $(OBJS) treasure
