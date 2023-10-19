all: main.cpp
	g++ main.cpp Animation.cpp -orun -lsfml-graphics -lsfml-window -lsfml-system && ./run
debug: main.cpp
	g++ -g main.cpp Animation.cpp -orun -lsfml-graphics -lsfml-window -lsfml-system && gdb run
