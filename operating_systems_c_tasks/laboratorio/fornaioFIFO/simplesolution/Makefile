CFLAGSCONSTRERROR=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED -D_POSIX_C_SOURCE=200112L
CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED 

LIBRARIES=-lpthread

all: 	 simple_fornaioFIFO.exe

simple_fornaioFIFO.exe:  simple_fornaioFIFO.o DBGpthread.o 
	gcc ${CFLAGS} -o simple_fornaioFIFO.exe simple_fornaioFIFO.o DBGpthread.o ${LIBRARIES}

simple_fornaioFIFO.o: simple_fornaioFIFO.c DBGpthread.h printerror.h
	gcc -c ${CFLAGS} simple_fornaioFIFO.c ${LIBRARIES}

DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGSCONSTRERROR} -c DBGpthread.c ${LIBRARIES}


.PHONY:	clean

clean:
	-rm -f simplesolution.o DBGpthread.o simplesolution.exe


