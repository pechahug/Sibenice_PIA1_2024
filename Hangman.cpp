#include "Hangman.h"

// Vypisuje zprávu uvnitř rámečku
void PrintMessage(std::string message, bool TopEdge, bool BottomEdge)
{
    if (TopEdge)
        std::cout << "+---------------------------------+" << std::endl << "|";
    else
        std::cout << "|";

    // Zarovnání zprávy na střed
    bool Front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (Front) message = " " + message;
        else message = message + " ";
        Front = !Front;
    }
    std::cout << message.c_str();

    if (BottomEdge)
        std::cout << "|" << std::endl << "+---------------------------------+" << std::endl;
    else
        std::cout << "|" << std::endl;
}

// Kreslí aktuální stav šibenice na základě počtu špatných pokusů
void DrawHangman(int GuessCount)
{
    if (GuessCount >= 1) PrintMessage("|", false, false);
    else PrintMessage("", false, false);

    if (GuessCount >= 2) PrintMessage("|", false, false);
    else PrintMessage("", false, false);

    if (GuessCount >= 3) PrintMessage("O", false, false);
    else PrintMessage("", false, false);

    if (GuessCount == 4) PrintMessage("/  ", false, false);
    if (GuessCount == 5) PrintMessage("/| ", false, false);
    if (GuessCount >= 6) PrintMessage("/|\\", false, false);
    else PrintMessage("", false, false);

    if (GuessCount == 7) PrintMessage("/  ", false, false);
    if (GuessCount >= 8) PrintMessage("/ \\", false, false);
    else PrintMessage("", false, false);

    if (GuessCount >= 9) PrintMessage("+-----------+", false, false);
    else PrintMessage("", false, false);

    if (GuessCount >= 10) PrintMessage("|           |", false, false);
    else PrintMessage("", false, false);

    if (GuessCount >= 11) PrintMessage("GAME OVER", false, false);
    else PrintMessage("", false, false);
}

// Zobrazuje nepoužité nebo hádané znaky
void PlayedLetters(std::string input, char from, char to)
{
    std::string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == std::string::npos)
            s += i + std::string(" "); // Znak nebyl hádán
        else
            s += "  "; // Znak již byl hádán
    }
    PrintMessage(s, false, false);
}

// Zobrazuje dostupné písmena k hádání
void PlayableLetters(std::string taken)
{
    PrintMessage("Available letters");
    PlayedLetters(taken, 'A', 'M');
    PlayedLetters(taken, 'N', 'Z');
    PrintMessage("Guess the word");
}

// Zobrazuje stav slova a kontroluje, zda hráč vyhrál
bool ChosenWord(std::string word, std::string guessed)
{
    bool won = true;
    std::string n;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == std::string::npos) // Neuhodnutý znak
        {
            won = false;
            n += "_ ";
        }
        else
        {
            n += word[i] + std::string(" "); // Uhodnutý znak
        }
    }
    PrintMessage(n, false);
    return won;
}

// Načítá náhodné slovo ze souboru
std::string LoadRandomWord(std::string path)
{
    std::vector<std::string> v;
    std::ifstream reader(path);
    std::string word;
    if (reader.is_open())
    {
        while (std::getline(reader, word))
            v.push_back(word);
        reader.close();
    }
    if (!v.empty())
        return v.at(rand() % v.size()); // Náhodný výběr slova
    return "";
}

// Počítá počet špatných pokusů
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