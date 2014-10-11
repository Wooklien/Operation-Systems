#make file for A1

EXEC = sem
TORM = a1.o
CC = g++
CCFLAGS = -g -O3 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings 

$(EXEC):	A1.o 
	$(CC) ${CCFLAGS} -o $(EXEC) A1.o -lpthread -lrt 

a1.o:	A1.c A1.h
		${CC} ${CCFLAGS} -c A1.c              

clean:
	rm -f *.o core a.out $(EXEC) ${TORM}
