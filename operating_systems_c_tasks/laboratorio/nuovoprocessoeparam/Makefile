GCC=gcc
CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_POSIX_C_SOURCE=200112L
LFLAGS=-lrt
LIBRARIES=-lpthread
all: 		duplieparam.exe

duplieparam.exe:	duplieparam.o DBGpthread.o
		${GCC} ${CFLAGS} -o duplieparam.exe duplieparam.o DBGpthread.o ${LIBRARIES} ${LFLAGS}


duplieparam.o:	duplieparam.c DBGpthread.h printerror.h
		${GCC} ${CFLAGS} -c duplieparam.c ${LFLAGS} ${LIBRARIES}
 
DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGS} -c DBGpthread.c ${LIBRARIES}


.PHONY:		clean


clean:	
		rm -f duplieparam.exe  duplieparam.o

