all: gauss progon

gauss:
	g++ -lstdc++ gauss.o -o gauss

gauss.o: gauss.cpp

progon: progon.o
	g++ -lstdc++ progon.o -o progon

progon.o: progon.cpp
