#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h> //používáme pro vybrání náhodného slova
using namespace std;

void PrintMessage(std::string message, bool TopEdge = true, bool BottomEdge = true )
{
    if (TopEdge)
    { 
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
       cout << "|" ;
    }

    bool Front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (Front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        Front = !Front;

    }
    cout << message.c_str();

    if (BottomEdge)
    {
        cout <<  "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
     
    else
    {
       cout << "|" << endl ;
    }

}

void DrawHangman(int GuessCount = 0)
{
    if (GuessCount >= 1)
    {
        PrintMessage("|", false, false);
    }
    else
    {
        PrintMessage("", false, false);
    }
    
    if (GuessCount >=2)
    {
        PrintMessage("|", false, false);
    }
    else 
    {
        PrintMessage("", false, false);
    }
    
    if (GuessCount >=3)
    {
        PrintMessage("O", false, false);
    }
    else 
    {
        PrintMessage("", false, false);
    }
    
    if (GuessCount ==4)
    {
        PrintMessage("/  ", false, false);
    }

    if (GuessCount ==5)
    {
        PrintMessage("/| ", false, false);
    }
    
    if (GuessCount >=6)
    {
        PrintMessage("/|\\", false, false); // "\" je zároveň "escape znak, a tudíž ho musíme napsat dvakrát z technických důvodů"
    }
    else 
    {
        PrintMessage("", false, false);
    }

    if (GuessCount ==7)
    {
        PrintMessage("/  ", false, false);
    }

    if (GuessCount >=8)
    {
        PrintMessage("/ \\", false, false); // "\" je zároveň "escape znak, a tudíž ho musíme napsat dvakrát z technických důvodů"
    }
    else 
    {
        PrintMessage("", false, false);
    }

    if (GuessCount >=9)
    {
        PrintMessage("+-----------+", false, false); 
    }
    else 
    {
        PrintMessage("", false, false);
    }

    if (GuessCount >=10)
    {
        PrintMessage("|           |", false, false); 
    }
    else 
    {
        PrintMessage("", false, false);
    }

    if (GuessCount >=11)
    {
        PrintMessage("GAME OVER", false, false); 
    }
    else 
    {
        PrintMessage("", false, false);
    }
    
}

void PlayedLetters (string input, char from, char to) 
{
    // Tato funkce slouží k vyloučení písmen které jsme odehráli
    std::string s;
    
    for(char i = from; i <=to; i++) 
    {
        if(input.find(i) == string::npos) 
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


void PlayableLetters(string taken)  // Funkce slouží k vykreslení odělovacích částí "available letters a guess the word" + k vykreslení všech nepoužitých písmen
{
    PrintMessage("Available letters");
    PlayedLetters(taken , 'A', 'M'); 
    PlayedLetters(taken , 'N', 'Z');
    PrintMessage("Guess the word");

}

bool ChosenWord(string word, string guessed) //Slouží k vykreslení počtu písmen hádaného slova + zobrazuje správně uhodnutá písmena
{

    bool won = true;
    std::string n;

    for (int i = 0; i < word.length(); i++) 
    {
        if (guessed.find(word[i]) == string::npos) 
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

std::string LoadRandomWord(string path) 
{
    int LineCount = 0;
    std::string word;
    std::vector<string> v;
    ifstream reader(path);
    if(reader.is_open()) 
    {
        while(std::getline(reader, word)) 
        {
            v.push_back(word);
        }
        int randomline = rand() % v.size();

        word = v.at(randomline);
        reader.close();

    }
    return word;
}

int TriesLeft(string word, string guessed) 
{
    int error = 0;
    for (int i = 0; i< guessed.length(); i++) 
    {
        if (word.find(guessed[i]) == string::npos)
        error ++;
    }
    return error;
}

int main()
{
    std::srand(time(0));
    std::string guesses;
    std::string WordToGuess;
    WordToGuess = LoadRandomWord("Words.txt");
    cout << WordToGuess << endl << endl;
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
        cout << ">"; cin >>x;
        if (guesses.find(x) == string::npos) 
        {
            guesses += x;
        }

        tries = TriesLeft(WordToGuess, guesses);

    } while (tries < 11);

    if(win) 
    {
        PrintMessage("YOU WON!");
    }
    else 
    {
        PrintMessage("GAME OVER");
    }


    system("pause");
    getchar();
    return 0;

    

  
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