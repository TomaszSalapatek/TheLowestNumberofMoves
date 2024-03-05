#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "Proj.h"
#include <conio.h>
#define WYBOR(a) a==1 ? "plansza1.txt": a==2 ? "plansza2.txt" : a==3 ? "plansza3.txt": "plansza4.txt"
int START_ROW;
int START_COL;
int GOAL_ROW;
int GOAL_COL;
int playerRow;
int playerCol;
char board[10][10];
int main() {
    printf("Sterowanie:\nGracz porusza sie za pomoca strzalek, oraz WASD\nAby skorzystac z ruchu po skosie nalezy wcisnac kolejno:\n");
    printf("Q - lewy gorny rog\nE - prawy gorny rog\nZ - lewy dolny rog\nC - prawy dolny rog\n");
    printf("=======================================================================\n");
    printf("Witaj zagubiony graczu, jaki labirynt chcesz wybrac?\nWpisz numer 1-4 \n");
    printf("=======================================================================\n");
    int flaga;
    if (scanf_s("%d", &flaga) < 1) {
        printf("Zly wybor przyjacielu");
        return 0;
    }
    else {      //ustalenie zmiennej flaga, aby trzymala plik ktory wybralismy
        switch (flaga) {
        case 1:
            odczyt("plansza1.txt", flaga);
            break;
        case 2:
            odczyt("plansza2.txt", flaga);
            break;
        case 3:
            odczyt("plansza3.txt", flaga);
            break;
        case 4:
            odczyt("plansza4.txt", flaga);
            break;
        default:
            printf("Zly numer");
            return 0;
        }
        double n = spr_dl(WYBOR(flaga));
        printBoard(playerRow, playerCol, flaga);  // Przekazanie pocz¹tkowych wspó³rzêdnych graczu
        while (playerRow != GOAL_ROW || playerCol != GOAL_COL) {
            printf("\n\x1b[32m Zielone pole - Pole Mety\n\x1b[0m Niebieskie Pole z napisem PL - pionek gracza\n\x1b[34m Niebieskie pole - Pole Startowe\n\x1b[31m Czerwone pole - Pola sa niebezpieczne\n");
            printf("\n\x1b[0m Wcisnij strzalke, aby poruszyc sie (aby poruszyc sie po skosach nalezy wcisnac odpowiednio: Q E Z C): \n");
            char moveDirection = _getch();  // Odczytanie pojedynczego znaku                
            int newPlayerRow = playerRow;
            int newPlayerCol = playerCol;
            movePlayer(&newPlayerRow, &newPlayerCol, moveDirection);    //ruch gracza

            if (isValidMove(newPlayerRow, newPlayerCol, flaga)) {   //sprawdzene warunku
                playerRow = newPlayerRow;   //zatwierdzenie nowych wspolrzednych gracza
                playerCol = newPlayerCol;
                printBoard(playerRow, playerCol, flaga);  // Aktualizacja planszy po ruchu gracza
                printf("Przesunieto gracza na pozycje (%d, %.0lf)\n", playerCol, (n - 1) - playerRow);
            }
            else {
                playerCol = START_COL;  //powrot gracza na start
                playerRow = START_ROW;
                printBoard(playerRow, playerCol, flaga);
                printf("Nieprawidlowy ruch! Wracasz na start!.\n");
                printf("\x1b[31m To bylo NIEBEZPIECZNE!");

            }
        }
        printf("\x1b[32mGratulacje! Osiagnieto pole docelowe.\n");
        printf("\x1b[0mIlosc mozliwych tras wynosi: %d\n", IloscTras(WYBOR(flaga), flaga));
    }
    return 0;
}