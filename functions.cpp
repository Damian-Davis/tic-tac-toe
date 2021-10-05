#include <iostream>
#include "functions.hpp"

//reset the grid
std::string reset(){
  std::string reset = "_________";
  return reset;
}

//introduction event
void introduction(){
  
  std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
  std::cout << "~~TIC TAC TOE 2020™~~\n";
  std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
  std::cout << "\n";
  std::cout << "Rule n°1: there is no rule >:)\n";
  std::cout << "Rule n°2: basic tic tac toe rules, player 1 is O, player 2, X\n";
  std::cout << "Rule n°3: the squares of the gametable are numbered from 1 to 9.\n";
  std::cout << "\n";

  std::string sample_grid = "123456789";
  drawGrid(sample_grid);

  std::cout << "\n";
  std::cout << "\n";
}

//method to handle the player input and update the grid
std::string playerInput(int turn, std::string grid){
  int input;
  char mark;
  int player = 1;

  if(turn%2==0){  
    mark = 'X';
    player = 2;
  } else {  
    mark = 'O'; 
    }
    std::cout << "Player " << player << " turn, enter a valid number between 1 and 9: ";
    error:
    std::cin >> input;
    if(input>9 ||input<1 ||grid[input-1]!='_')  
      {
      std::cout << "Wrong input.\n";
      goto error;
      }
      grid[input-1] = mark;
      return grid;
}

//draw the grid
void drawGrid(std::string grid){
  for(int i=0; i<9; i+=3){
    std::cout << grid[i] << "|" << grid[i+1] << "|" << grid[i+2] << "\n";
  }
  std::cout << "\n";
}

//check if a player has won
bool checkWin(std::string grid){
  for(int i=0; i<=9; i+=3){
    if(grid[i]==grid[i+1] && grid[i+1]==grid[i+2] && grid[i]!='_') return true;
    if(grid[i]==grid[i+3] && grid[i+3]==grid[i+6] && grid[i]!='_')  return true;
  }
  if(grid[0]==grid[4] && grid[4]==grid[8] && grid[0]!='_') return true;
  if(grid[2]==grid[4] && grid[4]==grid[6] && grid[2]!='_') return true;
  std::cout << "no winner detected\n";
  return false;
}

//end of the game event
void endGame(int turn){
  int player = 1;
  if(turn%2==0) player = 2;
  std::cout << "End of the game, player " << player << " is the winner in " << turn << " turns. \n";
}
