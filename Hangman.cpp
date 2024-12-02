#include "Hangman.h"

void PrintMessage(std::string message, bool TopEdge, bool BottomEdge)
{
    if (TopEdge)
    {
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|";
    }
    else
    {
        std::cout << "|";
    }

    bool Front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (Front)
            message = " " + message;
        else
            message = message + " ";
        Front = !Front;
    }
    std::cout << message.c_str();

    if (BottomEdge)
    {
        std::cout << "|" << std::endl;
        std::cout << "+---------------------------------+" << std::endl;
    }
    else
    {
        std::cout << "|" << std::endl;
    }
}

void DrawHangman(int GuessCount)
{
    if (GuessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (GuessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (GuessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);

    if (GuessCount == 4)
        PrintMessage("/  ", false, false);
    if (GuessCount == 5)
        PrintMessage("/| ", false, false);
    if (GuessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);

    if (GuessCount == 7)
        PrintMessage("/  ", false, false);
    if (GuessCount >= 8)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);

    if (GuessCount >= 9)
        PrintMessage("+-----------+", false, false);
    else
        PrintMessage("", false, false);

    if (GuessCount >= 10)
        PrintMessage("|           |", false, false);
    else
        PrintMessage("", false, false);

    if (GuessCount >= 11)
        PrintMessage("GAME OVER", false, false);
    else
        PrintMessage("", false, false);
}

void PlayedLetters(std::string input, char from, char to)
{
    std::string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == std::string::npos)
        {
            s += i;
            s += " ";
        }
        else
        {
            s += "  ";
        }
    }
    PrintMessage(s, false, false);
}

void PlayableLetters(std::string taken)
{
    PrintMessage("Available letters");
    PlayedLetters(taken, 'A', 'M');
    PlayedLetters(taken, 'N', 'Z');
    PrintMessage("Guess the word");
}

bool ChosenWord(std::string word, std::string guessed)
{
    bool won = true;
    std::string n;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == std::string::npos)
        {
            won = false;
            n += "_ ";
        }
        else
        {
            n += word[i];
            n += " ";
        }
    }
    PrintMessage(n, false);
    return won;
}

std::string LoadRandomWord(std::string path)
{
    std::vector<std::string> v;
    std::ifstream reader(path);
    std::string word;
    if (reader.is_open())
    {
        while (std::getline(reader, word))
        {
            v.push_back(word);
        }
        reader.close();
    }
    if (!v.empty())
    {
        int randomLine = rand() % v.size();
        return v.at(randomLine);
    }
    return "";
}

int TriesLeft(std::string word, std::string guessed)
{
    int error = 0;
    for (char ch : guessed)
    {
        if (word.find(ch) == std::string::npos)
            error++;
    }
    return error;
}
/*
+---------------------------------+
|            HANG MAN             |
+---------------------------------+
|                |                |
|                |                |
|                O                |
|               /|\               |
|               / \               |
|          +-----------+          |
|          |           |          |
|            GAME OVER            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|    A B C D E F G H I J K L M    |
|    N O P Q R S T U V W X Y Z    |
+---------------------------------+
|         Guess the word          |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
*/