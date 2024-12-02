#include "Hangman.h"

int main()
{
    std::srand(time(0));
    std::string guesses;
    std::string WordToGuess = LoadRandomWord("Words.txt");

    if (WordToGuess.empty())
    {
        PrintMessage("Nepodarilo se nacist slova!");
        return 1;
    }

    int tries = 0;
    bool win = false;

    do
    {
        system("cls");
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PlayableLetters(guesses);
        win = ChosenWord(WordToGuess, guesses);

        if (win)
        {
            break;
        }

        char x;
        std::cout << "> ";
        std::cin >> x;

        if (guesses.find(x) == std::string::npos)
        {
            guesses += x;
        }

        tries = TriesLeft(WordToGuess, guesses);

    } while (tries < 11);

    if (win)
    {
        PrintMessage("YOU WON!");
    }
    else
    {
        PrintMessage("GAME OVER");
    }

    system("pause");
    return 0;
}