all :		main.exe

main.exe :		main.o quadrato.o dimezza.o
				gcc -ansi -Wpedantic -o main.exe main.o quadrato.o dimezza.o -lm -L/home/studente/Desktop/main/headers/

main.o:		main.c /home/studente/Desktop/main/headers/quadrato.h /home/studente/Desktop/main/headers/dimezza.h 
				gcc -c -ansi -Wpedantic main.c -I/home/studente/Desktop/main/headers/

quadrato.o :	quadrato.c
				gcc -c -ansi -Wpedantic quadrato.c -I/home/studente/Desktop/main/headers/

dimezza.o :	dimezza.c
				gcc -c -ansi -Wpedantic dimezza.c -I/home/studente/Desktop/main/headers/

clean:			-rm main.exe *.o