bbrot: bbrot.o mbrot.o
	g++ -g bbrot.o mbrot.o -o bbrot

bbrot.o: bbrot.cpp bbrot.h image.h
	g++ -g -c bbrot.cpp

mbrot.o: mbrot.cpp mbrot.h
	g++ -g -c mbrot.cpp

clean:
	rm *.o bbrot.exe