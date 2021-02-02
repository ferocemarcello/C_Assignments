CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED -D_POSIX_C_SOURCE=200112L

LIBRARIES=-lpthread

all: 	circolare1a2.exe

circolare1a2.exe: circolare1a2.o DBGpthread.o
	gcc ${CFLAGS} -o circolare1a2.exe circolare1a2.o DBGpthread.o ${LIBRARIES}

circolare1a2.o: circolare1a2.c DBGpthread.h printerror.h
	gcc ${CFLAGS} -c circolare1a2.c ${LIBRARIES}

DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGS} -c DBGpthread.c ${LIBRARIES}

.PHONY:	clean

clean:
	-rm -f circolare1a2.o DBGpthread.o circolare1a2.exe


