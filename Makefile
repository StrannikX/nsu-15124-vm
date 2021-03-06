all: gauss progon reflect rotate richardson grad

run: all
	./richardson

gauss: gauss.o
	g++ -lstdc++ gauss.o -o gauss

gauss.o: gauss.cpp

progon: progon.o
	g++ -lstdc++ progon.o -o progon

progon.o: progon.cpp

reflect: reflect.o matrix.o
	g++ -lstdc++ reflect.o matrix.o -o reflect

reflect.o: reflect.cpp matrix.hpp

matrix.o: matrix.cpp matrix.hpp

rotate: rotate.o matrix.o
	g++ -lstdc++ rotate.o matrix.o -o rotate

rotate.o: rotate.cpp matrix.hpp

richardson: richardson.o matrix.o
	g++ -lstdc++ richardson.o matrix.o -o richardson

richardson: richardson.cpp matrix.hpp

grad: grad.o matrix.o
	g++ -lstdc++ grad.o matrix.o -o grad

grad: grad.cpp matrix.hpp
