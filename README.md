# Hangman

Jednoduchá implementace hry Hangman (Šibenice) v jazyce C++.

## Popis projektu

Tento projekt je textová hra, ve které hráč hádá náhodně vybrané ANGLICKÉ slovo. Hráč zadává písmena a snaží se uhodnout celé slovo dříve, než se dokončí kresba šibenice.

## Funkce

- Vykreslování šibenice podle počtu špatných pokusů.
- Podpora náhodného výběru slov ze souboru `Words.txt`.
- Zobrazení zbývajících pokusů.
- Zobrazení dostupných a již použitých písmen.

## Předpoklady

- **Kompatibilní operační systém:** Windows.
- **Editor:** Visual Studio Code, lze i jiný.
- **Kompilátor:** GCC (např. z balíčku MinGW).

## Instalace

1. Ujistěte se, že máte nainstalovaný GCC kompilátor (např. [MinGW](http://www.mingw.org/)).
2. Naklonujte tento projekt z repozitáře:
   https://github.com/pechahug/Sibenice_PIA1_2024
3. Otevřete složku projektu

## Kompilace a spuštění
Pro sestavení a spuštění programu použijte následující příkazy v terminálu:

1. kopilace: mingw32-make
2. spuštění: .\main.exe

## Použítí
1. Po spuštění programu se zobrazí šibenice a dostupná písmena.
2. Zadejte VELKÉ!! písmeno a stiskněte Enter. Pozor všeschna slova jsou ANGLICKÁ!
3. Pokračujte ve hře, dokud neuhodnete celé slovo nebo neprohrajete.

## Struktura projektu
- main.cpp – Hlavní funkce programu.
- Hangman.cpp – Implementace herní logiky a pomocných funkcí.
- Hangman.h – Hlavičkový soubor s deklaracemi funkcí.
- Words.txt – Soubor obsahující slova pro hru (každé slovo na samostatném řádku).

## Poznámky k vývoji
- Projekt využívá Makefile pro zjednodušení kompilace.
- Veškeré chyby během kompilace se zobrazují díky přepínači -Wall.
- Přepínač -g umožňuje ladění pomocí debuggeru.
