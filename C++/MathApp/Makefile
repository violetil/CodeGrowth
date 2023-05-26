# A simple makefile for MathApp

MathApp.exe: ./src/main.o ./src/Computer.o
	g++ -o ./output/MathApp.exe ./src/main.o ./src/Computer.o

./src/main.o: ./src/main.cpp ./src/Computer.h
	g++ -c -o ./src/main.o ./src/main.cpp

./src/Computer.o: ./src/Computer.cpp ./src/Computer.h
	g++ -c -o ./src/Computer.o ./src/Computer.cpp
