# Makefile per mutex e CondVar* 
# a causa della presenza di strerror_r in printerror.h
# occorre compilare col flag -D_POSIX_C_SOURCE=200112L

CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_POSIX_C_SOURCE=200112L
LIBRARIES=-lpthread -lrt

all: 	03.exe

03.exe: 03.o DBGpthread.o 
	gcc ${CFLAGS} -o 03.exe 03.o DBGpthread.o ${LIBRARIES}

DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGS} -c DBGpthread.c ${LIBRARIES}

03.o: 03.c
	gcc -c ${CFLAGS} 03.c ${LIBRARIES}


.PHONY:	clean

clean:
	-rm -f 03.o DBGpthread.o 03.exe


