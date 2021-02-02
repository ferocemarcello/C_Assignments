# CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED -D_POSIX_C_SOURCE=200112L
CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED -D_POSIX_C_SOURCE=200112L

LIBRARIES=-lpthread

all: 	main.exe

main.exe: main.o mySem.o
	gcc ${CFLAGS} -o main.exe main.o mySem.o ${LIBRARIES}

mySem.o: mySem.c mySem.h printerror.h
	gcc -c ${CFLAGS} mySem.c ${LIBRARIES}

main.o: main.c mySem.h printerror.h
	gcc -c ${CFLAGS} main.c ${LIBRARIES}


.PHONY:	clean

clean:
	-rm -f mySem.o main.o main.exe


