#include <iostream>
#include "functions.hpp"

//TIC TAC TOE 2021 
int main(){

  bool gameOn = true;
  int turn = 0;
  std::string grid = reset();
  
  introduction();

  while(gameOn){
    turn++;
    grid = playerInput(turn, grid);
    drawGrid(grid);
    gameOn = !checkWin(grid);
  }
  
  endGame(turn);
}