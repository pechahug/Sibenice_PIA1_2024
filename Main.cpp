#include <set>
#include <iostream>
#include <fstream>
#include <string>
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


int main()
{
    PrintMessage("HANG MAN");
    DrawHangman(11);

  
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