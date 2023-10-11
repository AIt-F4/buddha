bbrot: bbrot.o mbrot.o
	g++ bbrot.o mbrot.o -o bbrot

bbrot.o: bbrot.cpp bbrot.h
	g++ -c bbrot.cpp

mbrot.o: mbrot.cpp mbrot.h
	g++ -c mbrot.cpp

clean:
	rm *.o bbrot.exe