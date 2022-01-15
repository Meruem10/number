# -*- MakeFile -*-

number.exe: main.o sw_number.o
	gcc main.o sw_number.o -o number.exe

main.o: main.c sw_number.h
	gcc -c main.c

sw_number.o: sw_number.c sw_number.h
	gcc -c sw_number.c

clean:
	rm -f *.o number.exe
