CFLAGSCONSTRERROR=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED -D_POSIX_C_SOURCE=200112L
CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_MULTI_THREADED 

LIBRARIES=-lpthread

all: 	 fornaioBaseFIFO.exe

fornaioBaseFIFO.exe:  fornaioBaseFIFO.o DBGpthread.o 
	gcc ${CFLAGS} -o fornaioBaseFIFO.exe fornaioBaseFIFO.o DBGpthread.o ${LIBRARIES}

fornaioBaseFIFO.o: fornaioBaseFIFO.c DBGpthread.h printerror.h
	gcc -c ${CFLAGS} fornaioBaseFIFO.c ${LIBRARIES}

DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGSCONSTRERROR} -c DBGpthread.c ${LIBRARIES}


.PHONY:	clean

clean:
	-rm -f fornaioBaseFIFO.o DBGpthread.o fornaioBaseFIFO.exe


