CXX = g++

CXXFLAGS = -g -Wall -O0


LIBS = -lXext -lX11

EXEC = calculatrice
EXEC1 = tracer

all: $(EXEC) $(EXEC1)

$(EXEC): Polynome.o calculatrice.o 
	$(CXX) -o $@ $^ $(LIBS)

$(EXEC1): tracer.o Polynome.o ez-draw++.o
	$(CXX) -o $@ $^ $(LIBS)

tracer.o: tracer.cpp Polynome.hpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

ez-draw++.o : ez-draw++.cpp ez-draw++.hpp
	$(CXX) $(CXXFLAGS) -c $<

Polynome.o: Polynome.cpp Polynome.hpp
	$(CXX) $(CXXFLAGS) -c Polynome.cpp

calculatrice.o: calculatrice.cpp Polynome.hpp
	$(CXX) $(CXXFLAGS) -c calculatrice.cpp


clean:
	rm -f *.o $(EXEC) $(EXEC1)