#ifndef HANGMAN_H
#define HANGMAN_H

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

void PrintMessage(std::string message, bool TopEdge = true, bool BottomEdge = true);
void DrawHangman(int GuessCount = 0);
void PlayedLetters(std::string input, char from, char to);
void PlayableLetters(std::string taken);
bool ChosenWord(std::string word, std::string guessed);
std::string LoadRandomWord(std::string path);
int TriesLeft(std::string word, std::string guessed);

#endif