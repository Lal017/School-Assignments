# Make file for CS 202 Assignment #3, 
#			employee/manager object program

CC	= g++ 
CCFLAGS = -Wall -Wextra -pedantic -std=c++11 -g
OBJS	= main.o managerImp.o employeeImp.o wagesImp.o
EOBJS	= emain.o employeeImp.o wagesImp.o
DEPS	= manager.h employee.h wages.h
EDEPS	= employee.h wages.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o main $(OBJS)

main.o:	main.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c main.cpp

emain: $(EOBJS)
	$(CC) $(CCFLAGS) -o emain $(EOBJS)

wagesImp.o:	wagesImp.cpp wages.h
	$(CC) $(CCFLAGS)  -c wagesImp.cpp

emain.o:	main.cpp $(EDEPS)
	$(CC) $(CCFLAGS) -c emain.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)
