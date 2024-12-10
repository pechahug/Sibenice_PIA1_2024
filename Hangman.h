#ifndef HANGMAN_H 
#define HANGMAN_H 

#include <set>       
#include <iostream>  
#include <fstream>   
#include <string>    
#include <vector>    
#include <cstdlib>   
#include <ctime>     

// Deklarace funkcí používaných ve hře Hangman
void PrintMessage(std::string message, bool TopEdge = true, bool BottomEdge = true); // Vypisuje zprávu s rámečkem
void DrawHangman(int GuessCount = 0); // Kreslí aktuální stav šibenice
void PlayedLetters(std::string input, char from, char to); // Zobrazuje nehrané písmena
void PlayableLetters(std::string taken); // Zobrazuje dostupné písmena k hádání
bool ChosenWord(std::string word, std::string guessed); // Kontroluje, zda hráč vyhrál a zobrazuje stav slova
std::string LoadRandomWord(std::string path); // Načítá náhodné slovo ze souboru
int TriesLeft(std::string word, std::string guessed); // Počítá počet špatných pokusů

#endif