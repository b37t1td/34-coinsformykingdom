LDFLAGS=$(shell pkg-config --libs --cflags sdl2 )

all: 34coins

34coins: 34coins.hpp
	g++ -std=c++11 -O2 -g -Wall 34coins.cxx mainwindow.cxx -o 34coins $(LDFLAGS)

clean:
	rm  34coins