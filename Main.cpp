#include "Hangman.h"

int main()
{
    std::srand(time(0)); // Inicializace náhodného generátoru pro výběr slova
    std::string guesses; // Řetězec uchovávající hráčem hádané znaky
    std::string WordToGuess = LoadRandomWord("Words.txt"); // Načtení náhodného slova ze souboru

    if (WordToGuess.empty()) // Kontrola, zda se podařilo načíst slova
    {
        PrintMessage("Nepodarilo se nacist slova!"); // Chybová zpráva
        return 1; // Ukončení programu s chybovým kódem
    }

    int tries = 0; // Počet špatných pokusů
    bool win = false; // Stav hry (výhra/porážka)

    do
    {
        system("cls"); // Vyčištění obrazovky (pro Windows)
        PrintMessage("HANGMAN"); // Název hry
        DrawHangman(tries); // Kreslení šibenice podle počtu špatných pokusů
        PlayableLetters(guesses); // Zobrazení dostupných písmen
        win = ChosenWord(WordToGuess, guesses); // Zobrazení stavu slova a kontrola výhry

        if (win) // Pokud hráč vyhrál, ukončíme smyčku
        {
            break;
        }

        char x;
        std::cout << "> "; // Vstup od hráče
        std::cin >> x;

        if (guesses.find(x) == std::string::npos) // Přidání hádaného písmene, pokud ještě nebylo zadáno
        {
            guesses += x;
        }

        tries = TriesLeft(WordToGuess, guesses); // Aktualizace počtu špatných pokusů

    } while (tries < 11); // Hra pokračuje, dokud hráč neudělá 11 špatných pokusů

    if (win) // Výsledek hry
    {
        PrintMessage("YOU WON!"); // Hráč vyhrál
    }
    else
    {
        PrintMessage("GAME OVER"); // Hráč prohrál
    }

    system("pause");
    return 0;
}