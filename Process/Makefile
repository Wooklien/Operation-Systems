#make file for A3

EXEC = a3
TORM = A3.o
CC = g++
CCFLAGS = -g -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings 

$(EXEC):	A3.o
	$(CC) ${CCFLAGS} -o $(EXEC) A3.o

A3.o:	A3.cpp A3.h
		${CC} ${CCFLAGS} -c A3.cpp
		
clean:
	rm -f *.o core a.out $(EXEC) ${TORM}
