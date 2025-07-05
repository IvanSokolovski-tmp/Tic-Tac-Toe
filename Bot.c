#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
   The plan is to make a TicTacToe GUI, where you can play with a computer bot and you can
   select your difficulty. I'm thinking easy (1) - random, hard (2) - minmax algorithm with
   limited depth, will figure that out and impossible (3) - maximum depth minmax algorithm
   for the bot.
   Also planning on making a feature, where you can select if you want to be O or X, for
   now the code is limited to the player being X, but that would probably be an easy fix.
*/

void EraseBoard(char **board); // works properly
void PrintBoard(char **board); // works properly
int AreSpacesLeft(char **board); // not tested
void PlayerMove(char **board); // works properly
void ComputerMove(int depth, char **board); // unwritten
void SimPlayerMove(char **board); // unwritten
char Winner(char **board); // not tested

int main(){
  char **board;
  board = (char**) calloc(3, sizeof(char*));
  board[0] = (char*) calloc(3, sizeof(char));
  board[1] = (char*) calloc(3, sizeof(char));
  board[2] = (char*) calloc(3, sizeof(char));
  char winner = ' ';
  int are_spaces = 1;

  EraseBoard(board);
  PrintBoard(board);
  
  while(winner == ' ' && are_spaces){
    PlayerMove(board);
    PrintBoard(board);
    ComputerMove(0, board);
    PrintBoard(board);
    winner = Winner(board);
    are_spaces = AreSpacesLeft(board);
  }
  
/*   int difficulty;
  char c;

  printf("Select your difficulty: \nEasy - 1\nHard - 2\nImpossible - 3\n");
  scanf("%c", &c);
  c = toupper(c);

  if(c == 1) difficulty = 1;
  else if(c == 2) difficulty = 2;
  else difficulty = 3; */
  
  return 0;
}

void PrintBoard(char **board){
  printf("\n");
  for(int i = 0; i < 3; i++){
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if(i != 2) printf("-----------\n");
  }
  printf("\n");
  return;
}

void EraseBoard(char **board){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
  return;
}

int AreSpacesLeft(char **board){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(board[i][j] == ' ') return 1; 
    }
  }
  return 0;
}

char Winner(char **board){
  // didn't think of a better way for this. At least I can assume it will work when tested.
  if(board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2]) return board[0][0];
  else if(board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2]) return board[1][0];
  else if(board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2]) return board[2][0];
  else if(board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0]) return board[0][0];
  else if(board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1]) return board[0][1];
  else if(board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2]) return board[0][2];
  else if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[2][2];
  else if(board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) return board[0][2];
  else return ' ';
}

void PlayerMove(char **board){
  int a, b;
  printf("Enter row(1 - 3): ");
  scanf("%d", &a);
  while(a < 1 || a > 3) {
    printf("Enter valid row(1 - 3): ");
    scanf("%d", &a);
  }
  printf("Enter column(1 - 3): ");
  scanf("%d", &b);
  while(b < 1 || b > 3) {
    printf("Enter valid column: ");
    scanf("%d", &b);
  }
  a--; b--;
  board[a][b] = 'x';  
  return;
}

void SimPlayerMove(char **board){

  return;
}