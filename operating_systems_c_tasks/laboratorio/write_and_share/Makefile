GCC=gcc
CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_POSIX_C_SOURCE=200112L
LFLAGS=-lrt
LIBRARIES=-lpthread
all: 		writeandshmem.exe

writeandshmem.exe:	writeandshmem.o DBGpthread.o
		${GCC} ${CFLAGS} -o writeandshmem.exe writeandshmem.o DBGpthread.o ${LIBRARIES} ${LFLAGS}


writeandshmem.o:	writeandshmem.c DBGpthread.h printerror.h
		${GCC} ${CFLAGS} -c writeandshmem.c ${LFLAGS} ${LIBRARIES}
 
DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGS} -c DBGpthread.c ${LIBRARIES}


.PHONY:		clean


clean:	
		rm -f writeandshmem.exe  writeandshmem.o

