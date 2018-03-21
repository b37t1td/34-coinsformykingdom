SDL=$(shell pkg-config --libs --cflags sdl2)
SDL_IMAGE=$(shell pkg-config --libs --cflags SDL2_image)

all: 34coins

34coins: 34coins.hpp
	g++ -std=c++11 -O2 -g -Wall 34coins.cxx mainwindow.cxx -o 34coins $(SDL) $(SDL_IMAGE)
#	upx 34coins

clean:
	rm  34coins