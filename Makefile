all: gauss

gauss:
	g++ -lstdc++ gauss.o -o gauss

gauss.o: gauss.cpp
