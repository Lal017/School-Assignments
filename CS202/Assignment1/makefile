# Make file for counting first digits program.

OBJS	= benfordsLaw.o 
CC	= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g


all: benfordsLaw

benfordsLaw: $(OBJS)
	$(CC) $(CCFLAGS) -o benfordsLaw $(OBJS)

benfordsLaw.o:	benfordsLaw.cpp 
	$(CC) $(CCFLAGS) -c benfordsLaw.cpp


# -----
# clean by removing object files.

clean:
	rm $(OBJS)benfordsLaw

