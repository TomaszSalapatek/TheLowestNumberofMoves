#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define WYBOR(a) a==1 ? "plansza1.txt": a==2 ? "plansza2.txt" : a==3 ? "plansza3.txt": "plansza4.txt"
int START_ROW;
int START_COL;
int GOAL_ROW;
int GOAL_COL;
int playerRow;
int playerCol;
char board[10][10];
double spr_dl();
int _getch();
int system();
void odczyt(char* fname, int flaga) {
    
    FILE* plik;
    errno_t err;//przechowuje kod bledu pod zmienna err
    err = fopen_s(&plik, fname, "r");//otwarcie pliku
    if (err != 0) {
        printf("Nie mo¿na otworzyæ pliku.\n");
        return;
    }
    double n = spr_dl(WYBOR(flaga));//ustalenie wielkosci planszy
    for (int wiersz = 0; wiersz < n; wiersz++) {
        for (int kolumna = 0; kolumna < n; kolumna++) {
            board[wiersz][kolumna] = fgetc(plik); //odbiera pojedynczy znak az nie napotka znaku konca pliku
        }
    }

    fclose(plik); // Zamkniêcie pliku
    //przypisanie wartosci startu i mety
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if (board[i][j] == 'S') {
                START_ROW = i;
                START_COL = j;

            }
            else if (board[i][j] == 'G') {
                GOAL_ROW = i;
                GOAL_COL = j;

            }
        }
    }
    playerRow = START_ROW;//przypisanie startowych wspolrzednych
    playerCol = START_COL;
}
void printBoard(int playerRow, int playerCol, int flaga) {
    system("cls");//odswiezanie ekranu
    double n = spr_dl(WYBOR(flaga));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == playerRow && j == playerCol) {
                printf("\033[0;44mPL\033[0m");  // Oznaczenie aktualnej pozycji gracza jako 'PL'
            }
            else if (board[i][j] == 'X') {
                printf("\033[0;41m  \033[0m");//Oznaczenie pol niedostepnych
            }
            else if (board[i][j] == 'G') {

                printf("\033[0;42m  \033[0m");//oznaczenie mety
            }
            else if (board[i][j] == 'S') {

                printf("\033[0;44m  \033[0m");//oznaczenie startu
            }
            else {
                printf("\033[0;47m  \033[0m");//oznaczenie zwyklych pol
            }
        }
        printf("\n");
    }
}
bool isValidMove(int row, int col, int flaga) {
    double n = spr_dl(WYBOR(flaga));
    if (row >= 0 && row < n && col >= 0 && col < n && board[row][col] != 'X') {     //sprawdzenie czy ruch jest mozliwy
        return true;
    }
    return false;
}
void movePlayer(int* row, int* col, char direction) {


    switch (direction) {
    case 'w':
    case 'W':
    case 72:  // Kody ASCII dla strza³ki w górê
        (*row)--;
        break;
    case 's':
    case 'S':
    case 80:  // Kody ASCII dla strza³ki w dó³
        (*row)++;
        break;
    case 'a':
    case 'A':
    case 75:  // Kody ASCII dla strza³ki w lewo
        (*col)--;
        break;
    case 'd':
    case 'D':
    case 77:  // Kody ASCII dla strza³ki w prawo
        (*col)++;
        break;
    case 'q':
    case 'Q':
        (*row)--;
        (*col)--;
        break;
    case 'e':
    case 'E':
        (*row)--;
        (*col)++;
        break;
    case 'z':
    case 'Z':
        (*row)++;
        (*col)--;
        break;
    case 'c':
    case 'C':
        (*row)++;
        (*col)++;
        break;

    }
}
int IloscTras(char* fname, int flaga) {

    double a = spr_dl(WYBOR(flaga));
    int n = a;
    int dp[10][10];
    dp[n][n];
    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        if (board[i][0] == 'X')
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        if (board[0][j] == 'X')
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (board[i][j] == 'X')
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }
    return dp[n - 1][n - 1];
}
double spr_dl(char* fname) {
    FILE* plik;
    errno_t err;
    int licznik = 0;
    int ch;
    err = fopen_s(&plik, fname, "r");
    if (err != 0) {
        printf("Nie mo¿na otworzyæ pliku.\n");
        return 0;
    }
    while ((ch = fgetc(plik)) != EOF) { //zliczenie ilosci znakow

        licznik++;
    }
    double n;
    n = sqrt(licznik);
    fclose(plik); // Zamkniêcie pliku
    return sqrt(licznik);
}