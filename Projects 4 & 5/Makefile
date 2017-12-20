main: main.o Inventory.o Date.o Pipe.o Plastic.o Hardware.o Fastener.o Hinge.o Lumber.o Hardwood.o Softwood.o Store.o
	g++ -pedantic -Wall main.o Inventory.o Date.o Pipe.o Plastic.o Hardware.o Fastener.o Hinge.o Lumber.o Hardwood.o Softwood.o Store.o -o store
main.o: main.cpp Store.o
	g++ -pedantic -Wall main.cpp -c
Store.o: Store.cpp Store.h Hardware.o Fastener.o Hinge.o Lumber.o Hardwood.o Softwood.o Pipe.o Plastic.o
	g++ -pedantic -Wall Store.cpp -c
Fastener.o: Fastener.cpp Fastener.h Hardware.o
	g++ -pedantic -Wall Fastener.cpp -c
Hinge.o: Hinge.cpp Hinge.h Hardware.o
	g++ -pedantic -Wall Hinge.cpp -c
Hardware.o: Hardware.cpp Hardware.h
	g++ -pedantic -Wall Hardware.cpp -c
Hardwood.o: Hardwood.cpp Hardwood.h Lumber.o
	g++ -pedantic -Wall Hardwood.cpp -c
Softwood.o: Softwood.cpp Softwood.h Lumber.o
	g++ -pedantic -Wall Softwood.cpp -c
Lumber.o: Lumber.cpp Lumber.h
	g++ -pedantic -Wall Lumber.cpp -c
Plastic.o: Plastic.cpp Plastic.h Pipe.o
	g++ -pedantic -Wall Plastic.cpp -c
Pipe.o: Pipe.cpp Pipe.h
	g++ -pedantic -Wall Pipe.cpp -c

clean:
	rm main.o Store.o Fastener.o Hinge.o Hardware.o Hardwood.o Softwood.o Lumber.o Plastic.o Pipe.o
