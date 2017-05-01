CXX=g++ -std=c++11

all: main.o Color.h DivideAndConquer.h Font.h SDL_Plotter.h ThreadedStrassen.h
	$(CXX) main.o Graph.o polyReg.o Shapes.o -lSDL2main -lSDL2 -lSDL2_mixer -lpthread

main.o: main.cpp Graph.o Shapes.o 
	$(CXX) -c main.cpp

Graph.o: Graph.cpp Graph.h polyReg.o
	$(CXX) -c Graph.cpp

polyReg.o: polyReg.cpp polyReg.h
	$(CXX) -c polyReg.cpp

Shapes.o: Shapes.cpp Shapes.h
	$(CXX) -c Shapes.cpp


