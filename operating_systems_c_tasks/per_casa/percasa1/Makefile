CFLAGS=-ansi -Wpedantic -Wall

LIBRARIES=-lpthread

all: 	PerCasa1.exe

PerCasa1.exe: PerCasa1.o
	gcc ${CFLAGS} -o PerCasa1.exe PerCasa1.o ${LIBRARIES}

PerCasa1.o: PerCasa1.c
	gcc ${CFLAGS} -c PerCasa1.c ${LIBRARIES}

.PHONY:	clean

clean:
	-rm -f PerCasa1.o PerCasa1.exe


