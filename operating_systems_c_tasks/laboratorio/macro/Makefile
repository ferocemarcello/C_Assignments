all:		macro.exe

macro.exe:	test.o
				gcc -ansi -Wpedantic -o macro.exe test.o -lm macro.h
test.o:		
			gcc -c -ansi -Wpedantic test.c -lmacro.h

.PHONY: clean


clean:		
		rm ./*.exe ./*.o
