.cpp.o:	
	g++	-Wall -c $*.cpp

all:	LSEP

LSEP:	LSEP.o cLSEP.o cNoLSEP.o
	g++ -o $@ $^

clean:
	rm *.o LSEP
	