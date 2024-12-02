all:
	g++ -Wall -g -c  main.cpp
	g++ -Wall -g -c  Hangman.cpp
	g++ -o main main.o Hangman.o