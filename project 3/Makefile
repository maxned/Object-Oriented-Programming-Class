main: ShortMain.o Short.o
	g++ -pedantic -Wall ShortMain.o Short.o -o short
ShortMain.o: ShortMain.cpp Short.o
	g++ -pedantic -Wall ShortMain.cpp -c
Short.o: Short.cpp Short.h
	g++ -pedantic -Wall Short.cpp -c
clean:
	rm *.o