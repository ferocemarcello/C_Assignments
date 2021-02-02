CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED -D_POSIX_C_SOURCE=200112L

LIBRARIES=-lpthread

all: 	NProd1MProd2N+MCons.exe

NProd1MProd2N+MCons.exe: NProd1MProd2N+MCons.o DBGpthread.o
	gcc ${CFLAGS} -o NProd1MProd2N+MCons.exe NProd1MProd2N+MCons.o DBGpthread.o ${LIBRARIES}

NProd1MProd2N+MCons.o: NProd1MProd2N+MCons.c DBGpthread.h printerror.h
	gcc ${CFLAGS} -c NProd1MProd2N+MCons.c ${LIBRARIES}

DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGS} -c DBGpthread.c ${LIBRARIES}

.PHONY:	clean

clean:
	-rm -f NProd1MProd2N+MCons.o DBGpthread.o NProd1MProd2N+MCons.exe


