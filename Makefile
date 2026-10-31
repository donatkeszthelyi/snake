game : main.o Board.o Snake.o Food.o Game.o Input.o
	g++ -g -Wall main.o Board.o Snake.o Food.o Game.o Input.o -o game

main.o : main.cpp
	g++ -g -Wall -c main.cpp -o main.o

Board.o : Board.cpp
	g++ -g -Wall -c Board.cpp -o Board.o

Snake.o : Snake.cpp
	g++ -g -Wall -c Snake.cpp -o Snake.o

Food.o : Food.cpp
	g++ -g -Wall -c Food.cpp -o Food.o

Game.o : Game.cpp
	g++ -g -Wall -c Game.cpp -o Game.o

Input.o : Input.cpp
	g++ -g -Wall -c Input.cpp -o Input.o
