#include <iostream>

std::string reset();
void introduction();
std::string playerInput(int turn, std::string grid);
void drawGrid(std::string grid);
bool checkWin(std::string grid);
void endGame(int turn);