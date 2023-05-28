# A simple makefile for MathApp

objects = .\obj\main.o .\obj\Computer.o

.\output\MathApp.exe: $(objects)
	g++ -o .\output\MathApp.exe $(objects)

.\obj\main.o: .\src\main.cpp .\src\Computer.h
	g++ -c -o .\obj\main.o .\src\main.cpp

.\obj\Computer.o: .\src\Computer.cpp .\src\Computer.h
	g++ -c -o .\obj\Computer.o .\src\Computer.cpp

.PHONY : clean
clean:
	del /Q /F .\output\MathApp.exe $(objects)