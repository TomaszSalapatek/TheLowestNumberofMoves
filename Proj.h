#pragma once
void odczyt(char* fname, int flaga);
void printBoard(int playerRow, int playerCol, int flaga);
bool isValidMove(int row, int col, int flaga);
void movePlayer(int* row, int* col, char direction);
int IloscTras(char* fname, int flaga);
double spr_dl(char* fname);